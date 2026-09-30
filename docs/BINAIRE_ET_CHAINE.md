# Le binaire, et la chaîne qui le reconstruit

Tout ce qui suit est mesuré et reproductible par `make setup`. À ne pas
re-sonder. `CLAUDE.md` n'en garde que les repères ; ce fichier se consulte quand
on touche au découpage, à splat, à mwccgap, au script de lien ou à `make carve`.

---

# 1. Ce que le binaire dit de lui-même

- **Le binaire n'est pas strippé** : 17 298 symboles, 7 837 FUNC et 8 201
  OBJECT avec adresse et taille, 99 876 relocations. Une seule section
  chargée, `main`, 2 608 512 octets à `0x00100000`, sha1
  `eca0c93d5d6a25fcbf8f1fa41aa811a6f4b7aca8` ; le fichier entier fait
  4 054 516 octets, sha1 `32d26ba8e132a6b65f53212c89803903d0ad7f4d`.

- **316 symboles de section donnent les frontières de fichiers**, une par
  contribution d'objet : 192 pour `.text`, 60 `.rodata`, 32 `.data`, 21
  `.bss`, 5 `.vutext`, 5 `.vubss`, 1 `.vudata`. C'est ce que `splat` cherche
  d'ordinaire à tâtons par `find_file_boundaries` ; ici le binaire le dit, et
  l'option reste donc à `False`.

- **La disposition est séquentielle par groupe** : `.text` de `0x001000D0` à
  `0x00325C60`, `.vutext` de `0x00325C80` à `0x0032A380`, données et
  `.rodata` jusqu'à `0x0037961B`, les 49 initialiseurs statiques
  `__sinit_*.cpp` de `0x00379680` à `0x0037AFDC`, puis `.sdata` jusqu'à la fin
  du fichier en `0x0037CD80`, et 29 260 928 octets de bss jusqu'à
  `0x01F64A00`.

- **Les groupes s'enchaînent sur huit octets**, non sur 128. `.rodata`
  commence en `0x00363808` ; un alignement à 128 y insère 0x78 octets, décale
  toutes les données et fait rater sa cible à chaque `addiu` qui suit un
  `%hi`/`%lo`. Le symptôme est un écart de 0x80 sur des milliers de petites
  plages, avec un code par ailleurs exact.

- **`.reginfo` fixe `gp_value = 0x003846F0`.** 15 869 relocations `GPREL16`
  s'y rapportent, et l'assembleur doit recevoir la même base. Le *symbole* `_gp`
  que le lien définit, lui, n'a pas à porter ce nombre : `normalize.py` l'écrit
  `main_BSS_START + 0x7970`, la fin du contenu du fichier étant aussi le début du
  bss. Les deux ne se confondent pas — l'un sert à réencoder, l'autre à placer.

- **Le trou entre le code et les données est `.vutext`** : 18 208 octets de
  microprogrammes vectoriels, nommés (`Vu_prog_3dsp`, `_$MAIN_PROG`,
  `_$LPmain`), sans une seule relocation. Ce ne sont pas des instructions
  MIPS : ils restent des octets, sous `bin/`, et l'éditeur de liens les
  reprend par `objcopy -I binary`.

- **1 293 noms désignent plusieurs adresses**, tous à liaison locale :
  statiques homonymes d'une unité à l'autre, littéraux numérotés `@1069`,
  descripteurs RTTI. L'éditeur de liens n'en a jamais vu de conflit ; le
  désassembleur exige l'unicité.

- **Les noms Metrowerks portent des caractères que la chaîne refuse** : `@`
  fait échouer le script de lien GNU (« ignoring invalid character »), `$`
  introduit un registre pour l'assembleur, les chevrons des patrons
  (`Initialize__24CList<15mgCTexAnimeData>Fv`) ne passent dans aucun nom de
  fichier. Ils sont assainis en `_`, puis les collisions ainsi créées sont
  départagées par l'adresse — dans cet ordre, l'inverse en manquerait.

- **La chaîne de version ne nomme pas le compilateur.** `MW MIPS C Compiler
  (2.4.1.01)` est écrite par MWLD, et CodeWarrior R3.01 comme R3.04 la
  produisent. Laquelle a servi ne s'est pas lue : elle s'est mesurée — voir §2.

- **Deux objets portent 91 % du code.** Les 192 contributions `.text` ont une
  médiane de 280 octets — ce sont les objets de bibliothèque, une fonction
  chacun — et deux blocs font 1 432 736 et 628 336 octets : tout le code du jeu
  y est. Les frontières des 49 unités de traduction ne sont donc pas dans les
  symboles de section, et `find_file_boundaries` n'y change rien, les
  sous-segments étant explicitement bornés.

- **Le remplissage entre fonctions ne marque pas les unités de traduction.**
  3 809 des 5 017 fonctions du gros bloc sont suivies d'un trou, tous alignés
  sur 8 ou 16 : c'est l'alignement ordinaire des fonctions, pas une frontière.
  L'hypothèse est écartée par la mesure ; retrouver les 49 unités demandera
  autre chose — l'appariement avec `.rodata`, l'ordre des `__sinit_`, ou le
  couplage des appels.

## La provenance du code

- **Le mangling range la classe après la fonction** : `mgCFrame::Draw` s'écrit
  `Draw__8mgCFrameFv`. Classer par le début du symbole met donc tout le
  middleware de Level-5 avec le jeu ; c'est la classe qui dit la provenance.
  Le budget se compte par symbole, non par unité — attribuer une unité entière à
  son secteur dominant efface toute provenance minoritaire, et le middleware est
  dans ce cas.

- **Mais le nom ne suffit pas hors des unités du jeu.** Le code de bibliothèque
  de cette époque n'en porte pas qui le désigne : `_dtoa_r`, `memclr`, `quorem`,
  `kputchar`, `RFU000_FullReset`, `_defStopDMA` n'ont ni préfixe `sce` ni classe,
  et 480 fonctions — 84 572 octets, 4,3 % du secteur affiché — tombaient ainsi au
  compte du jeu. C'est l'emplacement qui tranche : `config/sectors.txt` déclare
  les deux plages du jeu, et hors d'elles chaque contribution vote par ses
  propres noms. Celle qu'aucun nom ne désigne hérite de sa voisine, l'éditeur de
  liens rangeant côte à côte les membres d'une même archive — c'est ce qui range
  `_motionComp0` et `_doCSC` avec `sceIpu*`, et `copysign` comme `quorem` avec la
  bibliothèque C. Le compte ainsi corrigé, sur les 7 837 fonctions : jeu 86,1 %,
  SDK Sony 5,8 %, middleware `mg*` 4,3 %, runtime Metrowerks 3,8 %.

- **`src/` se range par provenance** : `game/`, `sdk/`, `runtime/`, `mglib/`, et
  le nom d'une unité porte son dossier. Le partage vote sur le poids des octets,
  `sectors_by_symbol` tranchant par l'emplacement hors des plages du jeu. C'est
  une heuristique — `cscriptinterpreter` au middleware, `csound` au SDK sont à
  revoir —, et `config/units.txt` reste fait pour être corrigé à la main. Le
  middleware n'a aucune fonction hors des plages du jeu : `mg*` y est dispersé.

## Les tailles, et ce qu'elles permettent

- **Le tas commence exactement où le bss finit**, en `0x01F64A00`, sans marge : un
  texte plus long l'y recouvre, et `readelf` n'y trouve rien à redire. `pack.py`
  décale donc les sections et segments qui vivent au-delà du segment chargé.

- **Un exécutable plus long se porte jusqu'à la console, dans 524 octets.** ISO
  9660 alloue des secteurs entiers, et `SCES_511.90` en déclare 4 054 516 pour
  1 980 secteurs. Dans cette marge, seule la taille de l'entrée de répertoire est
  à corriger — en petit- **et** gros-boutiste, la norme écrivant ses entiers deux
  fois. Au-delà, la table des fichiers serait à refaire.

- **La fenêtre de `$gp` est pleine d'un côté et vide de l'autre.** Sur les 1 920
  symboles qu'un `%gp_rel` atteint, le plus bas est `sin_table_num` en
  `0x0037C700`, à `_gp - 32752` : seize octets de marge. Le plus haut est à
  `_gp - 23580`, donc 56 347 octets de la moitié haute ne servent à rien, et les
  petites données tiennent en 9 172 octets sur les 65 535 adressables. Éprouvé en
  déplaçant `_gp` : `+16` passe, `+32` rend dix « relocation truncated to fit ».
  Recentrer `_gp` rendrait ~28 Kio de marge de chaque côté, mais change les
  octets que le lien encode. **On ne le fait pas** : l'identité au disque se
  garde tant que le projet n'est pas entièrement recompilé, parce qu'elle est le
  seul oracle qui dise qu'une source est juste. La conséquence se tient : les
  petites données ne peuvent pas gagner plus de seize octets, quand le texte,
  lui, est libre.

- **Le texte peut grossir, c'est mesuré.** Treize instructions ajoutées à
  `CGamePad::WaitEnable` portent le texte de `0x00325C80` à `0x00325CE0`, le
  binaire à 2 608 608 octets, et `_gp` suit de lui-même à `0x00384750` sans qu'un
  seul `%gp_rel` déborde. Une seule instruction, elle, ne change rien :
  l'alignement à seize de MWCC l'absorbe. Ce qui reste à éprouver est la fenêtre
  de ±32 Kio, qu'un texte plus long ne sollicite pas — il pousse les petites
  données *avec* `_gp` — et qui ne se mesurera qu'en grossissant `.sdata`.

- **Les initialiseurs statiques se parcourent par une table de pointeurs.**
  `mwInit` en `0x00100190` appelle `__initialize_cpp_rts(début, fin, …)`, qui lit
  un pointeur, l'appelle par `jalr`, avance de quatre et boucle. La table est
  celle des 49 `_p__sinit_*`, de `0x0037AFE0` à `0x0037B0A4` — à ne pas confondre
  avec les corps `__sinit_*`, qui vivent de `0x00379680` à `0x0037AFDC`, ni avec
  le `__sinit` de la bibliothèque C en `0x001255F8`, qui n'a que le nom en
  commun et initialise les flux. **Les bornes se chargent par `%hi`/`%lo`**, donc
  le lien les reloge : ajouter une unité de traduction demande d'ajouter son
  pointeur, et la borne de fin suit.

---

# 2. Le compilateur

- **Le compilateur s'installe par `make tools`.** Les paquets de
  `decompme/compilers` portent le gestionnaire de licence qui laisse
  `mwccps2.exe` démarrer ; l'installateur d'origine réclame une licence FLEXlm
  et refuse de compiler sans elle.

- **La version est `mwcps2-3.0-011126`, et le niveau `-O4,p`.** Les vingt et une
  versions publiées par `decompme/compilers` s'installent par
  `make tools TOOLS_ARGS=--all`, et se départagent en les mesurant toutes sur
  une même fonction. Sur `CDngFloorManager`, celle-ci rend 100 % là où
  `3.0.1-020123` et `3.0.3` plafonnent à 97 et 98, les bêtas 2003-2006 sous
  85, et les 2.3.3 comme 2.4 à 77. Le compte est sans appel et se refait en
  une minute ; il vaut mieux que des heures de reformulation.

- **`-lang c++` est nécessaire** : mwccgap donne à son fichier intermédiaire
  l'extension `.c`, dont MWCC déduirait le dialecte.

- **`-fp` est tranché** : l'option n'a que `off` et `single`, et `single` est le
  défaut, celui du commerce — mesuré sur `IsLevelUp`, première fonction appariée
  à porter du flottant. `-inline`, `-enum` et `-RTTI` n'y changent rien non plus,
  mais elle ne les exerce pas : il faut du code à patrons et à fonctions
  virtuelles pour les éprouver. `-sdatathreshold` reste entier.

- **Les binutils de decompals exigent GLIBC 2.38**, que Debian bookworm n'a
  pas : l'image est bâtie sur trixie. Et le lien réclame `-EL`, faute de quoi
  l'émulation gros-boutiste par défaut refuse chaque objet.

## L'émulation logicielle du flottant n'est pas de notre chaîne

Deux signatures indépendantes le disent, et aucune ne dépend de la forme du C.
D'abord le cadre : `__negsf2` (0x0028D128) range ses locales en 0x00 et `ra`
en 0x20 sans sauver un seul registre, quand MWCC pose `ra` en 0x00 et les
locales par-dessus — c'est la disposition de tout le code du jeu déjà apparié
(`read_pad`, `pad_button_read`). Ensuite le masque : `__unpack_f` isole ses
23 bits de fraction par `lui`/`ori`/`and`, là où MWCC choisit la paire
`dsll32`/`dsrl32`. Les deux sont invariantes sur les 21 versions installées,
sur `-O0` à `-O4,p`, sur `-lang c` comme `-lang c++`, et sur quatre formes de
source. Les quinze fonctions de `runtime/fpmul` et les quinze de
`runtime/dpmul` sont donc à laisser greffées tant qu'on n'a pas la chaîne qui
les a produites. Les deux idiomes observés sont ceux de GCC, mais rien ne
l'établit — les noms d'entrée (`fpadd`, `sitofp`) sont ceux de Metrowerks, non
ceux de `libgcc` (`__addsf3`, `__floatsisf`).

**Une fonction sans cadre échappe à cette question.** `__pack_f`,
`__unpack_f`, `_fpadd_parts` et `__fpcmp_parts_f` ne touchent pas `$sp` :
1 252 des 3 036 octets de l'unité. Leur écart restant est le seul masque, ce
qui les laisse mesurables — mais pas appariables pour autant.

**Le runtime flottant est deux unités jumelles.** `runtime/dpmul`
(`0x0028B8F8`–`0x0028C5F0`) et `runtime/fpmul` (`0x0028C5F0`–`0x0028D160`) se
suivent sans un octet d'écart et portent les mêmes treize à quinze noms, en
double puis en simple précision — `__pack_d`/`__pack_f`, `dpadd`/`fpadd`.
C'est le cas d'école de ce que `make carve` ne peut pas voir : il avait
éclaté la simple précision en huit unités, dont sept rangées dans `game/`.
Une famille de fonctions libres contiguës mérite d'être lue avant d'être
découpée.

---

# 3. mwccgap et la greffe

- **mwccgap est ce qui rend le remplacement fonction par fonction possible.**
  MWCC émet le texte d'une unité d'un seul bloc, et n'accepte d'assembleur
  qu'entièrement défini ; une fonction non reconstruite ne peut donc pas venir
  d'un objet voisin. mwccgap la remplace par autant de `nop`, assemble le `.s`
  de référence à part, puis greffe le résultat en réparant les relocations.
  `INCLUDE_ASM("text/0012C1A8", Close__8CGamePadFv)` le déclenche.

- **`--as-flags` de mwccgap prend un nombre libre d'arguments**, donc il avale
  tout ce qui le suit : placé avant les drapeaux du compilateur, il emporte
  `-O4,p` et la compilation retombe en `-O0` sans un mot. Le symptôme est un
  appariement de 13,77 % là où la même commande à la main en rend 100.

- **Ce qu'on corrige dans un outil tiers se versionne en correctif.** Un commit ne
  retient d'un sous-module que sa référence : ce qu'on y change disparaîtrait.
  `tools/patches/*.patch` porte donc le nôtre, `make patch` le pose — le témoin
  `tools/.patched` en fait une dépendance de chaque objet, sans quoi l'écart
  n'apparaîtrait qu'au moment de comparer au disque —, et
  `make patch PATCH_ARGS=--update` le réécrit depuis l'état du sous-module. Deux
  pièges : `git apply` refuse un correctif dont les fins de ligne ont été
  traduites, ce que Python fait par défaut à l'écriture et ce que `.gitattributes`
  écarte à la lecture ; et l'arbre d'un sous-module cloné depuis Windows est en
  CRLF, que le git du conteneur ne convertit pas — d'où les deux dialectes que
  `patch_tools.py` essaie.

- **Un objet ne se recompile pas de ce que la greffe a changé.** Les règles du
  Makefile ne listaient que la source et les en-têtes : une correction dans
  mwccgap restait invisible jusqu'au prochain effacement de `build/`, et une
  reconstruction « identique au disque » ne prouvait alors rien. `$(MWCCGAP_SRC)`
  y est maintenant.

- **MWCC demande seize octets d'alignement pour chaque section qu'il émet**, et
  l'éditeur de liens comble jusque-là : un symbole que le binaire place ailleurs
  se retrouve poussé, avec tout ce qui le suit. Le symptôme est un `*fill*` dans
  la carte du lien juste avant lui, et un binaire plus long. Le compilateur n'a
  aucune option pour l'abaisser, mais mwccgap le peut sur ce qu'il greffe :
  `tools/patches/mwccgap-alignment.patch` prend l'alignement de l'adresse que le
  désassemblage donne au symbole, et une fonction greffée peut dès lors commencer
  n'importe où. Reste que la section d'une fonction *écrite* garde les seize
  octets de MWCC — mwccgap ne connaît pas son adresse —, donc une fonction que le
  binaire place ailleurs s'ouvre mais devra rester greffée. Le code du jeu s'y
  conforme presque partout : 4 994 fonctions sur 5 002 dans le premier bloc,
  1 840 sur 1 845 dans le second. Les treize exceptions que les plages du jeu
  contiennent ne sont pas du jeu — `__divdi3`, `__udivdi3`, `fpadd`, `fpmul`,
  `sitofp`, `__swsetup` : les auxiliaires du runtime et de la bibliothèque C,
  que ces plages englobent parce qu'elles sont grossières.

- **MWCC émet certaines suites de tables de saut à l'envers.** Sur les 52 unités
  qui en portent, 16 en rangent au moins deux à l'inverse des fonctions qu'elles
  servent : `_1399` en `0x003782B0` sert `0x00303010` quand `_1398` en
  `0x003782D0` sert `0x00302E98`, et les numéros décroissent quand les adresses
  montent — `text_0026D190` en aligne trois ainsi. Déclarée chacune près de sa
  fonction, elles s'échangent et chaque saut mène ailleurs. Le correctif les
  déclare groupées, dans l'ordre de leurs adresses, et retrouve chaque section
  par le symbole qui l'a déclarée plutôt que par sa place dans l'objet.

- **mwccgap greffe aussi la lecture seule, sous deux conditions.** Il sait lire
  la section `.rodata` qu'une fonction greffée emmène, mais n'y reconnaît le
  marqueur de symbole non apparié que sous le nom `nmlabel` — d'où
  `asm_nonmatching_label_macro: nmlabel` dans le découpage —, et il ne
  reconnaît ce nom-là *que* dans cette section : dans le texte, la même ligne
  compte pour une instruction, la fonction reçoit un `nop` de trop et la greffe
  échoue sur « Not enough assembly to fill ». `scripts/setup/normalize.py` l'y
  retire, ce qui ne coûte rien — mwccgap ne reportait déjà pas ce symbole dans
  l'objet compilé. Le même script écarte les commentaires que le désassembleur
  pose sous une chaîne, sur lesquels le préprocesseur s'arrête (« Unexpected
  entry in .rodata section »).

- **Le remplissage entre deux symboles de lecture seule migrés vient de
  l'alignement des sections.** Le désassembleur écrit chacun sous son `dlabel` et
  l'alignement entre eux en `.align`, que mwccgap ne reporte pas ; il en fait une
  section par symbole, et c'est l'alignement de celle-ci qui doit rendre le trou.
  Une plage `rodata:` porte donc son remplissage dès que chaque trou vaut
  exactement ce que l'adresse du symbole suivant réclame — au plus quinze octets.
  Un trou plus large tient une donnée que le désassembleur ne nomme pas. Le
  remplissage qui *termine* la plage, lui, revient de l'alignement du
  sous-segment voisin.

## Mesurer une forme sans regreffer son unité

`make lot` compile l'unité privée de ses `INCLUDE_ASM`, le fragment à la place
de la greffe, et interroge objdiff sur ce seul symbole. **546 ms par mesure**,
contre deux à cinq secondes par `make` sur l'unité.

**La réserve du dépôt a été levée par la mesure.** « La position d'une fonction
dans sa section décide de l'alignement de ses têtes de boucle » : si cela
mordait, une fonction mesurée hors greffe ne rendrait pas le score qu'elle rend
en unité. Sur soixante fonctions tirées au hasard dans le corpus des
quasi-succès, **cinquante-cinq ont rendu le même score au centième près, et
aucune n'a divergé** ; les cinq restantes ne compilent pas hors greffe, pour la
même péremption de fragment qui les gêne déjà en unité. La règle citée porte sur
les octets de l'image liée, non sur l'appariement d'un symbole.

**Le contexte se prend à l'unité, jamais inventé.** Une première version
déclarait tout nom inconnu comme une fonction à l'ellipse : seize fonctions sur
quarante étaient perdues, parce qu'un nom inconnu est aussi bien une globale ou
un type, et qu'un type déclaré en fonction rend « declaration syntax error ».
L'unité porte ces déclarations, exactes — et **la taille déclarée d'une globale
décide de `%gp_rel` contre `%hi`/`%lo`**, ce qui interdit d'improviser.

Ce que cela ne remplace pas : `match_percent` départage deux formes, il ne
prouve pas un gain. La reconstruction complète reste le seul verdict.

---

## Le coût d'un essai

- **Le coût d'un essai suit la taille de l'unité.** mwccgap regreffe toutes les
  fonctions de l'unité à chaque compilation : 0,6 s pour une unité entièrement
  écrite, 1,7 s pour une de 72 fonctions, dont 0,17 s de chargement du Makefile,
  0,5 s de MWCC, 0,2 s d'assemblage et le reste de greffe. Découper plus fin
  n'est pas le remède — la position d'une fonction dans sa section décide de
  l'alignement de ses têtes de boucle, donc changer les frontières changerait ce
  qu'on mesure. Ce qui se corrige, c'est le gaspillage : les assemblages sont
  indépendants et se lancent ensemble, et `find` n'a pas à descendre dans les
  7 759 fichiers d'`asm/nonmatchings/` pour les rejeter — `-prune`, non
  `-not -path`, sans quoi 0,73 s sont payées à *chaque* `make`.

- **Une commande par unité ne passe pas l'échelle.** `symbol_sources` appelait
  `make` puis `nm` une fois par source ; le seul démarrage de `make` coûte
  0,74 s, donc 319 unités faisaient quatre minutes avant la première mesure de
  `make diff`. Les deux commandes prennent tous les objets d'un coup — `nm`
  annonce alors chaque fichier par une ligne « chemin: », et n'annonce rien
  quand on ne lui en donne qu'un.

---

# 4. Le découpage : unités, plages `rodata:`, désassemblage

- **Une unité de travail se déclare dans `config/units.txt`** — début, fin, nom,
  et au besoin la plage `rodata` qui l'accompagne — et devient un sous-segment de
  type `cpp`. Le désassembleur en écrit alors une fonction par fichier sous
  `asm/nonmatchings/<nom>/`, et le script de lien y attend `build/src/<nom>.o` à
  la place de l'assemblé. C'est la seule pièce du découpage qui s'écrit à la
  main, et la seule qui se versionne : les frontières des 49 unités d'origine ne
  sont pas dans le binaire, donc elles se décident. Le binaire reste identique
  tant que l'ordre des fonctions est conservé, ce que `make build` tranche.

- **Le type `cpp` de splat, non `c`.** Le type `c` écrit un `src/<nom>.c` à côté
  du `.cpp` et l'éditeur de liens reçoit deux fois la même unité.

- **Il faut deux désassemblages.** Le désassembleur cesse d'extraire une fonction
  dès qu'une source la définit — seules celles qu'un `INCLUDE_ASM` réclame sont
  écrites —, donc la fonction reconstruite perdrait la référence contre laquelle
  on la mesure. `config/splat.ref.yaml` garde tout en assembleur sous `ref/asm`,
  et c'est la cible d'objdiff. DCDecomp fait de même : son CMakeLists assemble
  chaque dump « whether or not the link ends up using it ».

- **L'en-tête des fichiers inclus est vide chez MWCCPS2** là où le profil GCC de
  splat porte `.set noat` et `.set noreorder`. Sans lui, l'assembleur remplit les
  créneaux de délai : un `nop` de plus par fonction greffée, toutes les cibles de
  branchement décalées d'un mot, et 3 409 octets divergents sur les seules
  fonctions greffées. `asm_inc_header` y ajoute aussi `.include "macro.inc"`,
  sans quoi `make diff` ne peut pas assembler un fichier seul.

- **m2c s'arrête sur le marqueur de symbole non apparié.** Le désassembleur écrit
  `nmlabel <symbole>, <taille>` en tête de chaque fichier de référence ; m2c y voit
  une instruction hors fonction et refuse la fonction entière — « unsupported
  non-nop instruction outside of function ». Les 325 fichiers de `ref/asm/text/`
  en portent un, donc `make decompile` ne rendait rien nulle part. `decompile.py`
  écarte ces lignes dans une copie temporaire, y joint les blocs de lecture seule
  que le texte charge et qui portent des étiquettes — c'est le contenu qui
  désigne une table de saut, non son nom —, et les renomme en `jtbl…` le temps de
  l'analyse. Le fichier versionné ne bouge pas, et `config/symbol_addrs.txt` reste
  l'endroit où l'on corrige un nom pour de bon.

- **Le désassembleur ne réécrit pas un fichier qui existe déjà.** Changer
  `asm_inc_header` ne se voit qu'après avoir effacé `asm/nonmatchings`.

- **Le désassembleur écrit une source par défaut pour un sous-segment `cpp` qui
  n'en a pas**, et elle n'est pas au format que le projet emploie : ses
  `INCLUDE_ASM` portent `asm/nonmatchings`, que mwccgap cherche ensuite sous
  `asm/asm/nonmatchings`. Déclarer une unité sans écrire sa source échoue donc
  sur un fichier introuvable, non sur une absence de source.

- **Ranger les unités en dossiers en donne au désassemblage de référence.**
  `ref/asm/text/` gagne un sous-dossier par secteur, et toute lecture à plat n'y
  voit plus rien — `read_references` écartait alors les unités à table de saut,
  faute de trouver qui les atteint.

## Les bornes

- **La position d'une fonction dans sa section compte.** L'alignement d'une tête
  de boucle se calcule depuis le début de la section, donc une unité ouverte trop
  bas décale ce que le compilateur produit. Ouvrir la plage plus haut, sur les
  fonctions qui précèdent, rétablit la disposition d'origine.

- **La borne haute d'une unité vaut ce que son objet produit**, ni la fin de sa
  dernière fonction ni le début de la suivante par principe. Le remplissage qui
  les sépare est produit quand la dernière fonction est greffée — l'assembleur
  aligne alors la fin de la section — et absent quand elle est compilée. Aussi
  `gamepad` s'est-elle bornée au début de la suivante (`0x0014B500`) tant que sa
  dernière fonction était greffée, puis à la fin de celle-ci (`0x0014B4F4`) une
  fois écrite. L'inverse décale tout ce qui suit d'un mot, et le symptôme est un
  `jal` dont la cible perd quatre octets. `make open` propose la fin de la
  dernière fonction ; `make build` tranche, et l'autre borne est le premier
  essai à faire. La règle vaut même quand la plage est une contribution d'objet
  entière : `mpegdma` couvre `0x0010F4C0` à `0x0010F4E0` dans le binaire, mais
  se borne à `0x0010F4DC` une fois ses deux fonctions écrites — les quatre
  octets de remplissage restent en assembleur.
  Le remplissage *intérieur* à une plage, lui, se produit tout seul :
  `dngfloormanager` enjambe le `nop` qui sépare `IsClearMostFastDestroy`
  d'`IsClearPractice` sans qu'aucun `INCLUDE_ASM` ne le réclame — splat n'en
  écrit d'ailleurs pas de fichier, MWCC alignant la fonction suivante lui-même.

- **Une frontière de contribution d'objet l'emporte sur une unité déclarée.** Le
  désassembleur fait un sous-segment de chacun des 192 symboles de section
  `.text`, et il tronque sans un mot l'unité qui l'enjambe. Le seul symptôme est
  que la source réclame un `INCLUDE_ASM` dont le fichier n'existe pas. Les deux
  gros blocs du jeu n'en portent aucune à l'intérieur, ce qui explique que le cas
  ne se soit jamais présenté ; le code de bibliothèque en porte une par fonction,
  et les auxiliaires du runtime que les plages du jeu englobent sont dans ce cas.
  `config/elf_sections.txt` les écrit, et `make carve` y coupe.

- **La borne haute du découpage est `.vutext`, non la dernière fonction du
  binaire.** Les 49 initialiseurs statiques `__sinit_*` sont des `FUNC` mais
  vivent après les données, en `0x00379680`. Les prendre pour du texte en fait
  une unité dont le script de lien range le `.text` avec celui du jeu, et tout ce
  qui les sépare des données glisse ; le symptôme est un débordement `%gp_rel`,
  les petites données s'étant éloignées de `_gp` fixé en dur.

## Les tables de saut et les plages `rodata:`

- **m2c exige que la table de saut porte un nom en `jtbl`.** Faute de quoi il
  refuse la fonction — « Unable to determine jump table for jr instruction ». Le
  nom que Metrowerks lui donne, `@1200`, n'en est pas un ;
  `config/symbol_addrs.txt` le corrige en `jtbl_00377F10`, ce qui est le seul cas
  où l'on s'écarte du nom que le binaire porte. Il faut aussi donner à m2c le
  fichier `rodata` qui porte la table, en plus de celui du texte.

- **Une fonction à saut indirect s'ouvre en emmenant sa table.** Celle-ci vit en
  `rodata` et désigne des étiquettes du corps ; séparées, l'objet compilé
  n'expose plus les étiquettes et l'éditeur de liens s'arrête sur une faute de
  segmentation. `config/units.txt` accepte donc une plage `rodata:<début>-<fin>`
  en quatrième champ, que le découpage rend en sous-segment `.rodata` du même
  nom que l'unité — le point devant `rodata` est ce que splat exige pour
  rattacher la plage au fichier plutôt que d'en écrire un second désassemblage.
  Le désassemblage de référence, lui, ne reçoit pas cette coupure : il garde
  tout en assembleur, et la table doit y rester avec le corps qu'elle sert.
  `grep -c jlabel ref/asm/text/<unité>.s` dit d'avance si le cas se présente :
  zéro pour `gamepad`, sept pour `dngfloormanager`, quarante-deux pour
  `crunscript`.

- **Le désassembleur ne migre un symbole de lecture seule qu'à trois
  conditions.** C'est la règle de `SymbolRodata.shouldMigrate` dans spimdisasm, et
  non une supposition. `len(referenceFunctions) > 1` interdit la migration, quel
  que soit l'endroit d'où viennent ces références. Et `MWCCPS2` porte
  `allowRdataMigration = False`, donc ce qui passe pour une constante ne bouge pas
  non plus : ne voyagent qu'une chaîne, une table de saut de trois étiquettes au
  moins, et un flottant à queue nulle. Les chaînes en Shift-JIS, que le
  désassembleur rend en `.word` faute de les décoder, comptent pour des
  constantes. Or une plage `rodata:` porte tout ce qui s'intercale entre sa
  première table et sa dernière — 46 des 54 symboles de celle de `clsmes` sont
  atteints par plus d'une fonction. Ce que le désassembleur ne migre pas n'est
  écrit nulle part, et le lien s'arrête sur une faute de segmentation précédée de
  débordements `%gp_rel` : le contenu manquant a rapproché les petites données de
  `_gp`, dont le symbole le plus proche n'est déjà qu'à seize octets de la limite
  des ±32 Kio. La condition — forme migrable, un seul atteignant, et dans l'unité
  — est vérifiée par les 27 plages qui fonctionnaient déjà, et en écarte seize des
  proposées. Le remède se déduit de la règle : une unité qui ne porte qu'une table
  a une plage réduite à cette table, donc sûre.

- **Un prédicat sur la migration s'éprouve contre le désassemblage, non contre une
  reconstruction.** `asm/nonmatchings/<unité>/` dit ce que le désassembleur a migré
  et où ; comparer le prédit à l'observé coûte une seconde, là où reconstruire en
  coûte un quart d'heure. C'est ainsi que le troisième terme de la règle a été
  trouvé, et que deux erreurs de lecture de la référence l'ont été aussi — les
  trois champs du commentaire d'une ligne de donnée, et le remplissage qui suit
  `enddlabel` et faisait passer une table de saut pour une donnée mêlée.

- **Une plage `rodata:` s'arrête exactement où sa dernière table finit.** Le
  sous-segment d'une unité ne reçoit que ce que le désassembleur migre vers ses
  fonctions : un symbole que la plage avale sans qu'il le migre n'est plus écrit
  nulle part, et l'éditeur de liens s'arrête sur une faute de segmentation devant
  la référence qui lui reste. Étendre la borne pour tomber sur un multiple de
  seize suffit à provoquer cela — mesuré sur `cmenueffect`, dont la plage
  emportait ainsi le flottant de quatre octets qui suivait sa table. Le
  remplissage qui vient après revient de lui-même au sous-segment voisin, dont
  l'alignement suit le contenu.

- **Le remplissage qui termine une plage `rodata:` dépend de l'alignement d'un
  voisin, qui peut le perdre.** L'assembleur donne à une section l'alignement du
  plus grand `.align` qu'elle porte : couper un sous-segment de lecture seule plus
  court lui retire ce qui le portait, et les octets qu'il fournissait au voisin
  d'avant disparaissent. Le symptôme est une suite de symboles décalée de quatre
  ou huit octets, et une quarantaine de plages divergentes d'un seul octet —
  chaque `%lo` qui les désigne. La parade est la règle qui précède, et elle vaut
  d'être appliquée partout : `dngfloormanager` était la seule unité à border sur
  le symbole suivant plutôt que sur la fin de sa table, et déclarer une unité
  trois cent adresses plus loin a suffi à la faire échouer.

- **Une table de saut peut finir sur des mots nuls.** Six d'entre elles, toutes
  dans le code de bibliothèque, en portent un après leur dernière étiquette.
  `isJumpTable` de spimdisasm répond du type que le `jr` a donné au symbole, non
  de son contenu : elles migrent comme les autres, et la plage doit porter le
  symbole entier — borner à la dernière étiquette le coupe de quatre octets.

- **Une plage de lecture seule d'un seul symbole n'a pas de trou à expliquer.**
  La contiguïté se juge sur les symboles que le binaire dimensionne ; or les
  tables de saut du code de bibliothèque n'en sont pas — splat les nomme lui-même
  `jtbl_…` —, donc aucune taille ne les borne, et le cas se tranche sur ce que le
  désassembleur nomme.

- **Une plage de lecture seule trop large se resserre à une table par unité.**
  Une plage porte tout ce qui s'intercale entre la première table et la dernière ;
  n'en garder qu'une la réduit à cette table, et rien d'étranger ne s'y intercale
  plus. `make carve` découpe d'abord à la taille visée, éprouve chaque tranche, et
  ne replafonne que celles qui échouent — les grandes unités dont la plage tient
  déjà restent intactes. Les seize zones qui résistaient font ainsi 51 unités,
  383 588 octets, 91,5 % du texte, et le prix est une médiane à 5 980 octets pour
  24 576 visés, dix-sept unités sous 4 Ko et sept d'une seule fonction.

## `make carve`, et ce qui reste hors des unités

- **`make carve` découpe le code du jeu de bout en bout.** Réunir les classes dès
  qu'elles s'entrecoupent ne donne rien — les 5 002 fonctions du premier secteur
  ne font alors que trois composantes, dont une de 1,4 Mo. Le découpage vise donc
  une taille et choisit, dans une fenêtre autour d'elle, la frontière qui laisse
  le moins de classes à cheval, et coupe à chaque frontière de contribution
  d'objet. Il dit ce qu'il écarte, et n'écarte plus rien du code du jeu.

- **Une fonction hors unité ne peut pas s'écrire en C++.** Le remplacement
  fonction par fonction demande un sous-segment `cpp` et un `INCLUDE_ASM` ; c'est
  ce qui rend le découpage du code de bibliothèque obligatoire et non facultatif,
  puisque le SDK, le runtime et la bibliothèque C sont à reconstruire. Le coût en
  était surestimé : les 988 fonctions hors des plages du jeu n'occupent que 182
  contributions d'objet, dont 124 d'une seule fonction et une de 138. Le
  découpage couvre donc tout `.text` — 325 unités, 99,7 %.

---

# 5. Les données, le bss, le script de lien

- **Le bss se couvre d'un seul sous-segment.** `{ start: <fin du fichier>, type:
  bss, name: bss/0037CD80, vram: 0x0037CD80 }` le prend de bout en bout, et les
  symboles absolus passent de 2 503 à 55. La couverture doit être entière parce
  que le script de lien range les `.bss` à la suite les uns des autres, sans
  adresse : un segment déclaré seul n'atterrit pas où le binaire l'avait, et
  1 327 plages divergent. Un segment unique n'a par ailleurs aucune frontière
  intérieure à faire tomber juste, ce qui est la raison de préférer cette forme.

- **Un bloc vectoriel se borne au premier symbole dimensionné qui le suit.** Ses
  points d'entrée sont de taille nulle, donc rien ne borne son sous-segment, qui
  court jusqu'à la contribution suivante et avale ce que la section d'à côté
  porte. `.vutext` finit en `0x0032A380` et non `0x0032A3A0` ; la queue rendue aux
  données, les symboles absolus tombent de 55 à 51.

- **La queue de `.vudata` se rend aussi aux données**, en `0x00363580` : elle
  porte des RTTI, des littéraux et quatre tables de saut qui servent
  `runtime/std`, à qui la plage `rodata:0x00363660-0x003637B0` les rend.

- **Le désassembleur n'étiquette qu'aux multiples de quatre** quand il rend une
  section en mots : un objet d'un ou deux octets posé entre deux n'a pas de
  `dlabel` et arrive au lien par son adresse absolue. Sa taille dit son type, et
  `type:u8` le fait rendre en `.byte`. Sept objets du binaire sont dans ce cas,
  tous dans la série des dix `CHA_DEV_FONT_PIECE_*` en `0x00364548` ; il faut
  typer aussi ceux qui partagent leur mot, sous peine d'y mêler deux découpages.

- **splat déclare indéfini un symbole que spimdisasm définit.** Sa règle est
  `not s.defined`, et l'attribut ne suit pas toujours ce qui est écrit : une
  affectation absolue subsiste alors et fixerait le symbole où sa section le
  dément. `normalize.py` retire du script ceux qu'un `dlabel` définit, et le lien
  tranche — un symbole retiré à tort n'est plus défini nulle part.

- **Un bloc d'octets ne définit aucun de ses noms.** Lié par `objcopy -I binary`,
  il n'expose que ce qu'objcopy invente ; `Vu_progmain`, `Vu_prog_wtr` et
  `My_dma_start0` arrivaient donc au lien par leur adresse absolue, ce qui les
  figerait. `normalize.py` pose `<nom> = .;` devant l'objet dans le script de
  lien, et ils suivent alors sa position.

- **Deux noms pour une adresse en laissent un pendant.** `symbol_addrs.txt` est
  lu après `elf_symbol_addrs.txt` et le corrige ; `configure.py` écarte donc les
  adresses qu'il nomme, faute de quoi le nom d'origine reste référencé sans que
  rien le définisse. Le découpage doit aussi dépendre de cette table, sans quoi
  la correction ne prend qu'au prochain changement d'unité.

- **Ce qui reste absolu tient en seize symboles**, dont quinze fenêtres
  matérielles que leur nature y garde. Le seizième est `_xlaunch`, étiquette au
  milieu de `_kTLBException` : `type:label` la fait poser, mais la construction
  diverge alors de six octets en `0x00118798` — l'étiquette est locale à la
  section greffée et son `%hi`/`%lo` ne se résout plus comme le commerce
  l'encode. Le remède est du côté de mwccgap.

- **Un objet ne se recompile pas de ce que le découpage a changé.** La règle du
  Makefile ne dépendait ni de `config/units.txt` ni de `configure.py` : changer la
  plage `rodata:` d'une unité ne la faisait pas refaire, et l'objet gardait les
  sections d'avant. Le symptôme ne ressemble pas à sa cause — non pas une
  divergence d'octets, mais une **faute de segmentation au lien, sans message**,
  l'objet n'ayant plus la section que le script réclame. Mesuré sur
  `runtime/std`, dont l'objet a gagné six sections `.rodata` une fois refait, et
  qui a fait passer deux fois une coupure juste pour un défaut de `ld`.
  `$(UNITS)` est la dépendance qui manquait. **Devant une faute de segmentation au
  lien, `objdump -h` sur l'objet en cause tranche en une seconde.**

- **Un symbole se relie à sa source par l'objet compilé, non par le texte.** La
  source écrit `CGamePad::Close`, le binaire porte `Close__8CGamePadFv` ; seul le
  compilateur connaît la correspondance, et `nm` la lit.

---

# 6. Le rapport de progression

- **`objdiff.json` dépend des sources autant que du découpage.** C'est la
  présence de `src/<unité>.cpp` qui donne à une unité son `base_path`, donc
  l'objet contre lequel objdiff la mesure ; sans lui, le rapport la porte sans
  `matched_code_percent` et aucune de ses fonctions n'y paraît appariée, alors
  que `make diff` en rend 100 %. Le symptôme est une fonction juste qui reste
  grise dans la page. La règle du Makefile liste donc `$(SRC_FILES)`.

- **Une fonction greffée porte les octets du disque, donc objdiff l'apparie à
  100 %.** Ouvrir une unité suffirait ainsi à faire monter le rapport sans
  qu'une ligne de C++ soit écrite : à soixante-douze unités ouvertes, la page
  annonçait 61 % là où `make progress`, qui tranche sur la source, en donnait
  0,274 %. `report.py` écarte donc les symboles qu'un `INCLUDE_ASM` nomme, et
  refait la part de chaque unité depuis ses fonctions au lieu de lire celle
  qu'objdiff lui donne.

- **Le compte de fonctions et celui des octets ne disent pas la même chose.**
  La page porte les deux : `221 sur 7 792 fonctions identiques` à côté de
  `12 492 sur 2 209 044 octets`, soit 2,84 % contre 0,57 %. L'écart tient à la
  taille, et l'histogramme des ordres de grandeur le montre — une classe par
  puissance de deux, la première réunissant tout ce qui tient sous huit octets.
  Les 614 fonctions de huit à quinze octets portent 171 des 221 identiques et
  1 380 octets sur 2,2 Mo : reconstruire une petite fonction avance le compte
  de fonctions sans peser sur celui des octets. La masse est ailleurs : les 975
  fonctions de 512 octets et plus portent 1 305 936 octets, 59 % du code pour
  12,5 % des fonctions. Le compte se refait sur *toutes* les
  fonctions, non sur la carte : celle-ci n'en garde que les 1 200 plus grosses.

- **Un rapport de progression n'a pas besoin du disque.** objdiff compare des
  objets : le désassemblage de référence et les sources suffisent. C'est ce qui
  permet à DCDecomp de produire le sien en intégration continue — il versionne
  son désassemblage et son compilateur, et son workflow le dit explicitement.
  Notre règle est l'inverse, donc la même voie demanderait de publier soit le
  désassemblage, soit seulement le rapport. C'est un choix, non une contrainte.

- **decomp.dev lit un artefact de GitHub Actions**, nommé
  `<EXÉCUTABLE>_report`, et désigne ses projets par l'identifiant numérique d'un
  dépôt GitHub ; l'inscription se fait une fois à la main sur `/manage/new`.
  Aucune route n'accepte qu'on lui remette un rapport autrement. Il
  s'auto-héberge par ailleurs (Rust, npm, SQLite, `localhost:3000`).

- L'application objdiff lit `objdiff.json` en local et couvre le travail à la
  fonction, sans dépôt ni service.

---

# 7. Ce que d'autres projets fournissent

- **Le runtime Metrowerks a ses sources dans l'installateur CodeWarrior**, sous
  `PS2_Support/Runtime/Sources/` : `newop.cpp`, `delop.cpp`, `MWRTTI.cpp`,
  `__ptmf.c`, `StaticInitializers.cp`, `ExceptionHandler.cp`. Le binaire y
  répond — `__nw__FUi`, `__dl__FPv`, `__throw`, `__unexpected`,
  `FindExceptionHandler` — soit 2 264 octets sur les 48 228 du runtime. Ces
  sources sont propriétaires : elles servent de référence pour réécrire, non de
  copie à verser dans le dépôt. La bibliothèque C, elle, n'est fournie que
  compilée (`MSLGCC_PS2.LIB`) avec ses seuls en-têtes, donc `memcpy`, `sprintf`
  et `_dtoa` restent à décompiler.

- **`ps2sdk` est une réimplémentation, non les sources de Sony** : reverse des
  bibliothèques de la ROM, donc sans valeur pour l'appariement, mais il donne
  les prototypes exacts et les structures — `PAD_STATUS`, les environnements du
  GS — qui sont la moitié du travail sur une fonction `sce*`.

- **DCDecomp partage le middleware, pas son code.** Dark Cloud 1 porte les mêmes
  classes sans le préfixe : `CFrame` là où Dark Chronicle a `mgCFrame`. Sur les
  45 méthodes de `mgCFrame`, 16 portent un nom que DC1 déclare, soit 2 224
  octets sur 7 576 — 29 %. Et DC1 n'a que des déclarations : `src/mglib.cpp` y
  fait quinze lignes de globales. Ce sont donc les signatures qui se
  transposent, pas les implémentations.

- **objdiff démangle ce que les binutils ne savent plus faire.** Le style GNU-v2
  que Metrowerks emploie a été retiré de `c++filt` ; le démangleur CodeWarrior
  d'objdiff rend 86 % des 7 792 fonctions et nomme 303 classes, dont 961 560
  octets de méthodes. C'est de là que `make units` tire ses propositions.

# 8. Les compilateurs GCC de Sony

Le SDK Sony et la bibliothèque C du jeu (1 082 fonctions, 220 848 octets, 10 % des octets)
sont absents de `.mwcats` : MWCC ne les a pas compilés. Les marqueurs `gcc2_compiled.` de
l'ELF, le cadre de `__negsf2` et les noms de newlib (`_free_r`, `__sfp`, `__ieee754_*`)
disent GCC 2.x, le compilateur de Sony pour l'Emotion Engine.

- **Les compilateurs** sont dans la release `decompme/compilers` d'où vient déjà MWCC :
  `make tools TOOLS_ARGS=--gcc` installe huit builds sous `tools/compilers/ee-gcc*`
  (2.9-990721, 2.9-991111 et ses variantes `-01` et `a`, 2.95.2-273a, 2.95.3-114 et 136,
  2.96). Rien n'entre dans git.
- **Les binaires** sont des ELF i386 32 bits (2.9x et 2.96) ou des `.exe` de SN Systems
  (2.95.x, lancés par wibo). L'image Docker porte `libc6-i386` pour les premiers. Sur le
  montage Windows, leur `stat` 32 bits échoue sur les numéros d'inode (« Value too large for
  defined data type ») : le compilateur et la source se compilent depuis `/tmp`.
- **`scripts/build/gcc_essai.py`** compile une fonction sous chaque build et chaque jeu
  d'options (`-O2 -G0`, `-O2 -G8`, `-O2 -G128`, `-O1 -G0`, `-O3 -G0`) et rend le
  `match_percent` d'objdiff contre la référence : c'est la méthode qui a départagé les 21
  versions de MWCC, appliquée aux GCC.
- **Première mesure** : `sceGifPkInit` (quatre instructions) est à 100 % sous toutes les
  versions de 2.9-991111a à 2.96 en `-O2` et `-O3`, à 96,75 % en `-O1` : trop courte pour
  départager. Il faut des fonctions plus longues.
- **Tout n'est pas du C compilé.** Le `strlen` du jeu est de l'assembleur MMI écrit à la
  main (`lq`, `psubb`, `pnor`, `pcpyud`) : aucun compilateur ne le rendra depuis le `strlen`
  de newlib (57,9 % sous toutes les versions). Une fonction de ce genre reste de
  l'assembleur de référence.
