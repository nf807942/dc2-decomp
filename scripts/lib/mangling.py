"""Lit un nom manglé Metrowerks et rend la signature qu'il porte.

    Close__8CGamePadFv       → CGamePad::Close(void)
    SetPos__5CFontFii        → CFont::SetPos(s32, s32)
    _MENU_END__FP9SPI_STACKi → _MENU_END(SPI_STACK *, s32)

Le mangling range la classe *après* la fonction, entre le nom et le `F` qui
ouvre les arguments ; c'est donc lui, et non le début du symbole, qui dit la
provenance. Ce qu'il ne porte pas, il ne le rend pas : le type de retour n'est
pas manglé, et c'est le corps de la fonction qui le tranche.

Rendre `None` est une réponse : un symbole que ce module ne comprend pas reste
greffé plutôt que d'être reconstruit sur une signature devinée.
"""

from __future__ import annotations

import re
from dataclasses import dataclass, field

# Les types de base, dans les noms du projet : `types.h` donne `s32` là où le
# mangling dit `i`. Un paramètre déclaré `int` et un paramètre déclaré `s32`
# rendent les mêmes octets, mais pas les mêmes conventions de source.
BASE = {
    "v": "void", "c": "char", "s": "s16", "i": "s32", "l": "s32",
    "f": "f32", "d": "f64", "b": "bool", "x": "s64",
    "Uc": "u8", "Us": "u16", "Ui": "u32", "Ul": "u32", "Ux": "u64",
    "Sc": "s8",
}

# Un nom d'opérateur manglé : hors de notre lot, mais reconnu pour l'écarter
# proprement plutôt que de le lire comme un nom de fonction ordinaire.
SPECIAL = {"__ct": "constructeur", "__dt": "destructeur"}


@dataclass
class Symbol:
    """Ce qu'un nom manglé dit, et rien de plus."""

    mangled: str
    name: str                       # le nom écrit dans la source
    cls: str | None                 # la classe, quand c'en est une méthode
    params: list[str] = field(default_factory=list)
    const: bool = False
    kind: str = "fonction"          # fonction, méthode, constructeur, destructeur

    @property
    def named_types(self) -> list[str]:
        """Les types nommés que la signature emploie, déclaration en avant."""
        found = []
        for param in self.params:
            match = re.match(r"^(\w+)\s*\*?$", param)
            if match and match.group(1) not in BASE.values():
                found.append(match.group(1))
        return found

    def declaration(self, ret: str, this: str = "") -> str:
        """La ligne de définition, sans le corps."""
        args = ", ".join(self.params) if self.params else "void"
        scope = f"{self.cls}::" if self.cls and not this else ""
        return f"{ret} {scope}{self.name}({args})"


def _read_type(text: str, index: int) -> tuple[str | None, int]:
    """Lit un type à partir de `index`. Rend (type, index suivant)."""
    if index >= len(text):
        return None, index

    prefix = ""
    # `PC6CScene` : le `C` qualifie ce qui suit, le `P` ce qui en résulte.
    stars = 0
    while index < len(text) and text[index] in "PRCUS":
        char = text[index]
        if char == "P":
            stars += 1
            index += 1
        elif char == "R":
            stars += 1          # une référence s'écrit autrement, voir plus bas
            prefix = "&" + prefix
            index += 1
        elif char == "C":
            index += 1
            prefix = "const " + prefix
        elif char in "US":
            # `Uc`, `Ui` … : le signe fait partie du type de base.
            if index + 1 < len(text) and text[index:index + 2] in BASE:
                break
            index += 1
        else:
            break

    if index >= len(text):
        return None, index

    # Un type de base, sur une ou deux lettres.
    for width in (2, 1):
        token = text[index:index + width]
        if token in BASE:
            base = BASE[token]
            index += width
            break
    else:
        # Un type nommé : sa longueur le précède.
        match = re.match(r"(\d+)", text[index:])
        if not match:
            return None, index
        size = int(match.group(1))
        start = index + len(match.group(1))
        base = text[start:start + size]
        if len(base) != size:
            return None, index
        index = start + size

    is_reference = "&" in prefix
    prefix = prefix.replace("&", "")
    rendered = (prefix + base).strip()
    if stars:
        rendered += " " + ("*" * (stars - 1 if is_reference else stars))
        if is_reference:
            rendered += "&"
        rendered = rendered.replace(" &", " &").rstrip()
    return rendered.strip(), index


def _read_params(text: str) -> list[str] | None:
    """Lit la suite des arguments. `v` seul vaut « aucun »."""
    if text == "v":
        return []
    params: list[str] = []
    index = 0
    while index < len(text):
        # `Tn` reprend le n-ième argument déjà lu ; `Nkn` le reprend k fois.
        if text[index] == "T" and index + 1 < len(text) and text[index + 1].isdigit():
            rank = int(text[index + 1])
            if not 1 <= rank <= len(params):
                return None
            params.append(params[rank - 1])
            index += 2
            continue
        if text[index] == "e":          # ellipse
            params.append("...")
            index += 1
            continue
        kind, index_after = _read_type(text, index)
        if kind is None or index_after == index:
            return None
        params.append(kind)
        index = index_after
    return params or None


def demangle(mangled: str) -> Symbol | None:
    """Rend la signature d'un symbole, ou `None` si elle n'est pas sûre.

    Le nom et la queue se séparent sur un `__`, mais lequel ? Un nom peut en
    porter — `__ALPHA__FP9SPI_STACKi` s'appelle `__ALPHA`, et `_MENU_END__F…`
    en cache un au milieu. Le découpage juste est celui dont la queue s'analyse,
    et il n'y a qu'à les essayer : couper au premier `__` laissait 219 symboles
    illisibles sur les 7 840 du binaire.
    """
    # Le désambiguïsateur du désassemblage ajoute l'adresse en suffixe ; elle ne
    # fait pas partie du mangling, mais le nom qu'elle porte est celui à écrire.
    stem = re.sub(r"_00[0-9A-F]{6}$", "", mangled)

    for coupe in (index for index in range(len(stem) - 1)
                  if stem[index:index + 2] == "__"):
        lu = _lire(mangled, stem[:coupe], stem[coupe + 2:])
        if lu is not None:
            return lu
    return None


def _lire(mangled: str, name: str, tail: str) -> Symbol | None:
    """Lit un découpage nom/queue donné, ou rend `None` s'il ne tient pas."""
    if not name:
        return None

    kind = SPECIAL.get(name, "fonction")

    # La classe, quand il y en a une, tient entre le nom et le `F`.
    cls = None
    const = False
    if tail.startswith("F"):
        body = tail[1:]
    else:
        match = re.match(r"(\d+)", tail)
        if not match:
            return None
        size = int(match.group(1))
        start = len(match.group(1))
        cls = tail[start:start + size]
        if len(cls) != size:
            return None
        rest = tail[start + size:]
        if rest.startswith("CF"):
            const, rest = True, rest[1:]
        if not rest.startswith("F"):
            return None
        body = rest[1:]
        kind = SPECIAL.get(name, "méthode")

    params = _read_params(body)
    if params is None and body != "v":
        return None

    return Symbol(mangled=mangled, name=name, cls=cls,
                  params=params or [], const=const, kind=kind)
