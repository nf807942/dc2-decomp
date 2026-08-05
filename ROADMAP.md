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
code reconstruit : 6 080 octets sur 2 215 100      0,275 %      32 fonctions
unités ouvertes  : 72, 1 417 600 octets            64,0 %    5 072 fonctions
code du jeu ouvert : 5 070 fonctions sur 6 847     74 %        69,9 % des octets
```

Le découpage compte 213 sous-segments encore en assembleur, 72 confiés à une
source, 87 `rodata`, 32 `data`, 27 plages de lecture seule migrées avec leur
unité et 6 blocs d'octets vectoriels.

---

## Jalon 1 — Finir le découpage du texte

**Ce qui manque** : 26 % des fonctions du jeu et tout le code de bibliothèque.

- **25 unités que `make carve` écarte.** Leur plage de lecture seule ne tient
  pas les conditions établies : symboles qui ne se touchent pas, tables rangées
  à l'inverse des fonctions qu'elles servent. Deux voies, et la première est la
  bonne : faire greffer à mwccgap le remplissage entre symboles migrés
  (→ *Outillage*), ou couper l'unité plus finement pour qu'elle n'emmène qu'une
  table. La seconde multiplie les unités sans rien apprendre.
- **13 fonctions du jeu qu'un multiple de seize ne commence pas.** Elles restent
  en assembleur entre deux unités. Écrites en C++, la contrainte tombe d'elle-même,
  le compilateur ne s'alignant que sur ce qu'il produit. C'est donc un travail de
  décompilation, non de découpage.
- **Le code de bibliothèque** — 926 fonctions, dont 541 seulement alignées sur
  seize. Peu découpable tant que l'alignement des sections de mwccgap n'est pas
  réglé. À traiter après le jeu : c'est du code livré compilé, sans valeur de
  compréhension pour le jeu lui-même.
- **`.vutext`**, 18 208 octets de microprogrammes vectoriels en six blocs
  d'octets. Aucun assembleur de la chaîne ne les relit. Il faudrait un
  désassembleur VU dédié ; rien n'y oblige tant qu'on ne veut pas les modifier.

**Critère de sortie** : chaque octet de `.text` appartient à une unité, et
`make build` reste identique au disque.

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
| **mwccgap : rendre le remplissage entre symboles de lecture seule migrés** | les 25 unités écartées du jalon 1 |
| **mwccgap : abaisser l'alignement des sections de fonction** | le code de bibliothèque, et les 13 fonctions du jeu |
| **Relever qui emploie chaque donnée, par les relocations** | le jalon 2 en entier |
| **`make carve` : coupures plus fines autour des tables** | quelques unités du jalon 1, sans attendre mwccgap |
| **Un test d'exécution en émulateur** | le critère de sortie du jalon 3 |
| **Intégration continue** | la non-régression de `make build`, aujourd'hui vérifiée à la main |

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
