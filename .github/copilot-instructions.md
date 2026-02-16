<!-- Copilot instructions for contributors and AI agents -->
# Project snapshot: gestion-matrice

Purpose
- Short: small educational C project that implements dynamic matrices and simple I/O helpers.

Big-picture architecture
- Source roots: `src/` contains implementation `.c` files and an `include/` directory with public headers.
- Key components:
  - `src/include/matrice_float.h` — defines `matrice_t` and the public API for the simple matrix implementation.
  - `src/matrice_float.c` — concrete allocator, input, and print functions for `matrice_t`.
  - `src/main.c` — example runner that allocates a matrix, reads values, prints them, and frees memory.
- Notes: many files under `src/` are currently stubs (empty). There is no build system (Makefile/CMake); compilation is ad-hoc with `gcc`.

Developer workflows (how to build / run / test locally)
- Build (compile all `.c` files and include headers):

  gcc -I src/include -o bin/main src/*.c

- Run (from repository root):

  ./bin/main

- Quick alternative (compile into `src/` dir and run):

  gcc -I src/include -o src/main src/*.c
  ./src/main

- Tests: there are test sources in `src/tests/` but no test harness provided. Expect to add a small Makefile or CTest later.

Project-specific conventions & patterns
- Header placement: public headers live in `src/include/`; C files include them with `#include "include/<header>.h"`.
- Memory management: code uses manual `malloc`/`free` and expects callers (e.g., `main.c`) to free nested allocations (free each row, then `m`, then the struct). See `src/main.c` for the current pattern.
- Naming: functions in `matrice_float.c` use French identifiers (e.g., `allouer_matrice`, `saisir_coeffs_matrice`, `affiche_matrice`). Follow existing names when adding new functions.
- Type mismatch caution: despite the `matrice_float` name, the current implementation stores `int` values (`int **m`). Be consistent when extending (either rename to `matrice_int` or change types).

Observed code patterns and pitfalls (useful for PRs / fixes)
- I/O helpers use `scanf` directly (no validation). When adding features, validate input and avoid `scanf` for robust parsing.
- Watch loops and indices: `affiche_matrice` currently uses a wrong loop condition (`for (int j=0; i<mat->c; j++)`) — check index variables carefully.
- Allocation sizes: row pointer allocation uses `malloc(l * sizeof(int *))` — keep pointer types consistent.

Integration points and missing infra
- No external dependencies or libraries beyond the C standard library.
- No CI or test runner configured. Add a `Makefile` or simple `scripts/` to standardize build/test commands before adding CI.

What AI agents should do first (practical next steps)
- Prefer small, focused PRs: (1) add a Makefile or simple build script, (2) fix obvious bugs in `matrice_float.c` (printing loop, input prompts), (3) add minimal tests in `src/tests/` and a `run-tests.sh`.
- When editing code, include compile-and-run verification commands in the PR description.

References (files to open first)
- `src/main.c` — example usage and free pattern
- `src/matrice_float.c` — allocator, input, print implementation
- `src/include/matrice_float.h` — data type and API

If anything in this file is unclear or incomplete, ask for the preferred build target (binary location), whether matrices should hold `int` or `float`, and whether to add a `Makefile` or prefer a simple `build.sh`.
