# Ce que MWCC fait d'une forme de C

Chaque entrée est mesurée sur une fonction nommée, et le chiffre observé y est.
`CLAUDE.md` en garde la ligne actionnable ; ce fichier garde la preuve.

Le compilateur est `mwcps2-3.0-011126`, au niveau `-O4,p`, en `-lang c++`.

---

## Les divergences se rangent par cause, et la mesure la nomme

`make classes` impute chaque quasi-succès à la cause qui domine ses écarts, et
pèse chaque classe en octets. Le relevé brut de `make ecarts` mélange les causes
et leurs conséquences : sur `SetSprite__12CDamageScoreFPfiiii`, huit `sw`
divergent tous de quatre octets sur la même base — c'est *un* champ manquant, non
huit écarts ; et un `sd ra, K(sp)` ne dit rien de plus que le `addiu sp, sp, K`
qui le porte.

**686 fonctions relevées, 99 144 octets**, au 7 septembre 2026 :

| classe | fn | octets | part |
|---|---|---|---|
| `opcode` | 220 | 29 728 | 30,0 % |
| `cadre` | 75 | 17 068 | 17,2 % |
| `manquante` | 84 | 12 932 | 13,0 % |
| `registres` | 102 | 10 696 | 10,8 % |
| `largeur` | 69 | 9 232 | 9,3 % |
| `en_trop` | 54 | 7 676 | 7,7 % |
| `constante` | 46 | 6 048 | 6,1 % |
| `disposition` | 20 | 4 028 | 4,1 % |

`ARGS="--sous opcode"` range une classe par signature, notre opcode d'abord :

| signature | fn | octets |
|---|---|---|
| `daddu → addiu` | 42 | 4 724 |
| `addu → addiu` | 5 | 2 388 |
| `blez → slt` | 12 | 2 376 |
| `nop → addiu` | 16 | 2 208 |
| `beqz → bnez` | 15 | 2 076 |

La plus lourde **confirme l'idiome de l'adresse prise une fois** : nous gardons
la base dans un registre sauvegardé (`daddu s0, a0, zero`) là où le commerce y
matérialise l'adresse décalée (`addiu s0, a0, 0x8`). Quarante-deux fonctions
posent la même question.

`nop → addiu`, seize fonctions, est le créneau de délai que le commerce comble
et que nous laissons vide.

**Le cadre de pile penche d'un seul côté** : sur 107 divergences de
`addiu sp, sp, K`, **97 donnent au commerce une pile plus grande que la nôtre**.
L'original garde donc plus que nos sources n'expriment. La cause reste à établir.

## L'ordre des déclarations reproduit l'allocation de registres — et le permuteur redevient utile

La classe `registres` est celle dont la divergence ne porte ni sur un opcode, ni
sur une constante, ni sur un décalage : les deux suites font la même chose, avec
d'autres registres. Le dépôt l'avait rangée du côté du permuteur, puis avait
conclu que **le permuteur ne rattrape pas un jet m2c** — 121 essais sans bouger
sur la meilleure candidate.

**Ce verdict tenait au coût, non à la méthode.** Un essai valait alors 4,8
secondes, ce qui bornait la recherche à quelques dizaines de formes. À 546 ms,
les vingt-quatre ordres de quatre déclarations tiennent en treize secondes.

Mesuré sur la classe entière : **427 essais, quatre minutes et demie, sept
fonctions menées à 100 %** — `KnowScoop__17CScoopDataManagerFv`,
`Draw__9CStarDustFP10mgCTextureii`, `Search__14CFuncPointMngrFPc`,
`dynFRAME__FP9SPI_STACKi`, `GetTagProgSize__6CMovieFii`,
`GetFrameNum__8mgCFrameFv`, `GetMpegWorkSize__6CMovieFii`, 972 octets, image
identique au disque.

La règle sous-jacente était déjà consignée pour les compteurs de boucle : MWCC
attribue ses registres dans l'ordre où les variables lui viennent. Ce qui manquait
n'était pas la règle mais le droit d'énumérer.

**La marge reste mince** : m2c déclare peu de locales, et la moitié des fonctions
de la classe n'en ont que deux, soit un seul autre ordre. Ce n'est pas une
machine à décompiler ; c'est un finisseur qui marche, ce qu'on avait cessé de
croire.

## Un champ inféré tombe un mot trop loin quand l'alignement le reporte

Quatrième idiome, et le plus simple à poser. La classe `disposition` a la
divergence la plus lisible des huit : même registre de base, même opcode, deux
décalages qui diffèrent. `SetSprite__12CDamageScoreFPfiiii` en porte huit,
toutes de quatre octets — c'est *un* champ décalé, non huit écarts.

`SearchChara__12CActionCharaFPc` le montre en trois lignes. m2c écrit :

```c
/* 0x000 */ char pad0[0xF0];
/* 0x0F0 */ char unkF0;
/* 0x0F0 */ char padF0[0x588];
/* 0x678 */ CActionChara_infere2_890643 *unk678;
```

`0xF0 + 1 + 0x588` fait `0x679`, et le pointeur qui suit s'aligne sur quatre :
MWCC le place à `0x67C`. Le commerce le lit à `0x678`. **L'alignement du champ
suivant reporte celui-ci d'un mot**, et m2c ne le voit pas parce qu'il compte
sans aligner. Réduire le remplissage de quatre octets rend la disposition juste.

`make lot` essaie chaque remplissage de la structure pour une seconde, sans
savoir lequel est le bon. **88 essais sur la classe entière, trois fonctions
menées à 100 %** — `AssignData__9CSceneMapFP4CMapPc`,
`SearchChara__12CActionCharaFPc`, `SetSprite__12CDamageScoreFPfiiii`, 352
octets, image identique au disque.

**Le motif a d'abord ignoré toutes les structures concernées.** Il exigeait que
la ligne commence par `char`, quand m2c la préfixe d'un commentaire de décalage :
40 essais, zéro amélioration, et l'apparence d'un démenti. C'est la cinquième
fois de la séance qu'un motif décrit ce qu'on s'attendait à lire.

## Un pas de pointeur s'écrit en éléments, jamais en octets

C'est le troisième idiome que le classement a fait sortir, et il vise la classe
`constante` — celle qui domine les fonctions les plus proches du but : sur les
soixante premières, vingt-six en relèvent.

Sa divergence est toujours la même instruction, `addiu rX, rY, K`, avec deux
constantes dont **le rapport est entier**. `GetCosInfo__Fi` avance un `s16 *`
de `+= 4` en pensant quatre octets, et MWCC émet huit. `IsRun__14CRepairManagerFv`
fait `objet + var_a1` sur un `CRepairManager *` de 492 octets, et un pas de
quatre octets devient `0x7b0`.

**m2c compte en octets, MWCC met à l'échelle du type pointé.** Deux réparations,
selon que la constante du commerce est ou non un multiple de ce type :

- **le pas en éléments** — la constante de la source se divise par le rapport,
  `+= 4` devient `+= 2` sur un `s16 *` ;
- **le pas en octets** — la conversion se pose sur l'expression entière,
  `(T *) ((u8 *) p + i)`, quand aucun compte d'éléments ne rend la valeur voulue.

Rien n'oblige à savoir laquelle est juste : `make lot` mesure les deux pour un
peu plus d'une seconde. **28 essais sur la classe entière, trois fonctions
menées à 100 %** — `CalcCollision__12CActionCharaFv`, `GetCosInfo__Fi`,
`CosutmeSelDefaultSet__FiPs`, 204 octets, image identique au disque. Le pas en
octets porte `__ct__10CEohMotherFv` de 95,96 % à 99,99 %, à une instruction du
but.

## Un emplacement de pile porte la taille et l'ordre que le commerce impose

C'est le second idiome que le classement a fait sortir, et il vise la classe
`cadre` — 75 fonctions, 17 068 octets, 17,2 % des octets divergents.

`GetAnalyzeFlag__9CEditDataFii` le dit en quatre lignes. Le commerce ouvre un
cadre de `0x50` et passe deux adresses, `sp+0x10` et `sp+0x30` ; nous ouvrons
`0x20` et passons `sp+0x1c` et `sp+0x18`. m2c avait déclaré deux `s32` là où
l'original a deux tampons de trente-deux octets.

**Deux faits, et aucun ne se devine.**

- **La taille d'un emplacement se lit sur l'écart entre deux adresses prises**,
  le dernier borné par la taille du cadre. Ici `0x30 - 0x10` et `0x50 - 0x30`,
  soit `0x20` chacun.
- **MWCC attribue la pile dans l'ordre des déclarations, la plus basse à la
  première déclarée — et m2c les écrit à l'envers.** Élargir sans réordonner
  mène à 99,75 % : le cadre devient juste, les deux tampons restent échangés.
  Réordonner mène à 100 %.

Le nom que m2c donne à la locale porte déjà le décalage du commerce, puisqu'il
lit le désassemblage de référence : `sp10` est bien `sp+0x10` de l'original.
Rien n'est à inférer, tout est à lire.

**Rendement mesuré sur la classe entière** : 31 fonctions applicables sur 75,
quatre menées à 100 %, vingt améliorées sans y parvenir. Trois sont gardées —
`GetAnalyzeFlag__9CEditDataFii`, `mgInsideScreen__FPA4_fPA4_f`,
`SetCamWorldCoordGyaku__FP9mgCCamera`, 172 octets — la quatrième butant sur la
redéfinition des types que sa sœur venait de poser dans la même unité.

`SetCamWorldCoordGyaku__FP9mgCCamera` pose une définition de `mgCCamera`, qui
est une classe de base. L'image reste identique parce que rien d'autre ne
l'emploie encore ; cette disposition devra être reprise le jour où une dérivée
sera reconstruite.

**Deux fois de suite, la sonde s'est tue au lieu d'échouer.** L'épilogue
`addiu sp, sp, 0x50` était compté comme une adresse prise, et l'inversion de
l'ordre ne s'appliquait à rien parce que son motif exigeait `spNN;` quand les
déclarations portaient déjà `spNN[8];`. Les deux ordres rendaient alors le même
chiffre, ce qui ressemblait à un démenti de l'idiome. C'est la troisième fois
dans cette séance qu'une transformation nulle se fait passer pour une mesure :
**une sonde doit prouver qu'elle a changé le texte avant de le compiler.**

## Une adresse décalée se calcule avant la garde, non après

C'est le premier idiome que le classement des divergences a fait sortir, et il
tient trois fonctions.

`_DATAWEP__FP9SPI_STACKi` appelle deux fois le même accesseur, sur `arg0` puis
sur `arg0 + 1`, derrière une garde `if (SpiWeaponPt == NULL) return 0;`. Le
commerce ouvre ainsi :

```
bnez   $v0, .L00195E70
 addiu $s0, $a0, 0x8        <- créneau de délai
```

Il calcule l'adresse du second argument **dans le créneau de délai de la
garde**, donc avant elle. Nous y mettions `daddu $s0, $a0, zero` : nous gardions
la base et calculions le décalage au site d'appel.

**Ce n'est pas la forme de l'expression qui décide, c'est sa place.** Neuf
formes ont été mesurées sur cette fonction, toutes à **94,29 %** au centième
près : `arg0 + 1`, `&arg0[1]`, `(SPI_STACK *) ((u8 *) arg0 + 8)`, la base tenue
dans une locale, l'adresse décalée hissée dans une locale *après* la garde, la
cible hissée, les valeurs prises avant les rangements, la garde inversée.

Deux formes rendent **100 %**, et toutes deux calculent l'adresse avant la
garde :

```c
suivant = arg0 + 1;
if (SpiWeaponPt == NULL) {
    return 0;
}
```

et la même affectation portée dans la condition, `if ((suivant = arg0 + 1,
SpiWeaponPt) == NULL)`. La première est celle qui est écrite ; c'est la forme
qu'un humain aurait tapée.

Vérifié par reconstruction complète : `_DATAWEP__`, `_DATAWEP_ST__` et
`_DATAWEP_ST_L__`, 252 octets, image identique au disque.

Cet idiome complète celui du créneau de délai déjà consigné — « un créneau de
délai vide se comble en évaluant l'affectation *dans* la condition » — en
disant que le simple placement **avant** la garde suffit, sans opérateur
virgule. La classe `daddu → addiu` compte 42 fonctions et 4 724 octets, et la
classe `nop → addiu` seize de plus : c'est là qu'il faut l'essayer ensuite.

## La colonne de gauche est le commerce — l'avoir lue à l'envers a retourné deux verdicts

`sonde_m2c.ecarts` passe la référence à objdiff en `-1`, donc à gauche, et notre
objet en `-2`. La première version de `make classes` a lu l'inverse, et rien dans
le relevé ne le signalait.

Les deux conclusions qui en sont sorties étaient exactement retournées : le cadre
de pile paraissait plus grand chez nous qu'au commerce, et la classe dominante
semblait dire que le commerce gardait la base — ce qui contredisait l'idiome
« un champ atteint plusieurs fois se prend par son adresse », déjà mesuré
ailleurs. C'est cette contradiction qui a mis sur la piste.

**Le désassemblage entier a tranché en une seconde**, comme la règle du dépôt le
veut : `GetAnalyzeFlag__9CEditDataFii` ouvre à `addiu $sp, $sp, -0x50` dans
`ref/asm`, et c'est la colonne de gauche qui porte `-0x50`. Trois hypothèses
avaient déjà été éprouvées sur `_DATAWEP__FP9SPI_STACKi` avant cela, toutes à
94,29 % — quatre formes de l'expression d'appel, puis cinq structures de corps,
puis deux formes hissant l'adresse. Aucune ne pouvait réussir : elles visaient
le geste inverse de celui qu'il fallait.

## La classe `largeur` n'est pas une déclaration de champ — mesuré et démenti

L'hypothèse était mécanique : un `lh` chez nous contre un `lw` au commerce dirait
que le champ vaut trente-deux bits, il suffit de le corriger dans la structure
que m2c a écrite. Une sonde l'a posée sur les quatorze plus petits témoins de la
classe, corrigeant le champ au décalage exact que la divergence nomme.

La première version a annoncé **treize corrections et zéro gain**. Elle
substituait en réalité `s32` par `s32` : son motif visait la structure déjà
juste, et rien ne vérifiait que le texte avait changé. C'est le piège que ce
dépôt connaît — un motif qui lit m2c se vérifie sur sa sortie, jamais sur l'idée
qu'on s'en fait — et il coûte ici un démenti pour un autre.

Rendue incapable de compter une correction nulle, la sonde dit la vérité :
**treize des quatorze témoins n'ont aucun champ de largeur fausse**, leur
structure porte déjà celle du commerce. Le quatorzième, corrigé pour de bon, n'a
pas bougé de 90,62 %. La largeur vient donc du type de l'expression — la locale
qui reçoit, le retour, ou le prototype de l'appelé.

---

## Ce qui est outillé, et ce que ça rend

Un idiome ne vaut au projet que s'il se pose sans intervention.
`scripts/diff/idiomes.py` en porte huit, appliqués par `make affinage` aux
fonctions qui compilent entre 85 et 100 %.

**Mesuré le 4 septembre 2026, sur quarante fonctions tirées au hasard dans la
file :** trois menées à 100 %.

| transformation | essais | menées à 100 % |
|---|---|---|
| `seuil_deplace` | 6 | **2** |
| `early_return_from_guard` | 62 | 1 |
| `compose_assignment` | 26 | 0 |
| `compose_flottant` | 23 | 0 |
| `cas_unique` | 13 | 0 |
| `constante_a_gauche` | 12 | 0 |
| `rotate_loop_body` | 8 | 0 |

**Le taux d'applicabilité compte plus que le nombre d'essais.**
`seuil_deplace` réussit deux fois sur six applications et emporte deux des
trois succès ; `early_return_from_guard` tire soixante-deux fois pour un seul.
Un idiome qui vise juste paie fort ; un idiome qui transforme large fait perdre
du temps de compilation sans rien rendre.

`echange_deux_rangements` a été ajouté depuis et n'est pas encore mesuré.

**Ce chiffre était mesuré avec objdiff seul, et il était double du vrai.**
objdiff compare un objet à un objet : il ne voit ni le lien, ni le remplissage
qu'une unité porte en queue, ni le décalage qu'un changement de taille inflige
à tout ce qui suit. Une passe d'affinage a ainsi annoncé neuf gains dont la
reconstruction complète du binaire écartait la plupart — 68 % des octets
divergents, et l'image plus courte de 112 octets.

**Sous vérification de l'image liée : 3 fonctions gagnées sur 80, soit 3,75 %.**
C'est le rendement réel de l'affinage, et il vaut la moitié de ce que la mesure
par objet annonçait. Extrapolé aux 556 quasi-succès du corpus : environ
21 fonctions.

La leçon vaut pour toute mesure de ce dépôt : **`match_percent` d'objdiff
départage deux formes d'une même fonction, il ne prouve pas un gain.** Seule la
reconstruction complète le fait.

---

## Types et disposition

- **Un vecteur se copie en `lq`/`sq` parce que son type porte un quadmot.**
  `struct { f32 x, y, z, w; }` se recopie champ par champ, huit instructions
  pour seize octets ; `union { struct { f32 x, y, z, w; } f; u128 qw; }` rend
  `lq` puis `sq`. Ce n'est pas l'alignement de l'adresse qui décide, c'est le
  type — et le prix est un `.f.` à chaque accès de champ.

- **Un `Pf` dans le mangling dit que le champ est un tableau de flottants.**
  `f32 pos[4]` se passe tel quel à un paramètre `f32 *` ; `VECTOR pos` réclame
  `(f32 *)&this->pos`, et cette conversion suffit à renverser l'ordre des
  registres d'argument. Le vecteur garde tout de même son union à quadmot,
  employée au seul endroit qui copie seize octets — `*(VECTOR *)from =
  *(VECTOR *)this->target;` —, le transtypage vivant alors dans l'instruction et
  non dans un argument.

- **Une lecture tronquée ne dit pas la largeur du champ.** Les dix champs de
  `CMenuInvent` en `0x114` sont des `s32` ; `ExitEnd`, qui n'en garde que la
  moitié basse, les lit par `lh` et appariait aussi bien avec des `s16`. C'est
  la fonction qui les écrit en entier qui a tranché. Un type établi sur une
  seule fonction est une hypothèse.

- **MWCC réserve les deux premières entrées d'une table virtuelle.** La i-ième
  méthode déclarée occupe donc `(i + 1) * 4` : la première tombe en `0x08`, et un
  appel en `0x18` désigne la cinquième déclarée. Mesuré sur les dix virtuelles
  que `MenuItemDebugKey` atteint, de `0x14` à `0x118` — un décalage d'un rang
  déplace les dix d'un mot d'un coup, ce que le diff montre aussitôt.

- **Un appel virtuel passe par `$t9`, un appel par table de pointeurs par `$v0`.**
  `lw t9, 0x0(a0)` / `lw t9, off(t9)` / `jalr t9` est la marque de la méthode
  virtuelle ; écrire `((FN)obj->vtbl[off / 4])(obj)` rend la même suite en `$v0`
  et ne peut pas apparier. Une classe dont on ne connaît qu'une poignée de
  méthodes se déclare donc avec autant de virtuelles muettes qu'il faut pour
  amener les siennes au bon rang — soixante-neuf pour atteindre `0x118`.

- **Le quadmot ne peut pas être le type d'un champ.** `union VECTOR { f32 f[4];
  u128 qw; }` est ce qui rend `lq`/`sq` — mais il aligne aussi la classe sur
  seize, ce qui bourre `mgCCamera` de `0x64` à `0x70` et décale de seize octets
  tout ce que `CCameraControl` range après. Le symptôme est net : un champ lu en
  `0xD0` là où le commerce lit `0xC0`. Les champs restent donc en `f32[4]`, et
  seule la copie prend le type : `*(VECTOR *)saved_10 = *(VECTOR *)unknown_10;`
  rend le `lq`/`sq` sans toucher à la disposition. Mesuré sur
  `CCameraControl::ControlOn`, 99,94 % → 100 %.

## Adressage

- **Une globale hors de la fenêtre de `$gp` s'atteint comme un champ de
  structure, jamais comme un tableau indexé.** `ResetNpcTalkMes` efface deux
  mots de `EdEventInfo`, qui fait 4 768 octets ; le commerce y accède
  directement, en deux instructions par écriture :

  ```
  lui  $at, %hi(EdEventInfo + 0x126C)
  sw   $zero, %lo(EdEventInfo + 0x126C)($at)
  ```

  Déclarée `extern u8 EdEventInfo[]` et écrite `*(s32 *)&EdEventInfo[0x126C] = 0`,
  la même chose rend un `lui` *et* un `addiu` avant le `sw` : l'indexation
  matérialise l'adresse dans un registre. **54 %.** Déclarée en structure —
  `struct EdEventInfoData { u8 pad_0x0[0x126C]; s32 field_0x126C; … };` avec
  `extern EdEventInfoData EdEventInfo;` — et écrite `EdEventInfo.field_0x126C = 0`,
  elle rend les octets du disque. **100 %.**

  `scripts/diff/petites.py` engendre cette structure sous le nom
  `<Globale>Data`, par le même mécanisme que les en-têtes de classe. C'est ce
  qui a débloqué les 139 fonctions que le motif `lui` retenait.

- **La taille déclarée d'une globale décide de son adressage.** `MenuMesForm`
  fait 0x24 octets et s'atteint par `%hi`/`%lo` ; `MenuCommonInfo` en fait
  quatre et passe par `$gp`. Déclarer le premier comme un simple pointeur le
  ferait passer par `$gp` à son tour. `config/elf_symbol_addrs.txt` donne la
  taille, et c'est elle qu'il faut reproduire.

- **Une globale déclarée `extern` s'adresse par `$gp` d'elle-même.**
  `GetGameProgressNum` rend `ProgressNum` en une instruction, `lw` en
  `%gp_rel`, sans qu'aucun drapeau de petites données soit passé : le modèle est
  celui du commerce par défaut, à ces drapeaux-là. C'est ce dont dépendent les
  15 869 relocations `GPREL16`.

- **Un littéral partagé se déclare `extern`, il ne s'écrit pas.** Les chaînes
  d'une fonction vivent souvent hors de la plage `rodata:` de son unité ; les
  écrire en clair les ferait émettre dans le `.rodata` de l'objet et déplacerait
  tout ce qui suit. `extern char _5066[];` rend le `%hi`/`%lo` du commerce.

- **Une globale lue puis appelée se tient dans une locale.** `MenuCommonInfo` est
  un pointeur que `$gp` adresse ; écrit `line = MenuCommonInfo->unknown_70;` puis
  `MenuCommonInfo->CheckAnalogKey(0, axis)`, MWCC le recharge entre les deux —
  l'écriture de huit octets dans le tampon, qui s'intercale, peut aliaser la
  globale. Le commerce ne le charge qu'une fois et s'en sert pour le champ comme
  pour le `this`. `CMenuKeyFunc *common = MenuCommonInfo;` rétablit les trois
  écrans d'un coup : 97,77 % → 98,73 %.

- **La forme composée décale la lecture après l'appel.** `*field = *field + (s16)f(x)`
  charge `*field` avant l'appel, ce qui l'oblige à vivre dans un registre
  sauvegardé — un de plus à empiler, seize octets de pile en trop. `*field += (s16)f(x)`
  évalue la droite d'abord et lit `*field` après le `jal`, comme le commerce.
  Mesuré sur les cinq sites de `MenuItemDebugKey` : 95,87 % → 97,53 %, et le
  cadre est retombé de 0xD0 à 0xC0.

- **Une comparaison flottante porte la constante à gauche.** Le commerce éprouve
  `c.lt.s fv1, fv0` avec la borne en premier, ce que rend `if (255.0f < x)` ;
  `if (x > 255.0f)` donne `c.le.s fv0, fv1` suivi d'un `bc1t`. Même nombre
  d'instructions, deux encodages différents.

- **Un champ atteint plusieurs fois se prend par son adresse.** `read_pad`
  plafonnait à 77 % : le commerce hisse `&pad->phase`, `&pad->state`,
  `&pad->mode`, `&pad->term` et `&pad->lastTerm` dans des registres sauvegardés,
  et n'y touche plus qu'en `0x0(sN)`. Écrire `pad->phase` reforme l'offset après
  chaque appel. Déclarer les pointeurs a rendu le prologue identique d'un coup ;
  la même correction vaut pour une structure atteinte dans une boucle
  (`PAD_REPEAT *rep = &m_repeat[i]`). Le symptôme est un `addiu sN, base, offset`
  côté commerce là où nous portons l'offset dans chaque `lw`.

- **Une statique locale à fonction ne se définit pas encore.** MWCC lui attache
  un témoin d'initialisation et nomme les deux en leur ajoutant un numéro —
  `old_viewmode$8715`, `init$8716`, que l'assainissement rend en `_`. Le
  découpage des données n'étant pas fait, l'unité ne peut pas les placer à leur
  adresse : elles se déclarent `extern` et le témoin s'écrit à la main, ce qui
  rend le même code.

- **Un nom que le désassembleur a désambiguïsé s'appelle sous ce nom-là.** Le
  binaire porte quatre `GetStackInt` statiques, une par unité de traduction ;
  l'appel doit viser `GetStackInt__FP12RS_STACKDATA_00262DA0`, donc la source
  le déclare `extern "C"` sous ce nom et pose un raccourci valable pour la seule
  unité concernée. Même remède que pour `_fpadd_parts_0028C790`.

## Sites d'appel

- **Les arguments s'émettent dans l'ordre croissant des registres, et une
  conversion casse cet ordre.** Mesuré sur tout le désassemblage : 1 104 appels
  posent la copie de registre avant l'adresse, 1 208 l'inverse, et dans les deux
  cas c'est le registre le plus bas qui vient d'abord. Un argument que le site
  d'appel doit convertir, lui, est matérialisé *avant* les autres — même quand
  la conversion ne coûte aucune instruction. Le symptôme est un `a1` posé avant
  `a0`, et il tient contre tout ce qui n'est pas le type : 21 versions, dix jeux
  de drapeaux, trente pragmas, 450 essais du permuteur, 240 ordres de
  déclaration. `CSphida::SetUp` a passé 98,17 % → 100 % en retirant les
  transtypages de ses arguments.

- **Le type d'un paramètre de prototype décide de l'ordonnancement de l'appel.**
  `Init` a tenu 93,70 % contre seize formes de corps et 250 essais du permuteur :
  l'écart était dans `include/gamepad.hpp`. Déclaré `void *dma`, le troisième
  argument de `scePadPortOpen` impose une conversion depuis `u8[]` que MWCC
  matérialise avant les autres arguments, et le créneau de délai du `jal` reçoit
  alors le slot au lieu du `%lo` de l'adresse. `u8 *dma` rend 100 % d'un coup.
  Le corollaire vaut d'être retenu : quand le corps résiste, l'écart peut être
  hors de la fonction — dans un prototype, un type, une taille de champ.

- **La case d'un paramètre ne se réemploie que si la source y écrit.** Les deux
  rappels de `mpegdma` enchaînent leur calcul dans `$a0` — `lw a0, 0x40(a0)` puis
  `addiu a0, a0, 0x4C` —, ce qu'une variable locale ne rend pas : MWCC lui donne
  `$v0` et l'appariement tombe à 96,67 %, quelle que soit la forme du corps.
  Mesuré sur cinq variantes ; seule celle qui réaffecte le paramètre
  (`mpeg = (sceMpeg *)mpeg->work;`) apparie. Le transtypage qui s'ensuit est le
  prix de cette forme, et le commentaire doit le dire.

- **Le constructeur d'une classe polymorphe n'ordonnance pas comme une fonction
  ordinaire.** C'est ce qui décide de la forme des constantes flottantes d'un
  appel qu'il contient. `__ct__14CCameraControlFv` le prouve sur 288 octets : il
  construit deux fois `mgCCameraFollow` avec les mêmes quatre constantes, à 92
  octets d'écart, et le commerce rend le premier site sériel sur `$v0` et le
  second apparié `$v0`+`$v1`. Déclarée muette, notre chaîne rend exactement
  l'inverse — le premier apparié avec le `mtc1 zero` rejeté en queue, le second
  sériel. Déclarée polymorphe, elle rend les deux sites du commerce d'un coup, et
  la fonction passe de 90,67 % à 100 %.

  Bissecté sur `perm/variantes4` : ce n'est ni la position du témoin de table
  virtuelle, ni un stockage de plus ou de moins, ni le couplage des deux sites —
  le second retiré, le premier garde sa forme. Ce n'est pas non plus la classe
  *construite* : la même caméra polymorphe rangée en **membre** à l'offset zéro
  rend le même appel et ramène la forme appariée. C'est la classe **dont le
  constructeur est compilé** qui décide.

  Éprouvé en vain sur ce motif, en plus de ce que la section précédente liste :
  les quatre découpes d'arguments par défaut, les quatre formes de construction
  sur tas (placement `new` avec et sans test propre, `new` à allocateur libre,
  `new` à allocateur membre) et l'objet local. Aucune ne transporte le levier
  hors du constructeur, ce qui laisse `MenuItemDebugKey` — une fonction libre —
  hors de sa portée. Le témoin suivant est `TitleBootInit__Fv`, 2 692 octets :
  une fonction libre sans paramètre qui porte le même motif sous la forme du
  commerce.

- **L'ordre d'émission d'une suite de stockages est celui de la source.** Le
  commerce range le champ `0x10` de `CameraCtrlParam` entre `0x20` et `0x24`,
  et rien dans l'ordonnancement ne déplace un `sw` par-dessus quatre autres du
  même objet : réécrire la source dans cet ordre a rendu les vingt et une
  instructions du bloc d'un coup. Le corollaire sert : une suite de stockages
  divergente se lit comme un ordre de source, non comme un ordonnancement.

- **Une expression nommée se lit plus tôt qu'une expression écrite sur place.**
  Deux fois dans la même classe. `SetHeight` : le commerce appelle
  `GetActiveParam` *avant* de calculer, et l'écrire `GetActiveParam()->champ = h`
  laisse MWCC hisser la lecture de l'autre champ par-dessus l'appel — la locale
  `p = GetActiveParam();` rend 80,95 % → 100 %. `SetRotate` : le commerce lit ses
  deux hauteurs avant la copie du vecteur de travail, ce que
  `offset[1] = a[1] - b[1]` posé après la copie ne rend pas ; nommer la
  différence rend 79,35 % → 100 %. Les instructions sont les mêmes dans les deux
  cas, seul l'ordonnancement diffère : **c'est le point de lecture que la source
  décide, non l'ordre des écritures.**

## Expressions

- **`x += c` et `x = x + c` ne rendent pas le même ordre d'opérandes.** La forme
  composée rend `add.s f0, f1, f0`, l'affectation développée `add.s f0, f0, f1`
  — dans les deux sens d'écriture, `c + x` comme `x + c`. Trois additions
  flottantes de `CSphida::SetUp` en dépendaient.

- **`x > 99` et `x >= 100` ne rendent pas le même registre.** Les deux donnent
  `slti … 0x64`, mais le premier écrit dans `$at` et le second dans le registre
  comparé. Mesuré sur cinq formes.

## Graphe de contrôle

- **Un bloc conditionnel se met dans la condition, non après elle.** Écrit
  `if (ret != 1) return 0;` puis le bloc, MWCC sort par un `beq` doublé d'un
  `b` — quatre octets de trop. Écrit `if (ret == 1) { … } return 0;`, il branche
  dans le bon sens. Le symptôme est une taille supérieure de quatre octets et
  une queue de fonction décalée.

- **Un aiguillage à un seul cas n'est pas un `if`.** `IsLevelUp` a tenu 97,76 %
  contre cinquante-six formes, six lots et vingt-trois combinaisons de drapeaux :
  deux instructions, un créneau de délai où le commerce laisse un `nop` et où
  nous hissions la mise à zéro. L'écart était dans le graphe de contrôle. Écrit
  `if (kind != 3) return 0;`, ce retour se fond avec celui du niveau plafonné, et
  MWCC saute alors par-dessus le bloc nul en remplissant le créneau ; écrit
  `switch (kind) { case 3: … break; }`, les deux sorties restent distinctes et le
  créneau reste vide. Le symptôme à retenir : plusieurs retours d'une même
  valeur, dont l'un seulement passe par le bloc partagé.

- **Un créneau de délai vide se comble en avançant l'affectation dans la
  condition.** `GetDngMapFloorGlidInfo` plafonnait à 91 % : le commerce loge
  `i = 0` dans le créneau du `bgtz`, là où la source rendait un `nop` suivi de
  l'affectation. Ni la déclaration en tête, ni l'initialisation avant le test ne
  l'obtiennent — les deux déplacent l'allocation des registres. Il faut que
  l'affectation soit évaluée *dans* l'expression conditionnelle :
  `if (this->table == NULL || (i = 0, this->count) <= 0)`. La forme est laide et
  le commentaire doit dire pourquoi elle l'est.

- **Deux sorties de même valeur ne se replient pas, et c'est le sens du test qui
  les range.** `CEditEvent::Draw` rend zéro par deux chemins que le commerce
  garde distincts, sans saut entre eux. Quatre formes mesurées : l'aiguillage à
  un seul cas gagne un `b` de trop (85,71 %), la locale initialisée puis
  réaffectée se replie (70 %), le `default` en tête allonge (71,43 %). Ce sont
  deux `return` et le test **inversé** qui rendent les vingt-huit octets :
  `if (x != 1) return 0; return 0;` donne le `beq`, `x == 1` donne un `bne`.

## Aiguillages

- **MWCC borne sa table de saut au plus grand cas déclaré, en partant de zéro.**
  `MenuItemDebugKey` a sept cas — 2 à 7 et 10 — et reçoit une cascade de `beq` ;
  le commerce éprouve `sltiu 0xC` et lit une table de douze entrées, dont cinq
  mènent au défaut. Il y a donc un `case 11:` dans la source, qui ne fait rien.
  Un cas vide n'émet aucune instruction mais décide de la forme de l'aiguillage :
  l'ajouter a fait passer la fonction de 84,53 % à 86,14 % d'un coup, et la
  cascade de sept `beq` a disparu.

- **MWCC rend une table de saut à partir de six cas.** Deux commandes de script
  voisines et de même forme le montrent : `_GET_GYORACE_ETC` en a six et reçoit
  une table, `_SET_SAVEDATA_ETC` en a cinq et reçoit une cascade de `beq`, du
  cas le plus haut au plus bas.

- **L'ordre des cas dans la source est celui du code émis.** L'aiguillage
  intérieur de `MenuItemKey` écrit dans l'ordre naturel plafonnait à 90,65 % ;
  le commerce émet le cas `0..5` avant le cas `-1`, et les échanger a rendu
  98,71 %.

- **`addi` ne signe pas du code écrit à la main.** Le désassembleur marque
  « Handwritten » toute fonction qui l'emploie, l'addition qui piège le
  débordement n'étant pas ce qu'un compilateur C émet. Mais MWCC s'en sert pour
  normaliser l'index d'un aiguillage dont le premier cas est négatif : c'est son
  addition, non celle du programme. `MenuItemKey` en porte deux et se
  reconstruit.

- **Le nom d'une table de saut engendrée n'est pas une divergence.** MWCC nomme
  la sienne d'après son propre compteur — `@24` là où le commerce porte `@5068`
  —, et objdiff compte les deux instructions qui la désignent : 99,88 % sur
  `NextDifferentMode`, pour des octets identiques. `make build` tranche.

- **MWCC déroule seul, huit itérations à la fois.** `CPadControl::Initialize`
  efface les masques de ses cent vingt-huit boutons par huit stockages accolés,
  compteur avancé de huit et pas de `0x40` — et pourtant la source est une boucle
  ordinaire, `for (i = 0; i < 0x80; i++)`. Écrire la forme déroulée à la main
  serait la faute inverse. Apparié du premier coup, 128 octets.

## Boucles

- **Le nom d'un compteur de boucle décide de son registre.** La boucle de
  répétition d'`UpDate` plafonnait à 99,87 %, seuls deux registres différant :
  les compteurs extérieur et intérieur étaient échangés. Ni les 120 ordres de
  déclaration ni six autres structures de boucle n'y changent rien — ce qui
  apparie est d'employer `j` pour la boucle extérieure et `i` pour l'intérieure.
  MWCC attribue par ordre de déclaration, non par imbrication.

- **Deux boucles successives veulent deux compteurs.** Les quatre boucles
  d'`IsClearPractice` échangeaient toutes leur compteur avec le décalage
  d'octets que la réduction de force en tire — le commerce tient le premier en
  `a4`, le second en `a5`. Ni le sens du `et`, ni la forme du test, ni la place
  de `i` parmi onze déclarations n'y changent quoi que ce soit ; donner à chaque
  boucle son propre nom rétablit les trois premières d'un coup, et la quatrième
  suit quand son indice de ligne se déclare avant elle. Réutiliser un compteur
  coûtait dix-huit instructions sur deux cent neuf.

- **Ce compilateur garde une boucle vide, mais pas sous toutes ses formes.**
  `IsClearPractice` en porte une de sept tours, sans corps, que le commerce émet
  en huit créneaux — incrément, comparaison, quatre `nop`, branchement, `nop`.
  Les quatre `nop` ne sont pas des instructions effacées : une boucle vide en
  produit autant. Écrite `for (i = 0; i < 7; i++) {}`, elle disparaît
  entièrement ; une trentaine de corps morts éprouvés — tableau local mis à
  zéro, lecture jetée, appel d'une fonction `inline` vide, borne portée par une
  variable — sont tous emportés avec elle. Ce qui la retient est le test `!=`,
  ou l'incrémentation portée dans la condition (`i = 0; while (++i < 7) {}`) —
  et cette dernière seule laisse le `slti` signé du commerce.

---

# Méthode devant un plateau

- **Le désassemblage entier répond aux questions d'ordonnancement.** Compter les
  deux ordres possibles sur 2 312 sites d'appel a coûté une seconde et tranché
  ce que des heures d'essais laissaient en plateau : le commerce emploie les
  deux, donc la chaîne n'était pas en cause. Devant un plateau qui ressemble à
  une propriété du compilateur, mesurer d'abord si le binaire s'y tient partout.

- **Un plateau qui résiste à la forme du C *peut* désigner la chaîne.** Ce qui
  reste quand la taille est déjà juste — un créneau de délai vide, un registre
  sauvé qui diffère — ne s'est pas corrigé en réécrivant `IsSealFloor` : ni les
  cinquante formes essayées, ni le permuteur, ni les pragmas n'y ont rien changé,
  et `#pragma schedule off` fait même chuter de 97 à 75 %, ce qui confirme que
  l'ordonnancement du commerce est celui par défaut. Changer de version l'a
  emporté d'un coup.
  **Mais cette conclusion se tire en dernier, jamais en premier.** `CSphida::SetUp`
  y ressemblait trait pour trait et tenait à un transtypage d'argument : la
  mesure sur le désassemblage entier l'a montré en une seconde. La règle est donc
  celle du point précédent — compter d'abord.

- **Un fragment isolé se compile en une seconde, une unité en deux à quatre.**
  (Quatre-vingt-dix à la première mesure ; la construction se parallélise depuis,
  et le coût d'une unité est surtout fixe — voir « Ce que coûte un pas ».)
  `scripts/diff/probe.sh` passe un `.cpp` autonome au compilateur avec les
  drapeaux du projet et le désassemble : quand l'écart tient à quelques
  instructions, c'est ce qui rend une centaine de formes abordable. La
  reproduction est à faire d'abord — `perm/cam_isole.cpp` montre qu'il a fallu
  y recopier la réservation *suivante* pour que le pointeur reste dans `$v0`,
  sans quoi le fragment répondait à une autre question.

- **Le second registre de travail vient de l'ordonnanceur, pas de l'allocateur.**
  Devant quatre arguments flottants dont un nul, MWCC comble l'écriture-après-
  lecture de son registre de constante de deux façons : en y avançant le
  `mtc1 zero` — un seul registre —, ou en hissant le `lui` suivant, ce qui en
  réclame un second. `#pragma schedule off` et `-O2` rendent la première ;
  `-O3` et au-delà rendent la seconde dès qu'un registre est libre. Attention au
  nom du pragma : `#pragma scheduling` est ignoré en silence, c'est
  `#pragma schedule`.

- **Ce qui décide de la forme, c'est qu'un registre d'argument soit occupé.**
  Mesuré sur les 106 sites du binaire qui servent au moins trois flottants — 28
  à un registre de travail, 66 à deux, 12 à trois. Sur les 17 qui en servent
  quatre dont un nul, le rang auquel le zéro est émis suit exactement le nombre
  de registres : émis en deuxième, sept sites sur dix sont sériels ; rejeté en
  queue, aucun ne l'est. `scripts/diff/inventaire_flottants.py` refait ce compte.

  La règle se prouve en trois lignes. `void g(void *p) { ct(p, 40.0f, 30.0f,
  0.0f, 8.0f); }` — `$a0` y porte le paramètre, donc reste occupé — rend
  exactement la séquence du commerce :

      lui v0,0x4220 · mtc1 v0,$f12 · mtc1 zero,$f14 ·
      lui v0,0x41f0 · mtc1 v0,$f13 · lui v0,0x4100 · mtc1 v0,$f15

  Le `mtc1 zero` y comble l'écriture-après-lecture. Rendez `$a0` libre et
  l'ordonnanceur préfère hisser le `lui` suivant, ce qui réclame un second
  registre et rejette le zéro en queue.

- **Le binaire n'apparie deux constantes flottantes qu'à partir de `$v0`.** Compté
  sur tout le désassemblage : 741 paires de `lui` accolés sur registres
  distincts, dont 176 servent des arguments flottants. Elles emploient
  `v0`+`v1` 172 fois et `a0`+`v0` quatre fois — `$v0` figure dans les 176. Le
  couple `a0`+`v1` que nous produisons sur `MenuItemDebugKey` n'existe nulle
  part. La conclusion à ne pas en tirer est que `$a0` serait inemployable : les
  quatre sites `a0`+`v0` sont tous dans `DrawStatusSprite__7CSphidaFv`, et `$a0`
  y sert de registre de constante alors qu'il est aussi un argument sortant du
  même appel (`mtc1 a0, $f13` en 002EF500, puis `addiu a0, $sp, 0x60` pour le
  `jal` de 002EF51C). Ce qui est vrai est plus étroit : `$v0` indisponible, le
  commerce n'apparie pas et accepte le décrochage. Aux cinq sites où le commerce construit `mgCCameraFollow`, `$v0` tient
  le pointeur rendu par `__nw__` : n'ayant plus `$v0`, le commerce n'apparie pas
  et sort la forme sérielle. `scripts/diff/cherche_appariement.py` refait ce compte.

  Il reste que notre chaîne, elle, prend `$a0` comme second registre dans cette
  situation. Aucune écriture de la source ne l'en dissuade : les seules formes
  qui rendent la séquence du commerce occupent `$a0` par une instruction en plus
  — un `addiu a0, v0, 4`, une écriture à travers le pointeur —, et le commerce
  n'en a aucune, son créneau de délai portant un `nop`.

  Rejoué sur la fonction entière, le motif confirme la règle et l'enrichit d'un
  détail : le commerce teste `$v0` directement (`beqz v0` suivi du `nop`), le
  `this` n'étant matérialisé dans `$a0` qu'au créneau de délai de l'appel, à la
  toute fin du bloc. Notre chaîne, elle, copie le pointeur en `$a0` *avant* le
  test (`move a0, v0`), la copie y est morte après le `beqz`, et l'ordonnanceur
  la recycle en second registre de constante. Aux trois sites où le commerce
  garde le résultat du constructeur vivant dans `$v0` — `cfuncpointmngr`, la
  gyorace et notre fonction — il sort la forme sérielle sur `$v1` ; aux deux où
  il le jette, il apparie (`ceditmap` sur pile) ou intercale (`cmosbookmenu`).

- **Le tableau des versions, mesuré sur la fonction entière.** Il tranche, et il
  a été refait : `scripts/diff/versions.sh` calculait sa racine avec un `dirname`
  de trop et ne compilait rien, et `make diff MWCC_VERSION=…` ne recompile pas
  l'unité sans un `touch`. Vingt et une versions, chacune avec sa recompilation,
  sur `MenuItemDebugKey` (5 836 octets au disque) :

  | version | apparié | taille |
  |---|---|---|
  | `3.0-011126` | **99,84 %** | **5 836** |
  | `3.0.1-020123` | 99,75 % | **5 836** |
  | `3.0.3-020716` | 95,34 % | 5 848 |
  | `2.4-001213` | 86,38 % | 5 700 |
  | `2.3.3-000906` | 85,16 % | 5 644 |
  | les trois `3.0b*` | 84,66 % | 5 824 |
  | les trois `3.0.1b198`…`b210` | 82,67 % | 5 744 |
  | les neuf autres `3.0.1b*` | 0,00 % | 5 952 à 5 968 |

  Deux seulement rendent la taille juste, et `3.0.1-020123` échoue *en plus* sur
  le bloc contesté : elle laisse deux créneaux de délai de `beqz` vides que le
  disque comble d'un `andi`. `3.0-011126` est donc la version, sans réserve. Les
  deux 2.x, qui rendraient le bloc contesté d'emblée, se dénoncent autrement — un
  `sq ra` là où le disque a un `sd ra`, un `paddub` là où il a un `daddu`.

- **Une forme d'ordonnancement peut désigner la version — et se laisser
  démentir par la taille.** Sur ce même motif, les vingt et une versions se
  partagent en deux : les 2.x rendent la forme du commerce, toutes les 3.x
  rendent la nôtre. La tentation est de conclure à la version ; la taille
  tranche en sens inverse, `MenuItemDebugKey` faisant 5 836 octets sous
  `3.0-011126` — le compte exact — contre 5 700 et 5 644 sous les 2.x. Les
  vingt et une mesurées sur l'unité entière le confirment : les dix-neuf 3.x
  rendent toutes notre forme, et deux seulement rendent la taille juste.
  `scripts/diff/versions.sh` rejoue la comparaison sur n'importe quel fragment.

- **Éprouvé en vain sur ce motif**, et donc à ne pas refaire : les dix-sept
  formes du littéral nul (entier, `0.0f`, `0.0`, transtypé, négatif, locale,
  constante, expression repliée) et les 81 combinaisons de littéraux entier /
  flottant / double sur les quatre arguments — tous sont repliés avant que
  l'ordre ne se décide ; les douze formes du `this` (retour ignoré, variable
  distincte, test déporté, ternaire, sans test) ; les onze conversions de
  pointeur, y compris dérivée vers base — le levier de la conversion ne joue que
  sur les conversions numériques ; les huit formes de receveur (méthode
  ordinaire, virtuelle, `new` avec constructeur, avec base, avec membre de
  classe), le placement `new` au sens strict et la construction par fonction
  `inline` partagée ; les cinq rangs possibles du pointeur dans le prototype —
  le nom étant imposé par `extern "C"`, l'ordre des paramètres est libre, mais
  l'émission n'en dépend pas ; `register` et `volatile` ; vingt et un jeux de
  drapeaux ; et les trente-six pragmas d'optimisation, dont les noms sont tirés
  du binaire du compilateur lui-même (`opt_lifetimes`, `opt_pointer_analysis`,
  `peephole`, `global_optimizer`…) et non devinés. Seul `#pragma schedule off`
  bouge, et il rend l'ordre d'émission brut — `12 13 14 15`, la copie du `this`
  en queue —, non celui du commerce. Rejouées sur la fonction vivante (le
  `#if 0` basculé) plutôt que sur le motif réduit, six formes de plus
  plafonnent à 99,84 % : la branche vide puis `else`, le ternaire, le test
  déporté sur un second pointeur, l'affectation dans la condition, le
  placement `new` strict et la littérale en virgule flottante réécrite en
  transtypages ; seule la forme qui range l'affectation *dans* la condition
  (`if (camera != NULL) MenuDebugCamera = ct(…)`) dégrade, à 99,68 %. Les
  balayages sont sous
  `perm/balayage_*.py`.

- **Sous 3.0, c'est la disponibilité de `$v0` qui décide, et rien d'autre.** Le
  motif de `MenuItemDebugKey` se réduit à une fonction libre de quinze lignes
  (`perm/fonction/f01_libre.cpp`) qui reproduit l'écart. Treize contextes y ont
  été mesurés d'un trait avec `scripts/diff/sonde_lot.sh` : paramètre dans `$a0`
  vivant ou mort, méthode ordinaire d'une classe polymorphe ou muette,
  constructeur de l'une ou de l'autre, une à quatre valeurs vivantes de plus,
  le bloc rangé dans un aiguillage. **Aucun ne bouge.** Le seul qui bouge est
  celui où la fonction *rend* le pointeur : celui-là le range dans un registre
  sauvegardé, `$v0` redevient libre, et 3.0 sort la forme sérielle du commerce —
  au prix de deux `move` et d'un registre sauvé de plus, que le disque n'a pas.

  Le voisinage n'a rien à apprendre non plus : `TitleBootInit__Fv` porte le même
  motif, instruction pour instruction, dans une fonction libre elle aussi sans
  paramètre, et le commerce y rend la forme sérielle. Il n'y a donc pas de
  contexte à recopier — la propriété n'est pas dans le voisinage du bloc.

- **Les deux versions 2.x rendent la règle du disque sans condition**, sériel sur
  `$v1` quand `$v0` est occupé et sur `$v0` sinon, aux treize contextes. Elles
  restent écartées, et pour de bonnes raisons mesurées sur la fonction entière :
  86,38 % et 5 700 octets, un `sq ra` là où le disque a un `sd ra`, un `paddub`
  là où il a un `daddu`. Ce qui reste vrai est que l'écart est une préférence
  d'ordonnanceur que 3.0 a et que 2.x n'a pas, non une forme de source : deux
  générations de compilateur séparées d'un an rendent la même chose de notre
  source, et le disque en rend une autre.

- **Une variante se mesure, elle ne se devine pas.** `make measure S=… V=…`
  compile chaque forme d'un fragment encadré par `/* @@<nom> */` et `/* @@fin */`
  et rapporte leur `match_percent` ; il tranche en une passe ce que les essais un
  par un laissent en plateau. Sur `GetDngMapFloorGlidInfo`, six lots d'une
  quarantaine de formes ont mené de 74 % à 100 %, et les paliers ont chacun
  désigné le fait suivant à corriger ; sur `IsClearPractice`, six lots ont mené
  de 87,95 % à 99,95 % là où 300 essais du permuteur n'avaient rien trouvé. Les
  deux outils ne servent pas la même chose : le permuteur cherche seul, par
  transformations aveugles, quand on ne sait plus quoi essayer ; le banc répond à
  une question posée. Le permuter de decomp-permuter, lui, analyse du C pur : il
  ne lit pas nos sources C++.

- **Le permuteur retrouve les fixes par ses seules transformations.** Ajoutées au
  `scripts/diff/permute.py` (la scission d'une affectation composée en deux,
  le déplacement d'une affectation après un bloc, la matérialisation d'un
  paramètre en locale, l'entrée d'une affectation dans la branche qui l'emploie,
  `== 0` ↔ `!`), elles ont refait la route des trois corrections à partir des
  formes d'avant : `pad_button_read` 91,96 % → 100 % en 47 essais, le `!cnt_374`
  d'`UpDate` 99,09 % → 99,78 % en 125, et `AxisCalibration` 89,56 % → 100 % en
  31. Ce dernier a pris une voie neuve — `int course = value - 128;` puis
  `high = course; high = high - 49;` (et l'analogue pour `low`), sans rentrer
  dans les branches — là où la forme à corrections dans les branches rendait
  aussi 100 % : deux écritures, un même objet.

- **Les deux suites d'un diff n'avancent pas du même pas.** Ce que le commerce a
  en propre porte `DIFF_DELETE` de son côté, ce que nous avons en trop
  `DIFF_INSERT` du nôtre. Les apparier par indice décale tout après le premier
  écart de longueur et affiche des divergences imaginaires ; `match_percent`
  d'objdiff est le verdict, non le compte de lignes.

## Faits mesurés pendant la fournée du 29 septembre 2026

- **Une case de pile de script s'avance par `arg0++`.** `RS_STACKDATA` occupe
  huit octets : `GetStackInt(arg0++); GetStackInt(arg0);` place
  `addiu sN, a0, 8` dans le créneau de délai de l'appel, là où un calcul par
  octets le fait plus tard. Un vecteur de trois cases s'avance par `arg0 += 3`.
  Témoins : `_SET_CHARA_TYPE`, `_ADD_FUSION_POINT`, `_SPHIDA_GET_PRIZE` et
  `_POST_TREASURE_BOX`.

- **Affecter le résultat dans la condition laisse le test sur `v0`.**
  `if ((p = f()) == NULL) return 0;` place la copie de `v0` vers `s0` dans le
  créneau de délai du branchement ; séparer l'affectation et le test fait porter
  le branchement sur `s0`. Témoins : `_GET_BIT_CTRL`, `_CHARA_RESET_DA` et
  `_SET_BIT_CTRL`.

- **Un `switch` qui remplit une variable puis retourne conserve les branches de
  sortie.** La forme `switch (x) { case ...: ret = f(); break; default: ret = 0;
  break; } return ret;` rend les `b fin; nop` du commerce, contrairement à un
  `return` dans chaque cas. Un `case 1:` vide avant `default:` peut aussi
  matérialiser la valeur `1` avant l'appel par défaut. Témoins :
  `_ESM_SET_TARGET_ID_0027E700`, `_ESM_LOAD_BASE`, `Step__14CWeaponElementFv`.

- **Pour inverser un booléen retourné, `==`/`!=` suivi de `^ 1` garde le XOR.**
  `!(f() == 3)` et `!(f() != 0)` produisent un `andi 0xff` supplémentaire ;
  `(f() == 3) ^ 1` rend le `xori` attendu. Témoins : `scsMotionTrgWait` et
  `scsMotionWait`.

- **Le type des tampons de pile détermine à la fois leur taille et les
  instructions vectorielles.** `f32 sp[16]; f32 sp2[4];` réserve un cadre de
  `0x70` octets là où des tampons entiers sous-dimensionnés ne donnent que
  `0x40`. Pour une copie `lq`/`sq`, `*(u128 *) dst = *(u128 *) src` sur un
  `f32[4]` conserve les accès quadmot. Témoins : `CalcPosWorldCoord__FPf` et
  `PlaceRiverStep`.

- **L'ordre d'évaluation peut se fixer en matérialisant un appel avant une
  opération bit à bit.** `t = f(x); t & mask;` rend `and v0, v0, s0`, tandis que
  `f(x) & mask` rend les opérandes dans l'ordre inverse. Témoin : `_GET_BIT_CTRL`.

- **Une affectation composée flottante et la constante à gauche n'ont pas le
  même ordonnancement.** `x = 1.2f * x;` rend `mul.s fs0, fv0, fs0` ;
  `x *= 1.2f` ne le rend pas. Témoin : `Jump__12CSceneObjSeqFPffi`.

- **Le type de retour flottant doit être présent dans le prototype d'un appel.**
  Déclarer `SetStack` avec `(RS_STACKDATA *, f32)` évite la promotion par défaut
  de l'ellipse en `double`; lire le champ via `*(f32 *)&champ` donne le
  chargement flottant du commerce. Témoin : `_SPHIDA_GET_SHOT_POW`.

- **Pour un champ éloigné, la forme d'accès choisit le registre d'adresse.**
  `&((struct { char pad[0x1D2A0]; char m; } *)p)->m` rend la séquence
  `lui`/`ori`/`addu` avec `$at`; `p + 0x1D2A0` emploie un registre ordinaire.
  Témoin : `_CHECK_ENABLE_CHARA_CHANGE`.

- **Un champ 64 bits écrit depuis un `u32` peut exiger `s64` côté destination.**
  Cette déclaration donne le couple `lwu`/`sd` observé. Témoin :
  `_RESET_SUBJECT_COUNTER`.

- **Une boucle de remise à zéro se déplie d'elle-même.** `for (i = 0; i < 450; i++)`
  qui met à zéro les cinq champs d'un enregistrement de 16 octets rend le corps
  déplié huit fois du commerce (pas de 8, bornes 0x1BA puis 0x1C2, boucle de queue
  de 8). Ne pas dérouler à la main ; les jets m2c en champs `unk1F8..` sont à
  remplacer par un tableau de structures. Témoin : `InitMesWinTbl__6ClsMesFv`.

- **Deux variables distinctes pour « le résultat de la recherche » et « le dernier
  maillon ».** Réemployer celle de la boucle de recherche échange deux registres.
  L'ordre de déclaration `p`, `last`, `q` rend le commerce. Témoin :
  `AddOutLine__11CCharacter2FPcP12COutLineDraw`.

- **L'ajout en queue de liste garde le double test que m2c laisse voir** :
  `if (last != NULL) { do { q = last->next; if (q == NULL) break; last = q; }
  while (q != NULL); } last->next = line;`. Le `while ((q = p->next) != NULL)`
  naturel laisse 15 instructions divergentes. Même témoin.

- **Un `char *` lu par `lb` se déclare `s8 *` dans le corps**, quoique le mangling
  dise `Pc` : `*name` sur un `char *` (non signé ici, `-char unsigned`) rend
  `lbu`. 99,09 % → 100 %. Même témoin.

- **Deux sorties `return 0` / `return 1` distinctes, sans variable `ret`** : la
  variable donne 27 instructions divergentes, les deux retours mettent `v0` dans
  le créneau de délai. Témoin : `ChkEventEditStart__Fv`.

- **Le type d'une globale hors `$gp` se corrige dans la déclaration de l'unité,
  pas par un cast.** Un `pad0[0x1290]` opaque ne rend `lui at, %hi(g+0x20)` /
  `swc1 …(at)` pour aucune forme de cast, de référence ou de `pad0 + 0x20` : elles
  prennent toutes l'adresse. Il faut un champ réel à `0x20` (`f32 f20;`) dans le
  type déjà posé, mesuré à 92,31 % → 100 %. Élargir un type qu'aucun code n'emploie
  encore ne change pas les octets. Témoin : `ChkEventEditStart__Fv`
  (`EdEventInfo_keep`, `src/game/cripple.cpp`).

- **Une variable déclarée avant l'autre échange deux registres callee-saved** :
  `n` avant `p` a réglé un échange à 2 essais. Témoin :
  `GetTerritoryParts__8CEditMapFiPii`.

- **Le pas de pointeur d'une pile de script s'écrit `SetStack(p++, x)`, et le
  paramètre lui-même sert de pointeur mobile** : le renommer `p` a réglé un
  `addiu a0,a0,0x20` là où le commerce a `addiu a0,s0,0x20`. Témoin :
  `_GET_DUN_WORLD_COORD__FP12RS_STACKDATAi`.

- **Assigner dans la condition place le `daddu` dans le créneau de délai.**
  `if ((p = Get()) != NULL)` et `while ((p = Get()) != NULL)` rendent
  `daddu s1, v0, zero` dans le créneau du `beqz`/`bnez` ; sans l'affectation dans
  la condition, MWCC met le `daddu` avant le test, suivi d'un `nop`. 96,01 % → 100 %.
  Témoin : `GetSeSrcVolPan__FPA4_fP14CFuncPointMngrP15CFuncPointCheckPiPfPfi`.

- **Un vecteur de pile dont le quatrième mot s'écrit à part** : pour `sw v0, 0x9C(sp)`
  en sp-relatif avec `lq`/`sq` et `daddu a2, a0`, il faut
  `struct { f32 v[3]; u32 w; } q;` avec `*(u128 *) q.v = …`, `q.w = 0x3F800000` et
  `q.v` passé aux appels. `f32 v[4]` donne `sw 0xC(a0)`, `&q` un second `addiu` à
  la place du `daddu`, et `f32 v[3]` avec un `u32` séparé change l'ordre des
  emplacements. Même témoin.

- **Un prototype typé règle l'ordre de chargement des arguments qu'un `(...)`
  inverse.** `GetLWMatrix(void *, f32 (*)[4])`, `mgMulMatrix(f32 (*)[4] ×3)` avec
  `f32 mB0[4][4]` rétablissent `a0` puis `a1` ; `sceMcRead(s32, void *, s32)` typé
  corrige l'ordre des `lw a1` / `lw a0` dans `LoadOmakeFile__18CMemoryCardManagerFv`.
  Cela précise la neutralité du prototype `(...)` : elle vaut pour les octets de
  l'appel, non pour l'ordonnancement des arguments chargés depuis la mémoire.

- **L'ordre de déclaration choisit les registres sauvegardés** : `slot` déclaré avant
  `sp38`/`sp3C`/`idx` donne `self` = `s0`, `slot` = `s1` ; après, l'inverse. Témoin :
  `LoadOmakeFile__18CMemoryCardManagerFv`.

- **Une table de saut qui part d'une base a besoin d'un `case` vide devant le
  `default`.** Quand l'entrée 0 pointe vers le défaut, un `case 0xA0:` vide juste
  avant `default:` rend `-0xA0` et `0x40` là où son absence rend `-0xA1` et `0x3f`.
  Le nom de la table (`@118` contre `_288_00368800`) ne s'apparie jamais : `soumettre
  --table` garde à partir de 99,9 % et `make build` tranche. Témoin :
  `ascii2serno__FUc`, `SetWindowMode__6ClsMesFi`.

- **Une comparaison flottante à négatif dans un `default`** : `if (x < -10)` rend
  `slti at` + `beqz at`, `x > -11` rend `slti v0` + `bnez`, donc l'autre sens.
  Témoin : `SearchMcType__18CMemoryCardManagerFv`.

- **Le résultat d'un appel se range dans un paramètre inutilisé pour passer devant
  l'argument précédent.** `arg1 = GetWindowMode(mes); SetStack(next_slot, arg1);`
  place le déplacement de `v0` vers `a1` avant celui de `a0`, dans le créneau de
  délai ; la forme directe reste à 99,05 %, un local neuf et les casts `u32`/`u8`
  n'y font rien. Témoin : `_GET_MES_WINDOW_MODE__FP12RS_STACKDATAi`. Les trois
  fonctions `_CHECK_ITEM_OVER`, `_CHECK_LOADBG_FILE` et `_GET_SYS_SND_ID` (98,46 %,
  même écart `a1` avant `a0`) attendent d'être reprises avec cette forme.

- **Le compteur d'une boucle peut vivre dans le registre du paramètre.** Écrire dans
  le paramètre (`if (arg0 != 0) { arg0 = 0; … do { …; arg0 += 8; … } while
  (arg0 < 0x1B0); }`) rend le commerce ; un local `j` donne 98 %, une copie
  préalable `n = arg0` 89,5 %. Témoin : `InitItemMes__9CGameDataFii` (le premier
  paramètre s'écrit `void *` quand la classe est définie après la fonction).

- **Un type incomplet dans l'unité refuse `arg0++`** (« illegal operand »). Le
  pas dans le créneau de délai du premier `jal` s'obtient par un pointeur sur une
  structure locale de la bonne taille : `struct { u32 a, b; } *p = (…*)arg0;
  GetStackInt((RS_STACKDATA *) p++)`. `(u8 *) arg0 + 8` donne 87,65 %, copier puis
  avancer `arg0` 93,82 %. Témoin : `_SET_CHARA_NO__FP12RS_STACKDATAi`.

- **L'ordre des arguments de script peut être inversé** : le premier `GetStackInt`
  passe en `a2` et le second en `a1`, donc `SetDraw(esMother, GetStackInt(arg0),
  id)`. Témoin : `_IMG_SET_DRAW__FP12RS_STACKDATAi`.

- **Les accesseurs `_GET_CHARA_*` suivent la sœur `_GET_MES_STATUS`** : l'adresse du
  second emplacement se calcule avant la garde, le champ est un `f32` à un
  décalage fixe, `SetStack…f_00262E90(void *, f32)`. Cent pour cent du premier
  coup sur les trois. Témoins : `_GET_CHARA_HEIGHT`, `_GET_CHARA_WEIGHT`,
  `_GET_CHARA_WIDTH`.

- **Un `j f` en queue se rend par `return f(…)`, et le type de retour n'y change
  aucun octet** (`s32` ou `void`, même code). Les 60 fonctions de moins de 32 octets
  de la première vague sont presque toutes de cette forme. Témoins :
  `LoadHdBd__6CSoundFiiiii`, `Initialize__13CSceneGameObjFv`.

- **Ce que le créneau de délai d'un `j` porte passe avant l'appel.**
  `addiu a0, a0, N` se rend par `f(objet + N)` (avec `self` en `u8 *` pour éviter la
  mise à l'échelle : `GetMonsterBajjiDataPtr__16CUserDataManagerFi`,
  `Step__11CAutoMapGenFv` avec `(u8 *) this + 0x1C0`) ; `sw zero, 0x34(a0)` par
  `((u32 *) self)[0x34 / 4] = 0;` écrit avant l'appel (`Initialize__9CSceneMapFv`) ;
  un argument constant par l'argument en plus.

- **Un retour `u8` transmis d'une appelée `u8` impose le même type de retour** :
  avec `s32`, MWCC ajoute un `andi 0xff` et un cadre de pile que le commerce n'a
  pas. Témoin : `GetActiveSetNum__13CGameDataUsedFv`.

- **`jr ra; nop` est un corps vide**, et un `INIT_LOOP_ARG` qui ne fait rien se
  contente d'un paramètre `s32` (le type réel n'est pas lisible dans le binaire).
  Témoins : `ExitEnd__14CBaseMenuClassFv`, `InitCharaViewerMain__F13INIT_LOOP_ARG`.

- **Une signature déjà posée dans l'unité, même plus loin, est imposée à
  l'identique** : `s32 InitReadBG__Fv`, `s32 switchThread__Fv`, `s32 (void *)` pour les
  `Initialize__*` de `cscene.cpp`. Une autre forme donne « illegal function
  overloading » ; une fonction définie plus loin avec un type défini après exige une
  déclaration avancée (`struct X;`) puis le prototype recopié. Témoins :
  `switchThread__Fv`, `GetActiveSetNum__13CGameDataUsedFv`.

- **`sqc2 $vf0, 0($a0)` s'obtient par de l'asm en ligne MWCC** : `asm { sqc2 vf0, 0(v) }`
  dans une fonction `float *v` rend `jr ra` avec le `sqc2` dans le créneau de délai,
  sans prologue. `*v = 0` en `u128` donnerait `sq`. Première occurrence d'`asm {` du
  dépôt. Témoin : `mgZeroVectorW__FPf`.

- **Un `lw` de l'ancienne valeur avant le `sw` veut dire que la fonction retourne
  l'ancienne valeur** : `old = x; x = a; return old;`. Un `void` avec lecture
  `volatile` met l'ancienne valeur dans `$v1` au lieu de `$v0` (98,33 %). Témoins :
  `PauseEnable__Fi`, `videoDecSetState__FP8VideoDecUi`.

- **`slt` contre `sltu` : le signe du type décide.** `slt v0, zero, v0` demande
  `(s32) x > 0` ; `u32 x > 0` donne `sltu` (80 %), sans toucher à la déclaration
  `u32` de l'unité. Témoin : `NowTakePhoto__Fv`.

- **Une globale dont le type n'est défini que plus loin se prend par une déclaration
  avancée** : `struct dbinfo_champs; extern "C" dbinfo_champs dbinfo; return &dbinfo;`.
  Sans `struct X;` en tête, MWCC prend le nom pour un `int` (« function call does not
  match (int) »). Témoins : `dngGetDebugInfo__Fv`, `MenuShopDraw__Fv`,
  `NameRegistKey__Fv`.

- **Un tableau de taille inconnue relu en `u16` passe par une locale pointeur** :
  `extern "C" char FontTblBinBuff[]; u16 *p = (u16 *) FontTblBinBuff; return *p;` rend
  `lui`/`addiu` puis `lhu 0($v0)` ; lire `FontTblBinBuff[0]` en `u16[]` donne
  `lui $at` + `lhu %lo($at)` (72 %). Témoin : `GetHalfFontNum__Fv`.

- **Une copie `u128` suivie d'un appel de queue** : `*(u128 *)(self + 0x40) = *v;
  Draw(self, a, b);` rend `lq`, `j`, `sq` dans le créneau de délai, les flottants
  restant en `$f12`/`$f13`. Témoin : `Draw__12COutLineDrawFPfff`.

- **Les stockages suivent l'ordre des décalages croissants, non celui des paramètres** :
  `a2 → 0xC80` avant `a1 → 0xC84`. Écrits dans l'ordre des paramètres : 96 %. Témoin :
  `SetCameraInfoTable__4CMapFP11CCameraInfoi`.

- **Un champ lu à un grand décalage est un champ de structure, pas un tableau indexé**
  (règle de `CLAUDE.md`, ici en lecture) : `*(s16 *)(u8 *)self + 0x643D8` rend
  `lui`/`ori`/`addu` (72 %) ; `struct { u8 pad[0x643D8]; s16 tour; }` et `self->tour`
  rendent `lui`, `addu at`, `lh off(at)`. Témoin : `CheckNowTourEvent__9CSaveDataFv`.

- **Copie de vecteur avec décalage, sens « get »** : pour `daddu v0, a0, zero` puis
  `addiu a1, v0, off` dans le créneau, le paramètre est un `f32 *self` et le
  décalage s'écrit en éléments (`self + 0x10`). `(f32 *)((u8 *) self + 0x40)` calcule
  le décalage en premier (70 %). Le sens « set » rend l'inverse avec `(u8 *) self + off`.
  Témoins : `GetColor__13CEventSprite2FPf`, `GetPosition__13CEventSprite2FPf`.

- **Une adresse globale décalée en argument se replie dans `%hi`/`%lo` par un index
  scalaire** : `&(&mgRenderInfo.field_0x0)[0x68]` rend `lui`/`addiu` appariés ;
  `(u8 *) &mgRenderInfo + 0x1A0` rend un `addiu` de plus (57,5 %). Un prototype dont la
  matrice est `void *` évite la conversion qui ferait matérialiser l'argument avant les
  autres. Témoin : `mgTransWorldView__FPfPf`.

- **`#pragma schedule off` … `#pragma schedule reset` rend le créneau de délai vide du
  commerce.** Les fonctions dont le commerce écrit `daddu v0, zero, zero; jr ra; nop`
  (ou `lw` avant `jr`, ou un dernier `sw` hors du créneau) sont compilées sans
  ordonnanceur ; la chaîne remplit sinon le créneau. Douze fonctions l'exigent dans
  `mgCVisual` et `mgCVisualMDT` (`CreateBBox__9mgCVisualFPfPfPA4_f`,
  `Initialize__9mgCVisualFv`, `GetMaterialNum__12mgCVisualMDTFv`,
  `GetpMaterial__12mgCVisualMDTFv`, `Copy`, `CreatePacket`, `CreateRenderInfoPacket`,
  `Draw`, `GetMaterial`, `GetMaterialNum`, `GetpMaterial`). Signature : un `nop` dans le
  créneau là où l'on s'attendrait à une instruction utile ; `Set__9mgRect_i_Fiiii`
  (73 %, dernier `sw` glissé dans le créneau) est un candidat.

- **Un décalage 16 bits signé s'écrit comme un champ de structure** : au-delà de 0x7FFF,
  `struct { char pad[0xA490]; s32 f; }` rend `lui at,1 ; addu at,a0,at ; sw a1,-0x5B70(at)` ;
  `*(T *)((u8 *) p + 0xA490)` rend `ori at,zero,0xa494` (82 %). Témoins :
  `AutoChangeEnvOffset__6CSceneFi`, `GetEnvBGMVol__6CSceneFv`,
  `CheckNowTourType__9CSaveDataFv`.

- **Un tableau `char` extern lu à un décalage constant** : `*(u16 *)(Buff + 4)` replie le
  décalage dans `%hi/%lo(Buff+4)` (97 %) ; `((struct { u16 a, b, c; } *) Buff)->c` le garde
  dans le `lhu`. Une adresse retournée en `addiu v0, v0, 8` se prend comme adresse d'un champ
  `char tbl[1]` placé à 0x8. Témoins : `GetYoyakuTblNum__Fv`, `GetYoyakuTblTop__Fv`,
  `GetKanjiTopNo__Fv`.

- **Un corps à deux arguments par prototype `(...)`** : `__as(other + 0x10, self + 0x10)`
  rend le `daddu v0, a0, zero` du commerce. Témoin : `Copy__10CCollisionFR10CCollisionP9mgCMemory`.

- **Un `addiu v0, zero, 1` suivi du stockage en `$v0` dit que la fonction renvoie la valeur
  qu'elle écrit** : `texBugPatch = 1; return 1;` (retour `s32`), comme les `_RESET_*`.
  `#pragma scheduling off` n'existe pas et MWCC l'ignore sans message : le nom est
  `#pragma schedule off`. Témoin : `texBUG_PATCH__FP9SPI_STACKi`.

- **Un `Ul` est un 64 bits (`s64`)** : un pointeur par octets donne `ori at` + `addu v1`
  (72 %) ; `struct { char pad[0x45598]; s64 f; }` rend `lui at, 4` puis `sd 0x5598(at)`.
  Témoin : `SetCostumeBit__16CUserDataManagerFUl`.

- **La forme composée d'une expression flottante suit le commerce** : `t = b - a; t -= c;
  t *= d; t += a;` rend 100 % ; la même expression en une ligne rend 96 %, l'ordre des
  opérandes de `mul.s`/`add.s` étant inversé (même règle que `x += c`). Témoin :
  `CalcAutoPosSet__Fffff`.

- **`movz` vient d'un `c ? K1 : K2` dont l'un des deux est un `lui` seul** :
  `buff_id ? 0x70002000 : 0x70000000`. Témoin : `GetScrPad__Fv`.

- **Un vptr à un décalage non nul** (`lw t9, 0xD00(a0); lw t9, 8(t9); jr t9`) s'obtient par
  `struct Base { char pad[0xD00]; }; struct Virt : Base { virtual void Fn(s32); };` : le
  vptr tombe après la base. Témoins : `Draw__4CMapFv`, `DrawDirect__4CMapFv`.

- **Deux champs lus pour un appel de queue, dans une structure typée**, rendent la copie
  `daddu v0, a0, zero` du commerce (les casts d'octets : 83,6 %). Témoin :
  `ExeScript__14CBaseMenuClassFPc`.

- **`#pragma schedule off` pour un `jr ra` suivi d'un `nop` sans écriture** : sans lui,
  46,67 %. Il rend `Set__9mgRect_i_Fiiii` (73 % → 100 %), `Iam__12mgCVisualMDTFv`,
  `Iam__9mgCVisualFv`, `SetVisual__8mgCFrameFP9mgCVisual`, `__as__9sceGsTex0FRC9sceGsTex0`
  (copie de `u64` : le commerce charge dans `$v0` au lieu de `$v1`, 67 % sans le pragma).

- **Une fonction déclarée en `(...)` dans l'unité ne peut pas être définie avec des
  paramètres typés** (« illegal function overloading ») : on type la ligne de déclaration
  de l'unité — neutre en octets si l'appelant passe déjà des `s32` (`(CScene *, s32,
  s32, s32)`), puis on soumet. Témoin : `RegisterVillager__6CSceneFiiP18CVillagerPlaceInfo`.

- **Un booléen `>= 2` sur un `s16` s'écrit `(x < 2) ^ 1`** avec un retour `s32` : `>= 2`
  et `!(x < 2)` ajoutent un `andi 0xff` (60 %). Témoin : `IsUsed__12GYORACE_DATAFv`.

- **Une globale `$gp` lue deux fois se prend dans un pointeur local** : `u8 *p = (u8 *)
  EventScene; *(s32 *)(p + 0x303C) = 1; *(s32 *)(p + 0x3038) = 1;` ; la forme
  `*(s32 *)(EventScene + …)` recharge la globale (80 %). Témoins :
  `_CANCEL_LOAD_VILLAGER__FP12RS_STACKDATAi`, `_RESET_PALLET_ANIM__FP12RS_STACKDATAi`.

- **Un appel virtuel sur un sous-objet sans classe connue se rend par une classe locale
  de N virtuelles muettes plus la méthode** : slot 0x44 → 15 muettes + `Draw(s32)` ;
  slot 0xD4 → 51 muettes + `Step()` (une muette de trop donne 0x48 ou 0xD8, 99,8 %).
  Témoins : `Draw__8mgCFrameFv`, `Step__13CRandomCircleFv`.

- **Un `lb` dans le créneau du `beqz` avec `daddu v0, zero, zero` sur l'autre branche** :
  charger avant la garde puis écraser : `s32 b = *(s8 *)(p + 0x76C); if (*(s16 *)(p + 0x71C)
  != 0) b = 0; return b;`. Les formes `if/return` ou `r = 0; if …` divergent sur 5 instructions
  de 8. Témoin : `CheckRunEvent__12CActionCharaFv`.

- **Une adresse prise sur un vrai champ `f32[4]` matérialise `this` d'abord** :
  `struct { u8 pad[0x60]; f32 lo[4]; f32 hi[4]; }` avec `self->hi`, `self->lo` rend le
  `daddu v0, a0, zero` avant les `addiu` ; le cast `(f32 *)((u8 *) self + 0x70)` : 78 %.
  Témoin : `SetVertex__6CWaterFPfPf`.

- **Un champ à l'offset 0x906C derrière un entier `EventScene`** : une structure distincte
  par décalage (`struct S { u8 pad[0x906C]; s32 a; }`, `((S *) EventScene)->a`) rend
  `lui at,1 / addu at / sw -0x6F94(at)` ; l'arithmétique sur l'entier rend `swr`/`swl` ou
  `ori at,zero`. Témoins : `_BGM_LOAD_CANCEL`, `_BGM_PLAY_ENABLE`.

- **Indice avant base** : `sll v1,a1,2 ; addu v1,v1,a0 ; sw 0x258C(v1)` s'écrit
  `*(s32 *)((arg0 << 2) + (s32) self + 0x258C) = arg1;` ; `((s32 *) self)[0x963 + arg0]`
  donne `addu v1, a0, v1`. Témoin : `SetYokoHaba__6ClsMesFii`.

- **Un flottant passé en `$f12` traverse tel quel un appel de queue** ; les entiers
  suivent en `$a2`/`$a3` et `1.0f` en `$f13` : `f(a0, a1, arg2, 0, arg3, 1.0f)`. Témoin :
  `MenuCursorDraw__FP10mgCTexturePffi`.

- **Un registre qui garde une valeur lue avant le calcul et survit jusqu'au `jr ra` est le
  retour de la fonction**, même quand rien ne le dit : `DirectData__11mgCDrawPrimFi` renvoie
  l'ancien pointeur du curseur (`u8 *p = objet->cur; objet->cur = p + (n << 4); return p;`).
  Avec un retour `void`, MWCC réemploie `a1` en place (96 %, six essais perdus).

- **Les fonctions de vecteur `mgmath` s'écrivent en `asm {}` avec les registres `vfNN`
  nommés** : `lqc2 vf15,0(a)` / `lqc2 vf16,0(b)` / `vadd.xyzw vf15,vf15,vf16` /
  `sqc2 vf15,0(a)` ; MWCC ne réalloue pas les `vf`, le dernier `sqc2` tombe dans le créneau
  de délai, sans prologue. Témoins : `mgSubVector__FPfPf`, `mgAddVector__FPfPf`,
  `mgVectorMin__FPfPfPf`, `mgZeroMatrix__FPA4_f`. Une déclaration `(...)` de la même
  fonction plus bas dans l'unité est à retirer (elle contredit la définition).

- **Un octet de drapeaux modifié par un bit est un champ de bits** : `struct { u8 pad[0x20];
  u8 alphaTest:1; u8 hi:7; }` et `objet->alphaTest = arg0;` rendent `lbu`/`andi 1`/`or`/`sb`
  (`(*p & ~1) | (arg0 & 1)` : 37–46 %). Le premier champ déclaré occupe le bit 0. Témoin :
  `AlphaTestEnable__11mgCDrawPrimFi`.

- **Une copie `u128` à pointeur d'écriture avancé : lire la source d'abord, réemployer le
  paramètre** : `u128 v = *src; src = *(u128 **)(o + 0xDC); *(…) = src + 1; *src = v;` place
  le `lq` avant le `lw` et le `sq` dans le créneau (une locale `dst` : 63 %). Témoin :
  `Data__11mgCDrawPrimFPi` ; `Data4`/`Data0` passent par l'`asm` (`vftoi4`/`vftoi0`).

- **Un appel terminal dont l'argument est calculé (`addiu` dans le créneau du `j`) veut
  l'ordonnanceur actif** : `#pragma schedule off` laisse l'`addiu` avant le `j` (77 %).
  Témoin : `Initialize__13mgCVisualPrimFv`.
