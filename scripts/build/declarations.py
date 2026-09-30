"""Ce qu'une unité déclare déjà, et ce qu'une fonction lui demande.

Deux essais sur trois de la première fournée d'agents ont été perdus sur une
déclaration absente de l'unité (`spiGetStackFloat`, `MapInfo`). Le
désassemblage nomme tout ce que la fonction touche — cibles de `jal` et
globales `%gp_rel`/`%hi`/`%lo` — et l'unité, avec ses en-têtes, dit ce qui est
déjà déclaré : la différence se calcule avant le premier essai.

Le repérage d'une déclaration est une heuristique de ligne (un type, le nom,
puis `;`, `(`, `[`, `{` ou `=`), pas une analyse du C++ : il peut manquer une
déclaration écrite sur plusieurs lignes, et le dit en « non trouvée » plutôt
que de l'affirmer absente du compilateur.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT, sources  # noqa: E402

# `jal` appelle ; `j` vers un symbole est un appel de queue. Les étiquettes
# locales commencent par un point et n'y entrent pas.
_JAL = re.compile(r"\bj(?:al)?\s+([A-Za-z_]\w*)")
_DONNEE = re.compile(r"%(?:gp_rel|hi|lo)\(([A-Za-z_]\w*)")
_INCLUDE = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.MULTILINE)
_MOT_D_APPEL = {"return", "if", "else", "while", "for", "case", "switch", "do",
                "goto", "sizeof"}


def references(chemin_asm: Path) -> tuple[list[str], list[str]]:
    """Les appelés et les globales que le désassemblage nomme, dans l'ordre."""
    texte = chemin_asm.read_text(encoding="utf-8", errors="replace")
    appeles, donnees = [], []
    for n in _JAL.findall(texte):
        if n not in appeles:
            appeles.append(n)
    for n in _DONNEE.findall(texte):
        if n not in donnees:
            donnees.append(n)
    return appeles, donnees


def _motif(nom: str) -> re.Pattern:
    return re.compile(
        rf"^(?P<tete>[ \t]*(?:extern\b[^\n;{{=]*|[A-Za-z_][\w \t\*:<>,&]*?))"
        rf"\b{re.escape(nom)}\b[ \t]*(?:\[[^\]\n]*\][ \t]*)*(?:\(|;|=|\{{|,)",
        re.MULTILINE)


def declaration_dans(nom: str, texte: str) -> str | None:
    """La ligne qui déclare ou définit `nom` dans ce texte, si l'on en voit une."""
    for m in _motif(nom).finditer(texte):
        premier = m.group("tete").split()
        if premier and premier[0] in _MOT_D_APPEL:
            continue
        ligne = texte[texte.rfind("\n", 0, m.start()) + 1:
                      texte.find("\n", m.end()) if texte.find("\n", m.end()) >= 0
                      else len(texte)]
        return ligne.strip()
    return None


def _resolu(inclusion: str, depuis: Path) -> Path | None:
    for base in (depuis.parent, ROOT / "include", ROOT / "src"):
        cand = base / inclusion
        if cand.is_file():
            return cand
    return None


def textes_visibles(unite: Path) -> list[tuple[Path, str]]:
    """L'unité et, transitivement, les en-têtes du projet qu'elle inclut."""
    vus: dict[Path, str] = {}
    pile = [unite]
    while pile:
        p = pile.pop()
        if p in vus:
            continue
        vus[p] = p.read_text(encoding="utf-8", errors="replace")
        for inc in _INCLUDE.findall(vus[p]):
            r = _resolu(inc, p)
            if r is not None:
                pile.append(r)
    return list(vus.items())


def declare_ailleurs(nom: str, hors: Path) -> tuple[Path, str] | None:
    """Une déclaration de `nom` dans une autre unité : le modèle à recopier."""
    for src in sources():
        if src == hors:
            continue
        ligne = declaration_dans(nom, src.read_text(encoding="utf-8",
                                                    errors="replace"))
        if ligne and (ligne.startswith("extern") or ligne.endswith(";")):
            return src, ligne
    return None


def avant_la_greffe(unite: Path, symbole: str) -> int | None:
    """Le décalage de l'`INCLUDE_ASM` du symbole dans son unité.

    Une déclaration qui suit la fonction ne la sert pas : MWCC répond
    « undefined identifier » alors que la ligne existe bien plus bas.
    """
    m = re.search(rf'INCLUDE_ASM\s*\([^)]*\b{re.escape(symbole)}\s*\)',
                  unite.read_text(encoding="utf-8", errors="replace"))
    return m.start() if m else None


def etat_des_declarations(unite: Path, noms: list[str], candidat: str = "",
                          limite: int | None = None) -> dict[str, dict]:
    """Pour chaque nom : déclaré où, ou non trouvé, avec un modèle ailleurs.

    `limite` borne le texte de l'unité elle-même : seul ce qui précède ce
    décalage compte, puisque l'essai prendra la place de l'`INCLUDE_ASM`.
    """
    visibles = textes_visibles(unite)
    texte_unite = visibles[0][1]
    if limite is not None:
        visibles = [(c, t[:limite] if c == unite else t) for c, t in visibles]
    sortie: dict[str, dict] = {}
    for nom in noms:
        trouve = None
        if candidat:
            ligne = declaration_dans(nom, candidat)
            if ligne:
                trouve = ("l'essai", ligne)
        if trouve is None:
            for chemin, texte in visibles:
                ligne = declaration_dans(nom, texte)
                if ligne:
                    trouve = (str(chemin.relative_to(ROOT)), ligne)
                    break
        if trouve:
            sortie[nom] = {"ok": True, "ou": trouve[0], "ligne": trouve[1]}
        else:
            modele = declare_ailleurs(nom, unite)
            # Une déclaration qui suit la fonction n'aide pas MWCC, mais elle
            # donne la signature à recopier : une redéclaration d'une autre
            # forme (`(...)` contre un type) est refusée (« illegal function
            # overloading »).
            plus_loin = declaration_dans(nom, texte_unite) if limite is not None else None
            sortie[nom] = {"ok": False, "plus_loin": plus_loin,
                           "modele": (str(modele[0].relative_to(ROOT)),
                                      modele[1]) if modele else None}
    return sortie


_TYPE = re.compile(r"\b([A-Z][A-Za-z0-9_]*)\b")


def types_non_declares(unite: Path, ligne: str, limite: int | None) -> list[str]:
    """Les types nommés par une déclaration que rien ne définit avant la fonction.

    `extern "C" CNameRegiMenu *NameRegiMenuPtr;` se recopie dans l'essai, mais si
    `CNameRegiMenu` n'est défini qu'après la fonction, MWCC prend le nom pour un
    `int` (« function call does not match (int) ») : il faut `struct CNameRegiMenu;`
    en tête de l'essai.
    """
    visibles = textes_visibles(unite)
    texte = "\n".join(t[:limite] if (limite is not None and c == unite) else t
                      for c, t in visibles)
    inconnus = []
    for nom in dict.fromkeys(_TYPE.findall(ligne)):
        if nom in ("C", "NULL") or nom.isupper() and len(nom) <= 2:
            continue
        if not re.search(rf"\b(?:struct|class|union|enum)\s+{re.escape(nom)}\b|"
                         rf"\btypedef\b[^;]*\b{re.escape(nom)}\s*;", texte):
            inconnus.append(nom)
    return inconnus
