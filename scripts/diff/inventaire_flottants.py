"""Recense les sites d'appel qui matérialisent des constantes flottantes.

Question posée : devant le même nombre d'arguments flottants constants, qu'est-ce
qui décide que MWCC n'emploie qu'un registre entier de travail (forme sérielle,
`mtc1 zero` comblant l'écart) plutôt que deux (forme appariée) ?

Chaque site est réduit à ses traits observables : les registres flottants servis,
la présence d'un zéro et son rang, le nombre de registres entiers de travail,
d'où vient `$a0` et ce que le créneau de délai du `jal` porte.
"""

import collections
import glob
import os
import re
import sys

RACINE = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

# `    /* 1481DC 002481DC 2042033C */  lui  $v1, (0x42200000 >> 16)`
LIGNE = re.compile(r"^\s*/\*\s+\w+\s+([0-9A-F]{8})\s+\w{8}\s+\*/\s+(\S+)\s*(.*?)\s*$")


def instructions(chemin):
    """Rend la suite (adresse, mnémonique, opérandes, dans_un_créneau)."""
    suite = []
    delai = False
    for ligne in open(chemin, encoding="utf-8", errors="replace"):
        m = LIGNE.match(ligne)
        if not m:
            continue
        adresse, mnemo, args = m.group(1), m.group(2), m.group(3)
        suite.append((int(adresse, 16), mnemo, args, delai))
        delai = mnemo in ("jal", "jalr", "j", "jr", "b", "bc1t", "bc1f") or \
            mnemo.startswith(("beq", "bne", "bgt", "blt", "bge", "ble", "bgez",
                              "bltz", "bgtz", "blez"))
    return suite


REG = re.compile(r"\$(\w+)")


def sites(suite):
    """Découpe autour de chaque `jal` et décrit la matérialisation qui le précède."""
    for i, (adresse, mnemo, args, _) in enumerate(suite):
        if mnemo != "jal":
            continue
        appele = args.strip()

        # Le bloc utile s'arrête au branchement ou à l'appel précédent : au-delà,
        # l'ordonnanceur n'a pas pu déplacer.
        debut = i
        while debut > 0:
            _, m_p, _, _ = suite[debut - 1]
            if m_p in ("jal", "jalr", "jr") or m_p.startswith(("b", "j")):
                break
            debut -= 1
        bloc = suite[debut:i]
        if len(bloc) < 3:
            continue

        # Les `mtc1` vers $f12..$f15 disent quels arguments flottants sont servis.
        mtc1 = []
        for _, m, a, _ in bloc:
            if m != "mtc1":
                continue
            regs = REG.findall(a)
            if len(regs) != 2:
                continue
            source, cible = regs
            if cible in ("f12", "f13", "f14", "f15"):
                mtc1.append((cible, source))
        if len(mtc1) < 3:
            continue

        travail = sorted({s for _, s in mtc1 if s != "zero"})
        zeros = [c for c, s in mtc1 if s == "zero"]
        # Rang du zéro dans l'ordre d'émission, non dans l'ordre des arguments.
        rang_zero = next((n for n, (_, s) in enumerate(mtc1) if s == "zero"), -1)

        # Ce que le créneau de délai du `jal` porte.
        creneau = suite[i + 1][1] if i + 1 < len(suite) else "?"
        creneau_args = suite[i + 1][2] if i + 1 < len(suite) else ""
        a0_dans_creneau = creneau in ("daddu", "move", "addiu", "lw", "addu") and \
            creneau_args.startswith("$a0")

        yield {
            "adresse": adresse,
            "appele": appele,
            "cibles": "".join(c[1:] for c, _ in mtc1),
            "ordre": [c for c, _ in mtc1],
            "travail": travail,
            "n_travail": len(travail),
            "n_flottants": len(mtc1),
            "a_zero": bool(zeros),
            "rang_zero": rang_zero,
            "a0_creneau": a0_dans_creneau,
            "creneau": creneau,
            "bloc": bloc,
        }


def main():
    fichiers = glob.glob(os.path.join(RACINE, "ref", "asm", "text", "**", "*.s"),
                         recursive=True)
    if not fichiers:
        print("aucun désassemblage sous ref/asm/text — lancer `make setup`")
        return 1

    tous = []
    for chemin in fichiers:
        tous.extend(sites(instructions(chemin)))

    print(f"{len(fichiers)} unités, {len(tous)} sites servant au moins trois flottants\n")

    # Premier partage : combien de registres entiers de travail ?
    par_n = collections.Counter(s["n_travail"] for s in tous)
    print("registres entiers de travail :")
    for n in sorted(par_n):
        print(f"  {n} registre(s) : {par_n[n]:4d} sites")

    # Le cas qui nous occupe : quatre flottants, un zéro.
    quatre = [s for s in tous if s["n_flottants"] == 4 and s["a_zero"]]
    print(f"\nquatre flottants dont un zéro : {len(quatre)} sites")
    par_n = collections.Counter(s["n_travail"] for s in quatre)
    for n in sorted(par_n):
        print(f"  {n} registre(s) : {par_n[n]:4d} sites")

    # Le rang du zéro dans l'émission distingue-t-il les deux formes ?
    print("\n  rang du zéro émis × nombre de registres :")
    croise = collections.Counter((s["rang_zero"], s["n_travail"]) for s in quatre)
    for (rang, n) in sorted(croise):
        print(f"    zéro en position {rang}, {n} registre(s) : {croise[(rang, n)]:4d}")

    # D'où vient `$a0` : posé dans le créneau de délai, ou plus tôt ?
    print("\n  `$a0` posé dans le créneau × nombre de registres :")
    croise = collections.Counter((s["a0_creneau"], s["n_travail"]) for s in quatre)
    for (creneau, n) in sorted(croise):
        print(f"    a0 dans le créneau={creneau}, {n} registre(s) : {croise[(creneau, n)]:4d}")

    # Les sites d'un seul registre : lesquels, et quel registre ?
    seuls = [s for s in quatre if s["n_travail"] == 1]
    print(f"\n  sites sériels (un seul registre) : {len(seuls)}")
    for s in seuls[:40]:
        print(f"    {s['adresse']:08X}  {s['travail'][0]:4s} zéro#{s['rang_zero']} "
              f"ordre={'.'.join(c[1:] for c in s['ordre'])} "
              f"créneau={s['creneau']:6s} {s['appele'][:44]}")

    doubles = [s for s in quatre if s["n_travail"] >= 2]
    print(f"\n  sites appariés (deux registres ou plus) : {len(doubles)}")
    for s in doubles[:40]:
        print(f"    {s['adresse']:08X}  {'+'.join(s['travail']):9s} zéro#{s['rang_zero']} "
              f"ordre={'.'.join(c[1:] for c in s['ordre'])} "
              f"créneau={s['creneau']:6s} {s['appele'][:44]}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
