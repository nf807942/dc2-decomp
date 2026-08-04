# dc2decomp

Décompilation *matching* de **Dark Chronicle** (*Dark Cloud 2*), version PAL
`SCES-51190`, en C++ — dans la méthode que [decomp.wiki][wiki] décrit et que
les projets de [decomp.dev][dev] pratiquent.

Le but n'est pas d'écrire un programme qui ressemble au jeu : c'est d'écrire
le C++ qui, recompilé par le compilateur d'époque, rend **les octets du
disque**. Le verdict est binaire et se mesure à chaque construction.

Projet parallèle à [darkchronicles](../darkchronicles), qui recompile le même
jeu statiquement en Rust. Les deux partagent leur objet et rien d'autre : là
où la recompilation traduit des instructions sans jamais retrouver
d'intention, la décompilation reconstruit une source dont la preuve est le
binaire lui-même.

## État

| | |
|---|---|
| Construction identique au disque | **oui** — 2 608 512 octets, sha1 `eca0c93d5d6a25fcbf8f1fa41aa811a6f4b7aca8` |
| Code reconstruit en C++ | 52 octets sur 2 209 044 — 1 fonction sur 7 792 |
| Compilateur | `mwcps2-3.0.1-020123`, `-O4,p` — 100 % sur la première fonction |
| Découpage | 193 unités de texte, 92 de données, 6 blocs vectoriels, 1 unité ouverte |

La construction part du désassemblage entier et le réassemble ; chaque fonction
passée en C++ en remplace une part, et la construction doit rester identique.
`CGamePad::Close` est la première, appariée instruction pour instruction.

## Prérequis

* Docker ou Podman — toute la chaîne y vit, rien ne s'installe sur l'hôte.
* Le disque PAL de Dark Chronicle, posé dans `rom/`. Rien d'autre ne le
  fournit, et rien de ce qui en dérive n'entre dans ce dépôt.
* Le compilateur Metrowerks CodeWarrior for PlayStation 2 — voir plus bas.

## Démarrage

```sh
git clone --recurse-submodules <ce dépôt> && cd darkcloud2
cp "Dark Chronicle (Europe).iso" rom/

scripts/host/dc2 make tools    # installe le compilateur Metrowerks
scripts/host/dc2 make setup    # extrait le disque, écrit la config, désassemble
scripts/host/dc2 make build    # assemble, lie, compare au disque
```

La première invocation construit l'image ; les suivantes sont incrémentales.
L'arbre est monté dans le conteneur, jamais copié.

## Travailler sur une fonction

```sh
scripts/host/dc2 make decompile S=Close__8CGamePadFv   # premier jet de C++
scripts/host/dc2 make diff      S=Close__8CGamePadFv   # verdict contre le commerce
```

Les symboles s'écrivent manglés, comme le binaire les porte —
`Close__8CGamePadFv` est `CGamePad::Close(void)`. `config/elf_symbol_addrs.txt`
les liste tous.

`make diff` affiche les deux suites d'instructions côte à côte et le taux
d'appariement qu'objdiff calcule ; `100 %` veut dire que la fonction est
reconstruite.

### Ouvrir une unité

Une unité de travail se déclare dans `config/units.txt` — début, fin, nom :

```
0x0014A650 0x0014B500 gamepad
```

`make setup` en fait alors un sous-segment confié à `src/gamepad.cpp`, écrit le
désassemblage de la plage **par fonction** sous `asm/nonmatchings/gamepad/`, et
fait attendre au script de lien l'objet compilé à la place de l'assemblé.

Les frontières des 49 unités d'origine ne sont pas dans le binaire — deux objets
y portent 91 % du code —, donc elles se décident : une plage se délimite par ce
que les symboles montrent, une classe et les fonctions libres qui
l'accompagnent. Le binaire reste identique tant que l'ordre des fonctions est
conservé, ce que `make build` vérifie à chaque fois.

Le reste de l'unité n'a pas à attendre : `INCLUDE_ASM` garde une fonction sous
sa forme d'origine à l'intérieur d'une source par ailleurs compilée.

```cpp
#include "common.h"

INCLUDE_ASM("nonmatchings/gamepad", UpDate__8CGamePadFv);  // pas encore reconstruite

void CGamePad::Close() {                              // celle-ci l'est
    scePadPortClose(0, 0);
    scePadPortClose(1, 0);
    scePadEnd();
}
```

MWCC émet le texte d'une unité d'un seul bloc et n'accepte d'assembleur
qu'entièrement défini : une fonction non reconstruite ne peut donc pas venir
d'un objet voisin. [mwccgap][mwccgap] la remplace par autant de `nop`, assemble
le `.s` de référence à part, puis greffe le résultat en réparant les
relocations. C'est ce qui rend le remplacement fonction par fonction possible.

Les fonctions sont données dans l'ordre des adresses : c'est celui que
l'éditeur de liens attend.

### Deux désassemblages, et pourquoi

`ref/asm/` porte le binaire entier en assembleur, `asm/` seulement ce qui reste
à faire. La raison est que le désassembleur cesse d'extraire une fonction dès
qu'une source la définit : sans cette copie complète, une fonction reconstruite
perdrait l'original contre lequel on la mesure. `ref/` est donc la cible
d'objdiff, et `make reference` l'assemble.

[mwccgap]: https://github.com/mkst/mwccgap

## Voir l'avancement

```sh
scripts/host/dc2 make report    # puis ouvrir progress/index.html
```

La même vue que [decomp.dev][dev] — carte du code proportionnelle aux octets,
avancement par secteur, recherche par fonction — dans une page autonome de
450 Kio qu'on ouvre depuis le disque. Aucun dépôt public, aucun service tiers,
aucune requête sortante. La mesure vient d'`objdiff-cli report`, qui compare
l'objet compilé à l'objet de référence fonction par fonction ; la page n'en
change pas les chiffres, elle les rend lisibles.

La carte se lit à deux échelles. **Par fonction** est celle qui sert : le
binaire s'y répartit vraiment, et c'est l'unité de travail. **Par unité**
montre pourquoi — deux objets portent 91 % du code, parce que les frontières
des 49 unités de traduction du jeu ne sont pas encore retrouvées.

`make progress` donne le même chiffre en une ligne, sans passer par objdiff.

### Pourquoi une page à nous plutôt que decomp.dev

decomp.dev [s'auto-héberge][ddsrc] — Rust, npm, SQLite, sur `localhost:3000` —,
mais c'est un **bot GitHub** avant d'être un site : un projet y est désigné par
l'identifiant numérique de son dépôt GitHub, les rapports sont lus dans les
**artefacts de GitHub Actions**, et aucune route n'accepte qu'on lui en remette
un. Un dépôt git local n'a pas d'identifiant GitHub.

Ce n'est pas le disque qui manquerait : un rapport objdiff compare des objets,
donc le désassemblage et les sources y suffisent. [DCDecomp][dc1] produit ainsi
le sien en intégration continue — au prix de versionner son désassemblage et
son compilateur, ce que ce dépôt ne fait pas. La même voie nous demanderait de
publier soit le désassemblage entier, soit le seul `report.json`, qui ne porte
que des noms de fonctions et des tailles. Le choix reste ouvert ; en attendant,
la page locale ne demande rien.

### L'interface objdiff, pour le travail à la fonction

`make objdiff` écrit `objdiff.json`, que lit l'[application objdiff][objdiff] —
la même que tous les projets decomp emploient. Installée sur l'hôte, elle liste
les unités et leur avancement, affiche le diff instruction par instruction, et
reconstruit à chaque sauvegarde. C'est l'outil d'itération ; la page est la vue
d'ensemble.

## Le compilateur

`make tools` l'installe depuis [`decompme/compilers`][compilers], le dépôt qui
alimente decomp.me : ces paquets portent le gestionnaire de licence qui laisse
`mwccps2.exe` démarrer, là où l'installateur d'origine réclame une licence
FLEXlm et refuse de compiler sans elle.

Le binaire porte `MW MIPS C Compiler (2.4.1.01)`, mais cette chaîne est écrite
par **MWLD** et plusieurs versions l'écrivent à l'identique. La mesure a
tranché : sur `CGamePad::Close`, les trois versions 3.0.x rendent **100 %** avec
`-O4,p`, la 2.4 seulement 77 %, et tout autre niveau d'optimisation tombe sous
50 %. La 2.4 y sauve `$ra` par `sq` là où le binaire emploie `sd`, et met à zéro
par `paddub` au lieu de `daddu`.

`make tools TOOLS_ARGS=--all` installe les quatre candidates ;
`MWCC_VERSION=mwcps2-3.0.3-020716 make …` en choisit une autre.

[compilers]: https://github.com/decompme/compilers

## Ce que le binaire donne, et qui change tout

`SCES_511.90` n'est pas strippé. Là où un projet de décompilation ordinaire
devine ses frontières, celui-ci les lit :

* **17 298 symboles**, dont 7 837 fonctions et 8 201 objets, avec adresse et
  taille exactes ;
* **316 symboles de section** — un par contribution d'objet, dont 192 pour
  `.text` : ce sont les frontières de fichiers, données plutôt que cherchées ;
* **99 876 relocations**, qui disent quel mot est une adresse ;
* les **49 unités de traduction** du jeu, nommées par leurs initialiseurs
  statiques `__sinit_*.cpp`.

## Structure

```
config/    découpage et tables de symboles (engendrés, sauf symbol_addrs.txt)
asm/       désassemblage de référence — engendré, jamais versionné
src/       le C++ reconstruit — c'est le dépôt
include/   en-têtes reconstruits
scripts/   setup, construction, comparaison
tools/     compilateur, m2c, decomp-permuter
rom/       le disque et ce qu'on en extrait — jamais versionné
```

## Ce qui n'entre pas dans git

Rien de dérivé du jeu : ni image disque, ni exécutable, ni désassemblage, ni
tables tirées du binaire. Tout cela se régénère par `make setup` depuis le
disque de chacun. Le `.gitignore` et `.githooks/pre-commit` l'appliquent ;
installez le hook par `git config core.hooksPath .githooks`.

## Références

* [Decompedia][wiki] — la méthode, les compilateurs, les plateformes
* [DCDecomp][dc1] — Dark Cloud 1, même éditeur, même compilateur, projet mûr
* [splat][splat], [spimdisasm][spim], [objdiff][objdiff], [m2c][m2c]

[wiki]: https://decomp.wiki/
[ddsrc]: https://github.com/encounter/decomp.dev
[dev]: https://decomp.dev/
[dc1]: https://github.com/Adubbz/DCDecomp
[splat]: https://github.com/ethteck/splat
[spim]: https://github.com/Decompollaborate/spimdisasm
[objdiff]: https://github.com/encounter/objdiff
[m2c]: https://github.com/matt-kempster/m2c
