# La voie GCC : écrire le SDK Sony et la bibliothèque C

Établie le 1er octobre 2026. Elle complète `docs/METHODE_AGENTS.md` (qui décrit les
fournées d'agents) pour les 1 082 fonctions — 221 Ko, 10 % des octets — que MWCC n'a pas
compilées : le SDK Sony et la bibliothèque C du jeu.

## Ce qui est établi

- **Ces fonctions viennent de GCC, pas de MWCC.** Elles sont absentes de `.mwcats`, le
  binaire porte des marqueurs `gcc2_compiled.`, et leurs cadres de pile sauvent les registres
  par `sd`, comme `ee-gcc` 2.9-ee le fait (les 2.95.x de SN Systems et la 2.96 sauvent par
  `sq` : 74–79 % sur `floor`).
- **La version** : `ee-gcc2.9-991111-01`, `-O2 -G0`. Les quatre builds 2.9-ee sont proches ;
  `copysignf` (un `mfc1` suivi de son `nop` de délai) sépare le `-01` de la 990721 et de la
  991111, qui ajoutent un `nop` de trop.
- **La bibliothèque C et la libm sont newlib 1.9.0**, sources publiques. Mesuré sur la
  source inchangée : `copysign`, `copysignf`, `finite`, `isnan`, `__kernel_cosf` à 100 %,
  `floor` 99,75 %, et les **six fonctions de `findfp.c`** (`std`, `__sfmoreglue`, `__sfp`,
  `_cleanup_r`, `_cleanup`, `__sinit`) à 100 % — l'unité `runtime/sfp` est écrite, et la
  construction reste identique au disque.
- **Tout n'est pas du C.** Le `strlen` du jeu est de l'assembleur MMI écrit à la main
  (`lq`, `psubb`, `pnor`, `pcpyud`) ; le `strlen` de newlib en rend 58 % sous toutes les
  versions. Une fonction qui porte des instructions MMI ou COP2 reste en assembleur de
  référence, sauf si une mesure dit le contraire. Le dossier le signale.
- **Le SDK Sony n'a pas de source publique.** `ps2sdk` (réimplémentation) donne les
  prototypes et les structures, pas les octets. Ces fonctions s'écrivent comme celles du jeu :
  d'après le désassemblage, en C.

## Comment une unité passe par GCC

`config/gcc_units.txt` liste les unités compilées par `ee-gcc`. `soumettre` y ajoute une
unité de `src/sdk/` ou `src/runtime/` le temps de la mesure, et l'y laisse si la fonction
est gardée. Les autres unités de ces dossiers qui contiennent déjà du code MWCC ne passent
pas en GCC sans `--sdk` : le changer modifierait ce qui est déjà écrit.

La compilation est `scripts/build/ee_gcc_cc`, qui se fait passer pour MWCC auprès de
`mwccgap` (même greffe, mêmes `INCLUDE_ASM`). Ce qu'il fait, et pourquoi :

| Étape | Raison |
|---|---|
| copie du compilateur et des en-têtes dans `/tmp` | les `ee-gcc` sont des i386 32 bits dont le `stat` échoue sur les inodes du montage Windows (« Value too large for defined data type ») |
| `-ffunction-sections`, puis `.text.<nom>` → `.text` | `mwccgap` greffe fonction par fonction ; le script de lien ne réclame que `<unité>.o(.text)` |
| le `.text` vide de GCC renommé | il compterait pour une fonction de plus |
| les `asm void f() { nop… }` de `mwccgap` réécrits en `__asm__` avec `.ent`/`.end` | GCC n'a pas la syntaxe de MWCC ; l'assembleur donne ainsi au stub le type et la taille d'une fonction |
| `-I` de newlib (`tools/newlib/`) et de `include/gcc/` | les en-têtes publics de newlib, plus `stddef.h`, `stdarg.h`, `limits.h` que le paquet d'`ee-gcc` ne porte pas |

## Écrire une fonction

1. **`make dossier ARGS="<symbole>"`** : la section « voie GCC » dit si c'est du C ou de
   l'assembleur MMI, et quelle source de newlib la définit.
2. **`python scripts/build/newlib_source.py <symbole> [chemin]`** aplatit la source de newlib
   dans `progress/newlib/<symbole>.c`, que `gcc_essai.py` compile seule. La recherche
   (`--cherche`) lit l'index de `tools/newlib/` (`make tools TOOLS_ARGS=--gcc` le crée) ; elle
   retrouve les `_DEFUN`, les débuts de ligne K&R, les tableaux, les alias du préprocesseur
   (`fREe` pour `_free_r`) et les noms de fichier (`sf_`, `e_`, `k_`…).
3. **`scripts/host/dc2 python3 scripts/build/gcc_essai.py <symbole> <fichier.c> --inc <dossier>…`**
   compile sous chaque build d'`ee-gcc` et chaque jeu d'options, et rend le
   `match_percent`. `--montre` (avec `--versions` et `--opts` d'une valeur) affiche les
   instructions qui diffèrent. Les en-têtes de newlib sont ajoutés d'office quand l'index
   existe.
4. **Écrire la fonction dans l'unité** : c'est du **C**, dans un fichier `.cpp` (le nom reste,
   `-x c` est passé). On reprend le corps de newlib tel quel, avec l'en-tête de licence (BSD de
   Berkeley, Sun pour fdlibm) en tête d'unité, les mêmes `#include`, et les fonctions dans
   l'ordre des adresses du binaire — l'éditeur de liens l'attend. On n'ajoute pas de
   définition de donnée : celles du binaire viennent de `asm/data/`, une définition en double
   décalerait l'image. On déclare `extern`.
5. **`python scripts/build/soumettre.py <symbole> <essai.c>`** pose, mesure (5 s), garde à
   100 %. Le contrôle de déclarations MWCC ne s'applique pas ici : le compilateur dit ce qui
   manque.
6. **`make build`** reste le verdict, à l'orchestrateur.

## Quand la source de newlib ne donne pas 100 %

- **Un stockage en trop ou en moins** : newlib 1.9.0 n'est pas exactement la version du SDK.
  Exemple : `std` de `findfp.c` écrit `ptr->_bf._size = 0;` ; le jeu n'a pas ce stockage
  (95,41 % avec, 100 % sans). On retire la ligne et on le dit en commentaire, avec le chiffre.
- **Un `nop` de délai de plus** : c'est la version d'`ee-gcc` (`mfc1`…) ; `-01` l'évite.
- **75–95 %** (`rint`, `scalbn`, `__kernel_sinf`) : source d'une autre version de newlib, ou
  modifiée par Sony. On lit `--montre`, on cherche l'instruction qui diffère, puis la ligne.
- **Le SDK** n'a pas de source : on part du désassemblage (`make decompile` donne un squelette
  de structure, en C++ de MWCC à réécrire en C) et des prototypes de `ps2sdk`.

## Ce qui n'est pas encore prouvé

- Les unités **partiellement écrites** (une partie des fonctions en `INCLUDE_ASM`) greffent
  correctement (`_cleanup_r` à 100 % dans `sfp` dont les cinq autres restaient en assembleur),
  mais aucune n'a encore été gardée dans le dépôt.
- Les **données** définies dans une source de newlib (tables, `__mprec_bigtens`) n'ont pas été
  essayées : elles relèvent de `asm/data/` et demandent `extern`.
- Le SDK (`libgraph`, `libdma`, `libpad`, `libipu`, `libvif1`…) : une seule fonction mesurée
  (`sceGifPkInit`, quatre instructions).
