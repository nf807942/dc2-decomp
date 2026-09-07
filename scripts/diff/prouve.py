#!/usr/bin/env python3
"""La réparation qui emploie les faits prouvés du binaire, et non des essais.

`remplissage` corrige une disposition **à l'aveugle** : elle essaie chaque
bourrage de la structure et laisse le banc trancher. Cela marche, et cela a
rendu trois fonctions, mais cela ne sait rien.

Ici on sait. `make champs` a relevé, pour 268 classes, le décalage et la largeur
de 4 444 champs, en suivant `this` depuis le registre que le mangling type ; et
`make tailles` a lu la taille de 42 classes à l'argument d'`operator new`. Les
deux relevés concordent sur les quarante classes où ils se rencontrent, sans un
conflit.

**Ce module repose donc la structure forgée par construction.** m2c nomme ses
champs par leur décalage — `unk678` est à `0x678` — mais il calcule ses
remplissages sans aligner, si bien que le champ tombe ailleurs. On refait le
remplissage pour que chaque `unkNNN` tombe exactement à `0xNNN`, en prenant la
largeur au relevé quand il l'a, au type que m2c a écrit sinon.

C'est le premier emploi de l'axe B dans la recherche, et sa mesure dira si les
faits prouvés valent ce qu'ils ont coûté.
"""

from __future__ import annotations

import json
import re
from pathlib import Path

RACINE = Path(__file__).resolve().parents[2]
CHAMPS = RACINE / "progress" / "champs.json"

# m2c écrit **deux** formes de structure, et n'en reconnaître qu'une laissait
# passer la plus fréquente : `typedef struct X { … } X;` et `struct X { … };`.
# Sur les deux cents premiers fragments du corpus, la première ne couvrait que
# quatre cas. C'est le piège que ce dépôt connaît — un motif qui lit m2c se
# vérifie sur sa sortie, jamais sur l'idée qu'on s'en fait.
_STRUCT = re.compile(
    r"^(typedef struct (\w+) \{\n(?:.*?)^\} \2;[^\n]*|"
    r"struct (\w+) \{\n(?:.*?)^\};)$", re.MULTILINE | re.DOTALL)
# `    /* 0x678 */ TYPE unk678;` — un champ que m2c nomme par son décalage.
_CHAMP = re.compile(
    r"^[ \t]*(?:/\*[^*]*\*/\s*)?([A-Za-z_][\w ]*\**)\s+(unk([0-9A-Fa-f]+))\s*;"
    r"[ \t]*$", re.MULTILINE)

_LARGEUR = {"u8": 1, "s8": 1, "char": 1, "s16": 2, "u16": 2, "s32": 4,
            "u32": 4, "f32": 4, "s64": 8, "u64": 8, "u128": 16}

_RELEVE = None


def releve() -> dict[str, dict[int, int]]:
    """Les largeurs prouvées, par classe et par décalage. Lues une fois."""
    global _RELEVE
    if _RELEVE is None:
        brut: dict[str, dict[int, int]] = {}
        if CHAMPS.exists():
            for classe, fiche in json.loads(
                    CHAMPS.read_text(encoding="utf-8")).items():
                brut[classe] = {int(cle, 16): champ["largeur"]
                                for cle, champ in fiche["champs"].items()}
        _RELEVE = brut
    return _RELEVE


def _classe_du_tag(tag: str) -> str:
    """`CActionChara_infere2_890643` -> `CActionChara`."""
    return tag.split("_infere")[0].split("_champs")[0]


def disposition_prouvee(fragment: str, ecarts: list[str]) -> list[str]:
    """Repose chaque structure forgée sur les décalages que ses noms annoncent.

    Une seule forme est rendue par structure : il n'y a rien à essayer, la
    disposition est calculée. C'est ce qui la distingue de `remplissage`.
    """
    connus = releve()
    formes = []
    for trouve in _STRUCT.finditer(fragment):
        bloc = trouve.group(1)
        tag = trouve.group(2) or trouve.group(3)
        champs = list(_CHAMP.finditer(bloc))
        if not tag or not champs:
            continue
        typedef = bloc.startswith("typedef")
        largeurs = connus.get(_classe_du_tag(tag), {})
        lignes, position, bon = [], 0, True
        for champ in champs:
            type_c = champ.group(1).strip()
            nom, decalage = champ.group(2), int(champ.group(3), 16)
            if decalage < position:
                bon = False        # deux champs se chevauchent : on renonce
                break
            large = largeurs.get(decalage) or _LARGEUR.get(type_c, 4)
            if decalage > position:
                lignes.append("    char pad_%X[0x%X];"
                              % (position, decalage - position))
            lignes.append("    /* 0x%X */ %s %s;" % (decalage, type_c, nom))
            position = decalage + large
        if not bon or not lignes:
            continue
        neuf = ("typedef struct %s {\n%s\n} %s;" % (tag, "\n".join(lignes), tag)
                if typedef
                else "struct %s {\n%s\n};" % (tag, "\n".join(lignes)))
        forme = fragment[:trouve.start()] + neuf + fragment[trouve.end():]
        if forme != fragment:
            formes.append(forme)
    return formes
