# Feuille de route

Ce qui reste entre l'état d'aujourd'hui et un code entièrement maîtrisé. Les
chiffres sont ceux du 2 septembre 2026 ; ils se refont par `make etat` (une
demi-seconde), `make report`, `make carve`.

Ce document dit aussi ce qui n'est pas mesuré, et ce qui a été mesuré puis
démenti. Une étape dont le coût n'a pas été éprouvé le déclare — c'est ce qui la
distingue d'une étape planifiée.

**L'horizon est de dix ans, et c'est assumé.** Ce plan ne cherche donc pas un
levier qui multiplierait la cadence par cinq : aucun n'a résisté à la mesure. Il
cherche une méthode sans impasse, applicable fonction après fonction, dont le
rendement s'améliore à mesure que le corpus d'idiomes s'enrichit.

---

## Où on en est

```
fonctions connues     7 840        2 215 100 octets
écrites en C++          457 (5,83 %)   16 904 o   0,763 %
greffées              7 334        2 191 948 o
hors unité               49            6 248 o   (les __sinit_*)
```

| Provenance | fn | octets | part |
|---|---|---|---|
| `game` | 5 647 | 1 860 120 | 84,9 % |
| `sdk` | 905 | 142 304 | 6,5 % |
| `mglib` | 555 | 108 348 | 4,9 % |
| `runtime` | 227 | 81 176 | 3,7 % |

Deux distributions décident de l'ordre du travail :

- **Par taille** — 3 769 fonctions ≤ 128 o ne pèsent que **11 %** des octets ;
  les **410 fonctions > 1 Ko en pèsent 41 %**.
- **Par nature** — 2 858 méthodes sur **288 classes** (926 816 o), et **4 477
  fonctions libres ou statiques** (1 265 288 o). Les fonctions libres pèsent
  plus que toutes les classes réunies ; 67 classes seulement portent plus de dix
  méthodes.

---

## La méthode, et c'est le cœur du plan

**Une fonction se reconstruit en quatre gestes, et le troisième est le seul qui
demande un humain.**

1. **`make decompile S=…`** donne un premier jet. m2c lit le désassemblage,
   infère les structures, nomme les variables. Son résultat n'est pas juste,
   mais il est lisible et proche.
2. **La normalisation** rend ce jet compilable : `this` renommé, structures
   inférées posées, déclarations complétées depuis la table des symboles,
   champs non typés traduits par leur largeur. `scripts/diff/sonde_m2c.py` fait
   ce travail et dit où il bute.
3. **La correction des idiomes** — c'est ici que tout se joue. Le jet est
   typiquement à 90 %, et l'écart tient à deux ou trois formes que MWCC rend
   autrement. `docs/IDIOMES_MWCC.md` en porte une trentaine, chacune avec sa
   fonction témoin et son chiffre.
4. **`make diff S=…`** tranche, en 4,8 s. Puis `make ci` sur l'ensemble.

**Ce que cela vaut, mesuré de bout en bout** : `CScene::SearchCharaTexb`, 156
octets, jet m2c à **93,21 %**, deux corrections d'idiome, **100 %**, `make ci`
identique au disque. Les deux corrections étaient : *deux sorties identiques
s'écrivent deux fois*, et *une valeur employée dans une boucle s'y calcule*.
Toutes deux sont maintenant dans `CLAUDE.md`, et serviront à toutes les
suivantes.

**C'est le seul progrès qui compose.** Un idiome trouvé une fois épargne du
temps sur toutes les fonctions qui le portent. C'est ce qui rend un horizon de
dix ans praticable là où la force brute ne l'est pas.

---

## Ce que la mesure a démenti, et qu'il ne faut pas refaire

Quatre voies ont été outillées puis mesurées. Deux ne produisent pas, et les
inscrire ici évite de les rouvrir.

**La chaîne entièrement automatique ne produit que sur les petites fonctions.**
Elle gagne 10,8 % des fonctions de 32 à 64 octets et **rien au-delà de 512** ;
le détail est plus bas. Sur les moyennes, quatre-vingts pour cent des jets ne
compilent pas, et les causes sont hétérogènes — aucune ne domine, chacune
demande son diagnostic. m2c lui-même renonce sur un sur six.

**Le permuteur ne rattrape pas un jet m2c.** Sur la meilleure candidate, **121
essais n'ont pas bougé de 93,21 %** : l'écart était un décalage de branchement
dans une boucle, hors de portée de ses vingt-neuf transformations. Le permuteur
garde sa valeur là où il l'a prouvée — une allocation de registres sur du code
déjà juste —, pas comme finisseur.

**Un contexte partiel rend m2c moins bon que pas de contexte du tout.** Sans
contexte, il infère un type entier et en émet la déclaration ; avec une version
incomplète — structure vide, structure partielle, ou même un simple `typedef`
opaque —, il s'en sert *et* invente un `unkXX` que rien ne définit. Mesuré sur
trente fonctions : **3 compilent sans contexte, 1 avec**. `build/ctx.c` n'est
donc plus engendré par défaut.

**Une mesure par fonction peut mentir.** objdiff compare l'objet compilé au
commerce ; si la pose échoue, l'unité compile son propre assembleur et le score
rend 100 %. Une collision de nom de variable a suffi à produire quarante-quatre
faux gains d'affilée. `eprouve` refuse désormais de scorer une fonction dont
l'`INCLUDE_ASM` est encore là.

---

## Acquis — les outils

| | avant | après |
|---|---|---|
| `make diff S=…` | 15,4 s | **4,8 s** |
| `make build` complet | 7 min 49 s | **1 min 10 s** |
| une unité recompilée | — | 2,1 s + 8,5 ms par greffe |
| `make etat` / `make controle` | n'existait pas | **0,5 s, sur l'hôte** |

- **La mesure est honnête et gratuite.** `make etat` sépare l'écrit du greffé et
  tombe sur le même compte que `make report` par un chemin indépendant ;
  `progress/journal.jsonl` garde la cadence jour par jour.
- **La non-régression tient.** `make ci` enchaîne six contrôles textuels et la
  construction ; `.githooks/pre-push` la lance avant toute poussée. Aucun
  service distant ne peut le faire — il lui faudrait le binaire du commerce.
- **`make atlas`** relève ce que m2c infère des 325 unités et le fusionne :
  **369 types, 6 901 champs, 7,9 % de contradictions**, 65 des 67 classes de
  plus de dix méthodes couvertes. Sa place est dans les en-têtes du projet, pas
  dans le contexte de m2c.
- **`make injecte`** verse ces champs dans les classes déclarées vides. Mesuré :
  quarante-cinq champs posés dans `CMap` laissent `Iam__4CMapFv` à 100 %. Une
  disposition ne change les octets que si le code l'emploie — sauf pour une
  classe de base, dont l'élargissement décale ses dérivées.
- **`scripts/diff/petites.py`**, le traducteur déterministe, a produit **158
  fonctions** vérifiées. C'est la seule voie entièrement automatique qui ait
  jamais rien donné.

---

## Ce que la moisson automatique peut, et où elle s'arrête

`make chaine` passe m2c sur chaque fonction greffée, normalise, compile, mesure,
et **ne garde que ce qui rend exactement les octets du disque**. Elle coûte 3,1 s
par fonction et tourne sans surveillance. Son rendement a été mesuré sur 1 320
fonctions, et il s'effondre avec la taille :

| tranche | éprouvées | gagnées | taux |
|---|---|---|---|
| 32–64 o | 231 | 25 | **10,8 %** |
| 64–128 o | 339 | 11 | 3,2 % |
| 128–256 o | 309 | 2 | 0,6 % |
| 256–512 o | 165 | 1 | 0,6 % |
| 512–1024 o | 75 | **0** | **0 %** |
| 1024–2048 o | 29 | **0** | **0 %** |

**Au-delà de 512 octets, elle ne gagne rien** — et c'est là que sont 59 % des
octets restants (970 fonctions). Extrapolée sur tout le binaire, la moisson
plafonne à :

```
+161 fonctions,  +12 300 octets
709 / 7 840 fonctions = 9,0 %      des octets = 1,74 %
```

**C'est une passe finie.** Une fois qu'elle a traversé les 7 300 fonctions, il
n'y a plus rien à en tirer : les mêmes échoueront aux mêmes endroits. Elle ne se
relance que sur ce qu'une correction de la normalisation vient de débloquer.

Ce qu'elle laisse derrière elle vaut autant que ce qu'elle gagne : **99 fonctions
qui compilent sans apparier**, dont 41 au-dessus de 90 % et 27 au-dessus de
95 %. C'est le vivier de l'étape 2, et le moyen le moins cher d'enrichir le
corpus.

---

## Étape 1 — Épuiser le traducteur déterministe

La seule voie qui produit sans intervention. Elle n'atteint que les fonctions
sans pile ni branchement, mais elle les prend toutes.

`petites.py resume --secteur tout --mini 8 --maxi 255` classe les refus par
motif : on lève le plus lourd, on relance, on mesure. Restent, chiffrés :

- les **appels terminaux dont la cible est manglée** (~124 fn) — la signature se
  lit du mangling, il suffit d'y recourir au lieu de la table figée de trois
  entrées ;
- les **instructions arithmétiques simples** — `slt`, `andi`, `sll`, somme de
  deux registres (~150 fn) ;
- les **arguments au-delà du quatrième** (99 fn).

**On s'arrête aux branchements et à la pile** : 3 131 refus « registre `sp` sans
provenance » et ~430 refus de branchement sont le domaine de m2c. Les traiter
ici serait réécrire un décompilateur, et c'est la frontière de l'étape.

**Sortie attendue** : quelques centaines de fonctions, quelques milliers
d'octets. Certain, mais ne déplace pas la courbe des octets — c'est admis.

---

## Étape 2 — Le corpus d'idiomes

C'est l'étape qui rend les huit suivantes praticables, et la seule dont le
rendement croît avec le temps.

**La règle de travail, mesurée sur `CSphida::SetUp`** : compter d'abord sur le
désassemblage entier. Une propriété supposée du compilateur se vérifie en une
seconde sur des milliers de sites ; c'est ce qui a débloqué cette fonction là où
450 essais du permuteur avaient échoué.

**Le cycle** : reconstruire une fonction à la main depuis son jet m2c ; quand
l'écart résiste, en faire une question ; la trancher sur le désassemblage
entier ou par `make measure` ; consigner la réponse dans `docs/IDIOMES_MWCC.md`
avec sa fonction témoin et son chiffre.

**Ce qui vaut la peine d'être outillé** : appliquer automatiquement les idiomes
déjà connus au jet de m2c, avant de le donner à l'humain. Sortir un calcul de
boucle, dédoubler une sortie, retourner une comparaison flottante — chacun est
une transformation mécanique. C'est le seul endroit où l'automatisation a encore
une chance, et elle se mesure au taux de la sonde.

---

## Étape 3 — Le travail de fond, par classe puis par poids

C'est ici que passent les années, et c'est la seule étape qui se mesure sans se
planifier.

**Par classe d'abord**, tant qu'il en reste de lourdes : la disposition
s'établit une fois et sert toutes les méthodes. Dix classes font 31 % des octets
de classe, vingt-cinq 52 %, cinquante 71 %, cent 86 %. L'atlas donne le point de
départ, `make injecte` le pose, les vrais noms se substituent à mesure qu'on
comprend.

**Puis par poids** : les 410 fonctions de plus de 1 Ko, 41 % des octets
restants. Pas de disposition à établir, mais du graphe de contrôle — le terrain
de `make measure` et des idiomes.

L'ordre entre les deux n'est pas rigide : une classe lourde contient souvent de
grosses fonctions, et les traiter ensemble évite de rouvrir sa disposition.

---

## Étape 4 — Les chantiers indépendants

Aucun ne dépend des trois premiers. Ce sont les portes d'entrée naturelles pour
un contributeur, si le dépôt s'ouvre.

**4.1 Les tables virtuelles.** Dès qu'une classe est déclarée polymorphe — ce
que le commerce impose pour retrouver l'ordonnancement d'un constructeur —, MWCC
émet `__vt__<classe>` dans notre objet et le lien la voit deux fois. Le chemin
est repéré : une clé `vtables:` dans `config/units.txt`, un segment qui retire
ces octets du bloc brut de `00379358`, et la ligne `(.vtables)` posée par
`normalize.py`. `__ct__14CCameraControlFv` est reconstruit à 100 % et attend
cela sous un `#if 0`.

**4.2 Les bibliothèques externes**, 332 Ko et un oracle extérieur : le runtime
Metrowerks (81 176 o, dont 2 264 ont leur source dans l'installateur
CodeWarrior), la MSL C (`memcpy`, `sprintf`, `_dtoa`), le SDK Sony (142 304 o —
`ps2sdk` donne les prototypes exacts, mais son code n'apparie pas), le
middleware `mg*` (108 348 o, signatures transposables depuis DCDecomp). **Un
chiffre les désigne** : sur les 831 fonctions que le traducteur refuse pour
cause de mangling, **381 sont des noms C purs** — `abort`, `atof`, `fabsf` — qui
n'ont pas de signature manglée et n'en auront jamais.

---

## Étape 5 — La cohérence finale

Ces tâches ne peuvent pas précéder la recompilation.

**Les données.** Le bss est fait ; les symboles livrés au lien par adresse
absolue sont passés de 2 503 à **16 : les quinze fenêtres matérielles et
`_xlaunch`**. Ce dernier est une étiquette au milieu de `_kTLBException` que le
binaire déclare `OBJECT` de taille nulle ; le remède est du côté de mwccgap, qui
répare les relocations d'une section greffée. **Restent 95 sous-segments
`.rodata`, 147 `rodata` et 32 `data`** hors de toute unité ; les rattacher
demande de relever qui emploie chaque donnée par les relocations, ce qui n'est
pas outillé.

**Les tailles.** Deux verrous sur trois sont levés : `_gp` est calculé
(`main_BSS_START + 0x7970`), et le parcours des 49 initialiseurs statiques est
établi — `mwInit` charge ses bornes par `%hi`/`%lo`, ce sont des symboles que le
lien reloge. Le troisième est **mesuré et ne sera pas levé** : la fenêtre de
`$gp` n'a que seize octets de marge en bas et 56 347 inutilisés en haut ;
recentrer `_gp` changerait les octets que le lien encode, et l'identité au
disque est le seul oracle qui dise qu'une source est juste. Les petites données
ne peuvent donc pas grossir de plus de seize octets ; le texte, lui, est libre.
`pack.py` sait déjà porter un exécutable agrandi jusqu'à l'image, qui a 524
octets de marge.

**Les 49 `__sinit_*`**, 6 248 o, vivent après les données : les ouvrir en unité
ferait glisser tout ce qui les en sépare jusqu'au débordement `%gp_rel`.

**Le renommage** vient en dernier : 1 293 noms désignent plusieurs adresses,
tous à liaison locale, et le `static` d'origine les redistinguera une fois
l'unité reconstruite. `jtbl_00377F10` est le seul endroit où le projet s'écarte
du nom du binaire, parce que m2c l'exige ; à reverser.

**Le critère de sortie du projet** reste une mesure : faire grossir une fonction
d'une instruction, reconstruire, et vérifier que le jeu tourne dans un
émulateur. Tout est acquis sauf l'émulateur — treize instructions de plus sur
`CGamePad::WaitEnable` déplacent tout proprement, `_gp` suit de lui-même, et le
lien ne signale aucun débordement.

---

## Ordre et dépendances

```
Étape 1 (traducteur déterministe) ──┐
Étape 2 (idiomes) ──────────────────┼──→ Étape 3 (le fond) ──→ Étape 5
Étape 4.1 (vtables) ────────────────┘                          ↑
Étape 4.2 (bibliothèques) ─────────────────────────────────────┘
```

Les étapes 1 et 2 se mènent de front : la première produit sans surveillance, la
seconde s'enrichit de chaque fonction reconstruite à la main. L'étape 4 ne
dépend de rien.

---

## Outillage

| Chantier | Ce qu'il débloque |
|---|---|
| **Appliquer les idiomes connus au jet de m2c** | l'étape 2, et le seul reste d'automatisation crédible |
| **Posséder les tables virtuelles** | tout constructeur de classe polymorphe |
| **Relever qui emploie chaque donnée, par les relocations** | l'étape 5 |
| **mwccgap : abaisser l'alignement d'une fonction compilée** | les treize auxiliaires du runtime |
| **mwccgap : réparer les relocations d'une section greffée** | `_xlaunch`, dernier symbole absolu |
| **Un test d'exécution en émulateur** | le critère de sortie du projet |
| ~~Intégration continue~~ | **fait** — `make ci`, `.githooks/pre-push` |
| ~~Boucle de mesure courte~~ | **fait** — 4,8 s |
| ~~Atlas des types~~ | **fait** — `make atlas`, `make injecte` |

`make measure` répond à une question posée ; `make permute` cherche seul quand
on ne sait plus quoi demander, sur du code déjà juste ; `make etat` dit où en est
le compte ; `essai_petites.py` dit si un plan compile, en deux minutes. Un
prédicat sur le désassembleur s'éprouve contre `asm/nonmatchings/`, non contre
une reconstruction.

---

## Transverse

- **Passer le dépôt en public et l'inscrire sur decomp.dev.** Le rapport est au
  format attendu. Notre règle interdisant de publier le désassemblage, il faudra
  publier le rapport seul. C'est le préalable à tout contributeur, et la CI est
  désormais là.
- **Le rapprochement avec DCDecomp** sur le middleware `mg*`.
- **Questions ouvertes** : la liaison 13 que portent 193 `FUNC` et 27 `OBJECT` ;
  `.mwcats`, 56 392 octets propres à Metrowerks ; `-sdatathreshold` ; la
  compression du mangling que `P1P1i` révèle et que le démangleur lit mal.
- **Retrouver les 49 unités de traduction d'origine.** Le découpage actuel ne le
  prétend pas. Pistes non éprouvées : l'appariement avec `.rodata`, l'ordre des
  `__sinit_`, le couplage des appels.

---

## Ce qu'il faut se dire franchement

**Le rythme est de 574 octets par jour, et aucune des voies mesurées ne le
change d'un ordre de grandeur.** À ce compte, le binaire est reconstruit vers
2037. C'est l'horizon retenu.

Ce qui peut l'améliorer n'est pas un outil mais une accumulation : chaque idiome
consigné rend les fonctions suivantes plus rapides, et il en reste beaucoup à
trouver — les trente d'aujourd'hui ont été payés une par une. C'est un rendement
qui croît lentement mais qui ne redescend jamais.

**Deux choses seraient décisives et ne dépendent pas de la technique :**
l'ouverture à des contributeurs, dont l'étape 4 offre deux portes d'entrée sans
lien avec le chemin principal ; et le maintien de la discipline de mesure —
cette session a produit quarante-quatre faux gains avant qu'une garde ne les
arrête, et trois voies outillées avant d'être mesurées.

**La règle qui résume tout** : ne jamais construire plus de deux itérations sur
une hypothèse qu'aucun chiffre n'a confirmée.

---

## Prochaine action concrète

Reconstruire cinq à dix fonctions à la main depuis leur jet m2c, en notant
chaque idiome rencontré. C'est ce qui dira si les 93 % de `SearchCharaTexb` sont
représentatifs, et cela produit des fonctions en même temps que du corpus.

En parallèle, lever le premier blocage du traducteur déterministe — les appels
terminaux dont la cible est manglée, 124 fonctions dont la signature est déjà
dans le binaire.
