# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

Personal solutions to Advent of Code puzzles, written in C++23. Each day is a
standalone program that reads a puzzle input file and prints answers for Part 1
and Part 2.

## Commands

```sh
make new   YEAR=2015 DAY=2   # scaffold a new day from templates/day.cpp.tmpl
make run   YEAR=2015 DAY=1   # build and run a day (uses its input.txt)
make build YEAR=2015 DAY=1   # just build
make clean                   # remove build artifacts (bin/)
```

There is no test suite or linter target; correctness is checked by running
against the puzzle input and comparing the printed answers to the values AoC
accepts.

## Architecture

- `common/aoc.hpp` — header-only helpers shared across all days (`read_file`,
  `read_lines`, `split`). Add new shared utilities here rather than
  duplicating parsing code per day.
- `common/md5.hpp` — header-only MD5 implementation (RFC 1321), no external
  dependencies. `#include "md5.hpp"` and call `aoc::md5(str)` to get a
  lowercase hex digest. Needed for puzzles like 2015 day 4.
- `templates/day.cpp.tmpl` — scaffold for new solutions. `make new` copies
  this into `<year>/day_<n>/day_<n>.cpp`, substituting `{{YEAR}}`/`{{DAY}}`.
  Each solution's `main` takes an input file path as `argv[1]`, reads it via
  `aoc::read_lines`, then computes Part 1 and Part 2 in separate scoped
  blocks, each printing `"Part 1: "` / `"Part 2: "` followed by the answer.
  Keep this shape when writing new solutions.
- `<year>/day_<n>/input.txt` — personal puzzle input, gitignored per AoC's
  request not to share inputs. After `make new`, paste the puzzle input here
  before `make run` will work.
- `bin/<year>/day_<n>` — build output (gitignored), one binary per day.
- Compiled with `g++ -std=c++23 -O2 -Wall -Wextra -Wpedantic -Icommon`
  (mirrored in `compile_flags.txt` for clangd/editor tooling).
