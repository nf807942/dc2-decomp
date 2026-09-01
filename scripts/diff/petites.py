#!/usr/bin/env python3
"""Reconstruit d'un trait les fonctions que leur taille rend mécaniques.

    scripts/host/dc2 python3 scripts/diff/petites.py plan
    scripts/host/dc2 python3 scripts/diff/petites.py plan --secteur game

Une fonction de huit à quinze octets n'a qu'une ou deux instructions utiles :
son désassemblage dit la source à écrire, sans marge d'interprétation. Ce module
les traduit toutes en une passe, en interprétant le corps registre par registre
plutôt qu'en énumérant des cas — un accesseur, un effacement et un retour de
constante suivent le même chemin.

Il ne produit rien qu'il ne sache justifier : une instruction inconnue, un type
que le mangling ne rend pas, une globale non déclarée écartent la fonction, qui
reste greffée. Le verdict est `make build` ; le plan n'est qu'une proposition,
que `scripts/build/passe_petites.py` éprouve et annule au besoin.
"""

from __future__ import annotations

import argparse
import glob
import json
import os
import re
import struct
import sys
from dataclasses import dataclass, field

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from lib.mangling import Symbol, demangle  # noqa: E402

RACINE = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

TAILLE = re.compile(r"^(\S+) = 0x([0-9A-Fa-f]+); // type:func size:0x([0-9A-Fa-f]+)")
INCLUDE = re.compile(r'INCLUDE_ASM\("nonmatchings/([^"]+)",\s*([^)]+)\);')
INSTRUCTION = re.compile(r"^\s*/\*\s+\w+\s+[0-9A-F]{8}\s+\w{8}\s+\*/\s+(\S+)\s*(.*?)\s*$")

# Ce que chaque instruction de transfert dit du champ qu'elle touche. La largeur
# est celle de l'accès ; le signe, celui que l'instruction impose. Un `lh` ne
# prouve pas la largeur du champ — c'est la fonction qui l'écrit en entier qui
# tranche —, mais il décide de l'octet émis, seul verdict ici.
ACCES = {
    "lw": "s32", "lwu": "u32", "lh": "s16", "lhu": "u16",
    "lb": "s8", "lbu": "u8", "ld": "s64", "lwc1": "f32",
    "sw": "s32", "sh": "s16", "sb": "s8", "sd": "s64", "swc1": "f32",
}
LECTURES = {m for m in ACCES if m.startswith("l")}
ECRITURES = {m for m in ACCES if m.startswith("s")}

# La taille en octets de chaque type que ce module écrit.
LARGEUR = {"s8": 1, "u8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4,
           "f32": 4, "s64": 8, "u64": 8}

OBJET = re.compile(r"^(\w+) = 0x[0-9A-Fa-f]+; // size:0x([0-9A-Fa-f]+)")
GP_REL = re.compile(r"^\$(\w+), %gp_rel\((\w+)\)\(\$gp\)$")
DECALE = re.compile(r"^\$(\w+), (-?(?:0x)?[0-9A-Fa-f]+)\(\$(\w+)\)$")
TROIS = re.compile(r"^\$(\w+), \$(\w+), (\S+)$")
DEUX = re.compile(r"^\$(\w+), \$(\w+)$")


def _globales() -> dict[str, int]:
    """La taille déclarée de chaque objet, qui décide de son adressage."""
    chemin = os.path.join(RACINE, "config", "elf_symbol_addrs.txt")
    trouvees = {}
    for ligne in open(chemin, encoding="utf-8"):
        ligne = ligne.strip()
        if "type:func" in ligne:
            continue
        match = OBJET.match(ligne)
        if match:
            trouvees[match.group(1)] = int(match.group(2), 16)
    return trouvees


GLOBALES = _globales()


def entier(texte: str) -> int:
    return int(texte, 16) if texte.lower().startswith(("0x", "-0x")) else int(texte, 0)


def flottant(bits: int) -> str:
    """Le littéral C d'un motif de bits, sous la forme la plus courte qui le rend."""
    valeur = struct.unpack(">f", struct.pack(">I", bits & 0xFFFFFFFF))[0]
    for chiffres in range(1, 10):
        texte = "%.*g" % (chiffres, valeur)
        if struct.pack(">f", float(texte)) == struct.pack(">f", valeur):
            return texte + ("f" if "." in texte or "e" in texte else ".0f")
    raise Abandon("constante flottante 0x%08X" % bits)


# Les fonctions du runtime que le compilateur appelle sous leur nom C. Une
# fonction appelée en queue ne se reconnaît qu'à ce nom-là : un symbole manglé
# désigne une méthode, dont la déclaration demande sa classe entière.
# La déclaration est celle que les unités déjà écrites emploient : le nom C
# impose `extern "C"`, sans quoi l'appel viserait un symbole manglé.
RUNTIME = {
    "memset": ('extern "C" void *memset(void *destination, s32 value, u32 size);',
               ["void *", "s32", "u32"]),
    "memcpy": ('extern "C" void *memcpy(void *destination, const void *source,'
               " u32 size);", ["void *", "void *", "u32"]),
    "strcpy": ('extern "C" char *strcpy(char *destination, const char *source);',
               ["char *", "char *"]),
}


@dataclass
class Besoin:
    """Ce qu'une source réclame avant de compiler."""

    champs: dict[str, dict[int, str]] = field(default_factory=dict)
    types: set[str] = field(default_factory=set)

    def champ(self, type_nomme: str, offset: int, largeur: str) -> str:
        table = self.champs.setdefault(type_nomme, {})
        # Le premier accès nomme le champ ; un accès plus étroit ne le rétrécit
        # pas, faute de quoi deux accesseurs du même champ se contrediraient.
        table.setdefault(offset, largeur)
        return "field_0x%X" % offset


@dataclass
class Valeur:
    """Ce qu'un registre porte : une expression C++ et son type, quand il est sûr."""

    texte: str
    type: str | None = None
    adresse_de: tuple[str, int] | None = None   # (type nommé, décalage)


class Abandon(Exception):
    """Ce que le module ne sait pas traduire, il le laisse greffé."""


class Interprete:
    """Traduit un corps de quelques instructions en une source équivalente.

    Les registres portent des expressions, non des valeurs : `$a1` vaut le nom
    du paramètre, `$a0` vaut `this`, et un chargement rend l'accès au champ. Ce
    qui s'écrit en mémoire devient une phrase, ce qui reste dans `$v0` devient
    le retour.
    """

    def __init__(self, sym: Symbol, besoin: Besoin):
        self.sym = sym
        self.besoin = besoin
        self.effets: list[str] = []
        self.regs: dict[str, Valeur] = {"zero": Valeur("0", "s32")}
        self.globales: dict[str, str] = {}
        self.appel: str | None = None

        # `$a0` porte `this` pour une méthode ; sinon le premier paramètre. Les
        # flottants voyagent dans leur propre file, à partir de `$f12`.
        self.noms: list[str] = []
        entiers, flottants = 0, 0
        if sym.cls:
            self.regs["a0"] = Valeur("this", sym.cls + " *")
            entiers = 1
        for rang, kind in enumerate(sym.params):
            nom = "arg%d" % rang
            self.noms.append(nom)
            if kind in ("f32", "f64"):
                self.regs["f%d" % (12 + flottants)] = Valeur(nom, kind)
                flottants += 1
            else:
                if entiers > 3:
                    raise Abandon("plus de quatre arguments entiers")
                self.regs["a%d" % entiers] = Valeur(nom, kind)
                entiers += 1

    # -- lecture des opérandes ------------------------------------------

    def lire(self, registre: str) -> Valeur:
        valeur = self.regs.get(registre)
        if valeur is None:
            raise Abandon("registre %s sans provenance" % registre)
        return valeur

    def base(self, registre: str) -> tuple[str, str]:
        """L'expression d'un pointeur, et le type nommé qu'il désigne."""
        valeur = self.lire(registre)
        if not valeur.type or not valeur.type.endswith("*"):
            raise Abandon("base %s de type inconnu" % registre)
        nomme = valeur.type.rstrip(" *")
        if nomme in ("void", "char", "u8", "s8"):
            raise Abandon("base sans type nommé")
        return valeur.texte, nomme

    def acces(self, mnemonique: str, arguments: str) -> tuple[str, str]:
        """L'accès `off($base)` rendu en `pointeur->champ`, et sa largeur."""
        largeur = ACCES[mnemonique]

        # Une globale s'atteint par `$gp`. Sa taille déclarée décide du `%gp_rel`
        # que le commerce porte : on ne la reconstruit que si l'accès la couvre
        # tout entière, faute de quoi la déclaration serait une invention.
        match = GP_REL.match(arguments)
        if match:
            registre, nom = match.groups()
            if re.search(r"_00[0-9A-F]{6}$", nom):
                raise Abandon("statique locale %s" % nom)
            taille = GLOBALES.get(nom)
            if taille is None or taille != LARGEUR.get(largeur):
                raise Abandon("globale %s de taille %s" % (nom, taille))
            self.globales[nom] = largeur
            return (registre, nom), largeur

        match = DECALE.match(arguments)
        if not match:
            raise Abandon("opérande %r" % arguments)
        registre, decalage, source = match.groups()
        texte, nomme = self.base(source)
        offset = entier(decalage)
        champ = self.besoin.champ(nomme, offset, largeur)
        return (registre, "%s->%s" % (texte, champ)), largeur

    # -- exécution --------------------------------------------------------

    def instruction(self, mnemonique: str, arguments: str) -> None:
        if mnemonique in LECTURES:
            (registre, fleche), largeur = self.acces(mnemonique, arguments)
            self.regs[registre] = Valeur(fleche, largeur)
            return

        if mnemonique in ECRITURES:
            (registre, fleche), _largeur = self.acces(mnemonique, arguments)
            self.effets.append("%s = %s;" % (fleche, self.lire(registre).texte))
            return

        if mnemonique in ("addiu", "addi", "daddiu"):
            match = TROIS.match(arguments)
            if not match:
                raise Abandon("addiu %r" % arguments)
            cible, source, immediat = match.groups()
            if source == "zero":
                self.regs[cible] = Valeur(str(entier(immediat)), "s32")
                return
            texte, nomme = self.base(source)
            offset = entier(immediat)
            champ = self.besoin.champ(nomme, offset, "s32")
            self.regs[cible] = Valeur("&%s->%s" % (texte, champ), None,
                                      adresse_de=(nomme, offset))
            return

        if mnemonique in ("daddu", "addu", "move", "or"):
            match = TROIS.match(arguments) or DEUX.match(arguments)
            if not match:
                raise Abandon("copie %r" % arguments)
            groupes = match.groups()
            cible = groupes[0]
            gauche, droite = (groupes[1], groupes[2]) if len(groupes) == 3 \
                else (groupes[1], "zero")
            if droite.lstrip("$") == "zero":
                self.regs[cible] = self.lire(gauche)
            elif gauche == "zero":
                self.regs[cible] = self.lire(droite.lstrip("$"))
            else:
                raise Abandon("somme de deux registres")
            return

        if mnemonique == "lui":
            match = re.match(r"^\$(\w+), (\S+)$", arguments)
            if not match or match.group(2).startswith("%"):
                raise Abandon("lui %r" % arguments)
            self.regs[match.group(1)] = Valeur(
                str(entier(match.group(2)) << 16), "s32")
            return

        if mnemonique in ("ori", "addiu_haut"):
            match = TROIS.match(arguments)
            if not match:
                raise Abandon("ori %r" % arguments)
            cible, source, immediat = match.groups()
            gauche = self.lire(source)
            if not gauche.texte.lstrip("-").isdigit():
                raise Abandon("ori sur une expression")
            self.regs[cible] = Valeur(str(int(gauche.texte) | entier(immediat)), "s32")
            return

        # Une constante flottante voyage par `$at` avant d'entrer dans un
        # registre de calcul : c'est le motif que MWCC rend d'un littéral.
        if mnemonique == "mtc1":
            match = DEUX.match(arguments)
            if not match:
                raise Abandon("mtc1 %r" % arguments)
            source, cible = match.groups()
            valeur = self.lire(source)
            if not valeur.texte.lstrip("-").isdigit():
                raise Abandon("mtc1 d'une expression")
            self.regs[cible] = Valeur(flottant(int(valeur.texte)), "f32")
            return

        if mnemonique in ("mov.s", "mov.d"):
            match = DEUX.match(arguments)
            if not match:
                raise Abandon("mov %r" % arguments)
            self.regs[match.group(1)] = self.lire(match.group(2))
            return

        raise Abandon("instruction %s" % mnemonique)

    def queue(self, cible: str) -> str:
        """Un saut de queue vers une fonction du runtime, avec ses arguments."""
        signature = RUNTIME.get(cible)
        if signature is None:
            raise Abandon("appel terminal vers %s" % cible)
        _declaration, params = signature
        arguments = []
        for rang, kind in enumerate(params):
            valeur = self.regs.get("a%d" % rang)
            if valeur is None:
                raise Abandon("argument %d de %s inconnu" % (rang, cible))
            arguments.append(valeur.texte)
        self.appel = cible
        return "%s(%s);" % (cible, ", ".join(arguments))

    # -- rendu ------------------------------------------------------------

    def corps(self, suite: list[tuple[str, str]]) -> tuple[list[str], str]:
        """Rend les lignes du corps et le type de retour."""
        # Le saut de queue est la dernière chose qui s'exécute, mais pas la
        # dernière écrite : l'instruction de son créneau de délai le précède.
        cible = None
        for mnemonique, arguments in suite:
            if mnemonique in ("nop", "jr"):
                continue
            if mnemonique == "j":
                cible = arguments.strip()
                continue
            self.instruction(mnemonique, arguments)

        lignes = list(self.effets)
        if cible is not None:
            lignes.append(self.queue(cible))

        # Un constructeur rend `this` sans qu'on l'écrive ; toute autre valeur
        # laissée dans `$v0` ou `$f0` est le retour de la fonction.
        rendu = self.regs.get("v0") or self.regs.get("f0")
        if self.sym.kind == "constructeur":
            return lignes, ""
        if rendu is None or rendu.texte in ("this",):
            return lignes, "void"
        if rendu.type is None and rendu.adresse_de:
            # L'adresse d'un champ ne dit pas ce qu'on y trouve ; `void *` rend
            # le même `addiu` sans rien affirmer de plus.
            return lignes + ["return %s;" % rendu.texte], "void *"
        if not rendu.type:
            raise Abandon("retour de type inconnu")
        lignes.append("return %s;" % rendu.texte)
        return lignes, rendu.type


def tailles() -> dict[str, tuple[int, int]]:
    chemin = os.path.join(RACINE, "config", "elf_symbol_addrs.txt")
    trouvees = {}
    for ligne in open(chemin, encoding="utf-8"):
        match = TAILLE.match(ligne.strip())
        if match:
            trouvees[match.group(1)] = (int(match.group(2), 16), int(match.group(3), 16))
    return trouvees


_REFERENCE: dict[str, dict] | None = None


def reference() -> dict[str, dict]:
    """Le désassemblage de référence, indexé par symbole.

    C'est lui, et non `asm/nonmatchings/`, qui dit ce qu'une fonction contient :
    le second ne porte que ce qui reste greffé, donc une fonction déjà écrite y
    disparaît — et avec elle tout moyen de retrouver ce qu'on lui a déduit.
    """
    global _REFERENCE
    if _REFERENCE is not None:
        return _REFERENCE

    _REFERENCE = {}
    racine = os.path.join(RACINE, "ref", "asm", "text")
    for dossier, _sous, fichiers in os.walk(racine):
        for fichier in sorted(fichiers):
            if not fichier.endswith(".s"):
                continue
            chemin = os.path.join(dossier, fichier)
            unite = os.path.relpath(chemin, racine)[:-2].replace("\\", "/")
            nom, suite, precedent = None, [], None
            for ligne in open(chemin, encoding="utf-8", errors="replace"):
                if ligne.startswith("glabel "):
                    nom, suite, precedent = ligne.split()[1], [], None
                    continue
                if ligne.startswith("endlabel "):
                    if nom:
                        _REFERENCE[nom] = {"unite": unite, "instructions": suite,
                                           "remplissage": 0}
                        precedent = nom
                    nom = None
                    continue
                match = INSTRUCTION.match(ligne)
                if nom is not None:
                    if match:
                        suite.append((match.group(1), match.group(2)))
                elif match:
                    # Ce qui suit `endlabel` sans appartenir à personne est le
                    # remplissage d'alignement : MWCC le rend dans le symbole
                    # qu'il émet, le désassembleur le laisse dehors. Toute autre
                    # instruction ferme le compte.
                    if precedent and match.group(1) == "nop":
                        _REFERENCE[precedent]["remplissage"] += 1
                    else:
                        precedent = None
    return _REFERENCE


def instructions(secteur: str, nom: str) -> list[tuple[str, str]] | None:
    entree = reference().get(nom)
    return entree["instructions"] if entree else None


def inventaire(secteur: str, mini: int, maxi: int) -> list[dict]:
    """Les fonctions du cadran, greffées ou déjà écrites.

    L'unité vient du désassemblage de référence, non des `INCLUDE_ASM` : une
    fonction déjà écrite doit rester dans l'inventaire, sans quoi l'en-tête de
    sa classe se régénérerait sans elle et l'unité ne compilerait plus.
    """
    connues = tailles()
    lot = []
    textes: dict[str, str] = {}
    for nom, entree in reference().items():
        taille = connues.get(nom, (0, 0))[1]
        if not mini <= taille <= maxi:
            continue
        if secteur != "tout" and not entree["unite"].startswith(secteur + "/"):
            continue
        source = os.path.join("src", entree["unite"] + ".cpp")
        if not os.path.exists(os.path.join(RACINE, source)):
            continue
        if source not in textes:
            textes[source] = open(os.path.join(RACINE, source),
                                  encoding="utf-8").read()
        greffee = ('INCLUDE_ASM("nonmatchings/%s", %s);'
                   % (entree["unite"], nom)) in textes[source]
        lot.append({
            "source": source.replace("\\", "/"), "chemin_asm": entree["unite"],
            "symbole": nom, "taille": taille, "greffee": greffee,
            "remplissage": entree["remplissage"],
        })
    lot.sort(key=lambda entree: (entree["source"], entree["symbole"]))
    return lot


def traduire(entree: dict, besoin: Besoin) -> dict | None:
    """Rend la source d'une fonction, ou `None` quand elle n'est pas sûre."""
    sym = demangle(entree["symbole"])
    if sym is None:
        return {"raison": "mangling"}
    suite = instructions(entree["chemin_asm"], entree["symbole"])
    if suite is None:
        return {"raison": "désassemblage absent"}

    local = Besoin()
    try:
        interprete = Interprete(sym, local)
        lignes, retour = interprete.corps(suite)
    except Abandon as cause:
        return {"raison": str(cause)}

    # Le nom d'un constructeur est celui de sa classe, et il ne rend rien.
    nom = sym.cls if sym.kind == "constructeur" else sym.name
    args = ", ".join("%s %s" % (kind, "arg%d" % rang)
                     for rang, kind in enumerate(sym.params)) or "void"
    portee = "%s::" % sym.cls if sym.cls else ""
    tete = "%s%s%s(%s)" % ((retour + " ") if retour else "", portee, nom, args)
    if sym.const:
        tete += " const"
    corps = "\n".join("    " + ligne for ligne in lignes)
    texte = "%s {\n%s\n}" % (tete, corps) if corps else "%s {\n}" % tete

    besoin.types.update(local.types)
    for nomme, champs in local.champs.items():
        fusion = besoin.champs.setdefault(nomme, {})
        for offset, largeur in champs.items():
            fusion.setdefault(offset, largeur)

    # Ce que l'unité doit connaître avant de compiler ce corps : la globale que
    # l'accès nomme, et la fonction C qu'un saut de queue vise.
    declarations = ["extern %s %s;" % (kind, nom)
                    for nom, kind in sorted(interprete.globales.items())]
    if interprete.appel:
        declarations.append(RUNTIME[interprete.appel][0])

    # La déclaration en membre, que l'en-tête de la classe devra porter : une
    # définition hors ligne ne suffit pas, le compilateur veut d'abord savoir
    # que la classe a cette méthode.
    membre = "%s%s(%s)%s;" % ((retour + " ") if retour else "", nom, args,
                              " const" if sym.const else "")

    return {"cpp": texte, "classe": sym.cls, "champs": local.champs,
            "types": sorted(t for t in sym.named_types),
            "declarations": declarations, "membre": membre}


def main(argv: list[str]) -> int:
    parseur = argparse.ArgumentParser(description=__doc__)
    parseur.add_argument("commande", choices=["plan", "resume"])
    parseur.add_argument("--secteur", default="game")
    parseur.add_argument("--mini", type=int, default=8)
    parseur.add_argument("--maxi", type=int, default=15)
    parseur.add_argument("--sortie", default="progress/petites.json")
    options = parseur.parse_args(argv)

    lot = inventaire(options.secteur, options.mini, options.maxi)
    besoin = Besoin()
    retenues, refus = [], {}
    for entree in lot:
        rendu = traduire(entree, besoin)
        if rendu and "cpp" in rendu:
            retenues.append({**entree, **rendu})
        else:
            raison = (rendu or {}).get("raison", "inconnue")
            refus.setdefault(raison, []).append(entree["symbole"])

    print("lot %s, %d à %d octets : %d fonctions, %d traduites"
          % (options.secteur, options.mini, options.maxi, len(lot), len(retenues)))
    for raison, noms in sorted(refus.items(), key=lambda kv: -len(kv[1])):
        print("  écartées %4d  %s" % (len(noms), raison))

    if options.commande == "plan":
        chemin = os.path.join(RACINE, options.sortie)
        os.makedirs(os.path.dirname(chemin), exist_ok=True)
        with open(chemin, "w", encoding="utf-8") as sortie:
            json.dump({"fonctions": retenues,
                       "champs": {nomme: {str(k): v for k, v in champs.items()}
                                  for nomme, champs in besoin.champs.items()}},
                      sortie, ensure_ascii=False, indent=1)
        print("plan : %s" % options.sortie)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
