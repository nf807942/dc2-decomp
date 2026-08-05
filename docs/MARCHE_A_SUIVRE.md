# Marche à suivre

Reconstruire une fonction, du désassemblage jusqu'aux octets du disque.

Tout se lance dans le conteneur. Le préfixe est sous-entendu partout ici :

```sh
scripts/host/dc2 make …
```

---

## Une fois, au départ

```sh
make tools     # le compilateur Metrowerks, depuis decompme/compilers
make setup     # extrait le disque, écrit le découpage, désassemble
make build     # doit dire « identique au disque »
```

Si `make build` ne dit pas *identique*, rien de ce qui suit n'a de sens : la
référence est cassée, il faut la réparer d'abord.

---

## 1. Choisir où travailler

```sh
make units
```

Sort les classes dont la plage n'est traversée par aucune autre, la plus grosse
d'abord, avec la ligne prête à coller :

```
0x001D6D80 0x001DAF60 cautomapgen   # 28 méthodes, 16672 octets
```

Pour regarder une classe de près — ses méthodes, leurs tailles, et ce qui
s'intercale entre elles :

```sh
make units S=mgCFrame
```

Une classe *entrecoupée* n'est pas perdue : elle demande une plage plus large,
qui portera plusieurs classes. C'est d'ailleurs ce que le binaire fait, une
unité de traduction en contenant souvent plusieurs.

---

## 2. Ouvrir l'unité

```sh
make open S=CAutoMapGen
```

Ce qui se passe : la plage est ajoutée à `config/units.txt`, et
`src/cautomapgen.cpp` est écrit — entièrement en `INCLUDE_ASM`, dans l'ordre des
adresses.

```sh
make setup     # le désassembleur écrit la plage une fonction par fichier
make build     # doit rester « identique au disque »
```

**Ce `make build` est le vrai test de l'ouverture.** Pas une ligne de C++ n'est
écrite, donc le binaire doit être inchangé.

S'il ne l'est pas, c'est presque toujours la **borne haute**. Elle vaut ce que
l'objet produit : la fin de la dernière fonction quand celle-ci est écrite en
C++, le début de la fonction suivante quand elle est encore greffée — le
remplissage entre les deux n'appartient alors pas au même objet. `make open`
propose la première ; si le binaire diffère, essayer la seconde. Le symptôme est
franc : des `jal` dont la cible perd quatre octets, et des centaines de plages.

**Vérifier d'abord les sauts indirects :**

```sh
grep -c jlabel ref/asm/text/<unité>.s
```

Autre chose que zéro veut dire qu'une table de saut, rangée dans un
sous-segment `rodata`, pointe à l'intérieur d'une fonction de l'unité. Passée en
objet compilé, celle-ci n'expose plus ses étiquettes locales et le lien s'arrête.
Ces unités attendent — voir *Ce qui reste ouvert* dans `CLAUDE.md`.

---

## 3. Prendre une fonction

La plus petite d'abord : elle apprend les conventions de l'unité — comment la
classe est disposée, ce que ses membres valent — pour un coût minime.

```sh
make units S=CAutoMapGen        # les tailles sont dans la liste
```

Lire le désassemblage :

```sh
sed -n '/glabel Draw__11CAutoMapGenFv/,/endlabel/p' ref/asm/text/cautomapgen.s
```

Puis demander un premier jet :

```sh
make decompile S=Draw__11CAutoMapGenFv
```

Ce que m2c rend n'est pas une réponse : la structure de contrôle est juste, les
types sont à établir. Sur une fonction courte, c'est souvent presque exact.

---

## 4. Écrire, comparer, recommencer

Remplacer la ligne `INCLUDE_ASM` de la fonction par son corps, **à la même
place** — l'ordre des adresses est celui que l'éditeur de liens attend.

```sh
make diff S=Draw__11CAutoMapGenFv
```

Les deux suites d'instructions s'affichent côte à côte, avec le taux
d'appariement. `100 %` veut dire que la fonction est reconstruite.

Comment lire les écarts :

| Ce qu'on voit | Ce que ça dit |
|---|---|
| Mêmes instructions, un registre diffère | l'ordre d'évaluation, ou une variable de trop |
| Mêmes instructions, un décalage diffère | la disposition de la structure : un champ est ailleurs |
| Une instruction en plus chez nous | un cast, une variable temporaire, une lecture répétée |
| `lw` là où le commerce fait `lh`/`lb` | la largeur du champ |
| Tout est décalé après un point | une instruction manque avant ; regarder le premier écart seul |

Le premier écart est le seul qui compte : les suivants en découlent souvent.

**Un créneau de délai vide** — un `nop` là où le commerce a une instruction utile
— veut dire que la valeur n'est pas disponible assez tôt. L'avancer par une
déclaration en tête déplace l'allocation des registres et empire souvent le
résultat ; ce qui marche est de l'évaluer dans la condition elle-même :

```cpp
if (this->table == NULL || (i = 0, this->count) <= 0) {
```

**Quand une fonction plafonne**, écrire un script qui compile vingt variantes et
rapporte leur taux tranche plus vite que les essais un par un : chaque palier
désigne le fait suivant à corriger.

**Et si le plateau tient alors que la taille est déjà juste, changer de
compilateur avant de réécrire.** Vingt et une versions s'installent par
`make tools TOOLS_ARGS=--all` ; les mesurer toutes sur la fonction qui résiste
prend une minute et tranche souvent d'un coup. `MWCC_VERSION=… make …` en
choisit une. Ce qui reste à ce stade — un créneau de délai vide, un registre
sauvé qui diffère — vient de la chaîne, pas de la source : ni le permuteur ni
les pragmas ne le corrigent.

---

## 5. Confirmer

```sh
make build      # identique au disque : la fonction est acquise
make progress   # ce qui est reconstruit, en octets
```

`make build` est le seul juge : `make diff` compare une fonction, `make build`
compare le binaire entier. Une fonction à 100 % qui casse la construction
signifie que quelque chose a bougé autour — une globale, un ordre, une taille.

Puis la suivante, dans la même unité.

---

## Voir où on en est

```sh
make report     # puis ouvrir progress/index.html
```

Carte du code proportionnelle aux octets, avancement par secteur, recherche par
nom de fonction. Page autonome, rien n'en sort.

---

## Un exemple complet

`CGamePad::Connect`, 60 octets. Le désassemblage :

```mips
addiu  sp, sp, -0x10
daddu  a0, zero, zero
sd     ra, 0x0(sp)
jal    scePadGetState
daddu  a1, zero, zero
addiu  v1, zero, 0x6
bne    v0, v1, .L0014ADD8
b      .L0014ADE0
addiu  v0, zero, 0x1
.L0014ADD8:
xori   v0, v0, 0x2
sltiu  v0, v0, 0x1
```

Ce qui se lit : un appel à `scePadGetState(0, 0)`, puis `== 6` qui rend 1, sinon
`(v0 ^ 2) < 1` — c'est-à-dire `v0 == 2`. Deux états valent donc oui.

Le C++, avec les noms du SDK :

```cpp
int CGamePad::Connect() {
    int state = scePadGetState(0, 0);
    if (state == scePadStateStable) {
        return 1;
    }
    return state == scePadStateFindCTP1;
}
```

`make diff` : **100 %**, quinze instructions identiques. `make build` :
identique au disque.

Noter la forme : `if (…) return 1; return …;` et non
`return state == 6 || state == 2;`. Les deux disent la même chose, une seule
rend ces octets — le `b` vers la fin et le `xori`/`sltiu` sont la trace du
second `return`. **C'est le cœur du travail : trouver la formulation que le
compilateur a vue**, pas seulement une qui donne le bon résultat.

---

## Conventions

- Les symboles s'écrivent manglés, comme le binaire les porte :
  `Close__8CGamePadFv` est `CGamePad::Close(void)`.
  `config/elf_symbol_addrs.txt` les liste tous.
- Commentaires en français, identifiants en anglais.
- Un commentaire dit *pourquoi*, jamais *quoi*. Un fait établi par sondage se
  documente à l'endroit du code, avec le chiffre observé.
- Rien de dérivé du jeu n'entre dans git — ni disque, ni désassemblage, ni
  tables. Ce qui se versionne est ce qu'on écrit.

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
