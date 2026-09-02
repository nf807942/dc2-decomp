#!/usr/bin/env python3
"""Cherche par essais la forme de C++ qui rend les octets du commerce.

    make permute S=UpDate__8CGamePadFv N=400

La fonction visée doit être encadrée dans sa source :

    /* @@UpDate__8CGamePadFv */
    void CGamePad::UpDate() { … }
    /* @@fin */

Ce qui reste quand la taille et la logique sont déjà justes ne se corrige pas
en raisonnant : c'est une allocation de registres, et elle dépend de détails de
forme que rien ne laisse prévoir — l'ordre des déclarations, la présence d'un
temporaire, le sens d'une comparaison. Les essayer un par un à la main coûte
une conversation entière par fonction.

decomp-permuter fait ce travail ailleurs, mais il analyse du C par pycparser et
ne lit pas nos sources C++. Cet outil s'en passe : il transforme le texte, sans
prétendre en préserver le sens. C'est légitime ici parce que le verdict n'est
pas la lecture du C mais l'appariement des octets — une forme qui rend 100 % est
identique au commerce instruction par instruction, quoi qu'on ait écrit pour
l'obtenir. Ce que l'outil propose se relit avant d'être gardé.
"""

from __future__ import annotations

import argparse
import itertools
import json
import random
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from lib.project import ROOT, find_symbol, run  # noqa: E402
from idiomes import IDIOMES  # noqa: E402

# Une déclaration simple en tête de bloc : « int i; », « PAD_REPEAT *rep; ».
DECL = re.compile(r"^(\s*)((?:[A-Za-z_]\w*\s+)+\*?\w+(?:\[[^\]]*\])?);\s*$")
# La même, mais initialisée : « PAD_REPEAT *rep = &m_repeat[0]; ».
DECL_INIT = re.compile(r"^\s*(?:[A-Za-z_]\w*\s+)+\*?\w+(?:\[[^\]]*\])?\s*=\s*[^;]+;\s*$")


# --------------------------------------------------------------------------
# Les transformations
#
# Chacune rend la liste des variantes qu'elle sait tirer d'un texte. Aucune ne
# garantit le sens ; le score s'en charge.
# --------------------------------------------------------------------------

def reorder_declarations(text: str, rng: random.Random) -> list[str]:
    """Permute les déclarations en tête d'une fonction.

    C'est la transformation qui paie le plus : MWCC attribue ses registres dans
    l'ordre où les variables lui viennent, et deux formes qui n'en diffèrent que
    par là rendent des sorties dont seuls les noms de registres changent.
    """
    lines = text.split("\n")
    # Le bloc de déclarations commence après la première accolade ouvrante.
    try:
        start = next(i for i, l in enumerate(lines) if l.rstrip().endswith("{")) + 1
    except StopIteration:
        return []

    # Chaque déclaration emporte les commentaires qui la précèdent : les séparer
    # les rattacherait à la voisine, et la source deviendrait fausse à lire.
    groups: list[list[str]] = []
    pending: list[str] = []
    end = start
    while end < len(lines):
        line = lines[end]
        if DECL.match(line) or DECL_INIT.match(line):
            groups.append(pending + [line])
            pending = []
        elif not line.strip() or line.lstrip().startswith(("/*", "*", "//")):
            pending.append(line)
        else:
            break
        end += 1
    if len(groups) < 2:
        return []
    tail = pending  # ce qui suit la dernière déclaration reste en place

    out = []
    # Toutes les permutations quand elles sont peu nombreuses, un échantillon
    # sinon : au-delà de cinq déclarations, l'énumération explose.
    orders = (list(itertools.permutations(groups)) if len(groups) <= 5
              else [tuple(rng.sample(groups, len(groups))) for _ in range(40)])
    for order in orders:
        if list(order) == groups:
            continue
        rebuilt = [l for group in order for l in group]
        out.append("\n".join(lines[:start] + rebuilt + tail + lines[end:]))
    return out


def rewrite_comparisons(text: str, _rng: random.Random) -> list[str]:
    """`>= K` devient `> K-1`, et ainsi de suite.

    MWCC n'écrit pas la même chose selon le sens : `> 1000` lui fait poser son
    résultat dans `$at`, `>= 1001` lui fait allouer un registre.
    """
    out = []
    for match in re.finditer(r"([<>])(=?)\s*(-?\d+)\b", text):
        sign, equal, value = match.group(1), match.group(2), int(match.group(3))
        if equal:
            shifted = value - 1 if sign == ">" else value + 1
            replacement = f"{sign} {shifted}"
        else:
            shifted = value + 1 if sign == ">" else value - 1
            replacement = f"{sign}= {shifted}"
        out.append(text[:match.start()] + replacement + text[match.end():])
    return out


def split_initialisers(text: str, _rng: random.Random) -> list[str]:
    """`int x = e;` devient `int x;` puis `x = e;`, et l'inverse."""
    out = []
    for match in re.finditer(r"^(\s*)([A-Za-z_]\w*(?:\s+\*?|\s*\*\s*))(\w+)\s*=\s*([^;]+);",
                             text, re.M):
        indent, kind, name, value = match.groups()
        split = f"{indent}{kind}{name};\n{indent}{name} = {value};"
        out.append(text[:match.start()] + split + text[match.end():])
    return out


def assignment_into_condition(text: str, _rng: random.Random) -> list[str]:
    """`x = e;` suivi d'un test sur `x` rentre dans le test.

    Le commerce garde alors la valeur dans son registre au lieu de relire ce
    qu'il vient d'écrire.
    """
    out = []
    pattern = re.compile(
        r"^(\s*)([\w\[\]\.\->\*\(\)]+)\s*=\s*([^;\n]+);\n\s*if\s*\((\2)\s*(!=|==)\s*([^)]+)\)",
        re.M)
    for match in pattern.finditer(text):
        indent, target, value, _again, op, right = match.groups()
        joined = f"{indent}if (({target} = {value}) {op} {right})"
        out.append(text[:match.start()] + joined + text[match.end():])
    return out


def initialiser_into_condition(text: str, _rng: random.Random) -> list[str]:
    """`v = 0;` avant un `if` rentre dans sa condition par l'opérateur virgule.

    C'est ce qui comble un créneau de délai vide : la valeur est alors tenue
    pour disponible avant le branchement.
    """
    out = []
    pattern = re.compile(r"^(\s*)(\w+)\s*=\s*([^;\n]+);\n(\s*)if\s*\(([^\n]+)\)\s*\{", re.M)
    for match in pattern.finditer(text):
        indent, name, value, indent2, condition = match.groups()
        joined = f"{indent2}if (({name} = {value}, {condition})) {{"
        out.append(text[:match.start()] + joined + text[match.end():])
    return out


def equivalent_operators(text: str, _rng: random.Random) -> list[str]:
    """Les écritures qui disent la même chose : `*= 2` et `<<= 1`, `++` et `+= 1`."""
    swaps = [
        (r"(\w+)\s*\*=\s*2\b", r"\1 <<= 1"),
        (r"(\w+)\s*<<=\s*1\b", r"\1 *= 2"),
        (r"([\w\[\]\.>-]+)\+\+;", r"\1 += 1;"),
        (r"([\w\[\]\.>-]+)\s*\+=\s*1;", r"\1++;"),
        (r"([\w\[\]\.>-]+)\s*-=\s*1;", r"\1--;"),
    ]
    out = []
    for pattern, replacement in swaps:
        for match in re.finditer(pattern, text):
            out.append(text[:match.start()]
                       + re.sub(pattern, replacement, match.group(0))
                       + text[match.end():])
    return out


def commute_operands(text: str, _rng: random.Random) -> list[str]:
    """`a & b` devient `b & a` — l'ordre décide de quel registre porte quoi."""
    out = []
    for match in re.finditer(r"\(([\w\.\[\]>-]+) (&|\||\+|==|!=) ([\w\.\[\]>-]+)\)", text):
        left, operator, right = match.groups()
        out.append(text[:match.start()] + f"({right} {operator} {left})"
                   + text[match.end():])
    return out


def swap_statements(text: str, rng: random.Random) -> list[str]:
    """Échange deux affectations voisines de même indentation.

    L'ordre d'évaluation décide de la durée de vie des valeurs, donc des
    registres. Rien ne dit que l'échange préserve le sens ; le score le dira.
    """
    lines = text.split("\n")
    simple = [i for i, l in enumerate(lines)
              if re.match(r"^\s+[\w\[\]\.>-]+ [-+|&^]?= [^;]+;$", l)]
    pairs = [(a, b) for a, b in zip(simple, simple[1:])
             if b == a + 1 and len(lines[a]) - len(lines[a].lstrip())
             == len(lines[b]) - len(lines[b].lstrip())]
    rng.shuffle(pairs)
    out = []
    for a, b in pairs[:16]:
        copy = list(lines)
        copy[a], copy[b] = copy[b], copy[a]
        out.append("\n".join(copy))
    return out


def statement_into_for(text: str, _rng: random.Random) -> list[str]:
    """La dernière instruction d'une boucle passe dans sa clause d'incrément.

    Ce n'est pas la même chose pour l'ordonnanceur : ce qui vit dans la clause
    est calculé après le corps, et se loge donc dans le créneau de délai du
    branchement de fin.
    """
    out = []
    for header in re.finditer(r"^([ \t]*)for \(([^;]*);([^;]*);([^)]*)\) \{$",
                              text, re.M):
        indent, init, test, step = header.groups()
        body_start = header.end() + 1
        body_end = matching_brace(text, header.end() - 1)
        if body_end is None:
            continue
        body = text[body_start:body_end]
        # La dernière instruction du corps, et elle seule : celles des blocs
        # imbriqués ne se déplacent pas.
        last = re.search(r"\n([ \t]*)([\w\[\]\.>-]+ *[-+*|&^<>]*= [^;\n]+);\n[ \t]*$",
                         body)
        if not last or last.group(1) != indent + "    ":
            continue
        moved = (f"{indent}for ({init};{test};{step}, {last.group(2)}) {{\n"
                 f"{body[:last.start()]}\n{indent}}}")
        out.append(text[:header.start()] + moved + text[body_end + 1:])

    # Et l'inverse : ce que la clause porte redescend en fin de corps.
    for header in re.finditer(r"^([ \t]*)for \(([^;]*);([^;]*);([^),]*), ([^)]*)\) \{$",
                              text, re.M):
        indent, init, test, step, extra = header.groups()
        body_end = matching_brace(text, header.end() - 1)
        if body_end is None:
            continue
        body = text[header.end() + 1:body_end]
        moved = (f"{indent}for ({init};{test};{step}) {{\n{body}"
                 f"{indent}    {extra};\n{indent}}}")
        out.append(text[:header.start()] + moved + text[body_end + 1:])
    return out


def matching_brace(text: str, opening: int) -> int | None:
    """L'index de l'accolade qui ferme celle donnée."""
    depth = 0
    for i in range(opening, len(text)):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return i
    return None


def initialiser_into_for(text: str, _rng: random.Random) -> list[str]:
    """Une affectation qui précède une boucle passe dans sa clause d'entrée."""
    out = []
    pattern = re.compile(r"^(\s*)(\w+) = ([^;\n]+);\n\s*for \(([^;]*);", re.M)
    for match in pattern.finditer(text):
        indent, name, value, init = match.groups()
        joined = f"{indent}for ({init}, {name} = {value};"
        out.append(text[:match.start()] + joined + text[match.end():])
    return out


def temporary_for_expression(text: str, _rng: random.Random) -> list[str]:
    """Lie une sous-expression à une variable neuve, juste avant son emploi.

    C'est le mouvement central d'un permuteur : un temporaire allonge une durée
    de vie et déplace toute l'attribution des registres en aval. L'inverse —
    replier un temporaire dans son unique emploi — est rendu par
    `inline_temporary`.
    """
    out = []
    # Des sous-expressions que l'on sait relire : un accès indexé, un champ, une
    # opération binaire entre parenthèses. Rien qui appelle ni qui affecte.
    pieces = re.compile(r"(?<![\w>\].])"
                        r"((?:\*?\w+(?:\.\w+|->\w+|\[[\w+\- ]+\])+)"
                        r"|\(\w+ [-+*&|^] \w+\))")
    for line in re.finditer(r"^([ \t]+)(?![}{]|for |while |else|/\*|\*)([^\n]*;)$",
                            text, re.M):
        indent, statement = line.groups()
        if statement.lstrip().startswith(("return", "int ", "u8 ", "s8 ")):
            continue
        for piece in pieces.finditer(statement):
            expression = piece.group(1)
            if expression in ("", statement.split(" =")[0].strip()):
                continue
            name = "temp"
            if re.search(rf"\b{name}\b", text):
                continue
            replaced = statement[:piece.start(1)] + name + statement[piece.end(1):]
            hoisted = f"{indent}int {name} = {expression};\n{indent}{replaced}"
            out.append(text[:line.start()] + hoisted + text[line.end():])
    return out


def inline_temporary(text: str, _rng: random.Random) -> list[str]:
    """Replie une variable posée puis employée une seule fois juste après."""
    out = []
    pattern = re.compile(r"^([ \t]+)(?:[A-Za-z_]\w*\s+\*?)?(\w+) = ([^;\n]+);\n"
                         r"([ \t]+[^\n]*\n)", re.M)
    for match in pattern.finditer(text):
        indent, name, value, following = match.groups()
        if len(re.findall(rf"\b{re.escape(name)}\b", following)) != 1:
            continue
        folded = indent + following.strip().replace(name, f"({value})", 1) + "\n"
        out.append(text[:match.start()] + folded + text[match.end():])
    return out


def nest_conditions(text: str, _rng: random.Random) -> list[str]:
    """`if (A && B)` devient deux `if` emboîtés, et inversement.

    Les deux formes ne donnent pas le même enchaînement de branchements, donc
    pas les mêmes créneaux de délai.
    """
    out = []
    for header in re.finditer(r"^([ \t]*)if \(([^\n]+) && ([^\n]+)\) \{$", text, re.M):
        indent, left, right = header.groups()
        closing = matching_brace(text, header.end() - 1)
        if closing is None:
            continue
        body = text[header.end() + 1:closing]
        inner = "\n".join(("    " + l if l.strip() else l) for l in body.split("\n"))
        nested = (f"{indent}if ({left}) {{\n{indent}    if ({right}) {{\n"
                  f"{inner}{indent}    }}\n{indent}}}")
        out.append(text[:header.start()] + nested + text[closing + 1:])
    return out


def return_through_temporary(text: str, _rng: random.Random) -> list[str]:
    """`return E;` devient `resultat = E; return resultat;`."""
    out = []
    for match in re.finditer(r"^([ \t]+)return ([^;\n]{3,});$", text, re.M):
        indent, expression = match.groups()
        if "result" in text:
            continue
        replaced = f"{indent}int result = {expression};\n{indent}return result;"
        out.append(text[:match.start()] + replaced + text[match.end():])
    return out


def call_out_of_condition(text: str, _rng: random.Random) -> list[str]:
    """Sort un appel de sa condition et le pose dans une variable.

    L'ordonnanceur ne dispose pas des mêmes instructions de part et d'autre du
    branchement selon que l'appel y est ou non : c'est ce qui décide du contenu
    de son créneau de délai.
    """
    out = []
    for match in re.finditer(
            r"^([ \t]+)if \((\w+\([^()]*(?:\([^()]*\)[^()]*)*\))\s*(==|!=|<|>|<=|>=)"
            r"\s*([^)\n]+)\) \{$", text, re.M):
        indent, call, operator, right = match.groups()
        if "answer" in text:
            continue
        hoisted = (f"{indent}int answer = {call};\n"
                   f"{indent}if (answer {operator} {right}) {{")
        out.append(text[:match.start()] + hoisted + text[match.end():])
    return out


def hoisted_declaration(expression: str, name: str) -> str | None:
    """La déclaration qui tient `expression` dans une variable neuve.

    Le type ne se devine pas d'une expression quelconque ; il se lit du
    transtypage qu'elle porte déjà, faute de quoi on s'en tient aux entiers.
    Rendre `void *` ne va pas : le C++ refuse d'en revenir à un pointeur typé
    sans transtypage, et la variante ne compile pas — elle est alors mesurée
    à -1 et le permuteur la rejette sans qu'on sache pourquoi.
    """
    cast = re.match(r"\(\s*([A-Za-z_]\w*(?:\s*\*)+)\s*\)\s*(.+)$", expression)
    if cast:
        return f"{cast.group(1).replace(' ', '')} {name} = {expression};"
    if re.fullmatch(r"[&*]?[\w.>\[\]-]+", expression):
        return f"int {name} = {expression};"
    return None


def temporary_for_argument(text: str, _rng: random.Random) -> list[str]:
    """Pose un argument d'appel dans une variable avant l'appel.

    Un argument déjà calculé n'occupe plus le même registre au moment de
    l'appel, et l'ordonnanceur range le reste autrement.

    L'appel se cherche sur toute la ligne, non en tête d'instruction : une
    condition de boucle en porte tout autant, et c'est là que l'ordre des
    registres d'argument se décide le plus souvent.
    """
    out = []
    for line in re.finditer(r"^([ \t]*)([^\n]*\w\([^\n]*\)[^\n]*)$", text, re.M):
        indent, statement = line.groups()
        if "held" in text or statement.lstrip().startswith(("for ", "/*", "*")):
            continue
        for call in re.finditer(r"(\w+)\(([^()]*(?:\([^()]*\)[^()]*)*)\)",
                                statement):
            pieces = [a.strip() for a in call.group(2).split(",")]
            if len(pieces) < 2:
                continue
            for index, piece in enumerate(pieces):
                if re.fullmatch(r"-?[\d.]+f?", piece) or not piece:
                    continue
                declaration = hoisted_declaration(piece, "held")
                if declaration is None:
                    continue
                replaced = list(pieces)
                replaced[index] = "held"
                rebuilt = (statement[:call.start(2)] + ", ".join(replaced)
                           + statement[call.end(2):])
                # Une ligne qui ferme un bloc porte la déclaration à
                # l'intérieur : hors du corps, la valeur ne serait plus celle
                # du tour courant.
                inner = indent + "    " if statement.startswith("}") else indent
                out.append(text[:line.start()]
                           + f"{inner}{declaration}\n{indent}{statement}"
                           + text[line.end():])
    return out


def split_top_level(expression: str, operator: str) -> list[str]:
    """Découpe une expression sur un opérateur logique, hors parenthèses."""
    parts, depth, start, i = [], 0, 0, 0
    while i < len(expression):
        char = expression[i]
        if char == "(":
            depth += 1
        elif char == ")":
            depth -= 1
        elif depth == 0 and expression.startswith(operator, i):
            parts.append(expression[start:i].strip())
            i += len(operator)
            start = i
            continue
        i += 1
    parts.append(expression[start:].strip())
    return [p for p in parts if p]


def condition_into_body(text: str, _rng: random.Random) -> list[str]:
    """La condition d'un `do … while` passe dans le corps, un terme par `if`.

    C'est ce qui manquait le plus au catalogue : aucune autre transformation
    n'entre dans une condition de boucle. `while (A || B || C)` y était un bloc
    opaque, et les appels qu'elle porte — leurs arguments, leur ordre —
    échappaient à tout le reste. Éclatée en `for (;;) { if (A) continue; …
    break; }`, elle redevient une suite d'instructions que le catalogue entier
    peut reprendre.
    """
    out = []
    # La condition d'une boucle tient souvent sur plusieurs lignes : s'arrêter
    # au saut ne l'aurait jamais vue, et c'est justement quand elle porte assez
    # de termes pour déborder qu'il vaut la peine de l'éclater.
    pattern = re.compile(r"^([ \t]+)do \{\n"
                         r"((?:[ \t]*[^{}\n]*\n)*?)"
                         r"[ \t]*\} while \((.*?)\);$", re.M | re.S)
    for match in pattern.finditer(text):
        indent, body, condition = match.groups()
        terms = split_top_level(" ".join(condition.split()), "||")
        if len(terms) < 2:
            continue
        inner = indent + "    "
        tests = "".join(f"{inner}if ({term}) {{\n{inner}    continue;\n"
                        f"{inner}}}\n" for term in terms)
        rebuilt = (f"{indent}for (;;) {{\n{body}{tests}"
                   f"{inner}break;\n{indent}}}")
        out.append(text[:match.start()] + rebuilt + text[match.end():])
    return out


def conditions(text: str) -> list[tuple[int, int]]:
    """Les bornes de chaque condition de `if` ou de `while`.

    Une expression régulière ne sait pas s'arrêter à la bonne parenthèse : la
    première rencontrée ferme un appel, non la condition. Le comptage est le
    seul moyen d'atteindre les conditions qui portent des appels, et ce sont
    celles-là qui décident de l'ordre des registres d'argument.
    """
    found = []
    for opening in re.finditer(r"\b(?:if|while)\s*\(", text):
        depth, i = 1, opening.end()
        while i < len(text) and depth:
            depth += (text[i] == "(") - (text[i] == ")")
            i += 1
        if depth == 0:
            found.append((opening.end(), i - 1))
    return found


def reorder_disjuncts(text: str, _rng: random.Random) -> list[str]:
    """Échange deux termes voisins d'une chaîne de `||` ou de `&&`.

    L'ordre des termes décide de celui des appels, donc des registres vivants
    à chaque branchement. Le court-circuit en change le sens ; c'est la
    construction qui tranche, comme toujours.
    """
    out = []
    for start, stop in conditions(text):
        condition = " ".join(text[start:stop].split())
        for operator in ("||", "&&"):
            terms = split_top_level(condition, operator)
            if len(terms) < 2:
                continue
            for i in range(len(terms) - 1):
                swapped = list(terms)
                swapped[i], swapped[i + 1] = swapped[i + 1], swapped[i]
                rebuilt = f" {operator} ".join(swapped)
                out.append(text[:start] + rebuilt + text[stop:])
    return out


def reorder_arguments(text: str, rng: random.Random) -> list[str]:
    """Réordonne les arguments d'un appel.

    L'ordre dans lequel les arguments sont évalués décide de quel registre
    porte quoi à l'entrée de l'appel : deux ordres ne donnent pas les mêmes
    chargements, même pour les mêmes valeurs. Sur un site qui n'a plus qu'un
    créneau de délai à combler, c'est le dernier degré de liberté.
    """
    keywords = {"for", "while", "if", "switch", "sizeof", "do", "return",
                "case", "new", "delete", "catch"}
    out = []
    for call in re.finditer(r"(?<![A-Za-z0-9_])(\w+)\(([^()\n]*)\)", text):
        name, arguments = call.group(1), call.group(2).strip()
        if name in keywords or not arguments:
            continue
        pieces = [a.strip() for a in arguments.split(",")]
        if len(pieces) < 2 or len(pieces) > 5:
            continue
        orders = (list(itertools.permutations(range(len(pieces))))
                  if len(pieces) <= 4
                  else [tuple(rng.sample(range(len(pieces)), len(pieces)))
                        for _ in range(24)])
        for order in orders:
            if order == tuple(range(len(pieces))):
                continue
            reordered = ", ".join(pieces[i] for i in order)
            rebuilt = f"{name}({reordered})"
            out.append(text[:call.start()] + rebuilt + text[call.end():])
    return out


def for_to_while(text: str, _rng: random.Random) -> list[str]:
    """`for (init; test; step)` devient `init; while (test) { … step; }`.

    Le test passe en tête et l'incrément en fin de corps : MWCC ne déroule
    plus de la même façon, et la boucle change d'allure d'un mot près.
    """
    out = []
    for header in re.finditer(r"^([ \t]*)for \(([^;]*);([^;]*);([^)]*)\) \{$",
                              text, re.M):
        indent, init, test, step = header.groups()
        body_end = matching_brace(text, header.end() - 1)
        if body_end is None:
            continue
        body = text[header.end() + 1:body_end]
        rebuilt = ""
        if init.strip():
            rebuilt += f"{indent}{init.strip()};\n"
        rebuilt += f"{indent}while ({test.strip() or '1'}) {{\n{body}"
        if step.strip():
            rebuilt += f"{indent}    {step.strip()};\n"
        rebuilt += f"{indent}}}"
        out.append(text[:header.start()] + rebuilt + text[body_end + 1:])
    return out


def while_to_for(text: str, _rng: random.Random) -> list[str]:
    """L'inverse de `for_to_while` : l'initiale rejoint la clause d'entrée, et
    la dernière instruction du corps la clause d'incrément."""
    out = []
    pattern = re.compile(
        r"^([ \t]*)([A-Za-z_][\w\[\]]* = [^;\n]+);\n"
        r"([ \t]*)while \(([^\n]+)\) \{$", re.M)
    for match in pattern.finditer(text):
        indent, init, windent, test = match.groups()
        body_end = matching_brace(text, match.end() - 1)
        if body_end is None:
            continue
        body = text[match.end() + 1:body_end]
        step = ""
        last = re.search(r"\n([ \t]+)([\w\[\]\.>-]+)"
                         r"(\s*(?:\+\+|--) *| *[-+*|&^<>]*= [^;\n]+);\n[ \t]*$",
                         body)
        if last and last.group(1) == windent + "    ":
            step = " " + last.group(2) + last.group(3)
            body = body[:last.start()] + "\n"
        rebuilt = f"{indent}for ({init}; {test.strip()};{step}) {{\n{body}{indent}}}"
        out.append(text[:match.start()] + rebuilt + text[body_end + 1:])
    return out


def while_to_do_while(text: str, _rng: random.Random) -> list[str]:
    """`while (t) { … }` devient `if (t) { do { … } while (t); }`.

    Le test se présente alors deux fois, une pour entrer et une pour boucler :
    MWCC garde une branche de plus, et le créneau de délai change de camp.
    """
    out = []
    for header in re.finditer(r"^([ \t]*)while \(([^\n]+)\) \{$", text, re.M):
        indent, test = header.groups()
        body_end = matching_brace(text, header.end() - 1)
        if body_end is None:
            continue
        body = text[header.end() + 1:body_end]
        inner = "\n".join(("    " + line if line.strip() else line)
                          for line in body.split("\n"))
        rebuilt = (f"{indent}if ({test.strip()}) {{\n"
                   f"{indent}    do {{\n{inner}"
                   f"{indent}    }} while ({test.strip()});\n{indent}}}")
        out.append(text[:header.start()] + rebuilt + text[body_end + 1:])
    return out


def unwrap_do_while(text: str, _rng: random.Random) -> list[str]:
    """`if (t) { do { … } while (t); }` redevient `while (t) { … }`."""
    out = []
    pattern = re.compile(r"^([ \t]*)if \(([^\n]+)\) \{\n([ \t]*)do \{", re.M)
    for match in pattern.finditer(text):
        indent, test, dindent = match.groups()
        do_end = matching_brace(text, match.end() - 1)
        if do_end is None:
            continue
        body = text[match.end() + 1:do_end]
        tail = text[do_end + 1:]
        m = re.match(r"[ \t]*while \(([^\n]+)\);\n[ \t]*\}", tail)
        if not m:
            continue
        body = "\n".join(line[4:] if line.startswith(dindent + "    ")
                         else line for line in body.split("\n"))
        rebuilt = f"{indent}while ({m.group(1).strip()}) {{\n{body}{indent}}}"
        out.append(text[:match.start()] + rebuilt + text[do_end + 1 + m.end():])
    return out


def shift_vs_multiply(text: str, _rng: random.Random) -> list[str]:
    """`x << n` devient `x * 2^n`, et inversement — le choix change le registre."""
    out = []
    for m in re.finditer(r"(\w+) << (\d+)", text):
        name, shift = m.group(1), int(m.group(2))
        out.append(text[:m.start()] + f"{name} * {1 << shift}" + text[m.end():])
    for m in re.finditer(r"(\w+) \* (\d+)", text):
        name, value = m.group(1), int(m.group(2))
        if value and (value & (value - 1)) == 0:
            out.append(text[:m.start()] + f"{name} << {value.bit_length() - 1}"
                       + text[m.end():])
    return out


def invert_if_else(text: str, _rng: random.Random) -> list[str]:
    """`if (A) { X } else { Y }` devient `if (!A) { Y } else { X }`.

    L'inversion échange la branche chaude et la branche froide, et MWCC pose
    alors le test de l'autre côté du branchement.
    """
    out = []
    for header in re.finditer(r"^([ \t]*)if \(([^\n]+)\) \{$", text, re.M):
        indent, condition = header.groups()
        if_end = matching_brace(text, header.end() - 1)
        if if_end is None:
            continue
        tail = text[if_end + 1:]
        m = re.match(r"[ \t]*else \{", tail)
        if not m:
            continue
        else_end = matching_brace(text, if_end + 1 + m.end() - 1)
        if else_end is None:
            continue
        if_body = text[header.end() + 1:if_end]
        else_body = text[if_end + 1 + m.end() + 1:else_end]
        rebuilt = (f"{indent}if (!({condition.strip()})) {{\n{else_body}"
                   f"{indent}}} else {{\n{if_body}{indent}}}")
        out.append(text[:header.start()] + rebuilt + text[else_end + 1:])
    return out


def split_expression_assignment(text: str, _rng: random.Random) -> list[str]:
    """`x = A op B;` devient deux affectations, l'opérateur appliqué en dernier.

    MWCC rend `xori` quand le complément arrive sur une valeur déjà posée, et
    `li; xor` quand toute l'expression tient dans une seule affectation : c'est
    la scission qui décide laquelle. C'est elle qui a porté `pad_button_read`
    de 96,52 % à 100 %.
    """
    out = []
    for line in re.finditer(r"^([ \t]+)(\w+) = ([^;\n]+);$", text, re.M):
        indent, name, rhs = line.groups()
        for op_index in top_level_operators(rhs):
            left = rhs[:op_index].strip()
            right = rhs[op_index + 1:].strip()
            if left == name or re.search(rf"\b{re.escape(name)}\b", right):
                continue
            operator = rhs[op_index]
            out.append(text[:line.start()]
                       + f"{indent}{name} = {left};\n{indent}{name} = {name} {operator} {right};"
                       + text[line.end():])
            out.append(text[:line.start()]
                       + f"{indent}{name} = {right};\n{indent}{name} = {left} {operator} {name};"
                       + text[line.end():])
    return out


def top_level_operators(expression: str) -> list[int]:
    """Positions des opérateurs binaires de `expression` hors parenthèses."""
    depth = 0
    positions = []
    for i, ch in enumerate(expression):
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
        elif (depth == 0 and ch in "+-*/&|^" and i > 0 and i + 1 < len(expression)
              and expression[i - 1] == " " and expression[i + 1] == " "):
            positions.append(i)
    return positions


def move_after_block(text: str, _rng: random.Random) -> list[str]:
    """Une affectation qui précède un bloc se place après le bloc.

    Le commerce ne pose la valeur qu'à l'endroit où elle sert — le chargement
    du registre accompagne l'appel —, pas avant un test qui ne la consomme
    pas. C'est ce qui a porté `pad_button_read` de 91,96 % à 96,52 %.
    """
    out = []
    pattern = re.compile(
        r"^(\s*)(\w+) = ([^;\n]+);\n(\s*)(if|while|for) \(([^\n]+)\) \{$", re.M)
    for match in pattern.finditer(text):
        indent, name, value, indent2, keyword, condition = match.groups()
        closing = matching_brace(text, match.end() - 1)
        if closing is None:
            continue
        body = text[match.end() + 1:closing].rstrip(" \n")
        rebuilt = (f"{indent2}{keyword} ({condition.strip()}) {{\n{body}"
                   f"\n{indent2}}}\n{indent}{name} = {value.strip()};")
        out.append(text[:match.start()] + rebuilt + text[closing + 1:])
    return out


def materialize_parameter(text: str, _rng: random.Random) -> list[str]:
    """`x -= N;` devient `int x_ = x - N;`, les emplois suivants de `x`
    reprenant la locale.

    Le commerce re-matérialise la valeur dans un registre de travail au lieu
    de retoucher la case du paramètre, et le prologue en change. C'est la
    première moitié du passage d'`AxisCalibration` à 100 %.
    """
    out = []
    pattern = re.compile(r"^(\s*)(\w+) -= (-?\d+);\s*$", re.M)
    for match in pattern.finditer(text):
        indent, name, value = match.groups()
        local = f"{name}_course"
        if re.search(rf"\b{local}\b", text):
            continue
        renamed = re.sub(rf"\b{re.escape(name)}\b", local, text[match.end():])
        replaced = f"{indent}int {local} = {name} - {int(value)};"
        out.append(text[:match.start()] + replaced + renamed)
    return out


def move_into_branch(text: str, _rng: random.Random) -> list[str]:
    """Une affectation qui précède un `if` entre dans le corps du `if`.

    Le commerce ne calcule une valeur que dans la branche qui la consomme :
    l'ordonnanceur n'a pas à la tenir pendant le test. La valeur doit rester
    libre entre l'affectation et la condition. C'est la seconde moitié du
    passage d'`AxisCalibration` à 100 %.
    """
    out = []
    pattern = re.compile(
        r"^([ \t]+)(\w+) = ([^;\n]+);\n"
        r"((?:[ \t]+(?:\w+) = [^;\n]+;\n)*)"
        r"[ \t]*if \(([^\n]+)\) \{$", re.M)
    for match in pattern.finditer(text):
        indent, name, value, middle, condition = match.groups()
        if re.search(rf"\b{re.escape(name)}\b", middle):
            continue
        closing = matching_brace(text, match.end() - 1)
        if closing is None:
            continue
        body = text[match.end():closing]
        if not re.search(rf"\b{re.escape(name)}\b", body):
            continue
        inner = re.match(r"\n([ \t]*)", body)
        inner_indent = inner.group(1) if inner else indent + "    "
        rebuilt = (text[:match.start()]
                   + middle
                   + f"{indent}if ({condition.strip()}) {{\n"
                   + f"{inner_indent}{name} = {value.strip()};"
                   + body.rstrip(" \n") + f"\n{indent}}}")
        out.append(text[:match.start()] + rebuilt + text[closing + 1:])
    return out


def compare_zero_rewrite(text: str, _rng: random.Random) -> list[str]:
    """`x = (x == 0);` devient `x = !x;`, et les tests inverses.

    MWCC rend `xor; sltiu` pour la première forme et `sltu; xori; andi` pour
    la seconde : deux suites d'instructions qui ne se confondent pas. C'est ce
    qui a porté `UpDate` de 99,09 % à 99,78 %.
    """
    out = []
    swaps = [
        (r"(\w+) = \((\w+) == 0\);", r"\1 = !\2;"),
        (r"(\w+) = \((\w+) != 0\);", r"\1 = !!\2;"),
        (r"(\w+) = !\((\w+)\);", r"\1 = (\2 == 0);"),
        (r"if \((\w+) == 0\)", r"if (!\1)"),
        (r"if \((\w+) != 0\)", r"if (\1)"),
        (r"if \(!(\w+)\)", r"if (\1 == 0)"),
    ]
    for pattern, replacement in swaps:
        for match in re.finditer(pattern, text):
            rebuilt = text[:match.start()] + re.sub(
                pattern, replacement, match.group(0)) + text[match.end():]
            if rebuilt != text:
                out.append(rebuilt)
    return out


# Les transformations tirees d'idiomes mesures passent en tete : chacune vient
# d'une forme dont on a mesure qu'elle change les octets, sur une fonction
# nommee. Une transformation aveugle qui paie ne dit rien ; celles-la si.
TRANSFORMS = [
    *IDIOMES,
    reorder_declarations,
    statement_into_for,
    initialiser_into_for,
    for_to_while,
    while_to_for,
    while_to_do_while,
    unwrap_do_while,
    call_out_of_condition,
    temporary_for_argument,
    reorder_arguments,
    temporary_for_expression,
    inline_temporary,
    nest_conditions,
    invert_if_else,
    return_through_temporary,
    shift_vs_multiply,
    rewrite_comparisons,
    split_initialisers,
    assignment_into_condition,
    initialiser_into_condition,
    equivalent_operators,
    commute_operands,
    swap_statements,
    split_expression_assignment,
    move_after_block,
    materialize_parameter,
    move_into_branch,
    compare_zero_rewrite,
    condition_into_body,
    reorder_disjuncts,
]


# --------------------------------------------------------------------------
# La mesure
# --------------------------------------------------------------------------

class Scorer:
    """Compile la source et rend l'appariement de la fonction visée."""

    def __init__(self, symbol: str):
        self.symbol = symbol
        self.location = find_symbol(symbol)
        if self.location.source_file is None:
            raise SystemExit(f"{symbol} : aucune source ne le définit")
        self.source = self.location.source_file
        self.target = self.location.target_object
        self.base = self.location.base_object
        # La référence ne change pas d'un essai à l'autre.
        run(["make", str(self.target.relative_to(ROOT))], stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL)

    def score(self) -> float:
        built = run(["make", str(self.base.relative_to(ROOT))],
                    stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        if built.returncode != 0:
            return -1.0
        result = run(["objdiff-cli", "diff", "-1", str(self.target),
                      "-2", str(self.base), "-o", "-", "--format", "json",
                      self.symbol], capture_output=True, text=True)
        if result.returncode != 0:
            return -1.0
        try:
            payload = json.loads(result.stdout)
        except json.JSONDecodeError:
            return -1.0
        for entry in payload.get("left", {}).get("symbols", []):
            if entry.get("name") == self.symbol:
                return float(entry.get("match_percent", 0.0))
        return -1.0


# --------------------------------------------------------------------------

def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("symbol")
    parser.add_argument("-n", "--rounds", type=int, default=200,
                        help="nombre d'essais (défaut : 200)")
    parser.add_argument("--seed", type=int, default=1)
    args = parser.parse_args()

    scorer = Scorer(args.symbol)
    whole = scorer.source.read_text(encoding="utf-8")
    marks = re.compile(r"/\* @@" + re.escape(args.symbol) + r" \*/\n(.*?)/\* @@fin \*/",
                       re.DOTALL)
    found = marks.search(whole)
    if not found:
        raise SystemExit(
            f"{scorer.source.relative_to(ROOT)} n'encadre pas {args.symbol}.\n"
            f"Entourez la fonction de /* @@{args.symbol} */ et /* @@fin */.")

    def install(body: str) -> None:
        scorer.source.write_text(
            whole[:found.start(1)] + body + whole[found.end(1):], encoding="utf-8")

    rng = random.Random(args.seed)
    current = found.group(1)
    best, best_score = current, scorer.score()
    print(f"départ {best_score:.2f} %", flush=True)

    seen = {current}
    round_number = 0

    def measure(candidate: str) -> float:
        nonlocal round_number
        seen.add(candidate)
        round_number += 1
        install(candidate)
        return scorer.score()

    exhausted = False
    try:
        # Chaque tour mesure au moins une forme, ou s'arrête. Sans cette garantie
        # la recherche tourne à vide dès que l'espace est épuisé : les tirages ne
        # rendent plus que du déjà-vu, le compteur n'avance pas, et la condition
        # d'arrêt n'est jamais atteinte.
        while round_number < args.rounds and best_score < 100.0:
            # D'abord toutes les variantes à un coup : l'espace est petit et les
            # parcourir vaut mieux que d'y tirer au sort. La descente ne prend le
            # hasard qu'une fois ce voisinage épuisé sans gain.
            neighbourhood = []
            for transform in TRANSFORMS:
                neighbourhood.extend(o for o in transform(current, rng) if o not in seen)
            rng.shuffle(neighbourhood)

            improved = False
            for candidate in neighbourhood:
                if round_number >= args.rounds or best_score >= 100.0:
                    break
                score = measure(candidate)
                if score > best_score:
                    best, best_score, current = candidate, score, candidate
                    print(f"  essai {round_number:>4}  {score:6.2f} %  ← retenu",
                          flush=True)
                    improved = True
                    break
                if round_number % 25 == 0:
                    print(f"  essai {round_number:>4}  {best_score:6.2f} %"
                          f"  ({len(seen)} formes vues)", flush=True)
            if improved:
                continue

            # Un sommet local se quitte en composant plusieurs transformations.
            # Le tirage n'est pas une mesure : il se répète jusqu'à sortir une
            # forme neuve, et son échec signe l'épuisement de l'espace.
            fresh = None
            for _ in range(400):
                candidate = current
                for _ in range(rng.choice([2, 2, 3])):
                    options = rng.choice(TRANSFORMS)(candidate, rng)
                    if options:
                        candidate = rng.choice(options)
                if candidate not in seen:
                    fresh = candidate
                    break
            if fresh is None:
                exhausted = True
                break

            score = measure(fresh)
            if score > best_score:
                best, best_score, current = fresh, score, fresh
                print(f"  essai {round_number:>4}  {score:6.2f} %  ← retenu", flush=True)
            else:
                # Un palier se traverse en gardant une forme équivalente ; au-delà
                # on repart du meilleur connu.
                current = fresh if score >= best_score - 1.0 else best
    except KeyboardInterrupt:
        print("\ninterrompu", flush=True)
    finally:
        install(best)

    if exhausted:
        print(f"\nespace épuisé : {len(seen)} formes essayées, aucune meilleure.")
    print(f"\n{args.symbol} : {best_score:.2f} % après {round_number} essais")
    if best != found.group(1):
        print(f"{scorer.source.relative_to(ROOT)} porte la meilleure forme ; relisez-la.")
    return 0 if best_score >= 100.0 else 1


if __name__ == "__main__":
    sys.exit(main())
