#!/usr/bin/env python3
"""Applique aux outils tiers les correctifs que le projet porte.

    make patch                       les pose, ou constate qu'ils y sont
    make patch PATCH_ARGS=--update   les réécrit depuis l'état du sous-module

Les sous-modules sont pris tels que leur dépôt les publie, et un commit n'en
retient que la référence : ce qu'on y change n'est pas versionné. Ce qui se
versionne est le correctif, sous `tools/patches/`, et c'est lui que cette
commande applique.

L'application est idempotente : un correctif déjà en place est reconnu comme
tel, non réappliqué. Ce qui reste à corriger dans un outil tiers est du travail
à reverser en amont, et le correctif dit alors ce qui a été proposé — c'est le
texte qu'il porte avant son premier `diff --git`, que `--update` conserve.
"""

from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT  # noqa: E402

PATCH_DIR = ROOT / "tools" / "patches"

# Un correctif porte des fins de ligne LF, et l'arbre du sous-module celles que
# l'hôte lui a données : `git apply` refuse le mélange. La conversion se demande
# par `core.autocrlf`, mais l'imposer casserait le cas inverse — on essaie donc
# les deux formes, sans supposer sur quel système on tourne.
DIALECTS = ([], ["-c", "core.autocrlf=true"])


def git_apply(repository: Path, patch: Path, *flags: str) -> bool:
    """Applique le correctif dans le dialecte qui l'accepte.

    Rien n'est écrit tant qu'une des deux formes ne passe pas la vérification :
    un correctif à moitié appliqué serait pire que refusé.
    """
    for dialect in DIALECTS:
        command = ["git", *dialect, "apply", *flags]
        if subprocess.run(command + ["--check", str(patch)], cwd=repository,
                          capture_output=True).returncode:
            continue
        if "--check" in flags:
            return True
        result = subprocess.run(command + [str(patch)], cwd=repository,
                                capture_output=True, text=True)
        if result.returncode == 0:
            return True
        sys.stderr.write(result.stderr)
    return False


def rewrite(repository: Path, patch: Path) -> bool:
    """Réécrit le correctif depuis ce que le sous-module porte aujourd'hui.

    Les octets passent tels quels : un correctif dont les fins de ligne ont été
    traduites est refusé par `git apply`.

    Le dialecte compte ici autant qu'à l'application : sans conversion, un arbre
    en CRLF fait paraître modifié chaque fichier du sous-module, et le correctif
    grossit de trois mille lignes sans qu'un mot le signale. Les deux versions
    passent la vérification à l'envers — un tel correctif reste applicable —, donc
    ce n'est pas elle qui départage : on garde celle qui touche le moins de
    fichiers, l'autre en ayant ajouté par confusion.
    """
    rationale = patch.read_bytes().split(b"diff --git", 1)[0]
    candidates = [subprocess.run(["git", *dialect, "diff"], cwd=repository,
                                 capture_output=True).stdout
                  for dialect in DIALECTS]
    for diff in sorted(candidates, key=lambda d: d.count(b"\ndiff --git ")):
        if not diff:
            continue
        patch.write_bytes(rationale + diff)
        if git_apply(repository, patch, "--check", "--reverse"):
            return True
    return False


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--update", action="store_true",
                       help="réécrit les correctifs depuis les sous-modules")
    args = parser.parse_args()

    if not PATCH_DIR.is_dir():
        print("aucun correctif à appliquer")
        return 0

    failed = 0
    for patch in sorted(PATCH_DIR.glob("*.patch")):
        # Le nom porte le sous-module visé : `mwccgap-…patch` va sur
        # `tools/mwccgap`.
        target = ROOT / "tools" / patch.name.split("-", 1)[0]
        if not target.is_dir():
            print(f"{patch.name} : {target.name} absent — "
                  f"lancez `git submodule update --init`", file=sys.stderr)
            failed += 1
            continue

        if args.update:
            if rewrite(target, patch):
                print(f"{patch.name} : réécrit depuis {target.name}")
            else:
                print(f"{patch.name} : aucun dialecte n'en rend un correctif "
                      f"applicable", file=sys.stderr)
                failed += 1
            continue

        if git_apply(target, patch, "--check", "--reverse"):
            print(f"{patch.name} : déjà en place")
            continue

        if not git_apply(target, patch):
            print(f"{patch.name} : refusé — l'outil a changé en amont",
                  file=sys.stderr)
            failed += 1
            continue
        print(f"{patch.name} : appliqué")

    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
