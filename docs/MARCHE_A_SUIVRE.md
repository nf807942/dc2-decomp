# Marche à suivre

Reconstruire une fonction, du désassemblage jusqu'aux octets du disque.

Tout se lance dans le conteneur. Le préfixe est sous-entendu partout ici :

```sh
scripts/host/dc2 make …
```

---

## Au départ

```sh
make tools     # le compilateur Metrowerks, depuis decompme/compilers
make setup     # extrait le disque, écrit le découpage, désassemble
make build     # doit dire « identique au disque »
```

Si `make build` ne dit pas *identique*, rien de ce qui suit n'a de sens : la
référence est cassée, il faut la réparer d'abord.

**Le découpage est fait.** 7 791 des 7 840 fonctions du binaire vivent déjà dans
une des 319 unités, et chacune attend dans un `src/*.cpp` sous `INCLUDE_ASM`. Il
n'y a donc rien à ouvrir : le travail commence directement à une fonction. Les
sources sont rangées par provenance — `src/game/` pour Level-5, `src/sdk/` pour
Sony, `src/runtime/` pour Metrowerks et la bibliothèque C, `src/mglib/` pour le
middleware `mg*`.

Les 49 qui restent dehors sont les initialiseurs statiques `__sinit_*` : ce sont
des fonctions, mais elles vivent après les données, et le script de lien range
tous les `.text` ensemble. Les ouvrir ferait glisser ce qui les sépare des
données ; c'est un chantier à part, décrit dans la feuille de route.

---

## 1. Choisir une fonction

```sh
make report     # puis ouvrir progress/index.html
```

La page trie les fonctions par taille dans chaque unité, et c'est l'ordre le plus
rentable. Deux conseils qui valent plus que la taille :

- **rester dans une unité** une fois qu'on y est. La disposition d'une structure,
  une fois établie, sert toutes les méthodes de la classe ; un champ mal typé se
  paye sur chacune ;
- **commencer par la plus petite de l'unité**. Elle apprend les conventions du
  fichier pour un coût minime.

### Les petites, par lots

Une autre entrée vaut mieux que la page de rapport quand on cherche du volume :

```sh
python3 scripts/diff/inventaire_petites.py       # jusqu'à 50 octets
python3 scripts/diff/inventaire_petites.py 8     # les corps d'une instruction
```

L'outil compte les fonctions de `src/game/` encore greffées et **classe celles de
huit octets par forme** — l'instruction unique de leur corps dit à elle seule ce
que la source doit être. Le tas devient alors une poignée de lots uniformes qu'on
écrit d'un trait, et c'est bien plus rentable qu'une fonction à la fois : cent
cinquante-six fonctions sont entrées en trois passes, toutes à 100 % du premier
coup, dont soixante-trois commandes de script `s32 _NOM(RS_STACKDATA *, int)` qui
ne rendent qu'un code, trente-six autres retours constants et cinquante-sept
accesseurs de globales.

Trois choses à savoir avant de lancer un lot :

- **la vérification se fait d'un coup.** `make build` couvre les centaines de
  fonctions du lot en une passe et nomme les plages qui divergent ; `make diff`
  ne sert qu'à celles-là ;
- **les seuls achoppements sont des erreurs de compilation**, pas des écarts
  d'octets : un pointeur de fonction déclaré `s32`, une classe dont la méthode
  n'est pas déclarée, une globale de type pointeur, un `#include` placé après ce
  qui l'emploie. Elles se lisent dans la sortie de MWCC et se corrigent une par
  une ;
- **un retour constant ne réclame aucune disposition.** `class X { public: s32
  Foo(); };` suffit, et rien n'oblige à établir la classe entière — ce qui n'est
  pas vrai des accesseurs de champs, qui demandent l'offset et la largeur.

---

## 2. Lire, puis demander un premier jet

Le désassemblage de référence vit sous `ref/asm/text/<secteur>/<unité>.s` :

```sh
sed -n '/glabel Draw__11CAutoMapGenFv/,/endlabel/p' ref/asm/text/game/cautomapgen.s
make decompile S=Draw__11CAutoMapGenFv
```

Ce que m2c rend n'est pas une réponse : la structure de contrôle est juste, les
types sont à établir. Sur une fonction courte, c'est souvent presque exact.

---

## 3. Écrire, mesurer, recommencer

Remplacer la ligne `INCLUDE_ASM` de la fonction par son corps, **à la même
place** — l'ordre des adresses est celui que l'éditeur de liens attend.

```sh
make diff S=Draw__11CAutoMapGenFv
```

Les deux suites d'instructions s'affichent côte à côte, avec le taux
d'appariement. `100 %` veut dire que la fonction est reconstruite.

Le premier écart est le seul qui compte : les suivants en découlent souvent.

| Ce qu'on voit | Ce que ça dit |
|---|---|
| Mêmes instructions, un registre diffère | l'ordre d'évaluation, ou une variable de trop |
| Mêmes instructions, un décalage diffère | la disposition de la structure : un champ est ailleurs |
| Une instruction en plus chez nous | un cast, une variable temporaire, une lecture répétée |
| `lw` là où le commerce fait `lh`/`lb` | la largeur du champ |
| Tout est décalé après un point | une instruction manque avant ; regarder le premier écart seul |

---

## 4. Quand ça plafonne

Ce qui suit est le catalogue de ce qui a déjà résisté, avec la forme qui a fini
par apparier. Chacun est mesuré sur une fonction réelle, pas déduit.

**Un créneau de délai vide** — un `nop` là où le commerce a une instruction utile
— veut dire que la valeur n'est pas disponible assez tôt. La déclarer en tête
déplace l'allocation des registres et empire souvent le résultat ; ce qui marche
est de l'évaluer *dans* la condition :

```cpp
if (this->table == NULL || (i = 0, this->count) <= 0) {
```

**Un champ atteint plusieurs fois se prend par son adresse.** Le commerce hisse
`&pad->phase` dans un registre sauvegardé et n'y touche plus qu'en `0x0(sN)` ;
écrire `pad->phase` reforme l'offset après chaque appel. Le symptôme est un
`addiu sN, base, offset` côté commerce là où nous portons l'offset dans chaque
`lw`.

**Un calcul que le commerce enchaîne dans le registre d'un paramètre** ne
s'obtient qu'en écrivant dans ce paramètre :

```cpp
mpeg = (sceMpeg *)mpeg->work;          // lw a0, 0x40(a0) — apparie
sceMpegWork *work = mpeg->work;        // lw v0, 0x40(a0) — n'apparie pas
```

**Deux boucles successives veulent deux compteurs**, et **le nom du compteur
décide de son registre** : MWCC attribue par ordre de déclaration, non par
imbrication. Réutiliser `i` partout coûtait dix-huit instructions sur deux cent
neuf.

**Un aiguillage à un seul cas n'est pas un `if`.** Quand plusieurs retours rendent
la même valeur et qu'un seul passe par un bloc partagé, le `switch` garde les
sorties distinctes là où le `if` les fond — et le créneau de délai change avec.

**Une boucle vide survit, mais pas sous toutes ses formes.** Écrite
`for (i = 0; i < 7; i++) {}` elle disparaît ; ce qui la retient est le test `!=`,
ou l'incrémentation portée dans la condition — `i = 0; while (++i < 7) {}`.

**L'écart peut être hors de la fonction.** Un prototype, un type de paramètre,
une taille de champ : `Init` a tenu 93,70 % contre seize formes de corps et 250
essais du permuteur, et c'est `void *dma` au lieu de `u8 *dma` dans l'en-tête qui
la retenait.

### Les deux outils de recherche

Ils ne servent pas la même chose :

```sh
make measure S=<symbole> V=<variantes.py>   # répond à une question posée
make permute S=<symbole> [N=<essais>]       # cherche seul, à l'aveugle
```

`make measure` compile un lot de formes pour un même fragment — encadré dans la
source par `/* @@nom */` et `/* @@fin */` — et rapporte leur taux. Il tranche en
une passe ce que les essais un par un laissent en plateau : sur
`GetDngMapFloorGlidInfo`, six lots ont mené de 74 % à 100 %, et chaque palier a
désigné le fait suivant à corriger.

`make permute` applique des transformations aveugles quand on ne sait plus quoi
demander. Sur `AxisCalibration`, 31 essais ont trouvé une forme à laquelle
personne n'avait pensé.

### Si le plateau tient alors que la taille est déjà juste

Changer de compilateur avant de réécrire. Vingt et une versions s'installent par
`make tools TOOLS_ARGS=--all` ; les mesurer toutes sur la fonction qui résiste
prend une minute, et `MWCC_VERSION=… make …` en choisit une. Ce qui reste à ce
stade — un créneau vide, un registre sauvé qui diffère — vient de la chaîne, pas
de la source : ni le permuteur ni les pragmas ne le corrigent.

---

## 5. Confirmer

```sh
make build      # identique au disque : la fonction est acquise
make progress   # ce qui est reconstruit, en octets
```

`make build` est le seul juge. `make diff` compare une fonction, `make build`
compare le binaire entier : une fonction à 100 % qui casse la construction
signifie que quelque chose a bougé autour.

---

## Voir une fonction à l'œuvre dans le jeu

Pour savoir ce qu'une fonction fait vraiment, on peut la forcer à rendre une
constante — **sans toucher aux sources**, donc sans perdre l'oracle :

```sh
make mod M="IsLevelUp__13CGameDataUsedFv=1"
make iso ISO=build/essai.iso
```

`mod.py` retouche l'exécutable produit, pas le C++ : `make build` reste vert, et
la fonction garde sa taille. Cela vaut pour **n'importe quelle** fonction du
binaire, y compris celles qui ne sont pas encore reconstruites — c'est tout
l'intérêt.

L'image se lance dans un émulateur PS2, qui demande un BIOS que le dépôt ne
fournit pas.

---

## Conventions

- Les symboles s'écrivent manglés, comme le binaire les porte :
  `Close__8CGamePadFv` est `CGamePad::Close(void)`.
  `config/elf_symbol_addrs.txt` les liste tous.
- Commentaires en français, identifiants en anglais.
- Un commentaire dit *pourquoi*, jamais *quoi*. Un fait établi par sondage se
  documente à l'endroit du code, avec le chiffre observé. **Une forme laide qui
  apparie doit dire pourquoi elle l'est** — sans quoi le prochain lecteur la
  « corrigera ».
- Ne pas surinterpréter : ce qui n'est pas prouvé se dit tel quel, dans le code
  comme dans la sortie d'un outil.
- Rien de dérivé du jeu n'entre dans git — ni disque, ni désassemblage, ni
  tables. Ce qui se versionne est ce qu'on écrit.
- **L'identité au disque ne se négocie pas.** C'est le seul oracle qui dise
  qu'une source est juste ; tant que tout n'est pas recompilé, aucun gain de
  confort ne la vaut.

---

## Où trouver de l'aide sur une fonction

- **`sce*`** : [ps2sdk](https://github.com/ps2dev/ps2sdk) donne les prototypes
  et les structures. C'est une réimplémentation, donc sans valeur pour
  l'appariement, mais les types y sont justes.
- **`mg*`** : [DCDecomp](https://github.com/Adubbz/DCDecomp) porte le même
  middleware Level-5, sans le préfixe — `CFrame` pour notre `mgCFrame`. Ses
  en-têtes déclarent 16 des 45 méthodes de `mgCFrame`.
- **runtime Metrowerks** : les sources sont dans l'installateur CodeWarrior,
  sous `PS2_Support/Runtime/Sources/`. Elles sont propriétaires : à lire comme
  référence, jamais à copier dans le dépôt.
- **[decomp.wiki](https://decomp.wiki/)** pour la méthode générale, et
  [decomp.me](https://decomp.me) pour partager une fonction qui résiste.

---

## Annexe — retoucher le découpage

À ne lire que si une frontière d'unité est à corriger : le découpage couvre déjà
tout le code, et ces cas sont rares.

```sh
make units S=CAutoMapGen    # ce qu'une classe couvre, et ce qui l'entrecoupe
make carve                  # ce que le découpage automatique proposerait
make open S=CAutoMapGen     # ouvrir une plage à la main
```

`config/units.txt` est la seule pièce du découpage qui s'écrit à la main. Une
ligne y porte `<début> <fin> <secteur>/<nom> [rodata:<début>-<fin>]`.

Après toute modification : `make setup && make build`. **Ce `make build` est le
test.** Pas une ligne de C++ n'est écrite, donc le binaire doit être inchangé.

Trois pièges, dans l'ordre où on les rencontre :

- **la borne haute** vaut ce que l'objet produit — la fin de la dernière fonction
  quand celle-ci est écrite en C++, le début de la suivante quand elle est encore
  greffée. Le symptôme d'une erreur est franc : des `jal` dont la cible perd
  quatre octets, sur des centaines de plages ;
- **une table de saut doit voyager avec sa fonction**, ce que déclare le champ
  `rodata:`. `grep -c jlabel ref/asm/text/<secteur>/<unité>.s` le dit d'avance.
  La plage s'arrête exactement où la dernière table finit ;
- **une frontière de contribution d'objet l'emporte** sur une unité déclarée : le
  désassembleur tronque sans un mot celle qui l'enjambe, et le symptôme est un
  `INCLUDE_ASM` dont le fichier n'existe pas. `config/elf_sections.txt` les liste.

Et un réflexe : **devant une faute de segmentation au lien, sans message**,
`objdump -h` sur l'objet en cause tranche en une seconde — il lui manque une
section que le script réclame.
