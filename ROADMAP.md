# Feuille de route

Ce qui reste entre l'état d'aujourd'hui et un code entièrement maîtrisé, ordonné
selon ce que chaque étape débloque **en débit** — non selon la logique des
jalons. Les chiffres sont ceux du 2 septembre 2026 ; ils se refont par
`make etat` (une demi-seconde), `make report`, `make carve`.

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

Et deux distributions qui décident de la stratégie :

- **Par taille** — 3 769 fonctions ≤ 128 o ne pèsent que **11 %** des octets
  restants ; les **410 fonctions > 1 Ko en pèsent 41 %**. Le nombre et le poids
  ne se traitent pas de la même façon, et c'est la leçon la plus coûteuse de
  l'été : la passe automatique a fait passer le compte de fonctions de 298 à
  456 sans que la courbe des octets bouge d'un millimètre.
- **Par classe** — 288 classes portent encore 926 816 o ; **100 classes font
  86 %** de ce total. Les 4 477 fonctions libres ou statiques pèsent, elles,
  1 265 288 o — davantage que toutes les classes réunies.

Les dix classes les plus lourdes, qui font à elles seules 31 % des octets de
classe : `ClsMes` (41 436 o), `CEditMap` (35 272), `CMenuItemInfo` (34 412),
`CActionChara` (33 768), `CScene` (33 552), `CMenuInvent` (30 952), `CAquarium`
(24 172), `CMap` (20 048), `CMonsterMan` (19 332), `CMenuChrCngMenu` (16 800).

**La mesure est désormais fiable et gratuite.** `make etat` compte ce que les
sources écrivent, sans rien construire, et tombe sur le même chiffre que
`make report` par un chemin indépendant. Le journal `progress/journal.jsonl`,
versionné, garde la trace jour par jour ; il a été reconstitué depuis
l'historique git.

---

## Le calcul de cadence, qui cadre tout

```
pour finir en 2 ans :  10,0 fn/jour    3 003 o/jour
rythme observé      :  15,7 fn/jour      574 o/jour
fin projetée        :  2037
```

**Le compte de fonctions est en avance de 57 % sur ce qu'il faudrait ; le poids
est 5,2 fois trop lent.** Tout ce qui suit découle de ce déséquilibre. Une
étape qui n'avance que le nombre de fonctions ne rapproche plus l'échéance :
elle ne se justifie que par ce qu'elle apprend ou débloque.

Le plan ne tient que si la machine fait le gros et si l'humain ne traite que ce
qu'elle refuse. C'est déjà vrai du côté du coût unitaire — voir « Ce que coûte
un pas » dans `CLAUDE.md` — mais pas encore du côté du volume.

---

## Ce que T0 et T1.1 ont appris, et qui change le plan

Quatre enseignements, tous payés par l'expérience, tous vérifiables.

**1. m2c n'est pas le problème ; les déclarations le sont.** La sonde
`scripts/diff/sonde_m2c.py` a mesuré ce que m2c fait seul sur vingt fonctions de
150 à 400 octets : **une seule compile, mais elle apparie à 97,43 %**, sans
permuteur. Tous les échecs sont des identifiants, des types ou des signatures
que rien ne déclare — jamais une mauvaise traduction. La chaîne de T1 doit donc
investir dans le contexte et la normalisation, pas dans la recherche.

**2. La chaîne ne peut pas être mécanique tant que les dispositions de classe ne
sont pas capitalisées.** m2c retrouve les vrais champs d'une classe et les
propose ; nos classes restent des coquilles ne portant que les méthodes déjà
écrites, et rien ne recueille ce qu'il découvre. `class CMap` ne porte
aujourd'hui qu'une méthode et aucun champ. **C'est le verrou principal du
projet**, et il fait remonter l'ancien jalon 4 avant la chaîne.

**3. Un contexte ne doit contenir que ce qu'il sait.** Un type déclaré sans
définition, ou défini sans aucun champ, fait *plus de mal* que son absence :
m2c le tient pour connu et cesse d'inférer. La même règle vaut pour les
prototypes — un prototype nommant un type inconnu vaut moins que pas de
prototype.

**4. Une passe en bloc paie l'échec d'une fonction au prix de son unité.** La
première passe a perdu 122 fonctions pour une vingtaine de fautives. Le remède
tient en deux gestes : refuser en amont ce qu'on ne sait pas justifier, et
**laisser le compilateur désigner la ligne fautive** pour retirer cette
fonction-là et recommencer. Le compte d'unités en échec est tombé de 24 à 0.

---

## T0 — Le débit — **fait**

Acquis, mesuré, en place :

| | avant | après |
|---|---|---|
| `make diff S=…` | 15,4 s | **4,8 s** |
| `make build` complet | 7 min 49 s | **1 min 10 s** |
| une unité recompilée | — | 2,1 s + 8,5 ms par greffe |
| `make etat` / `make controle` | n'existait pas | **0,5 s, sur l'hôte** |

- **La mesure est honnête** : `make etat` sépare l'écrit du greffé, et compte
  une fonction comme faite seulement si une unité déclarée la couvre. Les deux
  rapports ne s'écrasent plus dans le même fichier.
- **La boucle courte** vient de ce que l'adresse d'un symbole suffit à trouver
  son unité et sa source : `config/units.txt` le dit, il n'y avait rien à
  chercher. Au passage, `make diff` ne rend plus « identique » sur une fonction
  greffée.
- **Le parallélisme** est le défaut (`MAKEFLAGS += -j$(nproc) -Otarget`).
- **La non-régression** : `make ci` enchaîne six contrôles textuels et la
  construction ; `.githooks/pre-push` la lance avant toute poussée. Aucun
  service distant ne peut le faire — il lui faudrait le binaire du commerce.

**Ce qui n'a pas été fait, et pourquoi** : le cache d'objets greffés dans
mwccgap. Mesuré et écarté — le coût d'une unité est fixe à 2,1 s et marginal à
8,5 ms par greffe, si bien qu'un cache ne rendrait que 1,7 s sur la pire unité.

---

## T1 — La chaîne d'abattage — **étape 1 faite, le reste ouvert**

**Fait** : le traducteur déterministe de `scripts/diff/petites.py`, fiabilisé et
épuisé. 298 → 456 fonctions, `make build` identique au disque. Un idiome neuf en
est sorti — *une globale hors de la fenêtre de `$gp` s'atteint comme un champ de
structure, jamais comme un tableau indexé*, 54 % contre 100 % — et il a débloqué
à lui seul 139 fonctions.

Outillage produit, réutilisable par tout ce qui suit :
`scripts/build/essai_petites.py` (applique, compile, écarte la fonction fautive,
rend l'état — deux minutes au lieu de vingt), `scripts/build/contexte.py`
(`make contexte`), `scripts/diff/sonde_m2c.py`.

**Ce qui reste, par ordre de rendement mesuré :**

**T1.2 — élargir le traducteur.** `petites.py resume` classe les refus par
motif, et c'est le tableau de bord : on lève le plus lourd, on relance, on
mesure. Restent les appels terminaux dont la cible est manglée (~124 fn), les
instructions arithmétiques simples (`slt`, `andi`, `sll`, somme de deux
registres, ~150 fn), les arguments au-delà du quatrième (99 fn). **On s'arrête
aux branchements et à la pile** : 3 131 refus « registre `sp` sans provenance »
et ~430 refus de branchement sont le domaine de m2c, et les traiter ici
reviendrait à réécrire un décompilateur. C'est la frontière du jalon, et elle
est nette.

**T1.3 — le pendant du contexte, côté compilation.** m2c connaît désormais les
types ; l'unité compilée, elle, ne les voit pas. Il faut poser dans l'unité la
définition de ce que le corps emploie — la structure inférée quand le projet
n'en a pas, l'en-tête du projet quand il en a un. **Bloqué par T2** : tant que
les dispositions ne sont pas capitalisées, poser une structure inférée entre en
conflit avec la coquille que l'unité déclare déjà.

**T1.4 — le pilote.** m2c → normalisation → compilation → score → permuteur si
< 100 % → gardé si 100 %, rendu à l'assembleur sinon. **Le parallélisme se prend
par unité, pas par fonction** : une unité est un fichier, deux ouvriers ne
peuvent pas y écrire ensemble, mais vingt unités se compilent de front. Tourner
sans surveillance demande trois choses : un état repris après coupure, `make
controle` après chaque unité avec retour à l'état d'avant en cas d'échec, et un
rapport au réveil classant les motifs.

**T1.5 — le permuteur en lot.** `permute.py` sait chercher mais il est
séquentiel et réécrit la source en place, à ~10 min par fonction. Deux
changements suffisent : une file triée par octets à gagner, et le travail sur
une copie que le pilote confie.

**Sortie visée**, revue à la lumière de la sonde : non plus « 74 % des
fonctions » — ce chiffre-là ne rapproche plus l'échéance — mais **25 % des
octets**, obtenus surtout par temps machine.

---

## T2 — Les types et les tables virtuelles — **le verrou, et il est passé devant**

C'était le jalon 4 ; la sonde m2c l'a fait remonter. **Rien de ce qui suit ne
peut être mécanique tant que ce chantier n'est pas ouvert.**

- **Capitaliser les dispositions de classe.** Une classe reconstruite doit
  accumuler ses champs à mesure qu'on les établit, et servir toutes ses
  méthodes. Aujourd'hui `include/gen/` porte ce qu'un accesseur a exigé, et
  `class CMap` ne porte aucun champ. Ce que m2c infère — offsets, types,
  tailles — doit s'y déverser au lieu de se perdre à chaque fonction.
- **Posséder les tables virtuelles.** Dès qu'une classe est déclarée polymorphe
  — ce que le commerce impose pour retrouver l'ordonnancement d'un constructeur
  —, MWCC émet `__vt__<classe>` dans notre objet et le lien la voit deux fois.
  Le chemin est repéré : une clé `vtables:` dans `config/units.txt` que
  `make carve` sache lire, un segment qui retire ces octets du bloc brut de
  `00379358`, et la ligne `(.vtables)` posée par `normalize.py`. MWCC émet la
  table dans une section à elle, distincte de `.rodata`.
  `__ct__14CCameraControlFv` est reconstruit à 100 % et attend cela sous un
  `#if 0`.
- **Relever qui emploie chaque donnée, par les relocations.** Non outillé
  aujourd'hui ; T6 en dépend aussi.
- **Déduire l'héritage des chaînes de constructeurs.**

**Sortie** : une classe se reconstruit d'un bloc, sans repayer la disposition à
chaque méthode ; un constructeur de classe polymorphe devient possible.

**Non mesuré** : le coût de faire converger une structure inférée et une
déclaration tenue à la main. C'est la seule inconnue sérieuse du plan.

---

## T3 — Les bibliothèques externes — 332 Ko, un oracle extérieur

15 % du code, et **indépendant de T2** : à confier à un contributeur distinct
dès que possible.

- **Le runtime Metrowerks**, 81 176 o, dont 2 264 correspondent à des sources
  présentes dans l'installateur CodeWarrior — à réécrire d'après elles.
- **La bibliothèque C** (`MSLGCC_PS2.LIB`), fournie compilée : `memcpy`,
  `sprintf`, `_dtoa` entièrement à faire.
- **Le SDK Sony**, 142 304 o. `ps2sdk` en donne les prototypes et structures
  exacts — la moitié du travail —, mais son code est une réimplémentation et
  n'apparie pas.
- **Le middleware `mg*`**, 108 348 o, partagé avec Dark Cloud 1 : ce sont les
  signatures qui se transposent depuis DCDecomp, pas les implémentations.

**Un chiffre qui désigne ce chantier** : sur les 831 fonctions que le traducteur
refuse pour cause de mangling, **381 sont des noms C purs** — `abort`, `atof`,
`fabsf`, `fprintf`. Elles n'ont pas de signature manglée et n'en auront jamais ;
leur oracle est ici, pas dans le binaire.

---

## T4 — Les 100 classes lourdes — le gros

Une classe par lot, dans l'ordre du poids. Dix classes = 31 % des octets de
classe, vingt-cinq = 52 %, cinquante = 71 %, cent = 86 %. Chaque classe achevée
referme ses champs et rend les suivantes moins chères — mais **seulement si T2
est là pour les retenir**.

C'est ici que passe l'essentiel du temps humain, et la seule tâche qui se mesure
sans se planifier.

---

## T5 — Les fonctions libres lourdes — 1 265 288 o

Plus lourdes que toutes les classes réunies, et sans disposition à établir : du
graphe de contrôle, donc le terrain du permuteur et de `make measure`. Les 410
fonctions de plus de 1 Ko y sont pour l'essentiel du poids.

Chevauche T4 ; ne dépend pas de T2.

---

## T6 — Données, tailles, renommage — en fin de course

Ces tâches ne peuvent pas précéder la recompilation.

**Les données.** Le bss est fait — un sous-segment unique le couvre, et les
symboles livrés au lien par adresse absolue sont passés de 2 503 à **16 : les
quinze fenêtres matérielles, et `_xlaunch`**. Ce dernier est une étiquette au
milieu de `_kTLBException` que le binaire déclare `OBJECT` de taille nulle ;
`type:label` la fait poser mais la construction diverge alors de six octets en
`0x00118798`, et le remède est du côté de mwccgap. **Restent 95 sous-segments
`.rodata`, 147 `rodata` et 32 `data` hors de toute unité** : chacun doit
rejoindre celle qui l'emploie, et c'est l'outil de T2 qui le dira.

**Les tailles.** Deux verrous sur trois sont levés : `_gp` est calculé
(`main_BSS_START + 0x7970`) et le parcours des 49 initialiseurs statiques est
établi — `mwInit` charge ses bornes par `%hi`/`%lo`, ce sont donc des symboles
que le lien reloge. Le troisième est **mesuré, non levé** : la fenêtre de `$gp`
n'a que seize octets de marge en bas et 56 347 inutilisés en haut. Recentrer
`_gp` rendrait ~28 Kio de chaque côté mais changerait les octets que le lien
encode — **ce ne sera pas fait**, l'identité au disque étant le seul oracle qui
dise qu'une source est juste. Conséquence à tenir : les petites données ne
peuvent pas grossir de plus de seize octets ; le texte, lui, est libre.
`pack.py` sait déjà porter un exécutable agrandi jusqu'à l'image, qui a 524
octets de marge.

**Les 49 `__sinit_*`**, 6 248 o, vivent après les données : les ouvrir en unité
ferait glisser tout ce qui les en sépare, jusqu'au débordement `%gp_rel`.

**Le renommage** vient en dernier : 1 293 noms désignent plusieurs adresses,
tous à liaison locale, et le `static` d'origine les redistinguera une fois
l'unité reconstruite. `jtbl_00377F10` est le seul endroit où le projet s'écarte
du nom que le binaire porte, parce que m2c l'exige ; à reverser.

**Le critère de sortie du projet** reste une mesure, non un raisonnement : faire
grossir une fonction d'une instruction, reconstruire, et vérifier que le jeu
tourne dans un émulateur. Tout est acquis sauf l'émulateur — éprouvé sur
`CGamePad::WaitEnable`, treize instructions de plus déplacent tout proprement,
`_gp` suit de lui-même et le lien ne signale aucun débordement.

---

## Ordre et dépendances

```
T0 (fait) ──→ T1.2 ─────────────────────────────┐
              T1.3 ──┐                          │
                     ├── T1.4 ── T1.5 ──────────┤
T2 (types, vtables) ─┘         │                ├──→ T6
                               └── T4 (classes) ┤
T3 (bibliothèques) ────────────────────────────┤
T5 (fonctions libres) ─────────────────────────┘
```

T3 et T5 ne dépendent de rien : ce sont les deux chantiers à ouvrir en parallèle
si quelqu'un d'autre s'y met. **T2 est sur le chemin critique** de tout ce qui
touche aux classes, c'est-à-dire de 926 816 octets.

---

## Outillage

Par ordre de ce que chacun débloque.

| Chantier | Ce qu'il débloque |
|---|---|
| **Capitaliser les dispositions de classe** | T1.3, T1.4 et T4 — le chemin critique |
| **Posséder les tables virtuelles** | tout constructeur de classe polymorphe |
| **Relever qui emploie chaque donnée, par les relocations** | T6 en entier |
| **mwccgap : abaisser l'alignement d'une fonction compilée** | les treize auxiliaires du runtime, qui ne peuvent qu'être greffés |
| **mwccgap : réparer les relocations d'une section greffée** | `_xlaunch`, dernier symbole absolu |
| **Un test d'exécution en émulateur** | le critère de sortie du projet |
| ~~Intégration continue~~ | **fait** — `make ci` et `.githooks/pre-push` |
| ~~Boucle de mesure courte~~ | **fait** — 4,8 s |

Un prédicat sur ce que fait le désassembleur s'éprouve contre `asm/nonmatchings/`,
non contre une reconstruction : la comparaison coûte une seconde là où
reconstruire en coûte une minute dix. Et une hypothèse sur ce que fait le
compilateur se compte d'abord sur le désassemblage entier — c'est ce qui a
débloqué `CSphida::SetUp` après 450 essais vains du permuteur.

`make measure` répond à une question posée ; `make permute` cherche seul quand
on ne sait plus quoi demander ; `make etat` dit où en est le compte ;
`essai_petites.py` dit si un plan compile, en deux minutes.

---

## Transverse

- **Passer le dépôt en public et l'inscrire sur decomp.dev.** Le rapport est au
  format attendu ; l'inscription se fait une fois à la main. Notre règle
  interdisant de publier le désassemblage, il faudra publier le rapport seul.
  **C'est le préalable à tout contributeur**, et la CI est désormais là.
- **Le rapprochement avec DCDecomp** sur le middleware `mg*`.
- **Questions ouvertes** : la liaison 13 que portent 193 `FUNC` et 27 `OBJECT` ;
  `.mwcats`, 56 392 octets propres à Metrowerks ; `-sdatathreshold` ; la
  compression du mangling que `P1P1i` révèle et que le démangleur lit mal.
- **Retrouver les 49 unités de traduction d'origine.** Le découpage actuel ne le
  prétend pas. Pistes non éprouvées : l'appariement avec `.rodata`, l'ordre des
  `__sinit_`, le couplage des appels.

---

## Ce qu'il faut se dire franchement

Deux ans à une personne pour 2,2 Mo de PS2 en *matching*, c'est le haut de la
fourchette ; les projets comparables tiennent trois à cinq ans, à plusieurs. Un
mois de travail a produit 456 fonctions et 0,756 % des octets — le compte de
fonctions tient la cadence, le poids non.

Les deux leviers qui ramènent dans la fenêtre restent les mêmes, mais leur ordre
a changé :

1. **T2 avant la chaîne.** L'été a montré que le temps machine ne remplace le
   temps humain qu'une fois les dispositions de classe capitalisées. Bâtir le
   pilote avant cela, c'est bâtir sur une coquille.
2. **L'ouverture à des contributeurs**, dont T3 et T5 sont les portes d'entrée
   naturelles — ni l'un ni l'autre ne dépend du chemin critique.

Sans l'un des deux, vise plutôt trois ans. Et si le choix doit se faire, **c'est
T2 qui décide** : il commande 926 816 octets de code de classe et conditionne
toute automatisation.

---

## Prochaine action concrète

Ouvrir T2 par le bout mesurable : **faire converger une structure inférée par
m2c et la déclaration que l'unité porte déjà**. `CMap` est le cas d'école — m2c
en donne les champs (`0x32C`, `0x330`, `0xC8C`, `0xC90`), `src/game/cmap.cpp`
n'en déclare aucun. Le jour où les deux se rejoignent sans casser
`make build`, T1.3 et T1.4 se débloquent d'un coup, et le pilote peut s'écrire.
