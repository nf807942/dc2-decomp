"""Inventorie les petites fonctions encore greffées, et les classe par forme.

    scripts/host/dc2 python3 scripts/diff/inventaire_petites.py
    scripts/host/dc2 python3 scripts/diff/inventaire_petites.py 8

Une fonction de huit octets n'a qu'une instruction utile, et cette instruction
dit à elle seule ce que la source doit être. Les classer par forme transforme un
tas de mille deux cents en une poignée de lots uniformes qu'on écrit d'un trait :
c'est ce qui a mené cent cinquante-six fonctions à 100 % en trois passes, dont
soixante-trois commandes de script à la même signature.

La sortie est un tableau par forme, puis la liste complète triée par unité, de
quoi engendrer le C++ ou le relire. Le verdict reste `make build`.
"""

import collections
import glob
import os
import re
import sys

RACINE = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

TAILLE = re.compile(r"^(\S+) = 0x([0-9A-Fa-f]+); // type:func size:0x([0-9A-Fa-f]+)")
INCLUDE = re.compile(r'INCLUDE_ASM\("nonmatchings/([^"]+)",\s*([^)]+)\);')
INSTRUCTION = re.compile(r"^\s*/\*\s+\w+\s+[0-9A-F]{8}\s+\w{8}\s+\*/\s+(\S+)\s*(.*?)\s*$")

# Chaque forme est un couple (mnémonique, motif d'arguments). L'ordre compte :
# la première qui correspond nomme la fonction.
FORMES = [
    ("rend une constante",  r"^addiu$",   r"^\$v0, \$zero, "),
    ("rend zéro",           r"^daddu$",   r"^\$v0, \$zero, \$zero$"),
    ("lecteur de globale",  r"^l[wbhd]u?|lwc1$", r"^\$\w+, %gp_rel\("),
    ("poseur de globale",   r"^s[wbhd]|swc1$",   r"^\$\w+, %gp_rel\("),
    ("poseur de champ",     r"^s[wbhd]|swc1$",   r"^\$(a1|f12), 0x[0-9a-f]+\(\$a0\)$"),
    ("lecteur de champ",    r"^l[wbhd]u?|lwc1$", r"^\$(v0|f0), 0x[0-9a-f]+\(\$a0\)$"),
    ("efface un champ",     r"^s[wbhd]$", r"^\$zero, 0x[0-9a-f]+\(\$a0\)$"),
    ("appel terminal",      r"^j$",       r"^\w+$"),
]


def tailles():
    chemin = os.path.join(RACINE, "config", "elf_symbol_addrs.txt")
    trouvees = {}
    for ligne in open(chemin, encoding="utf-8"):
        match = TAILLE.match(ligne.strip())
        if match:
            trouvees[match.group(1)] = (int(match.group(2), 16), int(match.group(3), 16))
    return trouvees


def instructions(secteur, nom):
    """Les instructions utiles du corps, `nop` d'alignement exclus."""
    chemin = os.path.join(RACINE, "asm", "nonmatchings", secteur, nom + ".s")
    if not os.path.exists(chemin):
        return None
    suite, dans_le_corps = [], False
    for ligne in open(chemin, encoding="utf-8", errors="replace"):
        if ligne.startswith("glabel"):
            dans_le_corps = True
            continue
        if ligne.startswith("endlabel"):
            break
        if dans_le_corps:
            match = INSTRUCTION.match(ligne)
            if match and match.group(1) != "nop":
                suite.append((match.group(1), match.group(2)))
    return suite


def forme(suite):
    if suite is None:
        return "désassemblage absent"
    utiles = [i for i in suite if i[0] != "jr"]
    if len(suite) != 2 or len(utiles) != 1:
        return "corps de %d instructions" % len(suite)
    mnemonique, arguments = utiles[0]
    for nom, remn, rearg in FORMES:
        if re.match(remn, mnemonique) and re.match(rearg, arguments):
            return nom
    return "autre : %s" % mnemonique


def main():
    plafond = int(sys.argv[1]) if len(sys.argv) > 1 else 50
    connues = tailles()

    greffees = []
    for source in sorted(glob.glob(os.path.join(RACINE, "src", "game", "*.cpp"))):
        unite = os.path.basename(source)[:-4]
        for ligne in open(source, encoding="utf-8"):
            match = INCLUDE.search(ligne)
            if not match:
                continue
            secteur, nom = match.group(1), match.group(2).strip()
            if nom in connues and connues[nom][1] <= plafond:
                greffees.append((connues[nom][1], unite, secteur, nom))
    greffees.sort()

    print("fonctions de `jeu` encore greffées, jusqu'à %d octets : %d"
          % (plafond, len(greffees)))
    par_taille = collections.Counter(t for t, _, _, _ in greffees)
    print("par taille : " + " ".join("%do:%d" % (t, n) for t, n in sorted(par_taille.items())))

    # Les formes ne se lisent que sur les corps d'une seule instruction.
    formes = collections.Counter()
    detail = collections.defaultdict(list)
    for taille, unite, secteur, nom in greffees:
        if taille != 8:
            continue
        f = forme(instructions(secteur, nom))
        formes[f] += 1
        detail[f].append((unite, nom))

    print("\nles %d fonctions de huit octets, par forme :" % par_taille.get(8, 0))
    for f, n in formes.most_common():
        print("  %-30s %3d" % (f, n))

    print("\ndétail des lots uniformes :")
    for f, _ in formes.most_common():
        if f.startswith(("corps de", "autre", "désassemblage")):
            continue
        print("\n  %s" % f)
        for unite, nom in sorted(detail[f]):
            print("      %-26s %s" % (unite, nom))
    return 0


if __name__ == "__main__":
    sys.exit(main())
