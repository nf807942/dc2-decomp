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
et **ne garde que ce qui rend exactement les octets du disque** — la
reconstruction complète du binaire est vérifiée après chaque unité productive,
et l'unité revient à son état d'entrée si le sha1 diverge. Elle tourne sans
surveillance, reprend après coupure, et enregistre la *cause* de chaque échec
avec la ligne que MWCC désigne.

### Son rendement s'effondre avec la taille, et c'est mesuré

| tranche | jugées | compilent | gagnées | rendement | médiane d'appariement |
|---|---|---|---|---|---|
| 32–63 o | 815 | 464 | 220 | **27 %** | 99,6 % |
| 64–127 o | 1 410 | 675 | 135 | **9,6 %** | 87,7 % |
| 128–255 o | 1 343 | 484 | 39 | **2,9 %** | 84,1 % |
| 256–511 o | 762 | 155 | 3 | **0,4 %** | 74,0 % |
| 512 o et plus | 16 | 1 | 0 | **0 %** | — |

Appliqué aux octets qui restent, cela **plafonne la moisson vers 4 % du
binaire**. Ce n'est pas une machine à décompiler le jeu : c'est une machine à
mettre des fonctions *sous mesure*.

### Où sont réellement les octets qui restent

| ce qui reste | octets | part | technique qui s'applique |
|---|---|---|---|
| moins de 512 o | 849 260 | 39 % | la moisson, puis l'affinage |
| **plus de 512 o (970 fn)** | **1 300 388** | **61 %** | **l'affinage seul** |
| dont SDK, runtime, `mg*` | 327 584 | 15 % | oracle extérieur |

**Au-delà de 512 octets, la sortie de m2c ne compile pas.** Mesuré sur 77
fonctions de cette tranche : 60 échouent à la compilation, 4 compilent, une
seule atteint la bande d'affinage. Le goulot y est donc **toujours la
compilation**, non l'appariement — contrairement à ce que ce document a
d'abord affirmé.

Les causes ne sont pourtant pas nouvelles : ce sont les mêmes familles que sur
les petites fonctions. Une fonction de 5 000 octets touche dix fois plus de
types, et il suffit d'un seul non résolu pour la perdre.

**Et il n'y a pas de percée en vue**, seulement une longue traîne de causes à
une dizaine de cas chacune. Six correctifs mesurés ont porté le taux de
compilation de 6,3 % à 8 % : la boucle de complétion portée à 24 tours, le
champ par valeur d'un type absent, la visibilité demandée au point de greffe,
les structures inférées déclarées en avant, l'emplacement de pile d'un type
incomplet, et la définition qu'une déclaration en avant faisait écarter.

**Et les six correctifs n'ont pas déplacé le taux de compilation** : 8 % avant,
8 % après. Ils ont déplacé les *causes* — `declaration syntax error` de 14 à 6,
`illegal function overloading` de 6 à 10 — sans qu'une seule fonction de plus
ne compile.

C'est le fait structurel de la tranche : **une grosse fonction porte plusieurs
obstacles indépendants**. Lever une cause ne la débloque pas, cela révèle la
suivante. Observé à la main sur `Draw__12CMosBookMenuFv` : six correctifs, six
erreurs différentes, toujours pas compilée.

L'économie des deux tranches est donc opposée, et cela commande l'ordre du
plan :

| | moins de 512 o | plus de 512 o |
|---|---|---|
| obstacles par fonction | ~1 | plusieurs |
| effet d'un correctif | gain immédiat | déplace la cause |
| retour | à chaque correctif | quand *presque toutes* les causes sont levées |

La tranche basse se moissonne donc en continu, correctif par correctif, avec
un retour à chaque pas. La tranche haute est un chantier à seuil : son avancée
se mesure en **causes éliminées**, non en fonctions gagnées, et elle ne rendra
rien avant d'en avoir levé l'essentiel. Les compter comme un même travail
fausse toute projection.

### Le chiffre qui décide du plan

**657 fonctions compilent entre 85 et 100 %** — 87 236 octets de binaire, dont
**5 708 octets seulement divergent réellement**. Cinq mille octets d'écart
séparent le projet de quatre-vingt-sept mille octets acquis.

C'est là, et nulle part ailleurs, que se joue le gros du binaire. Le rendement
de l'affinage **ne décroît pas avec la taille** : une décision de compilateur
corrigée sur une fonction de 5 000 octets vaut 5 000 octets, et les mêmes
décisions se répètent sur des milliers de sites. C'est la seule mécanique qui
passe à l'échelle de deux mégaoctets.

La moisson garde donc désormais le C++ de chaque quasi-succès sous
`build/proches/`, et `make affinage` le reprend sans retraduire.
`make affinage ARGS=--rendement` mesure ce que chaque idiome débloque, ce qui
dit si en outiller un de plus vaut la peine.

### La leçon de méthode

Tant que la chaîne échoue sans dire pourquoi, on prend son outillage pour une
propriété du binaire. Trois des défauts les plus coûteux étaient des fautes de
l'outil que rien ne signalait : un motif de substitution trop large qui amputait
trois unités et faisait échouer 330 fonctions par ricochet ; une vérification
annoncée mais jamais appelée, qui a laissé 546 gains faux ; une règle adoptant
un type nommé incomplet, qui bloquait une meilleure règle. D'où les gardes :
équilibre des accolades, image liée vérifiée, extrait de la ligne fautive.

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

**4.2 Les bibliothèques externes.** `make provenance` en donne le compte exact,
et il n'est pas celui que le classement par dossier suggérait : **928 fonctions,
182 648 octets**, soit tout ce que `.mwcats` ne porte pas. Deux cent onze
fonctions rangées en `sdk`/`runtime` ont en fait été compilées avec le jeu et
relèvent donc de la reconstruction ordinaire ; aucune fonction de bibliothèque
n'a en revanche été rangée à tort dans le jeu. Le détail : le runtime
Metrowerks (81 176 o, dont 2 264 ont leur source dans l'installateur
CodeWarrior), la MSL C (`memcpy`, `sprintf`, `_dtoa`), le SDK Sony (142 304 o —
`ps2sdk` donne les prototypes exacts, mais son code n'apparie pas), le
middleware `mg*` (108 348 o, sans oracle connu : DCDecomp, sur le premier
*Dark Cloud*, n'a decompile ni `mg*` ni le SDK, contrairement a ce que ce
plan a longtemps affirme). **Un
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
- **Le rapprochement avec DCDecomp**, dont l'apport est a etablir : le depot
  couvre le premier *Dark Cloud*, meme studio et meme middleware, mais son
  code decompile est celui du jeu, non celui de `mg*`. Ce qu'il peut donner
  est de la connaissance de structures, pas des signatures toutes faites.
- **Questions ouvertes** : la liaison 13 que portent 193 `FUNC` et 27 `OBJECT` ;
  `-sdatathreshold` ; la compression du mangling que `P1P1i` révèle et que le
  démangleur lit mal. **`.mwcats` n'en est plus une** : c'est la table des
  fonctions que MWCC a compilées lui-même, décodée et vérifiée sur ses 6 912
  entrées — voir `make provenance`.
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

---

## Point d'arrêt du 4 septembre 2026

État vérifié : **1 158 fonctions écrites, 66 496 octets, 3,00 % du binaire**,
`make ci` rend `identique au disque`. Corpus d'affinage : 577 fragments.

**Ce que la règle de conversion des globales a donné.** La moisson a rejugé
1 127 verdicts purgés (`pointer/array required`, `expression syntax error`,
`illegal type`) et rendu six fonctions de plus, dans six unités. Reconstruction
complète : l'image fait 2 608 528 octets, seize de trop, et 49 % des octets
divergent en 8 320 plages éparses — la signature d'un décalage tardif, dont
chaque relocation antérieure porte la trace. Les six unités sont revenues à leur
état d'entrée ; le tronc est propre.

Une bissection à trois unités a montré que le surplus **ne vient pas** de
`ccharacter2`, `ceffectscriptman` ni `cgamedata` : après leur retour en arrière,
l'image gardait ses seize octets de trop. Le coupable est donc dans
`cmenukeyfunc`, `text_001E2410` ou `text_002798A0`. Les six sources moissonnées
sont conservées hors de git, dans `build/moisson_a_verifier/`.

**Ce que cela dit du contrôle par unité.** La chaîne vérifie l'image après chaque
unité qui gagne, et elle a laissé passer ces six-là. Deux lectures possibles, à
départager avant de relancer une moisson : soit la vérification n'a pas tourné
sur ce parcours, soit elle a tourné sur une image déjà divergente et n'a donc
comparé qu'à elle-même. C'est le premier point à instruire.

### Ce qu'il faut faire ensuite, dans l'ordre

1. ~~Nommer l'unité qui coûte seize octets.~~ Fait : `cmenukeyfunc`, et les
   cinq autres sont gardées (`de9ca9e`).
2. ~~Instruire le silence de `image_identique()`.~~ Fait : elle ne s'armait que
   sur une unité qui gagne, et l'unité en cause avait été réécrite par un
   affinage sans gain (`9205119`, raconté sous `ed0d3e9`).
3. Reprendre le profil d'échecs (`m2c ne sait pas traduire`, 451) et grouper les
   extraits par forme normalisée — la méthode qui a produit chaque gain des
   dernières séances : le message du compilateur nomme le symptôme, la ligne
   qu'il souligne nomme la cause.
