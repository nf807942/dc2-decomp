# Construction de dc2decomp.
#
# Trois états se succèdent :
#   make setup    extrait le disque, écrit la configuration, désassemble
#   make build    assemble et lie, puis compare au disque
#   make diff S=… compare une fonction construite à celle du commerce
#
# Toutes les commandes tournent dans le conteneur ; scripts/host/dc2 le lance.
# Rien de ce que ces cibles écrivent n'entre dans git.

BASENAME  := SCES_511.90
VERSION   := pal

BUILD_DIR   := build
ASM_DIR     := asm
SRC_DIR     := src
INCLUDE_DIR := include
CONFIG     := config/splat.yaml
# Le découpage de référence : tout en assembleur, sous ref/.
CONFIG_REF := config/splat.ref.yaml
REF_DIR    := ref/asm
LD_SCRIPT := linker_scripts/$(BASENAME).ld

ELF       := $(BUILD_DIR)/$(BASENAME).elf
IMAGE     := $(BUILD_DIR)/main.bin
REFERENCE := rom/main.bin

# Les binutils de decompals sont les seuls à accepter les instructions MMI et
# COP2 du R5900 telles que le désassembleur les écrit.
CROSS     := mips-ps2-decompals-
AS        := $(CROSS)as
LD        := $(CROSS)ld
OBJCOPY   := $(CROSS)objcopy
OBJDUMP   := $(CROSS)objdump

# La construction se parallélise sans risque : chaque objet est indépendant, et
# le lien attend qu'ils soient tous là. Mesuré sur une reconstruction entière —
# 7 min 49 s en séquentiel, 1 min 09 s sur vingt fils, le binaire restant
# identique au disque. `-Otarget` garde la sortie d'une unité d'un seul bloc,
# sans quoi vingt compilations écriraient dans le même flux.
JOBS      ?= $(shell nproc 2>/dev/null || echo 4)
MAKEFLAGS += -j$(JOBS) -Otarget

PYTHON    := python3
SPLAT     := $(PYTHON) -m splat split

# -mabi=eabi parce que l'ABI o32 réduit les registres à 32 bits et rend chaque
# `ld` en macro sur $at, ce que les octets d'origine démentent. -G0 pour que
# rien ne migre en sdata de la seule décision de l'assembleur : la place de
# chaque objet est déjà fixée par le binaire.
ASFLAGS   := -EL -march=r5900 -mabi=eabi -G0 -mno-pdr -non_shared -I include -I $(ASM_DIR)

# Le compilateur d'époque. Quelle version a produit le binaire reste à établir :
# la chaîne `2.4.1.01` vient de l'éditeur de liens, et plusieurs versions
# l'écrivent. `make tools` les installe, MWCC_VERSION choisit.
MWCC_VERSION ?= mwcps2-3.0-011126
MWCC_DIR  := tools/compilers/$(MWCC_VERSION)
MWCC      := $(MWCC_DIR)/mwccps2.exe

# `MWCIncludes` est la liste que MWCC consulte pour les `<...>` ; `-i` ne
# nourrit que celle des `"..."`. C'est par là que les déclarations du projet
# remplacent celles du SDK absent.
MWCC_ENV  := MWCIncludes=$(INCLUDE_DIR)

# -char unsigned et -str readonly : le R5900 ne signe pas ses `char` par défaut
# dans ce compilateur, et les littéraux du binaire sont en lecture seule.
# -Cpp_exceptions off parce que le binaire n'en porte aucune trace.
#
# -RTTI off parce que le code du jeu n'en porte aucune trace non plus : les cinq
# seuls `__RTTI__` du binaire sont ceux des exceptions de la bibliothèque
# Metrowerks, compilée à part. Sans ce drapeau, toute classe déclarée polymorphe
# emporte dans son objet un `__RTTI__` et la chaîne de son nom, que le disque n'a
# pas.
#
# -lang c++ parce que mwccgap donne son fichier intermédiaire l'extension `.c`,
# dont MWCC déduirait le dialecte : le jeu est en C++, et son mangling le dit.
#
# `-c` n'y est pas : mwccgap l'ajoute lui-même devant ces drapeaux.
CFLAGS    ?= -O4,p -lang c++ -char unsigned -str readonly -Cpp_exceptions off \
             -RTTI off -sym on -i $(INCLUDE_DIR) -i $(SRC_DIR)

# mwccgap greffe l'assembleur de référence dans l'objet compilé : MWCC émet le
# texte d'une unité d'un seul bloc, donc une fonction non encore reconstruite ne
# peut pas venir d'un objet voisin.
#
# `--as-flags` prend un nombre libre d'arguments, donc il avale tout ce qui le
# suit : placé avant les drapeaux du compilateur, il emporte `-O4,p` et la
# compilation retombe silencieusement en `-O0`. Il vient donc en dernier, après
# les drapeaux destinés à MWCC.
MWCCGAP      := $(PYTHON) tools/mwccgap/mwccgap.py
# La greffe fait partie de la chaîne autant que le compilateur : ce qu'elle
# change se voit dans l'objet, et sans cette dépendance une correction reste
# invisible jusqu'au prochain effacement de `build/`.
MWCCGAP_SRC  := $(wildcard tools/mwccgap/mwccgap/*.py)
MWCCGAP_ARGS := --mwcc-path $(MWCC) --as-path $(AS) --use-wibo \
                --macro-inc-path $(INCLUDE_DIR)/macro.inc \
                --asm-dir-prefix $(ASM_DIR) \
                --as-march r5900 --as-mabi eabi
MWCCGAP_TAIL := --as-flags -EL -G0 -mno-pdr -non_shared
# Les symboles que rien n'implante — 2 502 objets du bss et des fenêtres
# matérielles — sont donnés par leur adresse absolue, dans les scripts que le
# découpage engendre.
AUTO_LD   := linker_scripts/auto/undefined_syms_auto.ld \
             linker_scripts/auto/undefined_funcs_auto.ld
# -EL : sans lui l'éditeur de liens prend l'émulation gros-boutiste par
# défaut et refuse chaque objet.
LDFLAGS   := -EL --no-check-sections --accept-unknown-input-arch \
             $(addprefix -T , $(AUTO_LD)) -T $(LD_SCRIPT) \
             -Map $(BUILD_DIR)/$(BASENAME).map

# Seul le désassemblage des sous-segments encore intacts s'assemble : sous
# `asm/nonmatchings/` vivent les fonctions d'une unité reconstruite, que
# mwccgap greffe dans l'objet compilé — les assembler à part les livrerait deux
# fois à l'éditeur de liens.
# L'écarter par `-prune` et non par `-not -path` : ce dossier porte une
# fonction par fichier, soit 7 759 entrées que `find` parcourait pour les
# rejeter — 0,73 s payées au chargement de *chaque* `make`, donc à chaque essai
# du permuteur.
S_FILES   := $(shell find $(ASM_DIR) -path '$(ASM_DIR)/nonmatchings' -prune -o -name '*.s' -print 2>/dev/null)
# Les microprogrammes des unités vectorielles restent des octets : leurs
# instructions ne sont pas du MIPS, et aucun assembleur de la chaîne ne les
# relit. Le désassembleur les dépose sous bin/, l'éditeur de liens les veut
# en objets.
BIN_FILES := $(shell find bin -name '*.bin' 2>/dev/null)
# Les unités que `config/units.txt` déclare, compilées depuis src/.
SRC_FILES := $(shell find $(SRC_DIR) -name '*.cpp' -o -name '*.c' 2>/dev/null)
# Une unité dépend des en-têtes qu'elle inclut : la disposition d'une structure
# y est écrite, et la changer change le code émis. Les lister tous est plus
# large que nécessaire, mais aucune modification ne peut alors passer inaperçue.
HEADERS   := $(shell find $(INCLUDE_DIR) -name '*.h' -o -name '*.hpp' 2>/dev/null)
# Le désassemblage de référence, assemblé pour qu'objdiff ait de quoi comparer.
REF_S_FILES := $(shell find $(REF_DIR) -name '*.s' 2>/dev/null)
REF_O_FILES := $(addprefix $(BUILD_DIR)/, $(REF_S_FILES:.s=.o))
O_FILES   := $(addprefix $(BUILD_DIR)/, $(S_FILES:.s=.o) $(BIN_FILES:.bin=.o) \
             $(addsuffix .o, $(basename $(SRC_FILES))))

.PHONY: all setup tools patch split build objects check diff decompile measure \
        atlas carve clean distclean contexte injecte provenance chaine affinage ecarts classes lot banc forge tailles vtables champs entetes contexte_prouve instructions controle ci etat progress report

all: build

# --------------------------------------------------------------------------
# Préparation
# --------------------------------------------------------------------------

setup: split

# Le découpage se refait dès qu'une unité s'ouvre, et dès qu'un symbole est
# nommé à la main : `configure.py` écarte de sa table les adresses que
# `symbol_addrs.txt` renomme, faute de quoi deux noms désignent le même endroit
# et le lien reçoit le second par son adresse absolue.
config/splat.yaml: config/units.txt config/symbol_addrs.txt scripts/setup/configure.py
	$(PYTHON) scripts/setup/configure.py

# Deux désassemblages : celui du travail, où une unité reconstruite laisse
# place à ses seules fonctions restantes, et celui de référence, complet, qui
# donne à objdiff l'objet contre lequel mesurer ce qui est déjà écrit.
# Le désassemblage repart propre : une coupure déplacée laisse derrière elle le
# fichier qu'elle a cessé de produire, et l'éditeur de liens reçoit alors les
# mêmes fonctions deux fois — des milliers de définitions multiples, jusqu'à la
# faute de segmentation. Tout ici est engendré, donc l'effacer ne coûte rien.
split: config/splat.yaml
	rm -rf $(ASM_DIR) $(REF_DIR) bin
	$(SPLAT) $(CONFIG)
	$(SPLAT) $(CONFIG_REF)
	@$(PYTHON) scripts/setup/normalize.py

# --------------------------------------------------------------------------
# Construction
# --------------------------------------------------------------------------

build: check

# Tous les objets, sans lier. C'est ce qu'objdiff mesure, et la mesure garde son
# sens là où le lien échouerait : une passe automatique construit ainsi avant de
# savoir si ce qu'elle propose tient.
objects: $(O_FILES) $(REF_O_FILES)

$(BUILD_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# Un bloc d'octets devient un objet dont la section `.data` porte le contenu,
# ce que le script de lien engendré nomme explicitement.
$(BUILD_DIR)/%.o: %.bin
	@mkdir -p $(dir $@)
	$(OBJCOPY) -I binary -O elf32-littlemips -B mips:5900 $< $@

# Ce qui décide du découpage décide aussi de ce que mwccgap greffe : changer la
# plage `rodata:` d'une unité change les sections de son objet sans toucher à sa
# source, et l'objet resterait alors celui d'avant. Le symptôme n'est pas une
# divergence mais une faute de segmentation au lien — l'objet n'a plus la section
# que le script attend, et les symboles qu'elle définissait manquent. Mesuré sur
# `runtime/std`, dont l'objet a gagné six sections `.rodata` une fois refait.
UNITS := config/units.txt scripts/setup/configure.py

# Une unité reconstruite passe par mwccgap, qui appelle MWCC puis greffe
# l'assembleur des fonctions encore marquées `INCLUDE_ASM`.
$(BUILD_DIR)/%.o: %.cpp $(HEADERS) $(MWCCGAP_SRC) $(UNITS) tools/.patched
	@mkdir -p $(dir $@)
	@test -f $(MWCC) || { echo "$(MWCC) absent — lancez \`make tools\`" >&2; exit 1; }
	$(MWCC_ENV) $(MWCCGAP) $< $@ $(MWCCGAP_ARGS) $(CFLAGS) $(MWCCGAP_TAIL)

$(BUILD_DIR)/%.o: %.c $(HEADERS) $(MWCCGAP_SRC) $(UNITS) tools/.patched
	@mkdir -p $(dir $@)
	@test -f $(MWCC) || { echo "$(MWCC) absent — lancez \`make tools\`" >&2; exit 1; }
	$(MWCC_ENV) $(MWCCGAP) $< $@ $(MWCCGAP_ARGS) $(CFLAGS) $(MWCCGAP_TAIL)

# Le compilateur, depuis les paquets de decompme/compilers.
tools: patch
	@$(PYTHON) scripts/setup/get_tools.py $(TOOLS_ARGS)

# Ce que le projet corrige dans les outils tiers. Un sous-module ne retient que
# sa référence, donc le correctif est ce qui se versionne ; le témoin le fait
# poser avant toute compilation, sans quoi l'écart n'apparaîtrait qu'au moment
# de comparer au disque.
patch: tools/.patched

tools/.patched: $(wildcard tools/patches/*.patch) scripts/setup/patch_tools.py
	@$(PYTHON) scripts/setup/patch_tools.py $(PATCH_ARGS)
	@touch $@

$(ELF): $(O_FILES) $(LD_SCRIPT)
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -o $@ $(O_FILES)

$(IMAGE): $(ELF)
	$(OBJCOPY) -O binary $< $@

# La comparaison porte sur le contenu chargé, non sur le fichier ELF : le
# commerce porte en plus une table de symboles et 99 876 relocations, que
# l'éditeur de liens ne reproduit pas et dont le jeu ne dépend pas.
check: $(IMAGE)
	@$(PYTHON) scripts/build/verify.py $(IMAGE) $(REFERENCE)

# --------------------------------------------------------------------------
# Travail sur une fonction
# --------------------------------------------------------------------------

# Compare une fonction construite à celle du commerce. `make diff S=symbole`.
diff:
	@test -n "$(S)" || { echo "usage : make diff S=<symbole>" >&2; exit 1; }
	@$(PYTHON) scripts/diff/diff.py $(S)

# Premier jet de C pour une fonction, depuis son désassemblage de référence.
decompile:
	@test -n "$(S)" || { echo "usage : make decompile S=<symbole>" >&2; exit 1; }
	@$(PYTHON) scripts/diff/decompile.py $(S)

# Cherche par essais la forme qui apparie une fonction déjà proche.
# `make permute S=UpDate__8CGamePadFv N=400`
permute:
	@test -n "$(S)" || { echo "usage : make permute S=<symbole> [N=<essais>]" >&2; exit 1; }
	@$(PYTHON) scripts/diff/permute.py $(S) $(if $(N),-n $(N)) $(PERMUTE_ARGS)

# Éprouve un lot de formes sur un même fragment de source.
# `make measure S=IsClearPractice__16CDngFloorManagerFi V=perm/boucle.py`
measure:
	@test -n "$(S)" -a -n "$(V)" || { echo "usage : make measure S=<symbole> V=<variantes.py>" >&2; exit 1; }
	@$(PYTHON) scripts/diff/measure.py $(S) $(V)

# Ouvre une unité : la déclare et écrit sa source, tout en INCLUDE_ASM.
open:
	@test -n "$(S)" || { echo "usage : make open S=<classe>" >&2; exit 1; }
	@$(PYTHON) scripts/build/open_unit.py $(S) $(OPEN_ARGS)

# L'exécutable bootable, et l'image qui le porte : la construction rend le
# contenu de la section chargée, non les en-têtes que la console lit.
elf: build
	@$(PYTHON) scripts/build/pack.py elf

iso: build
	@$(PYTHON) scripts/build/pack.py iso $(if $(ISO),--output $(ISO))

# Retouche l'exécutable construit sans toucher aux sources :
#   make mod M="IsGeoStone__16CDngFloorManagerFi=1"
mod: elf
	@test -n "$(M)" || { echo 'usage : make mod M="SYMBOLE=VALEUR"' >&2; exit 1; }
	@$(PYTHON) scripts/build/mod.py $(M)

# Découpe tout le code du jeu en unités, d'un coup.
#   make carve                      les plages proposées
#   make carve CARVE_ARGS=--apply   les déclare et écrit leurs sources
carve:
	@$(PYTHON) scripts/build/carve.py $(CARVE_ARGS)

# Les unités de travail : celles qu'on peut ouvrir, et ce qu'elles contiennent.
# `make units S=mgCFrame` détaille une classe.
units:
	@$(PYTHON) scripts/build/units.py $(S) $(UNITS_ARGS)

# L'atlas des types : ce que m2c infère du binaire entier, fusionné. Il tourne
# *sans* contexte — un type déjà déclaré fait cesser l'inférence — et c'est de
# lui que le contexte se construit ensuite.
atlas:
	@$(PYTHON) scripts/build/atlas.py $(ARGS)

# Ce que `.mwcats` dit de l'origine de chaque fonction : compilée depuis une
# source, ou recopiée d'une bibliothèque livrée compilée.
provenance:
	@$(PYTHON) scripts/build/provenance.py $(ARGS)

# La moisson : traduire, compiler, mesurer, ne garder que ce qui rend les octets
# du disque. `ARGS=--reprendre` repart de ce que `progress/chaine.json` sait.
chaine:
	@$(PYTHON) scripts/build/chaine.py $(ARGS)

# La seconde passe : reprend ce qui compile entre 85 et 100 %, la ou le gros
# des octets se trouve. `ARGS=--rendement` mesure ce que chaque idiome
# debloque au lieu de garder.
affinage:
	@$(PYTHON) scripts/build/affinage.py $(ARGS)

# `match_percent` dit de combien on s'ecarte, jamais ou. Cette passe repose
# chaque quasi-succes et releve les instructions qui divergent, puis les range
# par forme : c'est ce qui remplace le tirage d'idiomes a l'aveugle.
ecarts:
	@$(PYTHON) scripts/build/ecarts.py $(ARGS)

# Le releve d'ecarts melange les causes et leurs consequences : sept `sw`
# decales de quatre octets sur la meme base sont *un* champ manquant, et un
# `sd ra, K(sp)` ne dit rien de plus que le cadre de pile qui le porte. Cette
# passe impute chaque fonction a la cause qui domine ses ecarts et pese chaque
# classe en octets. Elle ne compile rien : une seconde, sur l'hote.
#   ARGS="--sous largeur"  range une classe par signature
#   ARGS="--classe cadre"  la liste entiere
classes:
	@$(PYTHON) scripts/build/classes.py $(ARGS)

# Mesurer une forme sans regreffer son unite : 550 ms au lieu de deux a cinq
# secondes, pour le meme chiffre au centieme pres. `ARGS=--fidelite 40` refait
# la mesure qui l'autorise, en comparant le score hors greffe a celui de
# l'unite sur quarante tirages.
lot:
	@$(PYTHON) scripts/diff/lot.py $(ARGS)

# Le meme travail, N formes par compilation : 3,5 ms par forme au lieu de 546.
# Les N formes tiennent dans une seule unite de traduction, chacune suffixee,
# et une reference synthetique porte les memes N noms pour un seul objdiff.
#   ARGS="--symbole X --combien 256"  eprouve la fidelite du banc
banc:
	@$(PYTHON) scripts/diff/banc.py $(ARGS)

# La forge : applique toutes les reparations connues, les compose en faisceau,
# mesure au banc, et ne garde que ce dont la reconstruction complete rend le
# sha1 du disque. Elle tourne sans surveillance et dit ce que chaque reparation
# rapporte, ce qui remplace l'intuition sur laquelle outiller ensuite.
#   ARGS="--garde"       pose pour de bon
#   ARGS="--rendement"   le seul compte par reparation
forge:
	@$(PYTHON) scripts/build/forge.py $(ARGS)

# La taille exacte de chaque classe, lue aux sites ou le jeu l'alloue. m2c ecrit
# `size >= 0x67C` parce qu'il ne voit que les champs employes ; le binaire, lui,
# passe le sizeof en argument a `operator new`, et la table virtuelle ecrite
# juste apres nomme la classe concrete. Une seconde, sur l'hote.
tailles:
	@$(PYTHON) scripts/build/tailles.py $(ARGS)

# L'ordre des methodes virtuelles et l'heritage, lus dans les 75 tables. C'est
# ce qui dit combien de virtuelles muettes declarer pour amener celles d'une
# classe au bon rang. Une seconde, sur l'hote.
vtables:
	@$(PYTHON) scripts/build/vtables.py $(ARGS)

# Le decalage et la largeur de chaque champ, en suivant `this` depuis `$a0`. Le
# mangling donne la classe, l'instruction donne la largeur : rien n'est infere.
# `ARGS=--controle` recoupe avec les tailles prouvees a l'allocation, deux
# derivations independantes qui doivent concorder.
champs:
	@$(PYTHON) scripts/build/champs.py $(ARGS)

# Les quatre releves joints en declarations de classe, chaque champ portant le
# symbole qui le prouve. `ARGS=--ecris` les pose sous include/prouve/, a cote
# des en-tetes engendres et non a leur place : les ecraser mettrait en jeu ce
# qui compile deja pour un gain non mesure.
entetes:
	@$(PYTHON) scripts/build/entetes.py $(ARGS)

# Le contexte que m2c lit, n'emettant que des types *complets* : une classe dont
# la taille est prouvee a un site d'allocation, fermee par un remplissage
# explicite. Mesure deux fois sur des methodes de ces classes : aucun effet sur
# le taux de compilation. Il ecrit build/ctx.c ; l'effacer le desarme.
contexte_prouve:
	@$(PYTHON) scripts/build/contexte_prouve.py $(ARGS)

# Ce que m2c ne sait pas lire, compte en fonctions perdues et en octets. Une
# seule instruction inconnue perd la fonction entiere : c'est ce releve qui a
# designe l'accumulateur flottant du R5900 comme le plus gros verrou.
instructions:
	@$(PYTHON) scripts/diff/instructions.py $(ARGS)

# Verse les champs de l'atlas dans les classes que le dépôt déclare vides. Une
# disposition ne change les octets que si le code l'emploie — sauf pour une
# classe de base, dont l'élargissement décale ses dérivées. `make build` tranche.
injecte:
	@$(PYTHON) scripts/build/injecte_atlas.py $(ARGS)

# Le contexte que m2c lit pour typer ce qu'il décompile, engendré depuis
# `include/` et l'atlas. Sans lui, m2c invente un nom de champ par décalage.
contexte:
	@$(PYTHON) scripts/build/contexte.py

# Ce qu'une construction paierait cher, décelé sans compiler : un en-tête
# engendré absent, une greffe sans désassemblage, deux unités qui se
# chevauchent. Une demi-seconde, sur l'hôte comme dans le conteneur.
controle:
	@$(PYTHON) scripts/build/controle.py

# La non-régression : les contrôles, puis les octets du disque. C'est ce que le
# hook `pre-push` lance, et ce qu'une intégration continue lancerait si le
# binaire du commerce pouvait sortir de cette machine — il ne le peut pas.
ci: controle
	@$(MAKE) build

# L'état du jour et la cadence, lus des sources : aucune construction, donc le
# chiffre sort en une demi-seconde et se consulte à chaque pas. `make report`
# reste la mesure fine, qui compare fonction par fonction.
etat:
	@$(PYTHON) scripts/build/etat.py $(ARGS)

# Part des octets qui viennent de source compilée plutôt que du désassemblage.
progress:
	@$(PYTHON) scripts/build/progress.py

# La configuration qu'objdiff lit : une unité par objet, avec son secteur.
#
# Les sources en sont une dépendance autant que le découpage : c'est leur
# présence qui donne à une unité son `base_path`, donc l'objet contre lequel
# objdiff la mesure. Sans elles, une unité dont la source vient d'être écrite
# reste sans base, et le rapport ne mesure aucune de ses fonctions.
objdiff.json: config/splat.yaml $(SRC_FILES)
	@$(PYTHON) scripts/build/gen_objdiff.py

# Les objets de référence, contre lesquels chaque fonction se mesure.
reference: $(REF_O_FILES)

# Rapport d'avancement en page web autonome, à ouvrir depuis le disque.
# objdiff lit les objets de référence, donc ils doivent exister.
report: objdiff.json reference
	@$(PYTHON) scripts/build/report.py

# --------------------------------------------------------------------------

clean:
	rm -rf $(BUILD_DIR)

# Efface aussi ce que `make setup` a engendré. Le disque reste.
distclean: clean
	rm -rf $(ASM_DIR) linker_scripts config/splat.yaml \
	       config/elf_symbol_addrs.txt config/main.sha1 rom/main.bin
