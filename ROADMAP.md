# Feuille de route

Ce qui reste entre l'état d'aujourd'hui et un code entièrement maîtrisé. Les
chiffres sont ceux du 2 septembre 2026 ; ils se refont par `make etat` (une
demi-seconde), `make report`, `make carve`.

Ce document dit aussi ce qui n'est pas mesuré. Une étape dont le coût n'a pas
été éprouvé le déclare — c'est ce qui la distingue d'une étape planifiée.

---

## Où on en est réellement

```
fonctions connues     7 840        2 215 100 octets
écrites en C++          456 (5,82 %)   16 748 o   0,756 %
greffées              7 335        2 192 104 o
hors unité               49            6 248 o   (les __sinit_*)
```

Ce qui reste, par provenance :

| Provenance | fn | octets | part |
|---|---|---|---|
| `game` | 5 648 | 1 860 276 | 84,9 % |
| `sdk` | 905 | 142 304 | 6,5 % |
| `mglib` | 555 | 108 348 | 4,9 % |
| `runtime` | 227 | 81 176 | 3,7 % |

Deux distributions décident de la stratégie :

- **Par taille** — 3 769 fonctions ≤ 128 o ne pèsent que **11 %** des octets
  restants ; les **410 fonctions > 1 Ko en pèsent 41 %**.
- **Par nature** — 2 858 méthodes réparties sur **288 classes** (926 816 o), et
  **4 477 fonctions libres ou statiques** (1 265 288 o). Les fonctions libres
  pèsent plus lourd que toutes les classes réunies, et 67 classes seulement
  portent plus de dix méthodes.

Les dix classes les plus lourdes font 31 % des octets de classe : `ClsMes`
(41 436 o), `CEditMap` (35 272), `CMenuItemInfo` (34 412), `CActionChara`
(33 768), `CScene` (33 552), `CMenuInvent` (30 952), `CAquarium` (24 172),
`CMap` (20 048), `CMonsterMan` (19 332), `CMenuChrCngMenu` (16 800).

---

## Le chiffre qui commande le plan

```
pour finir en 2 ans :  10,0 fn/jour    3 003 o/jour
rythme observé      :  15,7 fn/jour      574 o/jour
fin projetée        :  2037
```

**Le compte de fonctions est en avance de 57 % ; le poids est 5,2 fois trop
lent.** Un mois de travail a produit 456 fonctions et 0,756 % des octets.

La conséquence est dure et il faut la tenir : **une étape qui n'avance que le
compte de fonctions ne rapproche plus l'échéance.** Elle ne se justifie que par
ce qu'elle apprend ou débloque. Le plan qui suit n'est donc pas ordonné par
chantiers thématiques — bibliothèques, classes, fonctions libres —, mais par
**ce qui fait baisser le coût d'une fonction moyenne**.

---

## Ce que l'été a mesuré, et qui refait le plan

Quatre faits, tous éprouvés, dont deux invalident la structure précédente.

**1. m2c n'est pas le problème ; les déclarations le sont.** Sur vingt fonctions
de 150 à 400 octets, **une seule compile — mais elle apparie à 97,43 %**, sans
permuteur. Tous les échecs sont des identifiants, des types ou des signatures
que rien ne déclare. Le travail restant sur une fonction moyenne n'est donc pas
de la décompilation : c'est de la plomberie de déclarations, plus quelques
instructions de finition.

**2. La disposition d'une classe s'infère en masse, et c'est du temps machine.**
m2c infère une structure depuis *chaque* fonction. Fusionner ces inférences sur
les méthodes d'une même classe donne une disposition sans commune mesure avec
celle d'une fonction seule :

| classe | méthodes lues | champs fusionnés | contradictions | étendue |
|---|---|---|---|---|
| `CMap` | 35 | **47** | 3 (6 %) | 0xCFC |
| `ClsMes` | 30 | **136** | 7 (5 %) | 0x2950 |
| `CActionChara` | 30 | **229** | 30 (13 %) | 0xF5C |

Une seule fonction de `CMap` donnait quatre champs. **Le typage n'est donc pas
un chantier artisanal de plusieurs mois : c'est une nuit de calcul et
l'arbitrage de 5 à 13 % de contradictions.** C'est le changement le plus
important de ce plan.

**3. Le contexte et l'inférence sont antagonistes.** Un type déclaré au contexte
— même pauvre, même vide — fait cesser l'inférence de m2c. `ClsMes` rendait zéro
champ avec contexte et 136 sans. Toute passe d'inférence doit donc tourner
**sans contexte** ; le contexte se construit *à partir* d'elle, jamais l'inverse.

**4. Une passe en bloc paie l'échec d'une fonction au prix de son unité.** La
première passe a perdu 122 fonctions pour une vingtaine de fautives. Deux gestes
suffisent : refuser en amont ce qu'on ne sait pas justifier, et laisser le
compilateur désigner la ligne fautive pour retirer cette fonction-là et
recommencer. Le compte d'unités en échec est tombé de 24 à 0.

---

## Acquis — le débit

Fait cet été, et c'est le socle de tout le reste.

| | avant | après |
|---|---|---|
| `make diff S=…` | 15,4 s | **4,8 s** |
| `make build` complet | 7 min 49 s | **1 min 10 s** |
| une unité recompilée | — | 2,1 s + 8,5 ms par greffe |
| `make etat` / `make controle` | n'existait pas | **0,5 s, sur l'hôte** |

La mesure sépare l'écrit du greffé et tombe sur le même chiffre par deux chemins
indépendants ; `progress/journal.jsonl` garde la cadence jour par jour ;
`make ci` et `.githooks/pre-push` tiennent la non-régression. Le parallélisme est
le défaut. Le cache d'objets greffés a été mesuré puis **écarté** : il ne
rendrait que 1,7 s sur la pire unité.

Le traducteur déterministe de `petites.py` est épuisé pour ce qu'il sait faire —
298 → 456 fonctions — et il a produit un idiome neuf : *une globale hors de la
fenêtre de `$gp` s'atteint comme un champ de structure, jamais comme un tableau
indexé*, 54 % contre 100 %.

---

## Phase 1 — L'atlas des types (semaines, pas mois)

**C'est le seul chantier sur le chemin critique, et il est bien plus court qu'on
ne croyait.**

**1.1 La récolte.** Lancer m2c **sans contexte** sur les 7 335 fonctions
restantes, garder les structures inférées, les fusionner par type. Coût :
~3 s par fonction, soit **une nuit de machine**, refaisable. Sortie :
`config/atlas.json` — pour chaque type, chaque décalage vu, le ou les types
proposés, et par combien de fonctions.

**1.2 L'arbitrage.** 5 à 13 % des décalages portent deux propositions
contradictoires. Trois règles suffisent probablement, et chacune se mesure : le
nombre de témoins l'emporte ; un accès large l'emporte sur un accès étroit au
même décalage ; un pointeur l'emporte sur un entier de même largeur — cette
dernière est déjà éprouvée dans `petites.py`. Ce qui reste douteux se marque
comme tel dans l'en-tête plutôt que d'être tranché.

**1.3 Les en-têtes.** Engendrer un en-tête par type depuis l'atlas, et faire
converger avec ce que le dépôt tient déjà à la main. **C'est le point non
mesuré du plan** : `include/gen/` porte les champs qu'un accesseur a exigés,
`src/game/cmap.cpp` déclare une `class CMap` sans aucun champ, et les deux
doivent se rejoindre sans casser `make build`.

**1.4 Le contexte se refait depuis l'atlas**, et non plus depuis `include/`
seul. La règle mesurée s'applique : n'y mettre que ce qu'on sait.

**Critère de sortie, mesurable** : la sonde `sonde_m2c.py` passe de 1 sur 20 à
au moins 12 sur 20 qui compilent. C'est ce chiffre, et lui seul, qui autorise la
phase 2.

**Ce que l'atlas ne donnera pas**, et qu'il faut savoir d'avance : les noms de
champs restent `unkXX` — le renommage est une autre affaire ; une union ou un
héritage fausse les décalages ; et il ne dit rien des tables virtuelles.

---

## Phase 2 — La chaîne (1–2 mois)

Elle devient simple une fois la phase 1 acquise, parce qu'il ne reste que de la
plomberie.

**2.1 Le pilote** : m2c → normalisation → compilation → score → gardé si 100 %,
rendu à l'assembleur sinon. **Le parallélisme se prend par unité, pas par
fonction** — une unité est un fichier, mais vingt unités se compilent de front.

**2.2 Tourner sans surveillance** demande trois choses, et pas une de plus : un
état repris après coupure, `make controle` après chaque unité avec retour à
l'état d'avant en cas d'échec, et un rapport au réveil classant les motifs de
refus.

**2.3 Les paliers de taille**, du plus mécanique au plus lourd : ≤ 128 o
(3 769 fn, 11 % des octets), puis ≤ 512 o (6 375 fn cumulées, 41 %), puis
au-delà.

Les briques existent : `essai_petites.py` sait appliquer, compiler, écarter la
fonction que le compilateur désigne et rendre l'état, en deux minutes.

**Sortie visée** : **25 % des octets**, obtenus surtout par temps machine. Le
compte de fonctions n'est plus un objectif.

---

## Phase 3 — Le corpus d'idiomes (continu, à partir de la phase 2)

C'est ici que le permuteur trouve sa vraie place, qui n'est pas la première.

À 97,43 % au premier jet, il ne manque souvent que deux ou trois instructions —
et ces écarts se répètent. Le dépôt en a déjà nommé une trentaine dans
`docs/IDIOMES_MWCC.md` : l'ordre croissant des registres qu'une conversion
casse, `x += c` contre `x = x + c`, la constante à gauche d'une comparaison
flottante, le bloc conditionnel *dans* la condition.

**La règle de travail, mesurée sur `CSphida::SetUp` :** compter d'abord sur le
désassemblage entier. Une propriété supposée du compilateur se vérifie en une
seconde sur des milliers de sites ; c'est ce qui a débloqué cette fonction là où
450 essais du permuteur avaient échoué.

**Donc** : la chaîne classe ce qu'elle refuse ; les motifs qui reviennent
deviennent des règles appliquées automatiquement ; le permuteur ne sert que pour
le résidu. `permute.py` devra alors travailler sur une copie confiée par le
pilote, en file triée par octets à gagner.

---

## Phase 4 — Ce que la machine ne fera pas

Trois chantiers indépendants, à mener en parallèle des phases 2 et 3. **Aucun
n'est sur le chemin critique** — ce sont les portes d'entrée naturelles pour un
contributeur.

**4.1 Les tables virtuelles.** Dès qu'une classe est déclarée polymorphe — ce
que le commerce impose pour retrouver l'ordonnancement d'un constructeur —,
MWCC émet `__vt__<classe>` dans notre objet et le lien la voit deux fois. Le
chemin est repéré : une clé `vtables:` dans `config/units.txt` que `make carve`
sache lire, un segment retirant ces octets du bloc brut de `00379358`, et la
ligne `(.vtables)` posée par `normalize.py` — MWCC émet la table dans une
section à elle, distincte de `.rodata`. `__ct__14CCameraControlFv` est
reconstruit à 100 % et attend cela sous un `#if 0`.

**4.2 Les bibliothèques externes**, 332 Ko et un oracle extérieur : le runtime
Metrowerks (81 176 o, dont 2 264 ont leur source dans l'installateur
CodeWarrior), la MSL C (`memcpy`, `sprintf`, `_dtoa`), le SDK Sony (142 304 o —
`ps2sdk` en donne les prototypes exacts, mais son code ne peut pas apparier), le
middleware `mg*` (108 348 o, dont les signatures se transposent depuis
DCDecomp). **Un chiffre les désigne** : sur les 831 fonctions que le traducteur
refuse pour cause de mangling, **381 sont des noms C purs** — `abort`, `atof`,
`fabsf` — qui n'ont pas de signature manglée et n'en auront jamais.

**4.3 Les grosses fonctions.** Les 410 fonctions de plus de 1 Ko font 41 % des
octets restants. Pas de disposition à établir, mais du graphe de contrôle : le
terrain de `make measure` et du permuteur. **À traiter en dernier, et à la
main** : c'est le seul endroit où l'humain reste plus rapide que la machine.

---

## Phase 5 — La cohérence finale

Ces tâches ne peuvent pas précéder la recompilation.

**Les données.** Le bss est fait ; les symboles livrés au lien par adresse
absolue sont passés de 2 503 à **16 : les quinze fenêtres matérielles et
`_xlaunch`**. Ce dernier est une étiquette au milieu de `_kTLBException` que le
binaire déclare `OBJECT` de taille nulle ; le remède est du côté de mwccgap, qui
répare les relocations d'une section greffée. **Restent 95 sous-segments
`.rodata`, 147 `rodata` et 32 `data` hors de toute unité** ; les rattacher
demande de relever qui emploie chaque donnée par les relocations, ce qui n'est
pas outillé.

**Les tailles.** Deux verrous sur trois sont levés : `_gp` est calculé
(`main_BSS_START + 0x7970`) et le parcours des 49 initialiseurs statiques est
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
Phase 1 (atlas des types) ──→ Phase 2 (chaîne) ──→ Phase 3 (idiomes) ──┐
                                                                        ├──→ Phase 5
Phase 4.1 (vtables) ───────────────────────────────────────────────────┤
Phase 4.2 (bibliothèques) ─────────────────────────────────────────────┤
Phase 4.3 (grosses fonctions) ─────────────────────────────────────────┘
```

**Une seule chose est sur le chemin critique : l'atlas.** Tout le reste peut
attendre ou se mener en parallèle. C'est le renversement par rapport au plan
précédent, qui étalait le typage sur deux à trois mois en parallèle de la
chaîne — alors qu'il la conditionne et qu'il est court.

---

## Outillage

| Chantier | Ce qu'il débloque |
|---|---|
| **La passe d'inférence en masse** | la phase 1, donc tout |
| **Faire converger atlas et déclarations tenues à la main** | le seul point non mesuré |
| **Posséder les tables virtuelles** | tout constructeur de classe polymorphe |
| **Relever qui emploie chaque donnée, par les relocations** | la phase 5 |
| **mwccgap : abaisser l'alignement d'une fonction compilée** | les treize auxiliaires du runtime |
| **mwccgap : réparer les relocations d'une section greffée** | `_xlaunch`, dernier symbole absolu |
| **Un test d'exécution en émulateur** | le critère de sortie du projet |
| ~~Intégration continue~~ | **fait** — `make ci`, `.githooks/pre-push` |
| ~~Boucle de mesure courte~~ | **fait** — 4,8 s |

`make measure` répond à une question posée ; `make permute` cherche seul quand
on ne sait plus quoi demander ; `make etat` dit où en est le compte ;
`essai_petites.py` dit si un plan compile, en deux minutes. Un prédicat sur le
désassembleur s'éprouve contre `asm/nonmatchings/`, non contre une
reconstruction.

---

## Transverse

- **Passer le dépôt en public et l'inscrire sur decomp.dev.** Le rapport est au
  format attendu. Notre règle interdisant de publier le désassemblage, il faudra
  publier le rapport seul. **C'est le préalable à tout contributeur**, et la CI
  est désormais là.
- **Le rapprochement avec DCDecomp** sur le middleware `mg*`.
- **Questions ouvertes** : la liaison 13 que portent 193 `FUNC` et 27 `OBJECT` ;
  `.mwcats`, 56 392 octets propres à Metrowerks ; `-sdatathreshold` ; la
  compression du mangling que `P1P1i` révèle et que le démangleur lit mal.
- **Retrouver les 49 unités de traduction d'origine.** Le découpage actuel ne le
  prétend pas. Pistes non éprouvées : l'appariement avec `.rodata`, l'ordre des
  `__sinit_`, le couplage des appels.

---

## Ce qu'il faut se dire franchement

**La projection actuelle donne 2037.** Elle suppose que le rythme de l'été
continue, et c'est justement ce que ce plan refuse : le rythme de l'été venait
d'un traducteur qui n'atteint que les petites fonctions.

Ce qui peut faire basculer la courbe est chiffré, pas espéré. À 97,43 % au
premier jet, **le coût d'une fonction moyenne est celui de ses déclarations, pas
de sa logique.** Si la phase 1 fait passer la sonde de 1 sur 20 à 12 sur 20, la
chaîne traite les 6 375 fonctions de moins de 512 octets — 41 % des octets — par
temps machine. C'est le seul chemin connu vers l'échéance.

Ce qui reste ensuite est irréductible et se compte en mois d'humain : les 410
grosses fonctions, les tables virtuelles, les bibliothèques externes.

**Deux ans à une personne reste le haut de la fourchette** ; les projets
comparables tiennent trois à cinq ans, à plusieurs. Deux leviers, et le second
n'a pas changé :

1. **L'atlas d'abord.** Il est court, il est mesuré, et rien d'automatique n'est
   possible avant lui.
2. **L'ouverture à des contributeurs**, dont la phase 4 offre trois portes
   d'entrée qui ne touchent pas au chemin critique.

Sans l'un des deux, vise plutôt trois ans.

---

## Prochaine action concrète

Écrire la passe d'inférence en masse — `scripts/build/atlas.py` — et la lancer
une nuit sur les 7 335 fonctions restantes, **sans contexte**. Le prototype qui
a produit le tableau ci-dessus tient en quarante lignes ; ce qu'il lui manque
est la persistance, la reprise, et le compte des témoins par décalage.

Le lendemain, deux chiffres diront si le plan tient : combien de champs l'atlas
porte pour les 67 classes de plus de dix méthodes, et combien de contradictions
il faut arbitrer.
