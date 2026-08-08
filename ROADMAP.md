# Feuille de route

Ce qui reste entre l'état d'aujourd'hui et un code entièrement maîtrisé. Les
chiffres sont ceux du 5 août 2026 ; ils se refont par `make progress`,
`make carve` et `make report`.

Ce document dit aussi ce qui n'est pas mesuré. Une étape dont le coût n'a pas
été éprouvé le déclare — c'est ce qui la distingue d'une étape planifiée.

---

## L'état visé

« Maîtrisé » se décompose en quatre propriétés, qui ne s'obtiennent pas
ensemble et ne dépendent pas des mêmes travaux.

| Propriété | Ce qu'elle exige |
|---|---|
| **Lisible** | chaque fonction existe en C++ et le compilateur en rend les octets du disque |
| **Éditable** | changer un corps ne demande pas de retoucher le découpage |
| **Renommable** | un symbole se renomme sans que le lien ni le mangling s'en trouvent faux |
| **Sans contrainte de taille** | une fonction peut grossir, rétrécir ou disparaître, et le binaire reste cohérent |

La dernière est la plus lointaine et la moins évidente : elle ne tient pas à la
décompilation mais à ce qui reste adressé en dur.

---

## Où on en est

```
code reconstruit : 6 080 octets sur 2 215 100      0,274 %      32 fonctions
unités ouvertes  : 325, 2 208 852 octets           99,7 %    7 788 fonctions
```

Ce qui reste dehors : les 49 initialiseurs statiques, les microprogrammes
vectoriels et les données.

---

## Jalon 1 — Finir le découpage du texte

**Le compte passe de 72 unités à 325**, et `make build` rend les octets du disque.
`.text` est couvert à 99,7 % : il ne reste dehors que les 49 initialiseurs
statiques, et ceux-là ne sont pas du texte.

Le découpage ne s'arrête plus aux plages du jeu, et ce n'était pas un choix :
**le remplacement fonction par fonction demande un sous-segment `cpp` et un
`INCLUDE_ASM`, donc une fonction hors unité ne peut pas s'écrire en C++.** Le
jalon 4 réclamant le SDK, le runtime et la bibliothèque C, leur découpage en
était la condition. Le coût, mesuré, était bien moindre qu'estimé : les 988
fonctions restantes n'occupaient que 182 contributions d'objet, non 926.

`src/` se range désormais par provenance — `game/`, `sdk/`, `runtime/`,
`mglib/` —, et le nom d'une unité porte son dossier.

**Ce qui reste** :

- **Les 49 initialiseurs statiques `__sinit_*`**, 6 248 octets. Ce sont des
  `FUNC`, mais elles vivent après les données, en `0x00379680` : ouvertes en
  unité, le script de lien rangerait leur `.text` avec celui du jeu et tout ce
  qui les sépare des données glisserait. Le remède tient au jalon 3, où leur
  parcours par le runtime est déjà à établir.
- **`.vutext`**, 18 208 octets de microprogrammes vectoriels en six blocs
  d'octets. Aucun assembleur de la chaîne ne les relit. Il faudrait un
  désassembleur VU dédié ; rien n'y oblige tant qu'on ne veut pas les modifier.
- **Le classement par dossier est une heuristique** : il vote sur le poids des
  octets, et `cscriptinterpreter` rangé au middleware ou `csound` au SDK sont à
  revoir. `config/units.txt` est fait pour être corrigé à la main.
- **Les unités d'une seule fonction**, qu'une frontière de contribution isole ou
  que le resserrement d'une plage de lecture seule a détachées — 124 des 182
  contributions de bibliothèque sont dans ce cas, et c'est leur nature. Les
  réunir ne tient qu'à la lisibilité de `config/units.txt`.

**Non résolu, et c'est une limite du jalon 4 plus que de celui-ci** : MWCC aligne
sur seize octets la section de toute fonction qu'il *compile*, et mwccgap ne peut
rien y faire faute de connaître son adresse. Les treize auxiliaires du runtime que
les plages du jeu englobent — `__divdi3`, `fpmul`, `sitofp`, `__swsetup` — sont
donc ouverts mais devront rester greffés. La mesure vaut plus largement : **92 des
182 contributions de bibliothèque seulement commencent sur un multiple de seize**,
donc les 90 autres s'ouvrent sans pouvoir s'écrire tant que ce point tient.

**Critère de sortie** : chaque octet de `.text` appartient à une unité. Atteint,
aux initialiseurs statiques près — qui n'en sont pas.

---

## Jalon 2 — Découper les données

C'est le jalon dont dépend la liberté de taille. Son ampleur est désormais
mesurée, et sa difficulté n'est pas celle qu'on croyait.

**Le bss est fait.** Un sous-segment unique — `bss/0037CD80`, de la fin du
fichier à `0x01F64A00` — le couvre d'un seul tenant, et le compte des symboles
que le lien reçoit par adresse absolue passe de **2 503 à 55**. La couverture
devait être entière, le script de lien concaténant les `.bss` sans adresse : un
segment isolé n'atterrissait pas à la sienne, et rendait 1 327 plages
divergentes.

**La queue de `.vutext` est rendue aux données.** Un bloc vectoriel n'a pas de
symbole dimensionné, donc rien ne bornait son sous-segment : il courait jusqu'à la
contribution suivante. La borne juste est le premier symbole dimensionné qui le
suit — `0x0032A380` —, et le compte tombe à **51**.

**Les octets isolés sont typés.** Dix symboles d'un octet se suivent en
`0x00364548`, et le désassembleur n'étiquette qu'aux multiples de quatre quand il
rend une section en mots : `type:u8` les fait rendre en `.byte`, chacun sous son
`dlabel`. Sept seulement des 8 201 objets du binaire étaient dans ce cas.
`normalize.py` retire ensuite du script les symboles qu'une section définit —
splat les y laissait, sa règle étant `not s.defined` là où spimdisasm les écrit.

**Les deux queues de blocs vectoriels sont rendues aux données**, `.vutext` en
`0x0032A380` et `.vudata` en `0x00363580`, cette dernière emmenant quatre tables
de saut que la plage `rodata:0x00363660-0x003637B0` rend à `runtime/std`.

**Les noms en double sont écartés** — `configure.py` ne renomme plus une adresse
que `symbol_addrs.txt` nomme —, et **les blocs d'octets suivent leur objet** :
`normalize.py` pose `<nom> = .;` devant eux dans le script de lien, ce qui
rattache `Vu_progmain`, `Vu_prog_wtr` et `My_dma_start0` à la position que le
lien leur donne, au lieu de les figer.

Le compte tombe à **16 : les 15 fenêtres matérielles, et `_xlaunch`.**

**Le critère de sortie est donc atteint à un symbole près**, et celui-là est
mesuré. `_xlaunch` est une étiquette au milieu de `_kTLBException`, que le
binaire déclare `OBJECT` de taille nulle. `type:label` la fait poser par le
désassembleur, mais la construction diverge alors de six octets en `0x00118798` :
l'étiquette est locale à la section greffée, et son `%hi`/`%lo` ne se résout plus
comme le commerce l'encode. Le remède est du côté de mwccgap, qui répare les
relocations d'une section greffée — c'est là qu'il faudra regarder.

- **95 sous-segments `.rodata`, 147 `rodata` et 32 `data`** vivent hors de toute
  unité. Chacun devra rejoindre celle qui l'emploie, comme les plages de lecture
  seule déjà migrées — sans quoi une donnée renommée ou supprimée n'a pas de
  propriétaire.

**Critère de sortie** : `undefined_syms_auto.ld` ne porte plus que les six
fenêtres matérielles.

**Non mesuré** : le coût de rattacher chaque donnée à son unité. Les 8 201
symboles `OBJECT` du binaire disent leur taille, mais pas qui les emploie ;
l'établir demande de lire les relocations, ce qui n'a pas encore été outillé.

**Le point dur, et il est connu d'avance** : `_gp = 0x3846F0` tombe au milieu du
bss, et les 15 869 relocations `GPREL16` n'ont que ±32 Kio de fenêtre. Déplacer
la moindre petite donnée les casse, ce qui rattache ce jalon au verrou nº 2 du
suivant.

---

## Jalon 3 — Libérer les tailles

Une bonne nouvelle est déjà acquise : **le script de lien ne fixe qu'une seule
adresse**, `.main 0x100000`. Tout le reste est concaténé, et l'éditeur de liens
réajuste les relocations. La relocation du texte est donc en place — c'est ce
qui a rendu visible l'alignement à seize, puisqu'un décalage se propage.

Des trois verrous, **deux sont levés** — `_gp` est calculé, et le parcours des
initialiseurs statiques est établi. Reste la fenêtre de `$gp`, que le test de
croissance ne sollicite pas.

1. ~~**`_gp = 0x3846F0` est écrit en dur**~~ — **levé**. `normalize.py` le rend
   relatif à la fin du contenu du fichier, qui est aussi le début du bss :
   `_gp = main_BSS_START + 0x7970`, l'écart étant mesuré et non supposé. La
   valeur reste `0x003846F0` tant que rien ne bouge, ce que `make build`
   vérifie, et elle suivra sinon. `gp_value` reste en dur dans le découpage, et
   c'est autre chose : l'assembleur en a besoin pour réencoder les mêmes octets.
2. **La fenêtre de `$gp` ne porte que ±32 Kio**, et 15 869 relocations `GPREL16`
   s'y rapportent. Le symptôme est connu — « relocation truncated to fit » — et
   s'est déjà produit pour 32 octets manquants. Grossir les petites données au-delà
   de la fenêtre demandera de sortir des symboles du modèle `$gp`, donc de
   toucher `-sdatathreshold`, qui reste entier.
3. ~~**Comment le runtime parcourt les 49 initialiseurs statiques**~~ —
   **établi**, et la réponse lève le verrou. `mwInit` (`0x00100190`) appelle
   `__initialize_cpp_rts(début, fin, …)`, qui lit un pointeur, l'appelle par
   `jalr`, avance de quatre et boucle : c'est une **table de pointeurs**, les 49
   `_p__sinit_*` de `0x0037AFE0` à `0x0037B0A4`, distincte des corps
   `__sinit_*` qui vivent de `0x00379680` à `0x0037AFDC`.

   Ce qui compte pour la liberté de taille : **`mwInit` charge ses bornes par
   `%hi`/`%lo`**, donc ce sont des symboles que le lien reloge, non des
   constantes. Ajouter ou retirer une unité de traduction demande d'ajouter ou
   d'ôter son pointeur dans cette table ; la borne de fin suit d'elle-même.

   Reste que ces corps sont des `FUNC` situées après les données, et que le
   script de lien range tous les `.text` ensemble : les ouvrir en unité ferait
   glisser tout ce qui les sépare des données, jusqu'au débordement `%gp_rel`.
   C'est ce qui les tient hors du jalon 1, et c'est mesuré.

**Critère de sortie**, et c'est une mesure, non un raisonnement : faire grossir
une fonction d'une instruction, reconstruire, et vérifier que le jeu tourne dans
un émulateur. `make elf` et `make iso` produisent déjà de quoi le faire.

**La moitié en est acquise.** Sur `CGamePad::WaitEnable` : une instruction de plus
ne change rien — l'alignement à seize de MWCC l'absorbe —, mais treize déplacent
tout, et proprement. Le texte finit en `0x00325CE0` au lieu de `0x00325C80`, le
binaire fait 2 608 608 octets, **`_gp` suit de lui-même** à `0x00384750`, et le
lien ne signale aucun débordement `%gp_rel`. Reste l'émulateur.

Le test fait grossir le *texte*, qui pousse les petites données avec `_gp` : la
fenêtre de ±32 Kio n'est donc pas éprouvée, et ne le sera qu'en grossissant
`.sdata` elle-même.

**Non mesuré** : ce qu'un texte plus long fait à la disposition mémoire de la
console. Le bss va jusqu'à `0x01F64A00` et le tas commence après ; il y a de la
marge, mais elle n'a pas été chiffrée.

---

## Jalon 4 — Recompiler

C'est le gros du travail, et le seul qui se compte en années-personnes : 7 837
fonctions, 32 faites.

**Par où** — le rapport trie déjà les fonctions par taille dans chaque unité,
et c'est l'ordre le plus rentable. Deux réserves :

- une classe se reconstruit mieux d'un bloc que fonction par fonction : la
  disposition d'une structure, une fois établie, sert toutes ses méthodes, et
  un type de champ faux se paye sur chacune ;
- une fonction qui saute par table demande sa plage `rodata:` et se
  reconstruit d'un coup.

**Ce qu'il faut construire à côté du code** :

- **Les en-têtes.** `CGameDataUsed`, `CBaseMenuClass`, `MENU_SYS_DATA` n'ont
  aujourd'hui que les champs qu'une fonction appariée a exigés. Chaque
  disposition établie est un acquis réutilisable ; chaque champ deviné est une
  dette. La règle du dépôt vaut ici plus qu'ailleurs : ne pas surinterpréter,
  et dire dans le code ce qui n'est pas prouvé.
- **Le runtime Metrowerks**, 48 228 octets, dont 2 264 correspondent à des
  sources présentes dans l'installateur CodeWarrior — à réécrire d'après elles,
  non à recopier.
- **La bibliothèque C** (`MSLGCC_PS2.LIB`), fournie compilée : `memcpy`,
  `sprintf`, `_dtoa` restent à décompiler entièrement.
- **Le SDK Sony**, 127 688 octets. `ps2sdk` en donne les prototypes et les
  structures exacts, ce qui est la moitié du travail, mais son code est une
  réimplémentation et n'apparie pas.
- **Le middleware `mg*`**, 95 680 octets, partagé avec Dark Cloud 1 : ce sont
  les signatures qui se transposent depuis DCDecomp, pas les implémentations.

**Les drapeaux non éprouvés** — `-inline`, `-enum`, `-RTTI` n'ont rien changé
sur le code déjà apparié, mais celui-ci n'exerce ni patrons ni fonctions
virtuelles. Le premier code à en porter les tranchera.

---

## Jalon 5 — Renommer

Le renommage est le dernier, parce qu'il dépend de tous les autres : tant
qu'une fonction est greffée, son nom est celui que le binaire porte, et le
changer casse la greffe.

- **1 293 noms désignent plusieurs adresses**, tous à liaison locale. Le
  découpage les départage aujourd'hui par leur adresse ; une fois l'unité
  reconstruite, le `static` d'origine les rend de nouveau distincts et le
  suffixe disparaît.
- **Le nom des unités elles-mêmes** est à revoir à mesure qu'on les comprend :
  `make carve` les nomme d'après leur classe la plus lourde, ce qui range
  `InitDungeonMain` dans `cdamagescore`. C'est un point de départ, pas une
  conclusion, et `config/units.txt` est fait pour être corrigé à la main.
- **`jtbl_00377F10`** est le seul endroit où le projet s'écarte du nom que le
  binaire porte, parce que m2c l'exige. À reverser une fois la fonction écrite.

---

## Outillage

Par ordre de ce que chacun débloque.

| Chantier | Ce qu'il débloque |
|---|---|
| **Relever qui emploie chaque donnée, par les relocations** | le jalon 2 en entier |
| **mwccgap : abaisser l'alignement d'une fonction compilée** | les treize auxiliaires du runtime, qui ne peuvent qu'être greffés |
| **Un test d'exécution en émulateur** | le critère de sortie du jalon 3 |
| **Intégration continue** | la non-régression de `make build`, aujourd'hui vérifiée à la main |
| **`make carve` : réunir une unité d'une fonction à sa voisine** | la lisibilité de `config/units.txt` |

`tools/patches/` porte ce que le projet corrige dans les outils tiers, `make patch`
le pose, et `make patch PATCH_ARGS=--update` le réécrit depuis l'état du
sous-module. Un commit ne retient d'un sous-module que sa référence : le correctif
est ce qui se versionne, et son en-tête dit ce qu'il y aurait à reverser en amont.

Un prédicat sur ce que fait le désassembleur s'éprouve contre `asm/nonmatchings/`,
non contre une reconstruction : la comparaison coûte une seconde là où
`make setup && make build` en coûte un quart d'heure. C'est ce qui a trouvé le
troisième terme de la règle de migration, et deux erreurs de lecture de la
référence avec lui.

`scripts/setup/normalize.py` est une rustine assumée : il corrige après coup ce
que le désassembleur écrit autrement pour les fonctions greffées. Il disparaîtra
si splat rend l'accumulateur vectoriel avec son dollar dans les deux chemins.

Les deux outils de recherche gardent leurs rôles distincts : `make measure`
répond à une question posée, `make permute` cherche seul quand on ne sait plus
quoi essayer.

---

## Transverse

- **Passer le dépôt en public et l'inscrire sur decomp.dev.** Le rapport est
  déjà au format attendu ; l'inscription se fait une fois à la main sur
  `/manage/new`, et le service lit un artefact d'intégration continue nommé
  `<EXÉCUTABLE>_report`. Notre règle interdisant de publier le désassemblage, il
  faudra publier le rapport seul — c'est un choix, non une contrainte.
- **Le rapprochement avec DCDecomp** sur le middleware `mg*`.
- **Questions restées ouvertes** : la liaison 13 que portent 193 `FUNC` et 27
  `OBJECT` ; `.mwcats`, 56 392 octets propres à Metrowerks ; `-sdatathreshold`.
- **Retrouver les 49 unités de traduction d'origine.** Le découpage actuel ne
  le prétend pas. Les pistes non éprouvées restent l'appariement avec `.rodata`,
  l'ordre des `__sinit_` et le couplage des appels.

---

## Ordre et dépendances

```
Jalon 1 (texte) ──┬─→ Jalon 4 (recompiler) ──→ Jalon 5 (renommer)
                  │
Jalon 2 (données) ┴─→ Jalon 3 (tailles libres)
```

Les jalons 1 et 2 sont indépendants et peuvent avancer en parallèle. Le jalon 4
est le seul qui n'a pas de fin proche : il se mesure, il ne se planifie pas. Le
jalon 3 est celui que vous visez, et il ne demande pas que tout soit recompilé —
seulement que plus rien ne soit adressé en dur.

Le jalon 1 borne de moins en moins le jalon 4 : une fonction qui vit dans une
unité peut s'écrire sans que le découpage soit à refaire, et c'est le cas de la
grande majorité de celles du jeu.
