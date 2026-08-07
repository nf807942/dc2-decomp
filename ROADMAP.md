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
unités ouvertes  : 144, 2 027 016 octets           91,5 %    6 849 fonctions
```

Ce qui reste dehors : le code de bibliothèque, les microprogrammes vectoriels et
les données.

---

## Jalon 1 — Finir le découpage du texte

**Le compte passe de 72 unités à 144**, et `make build` rend les octets du disque.
Cinq causes ont été levées : trois dans mwccgap, portées par
`tools/patches/mwccgap-alignment.patch` — l'alignement d'une section greffée pris
de l'adresse du symbole, l'ordre des tables de saut pris de leurs adresses, et la
recherche d'une section par le symbole qui l'a déclarée —, une dans le découpage,
qui ignorait les frontières de contribution d'objet, et une dernière dans la
largeur des plages de lecture seule.

**Tout le code du jeu est ouvert** : les seize unités que leur plage retenait ont
été redécoupées à une table de saut par unité, ce qui réduit chacune à sa seule
table. Elles font 51 unités, 383 588 octets, et le prix de cette finesse est une
médiane à 5 980 octets et six unités d'une seule fonction — mesuré, et payé en
lisibilité de `config/units.txt`, non en exactitude.

**Ce qui reste** :

- **Le code de bibliothèque** — 926 fonctions. L'alignement ne les borne plus,
  mais **chacune est sa propre contribution d'objet**, et le désassembleur en fait
  un sous-segment : une unité ne peut pas en réunir deux. Ce serait donc 926 unités
  d'une fonction. Ce que le découpage y gagnerait est à peser avant de le faire ;
  c'est du code livré compilé, sans valeur de compréhension pour le jeu.
- **`.vutext`**, 18 208 octets de microprogrammes vectoriels en six blocs
  d'octets. Aucun assembleur de la chaîne ne les relit. Il faudrait un
  désassembleur VU dédié ; rien n'y oblige tant qu'on ne veut pas les modifier.
- **Vingt unités d'une seule fonction**, qu'une frontière de contribution isole
  ou que le resserrement d'une plage de lecture seule a détachées. Elles sont
  justes ; les réunir à leur voisine ne tient qu'à la lisibilité de
  `config/units.txt`.

**Non résolu, et c'est une limite du jalon 4 plus que de celui-ci** : MWCC aligne
sur seize octets la section de toute fonction qu'il *compile*, et mwccgap ne peut
rien y faire faute de connaître son adresse. Les treize auxiliaires du runtime que
les plages du jeu englobent — `__divdi3`, `fpmul`, `sitofp`, `__swsetup` — sont
donc ouverts mais devront rester greffés.

**Critère de sortie** : chaque octet de `.text` appartient à une unité.

---

## Jalon 2 — Découper les données

C'est le jalon dont dépend la liberté de taille, et le seul dont l'ampleur n'a
pas encore été mesurée.

- **2 448 symboles du bss sont donnés par adresse absolue** dans
  `linker_scripts/auto/undefined_syms_auto.ld`. Tant qu'ils y sont, aucune
  donnée ne peut bouger : le lien les place où le binaire d'origine les avait,
  et un texte plus long viendrait les recouvrir. Il faut les faire définir par
  des segments `bss` déclarés, ce que splat sait faire.
- **87 sous-segments `rodata` et 32 `data`** vivent hors de toute unité. Chacun
  devra rejoindre celle qui l'emploie, comme les 27 plages de lecture seule
  déjà migrées — sans quoi une donnée renommée ou supprimée n'a pas de propriétaire.
- **6 symboles sous l'adresse de chargement** sont des fenêtres matérielles
  (`0xFFFF`, `0x12000`…). Ceux-là restent absolus : c'est leur nature.
- **49 symboles hors des plages connues**, dont les points d'entrée `.vutext`.
  À rattacher au fur et à mesure.

**Critère de sortie** : `undefined_syms_auto.ld` ne porte plus que les fenêtres
matérielles.

**Non mesuré** : le coût de rattacher chaque donnée à son unité. Les 8 201
symboles `OBJECT` du binaire disent leur taille, mais pas qui les emploie ;
l'établir demande de lire les relocations, ce qui n'a pas encore été outillé.

---

## Jalon 3 — Libérer les tailles

Une bonne nouvelle est déjà acquise : **le script de lien ne fixe qu'une seule
adresse**, `.main 0x100000`. Tout le reste est concaténé, et l'éditeur de liens
réajuste les relocations. La relocation du texte est donc en place — c'est ce
qui a rendu visible l'alignement à seize, puisqu'un décalage se propage.

Restent trois verrous, dans l'ordre où ils se lèveront :

1. **`_gp = 0x3846F0` est écrit en dur** dans le script de lien. Il désigne le
   milieu des petites données ; si celles-ci bougent, il doit suivre. Une ligne
   à rendre calculée.
2. **La fenêtre de `$gp` ne porte que ±32 Kio**, et 15 869 relocations `GPREL16`
   s'y rapportent. Le symptôme est connu — « relocation truncated to fit » — et
   s'est déjà produit pour 32 octets manquants. Grossir les petites données au-delà
   de la fenêtre demandera de sortir des symboles du modèle `$gp`, donc de
   toucher `-sdatathreshold`, qui reste entier.
3. **Les 49 initialiseurs statiques `__sinit_*`** occupent une plage contiguë de
   `0x00379680` à `0x0037AFDC`. Comment le runtime les parcourt — table de
   pointeurs, bornes de section, suite d'appels — n'est pas établi. À trancher
   avant de supprimer ou d'ajouter une unité de traduction.

**Critère de sortie**, et c'est une mesure, non un raisonnement : faire grossir
une fonction d'une instruction, reconstruire, et vérifier que le jeu tourne dans
un émulateur. `make elf` et `make iso` produisent déjà de quoi le faire.

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
