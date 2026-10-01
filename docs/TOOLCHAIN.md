# The binary and the toolchain

Everything here is measured and reproducible by `make setup`. Read it when touching the
split, splat, mwccgap, the link script, `make carve`, or the GCC lane.

## 1. The binary

- **Not stripped**: 17,298 symbols, 7,837 FUNC, 8,201 OBJECT, 99,876 relocations. One loaded
  section `main`, 2,608,512 bytes at `0x00100000`, sha1
  `eca0c93d5d6a25fcbf8f1fa41aa811a6f4b7aca8` (whole file 4,054,516 bytes).
- **Layout**: `.text` `0x001000D0`–`0x00325C60`, `.vutext` to `0x0032A380`, data and `.rodata`
  to `0x0037961B`, 49 static initializers `__sinit_*` `0x00379680`–`0x0037AFDC`, `.sdata` to the
  end of file `0x0037CD80`, bss to `0x01F64A00` (the heap starts exactly there). Groups follow
  each other on **8 bytes**, not 128 (a 128 alignment shifts all data by 0x78).
- **316 section symbols** give object-contribution boundaries (192 `.text`, 60 `.rodata`,
  32 `.data`, 21 `.bss`, …); splat's `find_file_boundaries` stays `False`. But two objects carry
  91 % of the code (1.43 MB and 628 KB) — the game's 49 translation units are not in the
  symbols, and padding between functions is plain alignment, not a boundary.
- **`gp_value = 0x003846F0`**, 15,869 `GPREL16` relocations. The window is full at the bottom
  (16 bytes of margin: `sin_table_num` at `_gp - 32752`) and empty at the top, so small data
  cannot gain more than 16 bytes while text is free (13 added instructions in
  `CGamePad::WaitEnable` moved `_gp` without overflow). We do not re-center `_gp`: it changes
  encoded bytes. The `_gp` *symbol* is `main_BSS_START + 0x7970`, not the `.reginfo` value.
- **`.vutext`**: 18,208 bytes of VU microprograms, no relocations; kept as bytes under `bin/` and
  relinked by `objcopy -I binary` (which defines none of their names: `normalize.py` writes
  `<name> = .;`).
- **A longer executable fits on the disc within 524 bytes** of sector slack; only the directory
  entry size needs fixing (both endiannesses).
- **Names**: 1,293 names designate several addresses (local statics, `@1069` literals, RTTI);
  Metrowerks characters `@`, `$`, `<>` are sanitized to `_`, then collisions are settled by
  address. The version string `MW MIPS C Compiler (2.4.1.01)` is written by MWLD and does not
  name the compiler.
- **Static initializers**: `mwInit` (`0x00100190`) calls `__initialize_cpp_rts(start,end,…)`,
  which walks the 49-pointer table `_p__sinit_*` (`0x0037AFE0`–`0x0037B0A4`). Bounds are loaded by
  `%hi/%lo`, so the link relocates them.
- **Provenance** (7,837 functions): game 86.1 %, Sony SDK 5.8 %, `mg*` middleware 4.3 %,
  Metrowerks runtime 3.8 %. Mangling puts the class after the function (`Draw__8mgCFrameFv`),
  so the class gives provenance, not the symbol start. Outside the game's two ranges
  (`config/sectors.txt`) each contribution votes by its own names, else inherits from its
  neighbour. The exact answer is **`.mwcats`**: the table of functions MWCC itself compiled
  (6,912 records of marker/size/address; sizes exact). The 928 absent functions are the Sony SDK
  and Metrowerks runtime, shipped precompiled. `make provenance` uses it.

## 2. The compilers

### MWCC (game, `mglib`)

- Installed by `make tools` from `decompme/compilers` (license-manager patch). Version
  **`mwcps2-3.0-011126`**, `-O4,p`, `-lang c++` (mwccgap's intermediate file is `.c`). Settled by
  measuring all 21 versions (`make tools TOOLS_ARGS=--all`): 100 % on `CDngFloorManager` where
  `3.0.1-020123`/`3.0.3` give 97/98, betas < 85, 2.x 77. `-fp` default `single` is retail's.
  decompals binutils need GLIBC 2.38 (image on Debian trixie); the link needs `-EL`.
- **Software floating point is not from our toolchain** (`runtime/fpmul`, `runtime/dpmul`):
  `__negsf2` stores locals at 0x00 and `ra` at 0x20 without saving registers (MWCC puts `ra` at
  0x00), and `__unpack_f` masks with `lui/ori/and` (MWCC: `dsll32/dsrl32`). Invariant across all
  versions and flags. Leave them grafted. Contiguous twin units; read a family before carving it.

### ee-gcc (Sony SDK, libc, libm)

The 1,082 SDK/libc functions (220,848 bytes, 10 %) are absent from `.mwcats`, carry
`gcc2_compiled.` markers, and save registers with `sd` as ee-gcc 2.9-ee does (2.95.x and 2.96 use
`sq`). `make tools TOOLS_ARGS=--gcc` installs eight builds under `tools/compilers/ee-gcc*`.

- **Version**: default `ee-gcc2.9-991111-01 -O2 -G0`, **chosen per unit** in
  `config/gcc_units.txt` (`<unit> [<version>]`; e.g. `sdk/sysbitflush ee-gcc2.96`, where
  `_sysbitNext` 77 → 100). `soumettre … --gcc-version V` enters a unit under a version; it covers
  the whole unit. Before hunting a source form for a 77–98 % plateau, run `gcc_essai.py` on all
  versions: a delay `nop` where the game has an instruction signals another version.
- **libc and libm are newlib 1.9.0** (public). On unchanged source: `copysign`, `finite`, `isnan`,
  `__kernel_cosf` 100 %, `floor` 99.75 %, all of `findfp.c` (`runtime/sfp`) and `mprec.c`
  (`runtime/multiply`, 17 functions) 100 %. The **Sony SDK has no public source** (`ps2sdk` is a
  reimplementation: right prototypes and structs, wrong bytes); write it from the disassembly, in C.
- **Not everything is C**: the game's `strlen` is hand-written MMI (`lq`, `psubb`, `pnor`, `pcpyud`;
  newlib's gives 58 %). Syscall stubs and `crt0` (`_exit`) are hand-written assembly; `make etat`
  counts them as "original assembly", done. COP2 is *not* hand-written: `libvu0` is inline asm
  (`__asm__ volatile ("lqc2 $vf4,0(%1)\n …sqc2 $vf6,0(%0)\n" : : "r"(d),"r"(a),"r"(b) : "memory")`;
  accumulator without `$`: `vopmula.xyz ACC,vf4,vf5`).
- **Wrapper `scripts/build/ee_gcc_cc`** poses as MWCC to mwccgap: copies the i386 compiler to `/tmp`
  (their 32-bit `stat` fails on Windows-mount inodes), `-ffunction-sections` then `.text.<fn>` →
  `.text`, renames GCC's empty `.text`, rewrites mwccgap `asm void f(){nop…}` stubs into `__asm__`
  with `.ent/.end`, adds newlib and `include/gcc/` includes. Units of `src/sdk`, `src/runtime`
  go through it; **a unit mixing MWCC and GCC is refused** (`sdk/initseq`): split it in
  `config/units.txt`.

**Writing a GCC function**: `make dossier ARGS="<sym>"` (says C vs MMI and the newlib source);
`newlib_source.py <sym>` flattens the source (`--cherche`, `--fonction`); `gcc_essai.py <sym> f.c
--inc …` measures under every build/option (`--montre` shows differing instructions);
write C in the unit's `.cpp` (the file name stays, `-x c` is passed), newlib body as is with its
licence header, functions in address order, **no data definitions** (they come from `asm/data/`;
declare `extern`); `soumettre.py <sym> attempt.c` keeps at 100 %; `make build` is the verdict.

GCC lessons (each measured):
- Newlib renames by macro (`#define Balloc _Balloc`): write the binary's symbol in `_DEFUN`.
  A local static has another name in the binary (`p05.27` → `extern const int p05_27[3];`).
  Source gaps vs the SDK: a store absent from the game (`std`: `_bf._size = 0` removed, 95.41 →
  100); `_d2b` `if ((y = d1) != 0)` form (97.58 → 100); `srand` writes `_impure_ptr+0x58` as a
  32-bit store (the game's `_reent` differs).
- **Fixed prototypes for stubs**: a variadic `ioctl(int,int,...)` pushes `a2`–`a7` (0 %).
- **Return type decides tail call**: `void` gives `j SignalSema`; `return SignalSema(...)` gives a
  prologue + `jal` (0 %). A non-tail call wants `int` and declared parameters (`void f(void)` gives
  `j`, 20 %). A "void" function whose old value is still in `v0` really returns it
  (`sceGifPkReserve`: `T *q = p->p; p->p = q + n; return q;`).
- **Store order**: GCC's scheduler reorders `sw`; write *field order*, or a local target struct with
  fields reversed (`_alalcInit` 99.40 → 100). Repeated `*(T *)(base+off)` reloads the base; a target
  local struct fixes it.
- `typedef int u128 __attribute__((mode(TI)))` gives `sq`; `register u128 t __asm__("$6"); t = *s;
  *d = t;` pins the `lq/sq` register (`sceVu0CopyVector` 96.67 → 100); `__asm__("" : "+r"(s));`
  freezes a constant base. `fabsf`: use `GET_FLOAT_WORD/SET_FLOAT_WORD` (`include/gcc/ieee754.h`).
  CP0 (`mfc0`, `ei`) via `__asm__ volatile`; emitted order follows the asm statements.
- A shared global keeps its first declaration's type in the unit; a failed compile leaves its
  `extern`. `soumettre` leaves an attempt's typedefs/defines in the unit: use distinct type names.
- Unproven: partially written GCC units kept in the repo; newlib data tables; most of
  `libgraph/libdma/libpad/libipu/libvif1`.

## 3. mwccgap and the graft

- **mwccgap is what makes function-by-function replacement possible.** MWCC emits a unit's text in
  one block and accepts only fully defined assembly; mwccgap replaces an unwritten function by
  `nop`s, assembles the reference `.s` aside, then grafts it back repairing relocations
  (`INCLUDE_ASM("text/0012C1A8", Close__8CGamePadFv)`).
- **Third-party fixes are versioned as patches** (`tools/patches/*.patch`, `make patch`; the
  `tools/.patched` witness is a dependency of each object; `make patch PATCH_ARGS=--update`
  rewrites). Beware: `git apply` refuses translated line endings, and a Windows-cloned submodule is
  CRLF. Ours: m2c register names (o32 vs EABI); alignment of grafted symbols; jump tables declared
  grouped in address order (MWCC emits some series backwards — 16 of 52 units); **label section
  index** (labels defined in a grafted `.text` get the function's section — without it objdiff fails
  with "Symbol data out of bounds").
- **Rules and recompilation**: Makefile rules must list `$(MWCCGAP_SRC)`, `$(UNITS)` and
  `$(SRC_FILES)`, or an "identical" rebuild proves nothing; changing `config/units.txt` without
  rebuilding gives a segfault at link, not a byte divergence.
- **MWCC aligns each emitted section to 16 bytes**; the linker fills up to there, so a symbol the
  binary places elsewhere is pushed. mwccgap fixes this on what it grafts; a *written* function
  keeps 16 (4,994 of 5,002 game functions conform; the 13 exceptions are runtime/libc helpers).
- **Read-only grafting**: mwccgap reads a grafted function's `.rodata` but recognizes the
  unmatched-symbol marker only as `nmlabel` (`asm_nonmatching_label_macro: nmlabel`) and *only* in
  that section; `normalize.py` removes it from text (else "Not enough assembly to fill") and drops
  comments under strings. Padding between migrated read-only symbols comes from section alignment.
- **`make lot` measures a form without regrafting** (546 ms vs 2–5 s). It matched the in-unit score
  to the hundredth on 55 of 60 functions (the rest do not compile outside the graft). Context is
  taken from the unit, never invented (a type declared as a function gives a syntax error).
- **Cost of an attempt follows unit size** (0.6 s fully written, 1.7 s for 72 functions); do not cut
  finer — position in a section decides loop-head alignment. Avoid per-unit `make`/`nm` calls
  (0.74 s each); pass all objects at once; `find -prune`.

## 4. The split

- **A work unit is declared in `config/units.txt`** — `<start> <end> <sector>/<name>
  [rodata:<start>-<end>]` — and becomes a splat `cpp` subsegment (type `cpp`, not `c`): one function
  per file under `asm/nonmatchings/<name>/`, linked from `build/src/<name>.o`. It is the only
  hand-written part of the split. Binary stays identical while function order is kept.
- **Two disassemblies**: `config/splat.ref.yaml` keeps everything in assembly under `ref/asm` (the
  objdiff target); `asm/` only what is still to do, because splat stops extracting a function once a
  source defines it. The included-file header needs `.set noat/.set noreorder` and
  `.include "macro.inc"` (without them: one `nop` more per grafted function, 3,409 divergent bytes).
- **m2c** stops on the `nmlabel` marker; `decompile.py` strips it in a temp copy, adds the
  label-bearing read-only blocks, and renames jump tables `jtbl…` (`config/symbol_addrs.txt`
  corrects `@1200` → `jtbl_00377F10`). The disassembler does not rewrite existing files: erase
  `asm/nonmatchings` after changing `asm_inc_header`; it also writes a wrongly-formatted default
  source for a `cpp` subsegment that has none.
- **Bounds**: a function's position in its section matters (loop-head alignment is computed from
  the section start). **A unit's upper bound is what its object produces** — end of the last function
  when written, start of the next while still grafted (`gamepad` `0x0014B500` → `0x0014B4F4`); wrong
  gives a `jal` whose target loses 4 bytes. An object-contribution boundary wins over a declared unit
  (`config/elf_sections.txt`; symptom: an `INCLUDE_ASM` whose file does not exist). Splitting stops at
  `.vutext`, never at the last FUNC (the `__sinit_*` live after the data; taking them for text slides
  everything and overflows `%gp_rel`).
- **Jump tables and `rodata:` ranges**: a function with an indirect jump brings its table (`grep -c
  jlabel ref/asm/text/<unit>.s` tells). spimdisasm migrates a read-only symbol only if migratable
  (string, ≥3-label jump table, float with null tail), referenced by exactly one function, and inside
  the unit (`allowRdataMigration = False` for MWCCPS2). **A range stops exactly where its last table
  ends**: wider, it swallows a symbol that is then written nowhere (segfault preceded by `%gp_rel`
  overflows). The padding that ends a range depends on a neighbour's alignment. A table may end on
  zero words; keep the whole symbol. One table per unit tightens an over-wide range. Predicates on
  migration are tested against the disassembly, not a rebuild.
- **`make carve`** cuts the game from end to end: aims at a size, picks the boundary leaving fewest
  classes straddling, cuts at every contribution boundary. 988
  functions outside the game's ranges occupy only 182 contributions.
- **Data and bss**: one `bss` subsegment from the file end (absolute symbols 2,503 → 55); `.vutext` is
  bounded at its first sized symbol; splat declares undefined what spimdisasm defines (`normalize.py`
  removes those a `dlabel` defines); `symbol_addrs.txt` overrides `elf_symbol_addrs.txt`; the 1-2 byte
  objects between words need `type:u8` (the ten `CHA_DEV_FONT_PIECE_*`); sixteen symbols stay
  absolute (`_xlaunch` unresolved, a mwccgap matter).

## 5. Progress report

- `objdiff.json` depends on sources (`src/<unit>.cpp` gives a unit its `base_path`) as well as the
  split. A grafted function matches at 100 % by construction (the object holds the disc's bytes), so
  objdiff alone overstates progress: `make report` runs `scripts/build/filter_report.py`, which zeroes
  functions still under `INCLUDE_ASM` (except original hand-written assembly, which cannot be
  decompiled) and recomputes the unit, category and total measures. `make etat` counts from sources.
- Function count and byte count differ (2.84 % vs 0.57 % early on): the 975 functions of ≥ 512 bytes
  hold 59 % of the code.
- **decomp.dev** reads a GitHub Actions artifact `<version>_report` of a public repository,
  registered once at `/manage/new`. `make report` writes `progress/report.json`;
  `.github/workflows/progress.yml` fetches the disc from a private repo (deploy key) and uploads
  `pal_report`. The objdiff app reads `objdiff.json` locally for function-level work.

## 6. What other projects provide

- **Metrowerks runtime sources** are in the CodeWarrior installer (`PS2_Support/Runtime/Sources/`:
  `newop.cpp`, `MWRTTI.cpp`, `__ptmf.c`, `ExceptionHandler.cp`…): proprietary, read as reference, never
  copy. The C library is shipped compiled only.
- **`ps2sdk`**: reimplementation, worthless for bytes, useful for exact prototypes and structs
  (`PAD_STATUS`, GS environments).
- **DCDecomp** (Dark Cloud 1) shares the middleware classes without the `mg` prefix; 16 of 45
  `mgCFrame` methods match by name, but DC1 has only declarations, so signatures transpose, not code.
- **objdiff's CodeWarrior demangler** names 86 % of functions (303 classes); `make units` uses it.
