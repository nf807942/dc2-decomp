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
CONFIG    := config/splat.yaml
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
MWCC_VERSION ?= mwcps2-3.0.1-020123
MWCC_DIR  := tools/compilers/$(MWCC_VERSION)
MWCC      := $(MWCC_DIR)/mwccps2.exe

# `MWCIncludes` est la liste que MWCC consulte pour les `<...>` ; `-i` ne
# nourrit que celle des `"..."`. C'est par là que les déclarations du projet
# remplacent celles du SDK absent.
MWCC_ENV  := MWCIncludes=$(INCLUDE_DIR)

# -char unsigned et -str readonly : le R5900 ne signe pas ses `char` par défaut
# dans ce compilateur, et les littéraux du binaire sont en lecture seule.
# -Cpp_exceptions off parce que le binaire n'en porte aucune trace.
# `-c` n'y est pas : mwccgap l'ajoute lui-même devant ces drapeaux.
CFLAGS    ?= -O4,p -char unsigned -str readonly -Cpp_exceptions off \
             -sym on -i $(INCLUDE_DIR) -i $(SRC_DIR)

# mwccgap greffe l'assembleur de référence dans l'objet compilé : MWCC émet le
# texte d'une unité d'un seul bloc, donc une fonction non encore reconstruite ne
# peut pas venir d'un objet voisin.
#
# `--as-flags` prend un nombre libre d'arguments, donc il avale tout ce qui le
# suit : placé avant les drapeaux du compilateur, il emporte `-O4,p` et la
# compilation retombe silencieusement en `-O0`. Il vient donc en dernier, après
# les drapeaux destinés à MWCC.
MWCCGAP      := $(PYTHON) tools/mwccgap/mwccgap.py
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

S_FILES   := $(shell find $(ASM_DIR) -name '*.s' 2>/dev/null)
# Les microprogrammes des unités vectorielles restent des octets : leurs
# instructions ne sont pas du MIPS, et aucun assembleur de la chaîne ne les
# relit. Le désassembleur les dépose sous bin/, l'éditeur de liens les veut
# en objets.
BIN_FILES := $(shell find bin -name '*.bin' 2>/dev/null)
O_FILES   := $(addprefix $(BUILD_DIR)/, $(S_FILES:.s=.o) $(BIN_FILES:.bin=.o))

.PHONY: all setup tools split build check diff decompile clean distclean \
        progress report

all: build

# --------------------------------------------------------------------------
# Préparation
# --------------------------------------------------------------------------

setup: split

config/splat.yaml:
	$(PYTHON) scripts/setup/configure.py

split: config/splat.yaml
	$(SPLAT) $(CONFIG)

# --------------------------------------------------------------------------
# Construction
# --------------------------------------------------------------------------

build: check

$(BUILD_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# Un bloc d'octets devient un objet dont la section `.data` porte le contenu,
# ce que le script de lien engendré nomme explicitement.
$(BUILD_DIR)/%.o: %.bin
	@mkdir -p $(dir $@)
	$(OBJCOPY) -I binary -O elf32-littlemips -B mips:5900 $< $@

# Une unité reconstruite passe par mwccgap, qui appelle MWCC puis greffe
# l'assembleur des fonctions encore marquées `INCLUDE_ASM`.
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@test -f $(MWCC) || { echo "$(MWCC) absent — lancez \`make tools\`" >&2; exit 1; }
	$(MWCC_ENV) $(MWCCGAP) $< $@ $(MWCCGAP_ARGS) $(CFLAGS) $(MWCCGAP_TAIL)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@test -f $(MWCC) || { echo "$(MWCC) absent — lancez \`make tools\`" >&2; exit 1; }
	$(MWCC_ENV) $(MWCCGAP) $< $@ $(MWCCGAP_ARGS) $(CFLAGS) $(MWCCGAP_TAIL)

# Le compilateur, depuis les paquets de decompme/compilers.
tools:
	@$(PYTHON) scripts/setup/get_tools.py $(TOOLS_ARGS)

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

# Part des octets qui viennent de source compilée plutôt que du désassemblage.
progress:
	@$(PYTHON) scripts/build/progress.py

# La configuration qu'objdiff lit : une unité par objet, avec son secteur.
objdiff.json: config/splat.yaml
	@$(PYTHON) scripts/build/gen_objdiff.py

# Rapport d'avancement en page web autonome, à ouvrir depuis le disque.
report: objdiff.json
	@$(PYTHON) scripts/build/report.py

# --------------------------------------------------------------------------

clean:
	rm -rf $(BUILD_DIR)

# Efface aussi ce que `make setup` a engendré. Le disque reste.
distclean: clean
	rm -rf $(ASM_DIR) linker_scripts config/splat.yaml \
	       config/elf_symbol_addrs.txt config/main.sha1 rom/main.bin
