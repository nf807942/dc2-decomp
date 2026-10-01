# What MWCC does with a form of C

Compiler: `mwcps2-3.0-011126`, `-O4,p`, `-lang c++`. Each rule is measured on a named
witness function; figures are `match_percent` before → after. Read this as soon as a
function plateaus.

## Types and layout

- **A vector copies as `lq`/`sq` only if its type carries a `u128`**
  (`union { f32 f[4]; u128 qw; }`). Never make it a field's type: it aligns the class to 16
  and shifts later fields. Keep fields `f32[4]` and cast only the copy,
  `*(VECTOR *)a = *(VECTOR *)b;` (`CCameraControl::ControlOn`, 99.94 → 100).
- **`Pf` in the mangling means `f32[4]`**, not a struct; `(f32 *)&this->pos` on a struct
  field is a conversion and reorders arguments.
- **A truncated read (`lh`) does not tell the width**; the function that writes the field in
  full does (`CMenuInvent` `0x114`). A type established on one function is a hypothesis.
- **vtables**: MWCC reserves the first two entries; the i-th declared method is at
  `(i + 1) * 4`, the first at `0x08`. A virtual call goes through `$t9`; a call through a
  pointer array goes through `$v0`. Declare an unknown class with as many silent virtuals
  as needed to reach the slot (69 for `0x118`; slot `0x44` = 15 silent + `Draw`).
  A vptr at a nonzero offset: `struct Base { char pad[0xD00]; }; struct V : Base { virtual … };`.
- **An inferred field lands one word too far when alignment pushes it.** m2c counts padding
  without aligning: `0xF0 + 1 + 0x588` = `0x679`, the next pointer aligns to `0x67C` where
  retail reads `0x678`. Reduce the padding by four (`SearchChara__12CActionCharaFPc`).
- **A stack slot carries retail's size and order.** Size = gap between two taken addresses,
  the last bounded by the frame. MWCC assigns stack in declaration order, lowest to the first
  declared; m2c writes them reversed (`GetAnalyzeFlag__9CEditDataFii`, 99.75 → 100).
  The type of stack buffers decides size and vector instructions
  (`f32 sp[16]; f32 sp2[4];` → frame `0x70`).
- **A flag byte modified by one bit is a bit-field**: `u8 alphaTest:1; u8 hi:7;`; the first
  declared field is bit 0 (`AlphaTestEnable__11mgCDrawPrimFi`).
- **`Ul` is 64-bit** (`s64`, `lui at,4` + `sd`); a 64-bit field written from a `u32` may
  need `s64` on the destination (`lwu`/`sd`).
- **Widening a base class shifts everything that inherits from it.** A layout changes no
  byte until something uses it (45 fields in `CMap` leave `Iam__4CMapFv` at 100); a widened
  `mgCCamera` moves `CCameraControl` fields and breaks 132 bytes.
- **`slt` vs `sltu`**: the sign of the type decides (`NowTakePhoto__Fv`).

## Addressing

- **A global outside the `$gp` window is reached as a struct field, never as an indexed
  array.** `EdEventInfo.field_0x126C = 0` gives `lui at,%hi` + `sw %lo(at)`;
  `*(s32 *)&EdEventInfo[0x126C] = 0` materializes the address (`ResetNpcTalkMes`, 54 → 100).
  Same for reads, and for signed 16-bit offsets past `0x7FFF`
  (`struct { char pad[0xA490]; s32 f; }`, not `(u8 *)p + 0xA490`). One distinct struct per
  offset when needed (`EventScene`).
- **The declared size of a global decides `%gp_rel` vs `%hi`/`%lo`.**
  `config/elf_symbol_addrs.txt` gives it. An `extern` global is addressed through `$gp` by
  itself, without a flag (15,869 `GPREL16` relocations depend on it).
- **A shared literal is declared `extern char _5066[];`**, not written (writing it emits it
  in the object's `.rodata`).
- **A global read, then called, is held in a local** — an intervening write may alias it
  (`CMenuKeyFunc *common = MenuCommonInfo;`, 97.77 → 98.73). A `$gp` global read twice:
  `u8 *p = (u8 *)EventScene;`.
- **A field reached several times is taken by its address.** Retail hoists `&pad->phase`
  into a saved register. Symptom: `addiu sN, base, offset` on retail where we carry the
  offset in each `lw` (`read_pad`, 77 → 100).
- **An address taken before a guard stays materialized before the branch**
  (`&mgTexManager` in a local, `MenuReloadTexture__FRii`, 66 → 100).
- **A function-local static is declared `extern` with its number** (`old_viewmode_8715`) and
  its guard written by hand.
- **A name the disassembler disambiguated is called by that name**: `extern "C"` plus a
  unit-local `#define` (`GetStackInt__FP12RS_STACKDATA_00262DA0`).
- **A distant field**: `&((struct { char pad[0x1D2A0]; char m; } *)p)->m` gives
  `lui`/`ori`/`addu` with `$at`; `p + 0x1D2A0` uses an ordinary register.
- **An array of unknown size re-read as `u16`** goes through a pointer local
  (`u16 *p = (u16 *)Buf; return *p;`, `GetHalfFontNum__Fv`); a constant offset into an
  extern `char` array folds into `%hi/%lo` unless read through a struct.
- **An offset global address as an argument** folds with a scalar index:
  `&(&mgRenderInfo.field_0x0)[0x68]` (`mgTransWorldView__FPfPf`).
- **A global whose type is defined later** needs a forward declaration (`struct X;`), else
  MWCC takes it for an `int`.

## Call sites

- **Arguments are emitted in increasing register order; a conversion breaks this.** The
  converted argument is materialized first, even at zero cost. Symptom: `a1` set before
  `a0`. It holds against 21 versions, 30 pragmas, 450 permuter attempts. `CSphida::SetUp`
  98.17 → 100 by removing argument casts.
- **A prototype parameter's type decides call scheduling**; when the body resists, the gap
  may be outside the function (`Init`: `void *dma` → `u8 *dma`, 93.70 → 100). A typed
  prototype also fixes load order of memory arguments that `(...)` reverses
  (`GetLWMatrix`, `mgMulMatrix`, `sceMcRead`).
- **A `void *` parameter is an exception**: all-`void *` pointers cost nothing (83 % vs 85 %
  on 203 functions). The rule holds for conversions that change representation.
- **A `(...)` prototype is byte-neutral** for the call itself; it lets two callers designate
  one callee. Caveat: default promotion (`float` → `double`), so type float parameters
  (`SetStack(RS_STACKDATA *, f32)`). A function declared `(...)` in the unit cannot then be
  defined with typed parameters: type the declaration line first.
- **A parameter's slot is reused only if the source writes to it**
  (`mpeg = (sceMpeg *)mpeg->work;` matches, a local does not). Also holds for loop counters
  living in the parameter register (`InitItemMes__9CGameDataFii`).
- **Constants: one work register or two.** With several float constants, either one register
  with `mtc1 zero` filling the slot, or two registers (paired `lui`, zero last).
  **A polymorphic class constructor gives the first, an ordinary function the second**
  (`CCameraControl::CCameraControl`, 90.67 → 100); the lever does not leave the constructor.
  It is decided by whether `$v0` is free; `#pragma schedule off` / `-O2` give the first form.
  The binary pairs two float constants only starting from `$v0`.
- **Emission order of a series of stores is source order**, ascending offsets, not parameter
  order (`CameraCtrlParam`, 21 instructions at once; `SetCameraInfoTable`).
- **A named expression is read earlier than one written in place**: `p = GetActiveParam();`
  80.95 → 100 (`SetHeight`); naming a difference, 79.35 → 100 (`SetRotate`). The source
  decides the *read point*, not write order.
- **A call result stored in an unused parameter** passes ahead of the previous argument
  (`arg1 = GetWindowMode(mes); SetStack(next, arg1);`).
- **Evaluation order**: `t = f(x); t & mask;` vs `f(x) & mask` swaps operands.
- **Script stacks**: `RS_STACKDATA` is 8 bytes: advance with `arg0++` / `p++` (3-slot vector
  `arg0 += 3`); an incomplete type refuses `arg0++`, use a local struct pointer.
- **Tail calls**: `j f` is `return f(…)`, return type irrelevant (`s32` or `void`); what the
  `j`'s delay slot carries is written before the call (`f(object + N)` with `u8 *` self; a
  constant store before). A `u8` forwarded from a `u8` callee needs the same return type.
- **A signature already placed in the unit, even further down, is imposed identically**;
  other forms give "illegal function overloading". A later-defined type needs `struct X;`.
- **A return that survives to `jr ra` is the function's return** even when unsaid: an `lw` of
  the old value before the `sw` means `old = x; x = a; return old;` (`PauseEnable__Fi`); a
  `void` makes MWCC reuse `a1` (96 %). Also `texBugPatch = 1; return 1;`.

## Expressions

- **`s += f()` gives `addu s0,s0,v0`; `s = f()` gives `daddu s0,v0,zero`** — even when `s`
  was zero (`DeleteItem_Local`, 92.76 vs 93.98).
- **`x += c` gives `add.s f0,f1,f0`; `x = x + c` gives `add.s f0,f0,f1`.** The compound form
  also moves the read after a call on the right side, saving a saved register and 16 bytes of
  stack (`MenuItemDebugKey`, 95.87 → 97.53). The same holds for whole float expressions
  (`t = b - a; t -= c; t *= d; t += a;`, 96 → 100) and `x = 1.2f * x`.
- **A float comparison carries the constant on the left**: `255.0f < x` gives `c.lt.s`;
  `x > 255.0f` gives `c.le.s` + `bc1t`.
- **`x > 99` writes the `slti` in `$at`; `x >= 100` in the compared register.**
  `(x < 2) ^ 1` for `>= 2` on an `s16` (else extra `andi 0xff`).
- **Boolean inversion**: `(f() == 3) ^ 1` keeps the `xori`; `!(f() == 3)` adds `andi 0xff`.
- **Float negative in a `default`**: `x < -10` gives `slti at` + `beqz`; `x > -11` the other way.
- **`movz`** comes from `c ? K1 : K2` where one is a lone `lui`.
- **Zeroing constructors**: `memset(this, 0, size); return this;` (five `__ct__` at 100).
- **`char *` read by `lb`** is declared `s8 *` in the body (`-char unsigned` otherwise `lbu`).
- **Struct-typed accessors**: an address taken on a real `f32[4]` field materializes `this`
  first (`SetVertex__6CWaterFPfPf`); vector copy with offset in "get" direction uses element
  steps on `f32 *self`.
- **A stack vector whose fourth word is written apart**: `struct { f32 v[3]; u32 w; } q;`.

## Control flow

- **A conditional block goes *inside* the condition**, not after it. Symptom: 4 extra bytes,
  shifted tail.
- **Two identical exits are written twice.** Retail often emits `b` to the tail with the
  value in the delay slot; that is two distinct `return` statements (`CScene::SearchCharaTexb`,
  93.3 → 100; `ChkEventEditStart__Fv`). Test direction files them: `if (x != 1) return 0;
  return 0;` gives `beq`, `x == 1` gives `bne` (`CEditEvent::Draw`).
- **A one-case dispatch is not an `if`**: `switch` keeps exits distinct and leaves the delay
  slot empty (`IsLevelUp`, 97.76 → 100). A `switch` that fills a variable then returns keeps
  the `b end; nop` exits.
- **An empty delay slot is filled by evaluating the assignment inside the condition**:
  `if (t == NULL || (i = 0, n) <= 0)` (`GetDngMapFloorGlidInfo`, 91 → 100); and
  `if ((p = f()) == NULL)` leaves the test on `v0` (`daddu` in the slot).
- **An offset address is computed before the guard, not after**: MWCC then puts it in the
  branch's delay slot. Nine expression shapes gave 94.29; two placements before the guard gave
  100 (`_DATAWEP__FP9SPI_STACKi`).
- **A value used in a loop is computed there**: `j = i + 8` in the body gives
  `addiu s2,s1,8` each turn; initializing before the loop gives `addiu s2,zero,8`. m2c
  hoists it out; put it back.
- **MWCC unrolls by itself, 8 at a time**: write the ordinary loop (`CPadControl::Initialize`,
  `InitMesWinTbl__6ClsMesFv`).
- **Appending to a list** keeps m2c's double test (`do { q = last->next; if (!q) break;
  last = q; } while (q);`); variables `p`, `last`, `q` in that declaration order.
- **`#pragma schedule off` … `reset`** around a definition (file level, not in the body)
  gives retail's empty delay slot when retail writes `daddu v0,zero,zero; jr ra; nop`, a `lw`
  before `jr`, or a last `sw` outside the slot (12 functions in `mgCVisual*`, `Set__9mgRect_i_Fiiii`
  73 → 100). Wrong spelling `#pragma scheduling` is silently ignored. Conversely a tail call
  with a computed argument wants the scheduler on.

## Switches

- **Jump table from six cases**; below, a `beq` cascade from the highest case to the lowest.
- **The table is bounded by the largest declared case, from zero.** An empty case emits
  nothing but decides the size: `case 11:` that does nothing (84.53 → 86.14). Entry 0
  pointing to the default needs an empty `case 0xA0:` before `default:`.
- **Source case order is emitted order** (`MenuItemKey`, 90.65 → 98.71).
- **`addi` does not sign handwritten code**: it normalizes an index whose first case is
  negative.
- **A generated table's name (`@24` vs `@5068`) is not a divergence**; `make build` decides.
  `soumettre --table` keeps from 99.9 %.

## Loops

- **The counter's name decides its register**: MWCC allocates by declaration order, not
  nesting; `j` outside, `i` inside (`UpDate`, 99.87 → 100).
- **Two successive loops want two counters** (`IsClearPractice`, 18 instructions of 209).
- **An empty loop survives only under `!=` or an increment in the condition**
  (`i = 0; while (++i < 7) {}`); only that form leaves the signed `slti`.
- **A variable declared before another swaps two callee-saved registers**
  (`GetTerritoryParts__8CEditMapFiPii`, `LoadOmakeFile__18CMemoryCardManagerFv`).

## Inline asm (COP2) and `volatile`

- `asm { sqc2 vf0, 0(v) }` in a `float *v` function gives `jr ra` with the `sqc2` in the slot.
  The `mgmath` vector functions are `asm {}` with named `vfNN` registers (`lqc2`, `vadd.xyzw`,
  `sqc2`); MWCC does not reallocate `vf`.
- A `volatile` counter field keeps the second `lw` between test and `sw`
  (`voBufDecCount__FP5VoBuf`).

## Method facing a plateau

0. **`make etat`** before choosing: what is written, what remains, at what pace.
1. **Count on the whole disassembly first.** A supposed compiler property is checked in one
   second on thousands of sites (it unblocked `CSphida::SetUp` after 450 failed permuter
   attempts; counting 2,312 call sites showed retail uses both argument orders).
2. **`make measure S=… V=…`** compiles all forms of a fragment framed by `/* @@name */` …
   `/* @@fin */` in one pass (`GetDngMapFloorGlidInfo` 74 → 100 in six batches).
3. **Change witness when the function is too big**: a 288-byte function carries the same
   pattern as a 5,836-byte one (`scripts/diff/sonde_lot.sh`).
4. **`make permute`** searches blindly when you no longer know what to ask. Its yield improved
   once an attempt cost 546 ms instead of 4.8 s (427 attempts, 7 functions to 100).
5. **objdiff's `match_percent` is the verdict**, never a diff line count. The left column of an
   objdiff diff is retail; reading it backwards reversed two verdicts.
6. **Blame the toolchain last.** A plateau that resists C forms *may* be another compiler
   version (empty delay slot where retail has an instruction): measure all 21
   (`make tools TOOLS_ARGS=--all`). On `MenuItemDebugKey`, only `3.0-011126` and `3.0.1-020123`
   give the right size, and `3.0-011126` matches best (99.84 %); the 2.x give retail's
   scheduling but a wrong size and `sq ra` where retail has `sd ra`.
7. **A probe must prove it changed the text before compiling it.** Three separate "refutations"
   (stack-order inversion, width correction, `s32`→`s32`) were null transformations.
8. **A measurement is valid only if the function stopped being grafted**: a failed graft
   compiles its own assembly and scores 100 %. And objdiff alone overstates gains by about 2×
   (3 real gains in 80): only the full rebuild proves one.

## Recurring pitfalls

- **Declaring a polymorphic class makes our object emit its vtable**; the link sees it twice
  while the disc carries it. `-RTTI off` removes the RTTI, not the table.
- **A shell class is redefined like a full class** ("tag 'CMap' redefined"): "should this type
  be placed?" and "is this name taken?" are different questions, answered by following
  includes transitively (23 of 24 diagnosed compile failures).
- **With m2c, partial knowledge is worse than none**: a partial struct or opaque typedef makes
  it invent `unkXX` (3 compile, median 86.4 % without context; 1 compile, 68.7 % with).
- **Check a pattern that reads m2c on its output**: five families of functions were lost to
  regexes describing what we expected (`void *Name(`, `? *Name(`, chained arrows, by-value
  fields, `&sp` vs `&sp0`).
- **`make diff MWCC_VERSION=…` does not recompile the unit**: `touch` the source first.
- **Changing which functions are grafted needs `make setup`**; `make controle` flags it in
  half a second along with five other faults.
- **mwccgap `--as-flags` swallows everything after it**: placed before compiler flags it takes
  `-O4,p` along and compilation falls to `-O0` (13.77 % instead of 100).
- **A segfault at link time with no message** is an object missing a section the script asks
  for; `objdump -h` settles it.
