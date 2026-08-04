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
| Code reconstruit en C++ | 0 sur 2 215 100 octets (7 837 fonctions) |
| Découpage | 192 unités de texte, 92 de données, 6 blocs vectoriels |

La construction part aujourd'hui du désassemblage entier et le réassemble.
C'est l'état de départ voulu : à partir de là, chaque unité de traduction
passée en C++ doit laisser la construction identique.

## Prérequis

* Docker ou Podman — toute la chaîne y vit, rien ne s'installe sur l'hôte.
* Le disque PAL de Dark Chronicle, posé dans `rom/`. Rien d'autre ne le
  fournit, et rien de ce qui en dérive n'entre dans ce dépôt.
* Le compilateur Metrowerks CodeWarrior for PlayStation 2 — voir plus bas.

## Démarrage

```sh
git clone --recurse-submodules <ce dépôt> && cd darkcloud2
cp "Dark Chronicle (Europe).iso" rom/

scripts/host/dc2 make setup    # extrait le disque, écrit la config, désassemble
scripts/host/dc2 make build    # assemble, lie, compare au disque
```

La première invocation construit l'image ; les suivantes sont incrémentales.
L'arbre est monté dans le conteneur, jamais copié.

## Travailler sur une fonction

```sh
scripts/host/dc2 make decompile S=Close__8CGamePadFv   # premier jet de C++
scripts/host/dc2 make diff      S=Close__8CGamePadFv   # verdict contre le commerce
scripts/host/dc2 make progress                          # part reconstruite
```

Les symboles s'écrivent manglés, comme le binaire les porte —
`Close__8CGamePadFv` est `CGamePad::Close(void)`. `config/elf_symbol_addrs.txt`
les liste tous.

## Le compilateur

Le binaire porte `MW MIPS C Compiler (2.4.1.01)`. Cette chaîne vient de
**MWLD**, pas du compilateur : deux versions de CodeWarrior — R3.01 et R3.04 —
l'écrivent à l'identique alors que leurs `mwccps2.exe` diffèrent (1 413 120 et
1 638 400 octets). Laquelle a servi reste à établir en faisant compiler
quelques fonctions connues.

Les deux sont installées sous `tools/compilers/mw/{3.01,3.04}/`, hors git.
Elles réclament une licence FLEXlm que l'archive d'origine accompagne d'un
`license.dat` ; posez-le à côté des exécutables et le compilateur démarre :

```sh
cp <archive>/crack/license.dat  tools/compilers/mw/3.01/
cp <archive>/crack/lmgr326b.dll tools/compilers/mw/3.01/
```

Sans lui, `mwccps2.exe` refuse de compiler — « License check failed ». Tout le
reste du projet fonctionne : le désassemblage, la construction identique au
disque et `make decompile` n'en dépendent pas.

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
[dev]: https://decomp.dev/
[dc1]: https://github.com/Adubbz/DCDecomp
[splat]: https://github.com/ethteck/splat
[spim]: https://github.com/Decompollaborate/spimdisasm
[objdiff]: https://github.com/encounter/objdiff
[m2c]: https://github.com/matt-kempster/m2c
