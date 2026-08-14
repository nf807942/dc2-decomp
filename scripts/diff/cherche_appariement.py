"""Cherche dans tout le désassemblage le motif que nous produisons.

Nous émettons deux `lui` accolés, puis les deux `mtc1` qui les consomment :

    lui  v1, c1
    lui  a0, c2
    mtc1 v1, $f12
    mtc1 a0, $f13

Si le commerce ne le porte nulle part, notre appariement est systématiquement
faux et sa cause est globale ; s'il le porte, le contexte de ces sites-là dit ce
qui l'autorise.
"""

import collections
import glob
import os
import re
import sys

RACINE = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
LIGNE = re.compile(r"^\s*/\*\s+\w+\s+([0-9A-F]{8})\s+\w{8}\s+\*/\s+(\S+)\s*(.*?)\s*$")
REG = re.compile(r"\$(\w+)")


def instructions(chemin):
    suite = []
    for ligne in open(chemin, encoding="utf-8", errors="replace"):
        m = LIGNE.match(ligne)
        if m:
            suite.append((int(m.group(1), 16), m.group(2), m.group(3)))
    return suite


def main():
    fichiers = glob.glob(os.path.join(RACINE, "ref", "asm", "text", "**", "*.s"),
                         recursive=True)
    accoles = []      # deux `lui` accolés, tous deux consommés par des mtc1
    total_lui = 0

    for chemin in fichiers:
        suite = instructions(chemin)
        for i in range(len(suite) - 6):
            a, m1, arg1 = suite[i]
            _, m2, arg2 = suite[i + 1]
            if m1 != "lui" or m2 != "lui":
                continue
            r1 = REG.findall(arg1)
            r2 = REG.findall(arg2)
            if not r1 or not r2 or r1[0] == r2[0]:
                continue
            # Les deux `lui` doivent porter des constantes flottantes, non des
            # adresses : un `%hi(...)` ne se compare pas à un immédiat.
            if "%hi" in arg1 or "%hi" in arg2:
                continue
            total_lui += 1
            # Cherchons les `mtc1` qui les consomment dans les six suivantes.
            fenetre = suite[i + 2:i + 8]
            consomme = {}
            for _, m, arg in fenetre:
                if m != "mtc1":
                    continue
                regs = REG.findall(arg)
                if len(regs) == 2 and regs[1].startswith("f1"):
                    consomme[regs[0]] = regs[1]
            if r1[0] in consomme and r2[0] in consomme:
                cible = next((suite[j] for j in range(i + 2, min(i + 10, len(suite)))
                              if suite[j][1] == "jal"), None)
                accoles.append((a, r1[0], r2[0], consomme[r1[0]],
                                consomme[r2[0]], cible[2] if cible else "?"))

    print(f"{len(fichiers)} unités")
    print(f"paires de `lui` accolés sur registres distincts, hors adresses : {total_lui}")
    print(f"dont les deux sont consommés par un `mtc1` d'argument : {len(accoles)}\n")

    if not accoles:
        print("Le commerce ne porte nulle part le motif que nous produisons.")
        return 0

    par_cible = collections.Counter(c[5] for c in accoles)
    print(f"{len(par_cible)} fonctions appelées distinctes\n")

    # Quels registres le commerce emploie-t-il pour apparier ?
    paires = collections.Counter(tuple(sorted((c[1], c[2]))) for c in accoles)
    print("couples de registres employés :")
    for (ra, rb), n in paires.most_common():
        print(f"  {ra:4s} + {rb:4s} : {n:3d} sites")

    avec_argument = [c for c in accoles
                     if c[1].startswith("a") or c[2].startswith("a")]
    print(f"\nsites appariant avec un registre d'argument ($a0..$a3) : "
          f"{len(avec_argument)}")
    for adresse, ra, rb, fa, fb, appele in avec_argument[:15]:
        print(f"  {adresse:08X}  {ra}->{fa}  {rb}->{fb}   {appele[:52]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
