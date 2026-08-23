# advent_of_code
My solutions to advent of code problems, written in C++.

## Layout

```
common/                   shared helpers (aoc.hpp)
templates/day.cpp.tmpl    template used to scaffold new days
<year>/day_<n>/
    day_<n>.cpp           solution
    input.txt             personal puzzle input (gitignored, not committed)
```

## Usage

```sh
make new   YEAR=2015 DAY=2   # scaffold a new day from the template
make run   YEAR=2015 DAY=1   # build and run a day (uses its input.txt)
make build YEAR=2015 DAY=1   # just build
make clean                   # remove build artifacts
```

Puzzle inputs are personal to each account, so `input.txt` files are gitignored
per AoC's request not to share them. After scaffolding a new day, paste your
own puzzle input into `<year>/day_<n>/input.txt`.
