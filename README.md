# Dark Chronicle Decompilation Project

[![Code PAL Progress]](https://decomp.dev/nf807942/dc2-decomp/pal)

[Code PAL Progress]: https://decomp.dev/nf807942/dc2-decomp/pal.svg?mode=shield&label=PAL&measure=matched_code_percent
[progress_link]: https://decomp.dev/nf807942/dc2-decomp/pal

[<img src="https://decomp.dev/nf807942/dc2-decomp/pal.svg?w=512&h=256" width="512" height="256" alt="Progress">][progress_link]

*Matching* decompilation of **Dark Chronicle** (*Dark Cloud 2*) for the PlayStation 2,
PAL version `SCES-51190`, in C++.

The goal is to write the C++ that, recompiled by the period compiler, gives **the exact
bytes of the disc**. The verdict is binary and measured at every build. The method is that
of [decomp.wiki][wiki].

| | |
|---|---|
| Build identical to the disc | **yes** — 2,608,512 bytes, sha1 `eca0c93d5d6a25fcbf8f1fa41aa811a6f4b7aca8` |
| Compilers | `mwcps2-3.0-011126 -O4,p` (game), `ee-gcc 2.9x` (Sony SDK and libc) |

This repository contains **no game data**: no disc, no executable, no disassembly. All of
it is regenerated from your own copy of the disc.

## Building

1. Install Docker or Podman. The whole toolchain lives there.
2. Clone the repository: `git clone --recurse-submodules <url> && cd <repository>`
3. Put the PAL disc image in `rom/`, e.g. `rom/Dark Chronicle (Europe).iso`.
4. Run:

```sh
scripts/host/dc2 make tools    # installs the compilers
scripts/host/dc2 make setup    # extracts the disc, writes the config, disassembles
scripts/host/dc2 make build    # assembles, links, compares to the disc
```

`make build` must print "identique au disque" (identical to the disc). Anything else is a
regression.

## Working on a function

```sh
scripts/host/dc2 make etat                              # what remains to be written
scripts/host/dc2 make decompile S=Close__8CGamePadFv    # first draft from m2c
scripts/host/dc2 make diff      S=Close__8CGamePadFv    # verdict against retail
```

Symbols are written mangled, as the binary carries them: `Close__8CGamePadFv` is
`CGamePad::Close(void)`. `make diff` compares the function to the original with
[objdiff][objdiff]; `100 %` means it is rebuilt.

`make report` writes `progress/report.json`, the objdiff report that [decomp.dev][dev]
reads; `.github/workflows/progress.yml` publishes it on every push.

## Documentation

* [docs/IDIOMS.md](docs/IDIOMS.md) — what MWCC does with each form of C
* [docs/TOOLCHAIN.md](docs/TOOLCHAIN.md) — the binary, the compilers (MWCC, ee-gcc), the split, the link

## Contributing

Do not version anything derived from the game: `.gitignore` and the pre-commit hook
(`git config core.hooksPath .githooks`) refuse it, and must not be bypassed. A function
counts as progress only if `make build` stays identical to the disc.

## License

[MIT](LICENSE). Dark Chronicle belongs to its publisher; this project is neither affiliated
with nor endorsed by it, and distributes none of its files.

## References

[Decompedia][wiki] · [DCDecomp][dc1] (Dark Cloud 1) · [splat][splat] · [objdiff][objdiff] ·
[m2c][m2c] · [mwccgap][mwccgap]

[wiki]: https://decomp.wiki/
[dev]: https://decomp.dev/
[dc1]: https://github.com/Adubbz/DCDecomp
[splat]: https://github.com/ethteck/splat
[objdiff]: https://github.com/encounter/objdiff
[m2c]: https://github.com/matt-kempster/m2c
[mwccgap]: https://github.com/mkst/mwccgap
