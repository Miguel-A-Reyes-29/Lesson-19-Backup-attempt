# Lab 19: Pokemon

CS210, Lesson 19: Structs Introduction
**Worth 2 points**, submitted on Gradescope.

You will build a small piece of a Pokedex: the header that declares a
`pokemon_t` struct and its related enum, and three functions that create,
modify, and print Pokemon.

## What you will write

Two files: `pokemon.h` and `pokemon.c`. `main.c` and `tests.h` are provided and
must not be edited.

### pokemon.h (you write the types; the prototypes are provided)

The header ships as scaffolding with four TODO markers. In order:

1. **An include guard** around the whole file (DFCS standard 4.1, from Lesson
   18). The autograder includes `pokemon.h` twice in one program; without a
   guard, that program does not compile.
2. **`enum PokemonType`** with exactly these six members, in this order:
   `TYPE_FIRE`, `TYPE_WATER`, `TYPE_GRASS`, `TYPE_ELECTRIC`, `TYPE_PSYCHIC`,
   `TYPE_NORMAL`.
3. **`struct Pokemon`** with exactly these six fields, in this order:
   `int pokedex_num`, `int hp`, `int attack`, `int defense`,
   `double catch_rate`, `enum PokemonType type`.
4. **A typedef** so that `pokemon_t` is another name for `struct Pokemon`.

The order matters: the struct uses the enum, and the provided prototypes use
`pokemon_t`, so each piece must come before the code that needs it. The names
are fixed because `main.c`, your tests, and the autograder use them.

**The template does not compile until the header has its types and
`init_pokemon` returns something.** That is expected. Write the header, then
`init_pokemon`, and build after each step.

### pokemon.c

Implement:

1. **`pokemon_t init_pokemon(int pokedex_num, int hp, int attack, int defense, double catch_rate, enum PokemonType type)`**
   Build and return a fully-initialized `pokemon_t` using a designated
   initializer.

2. **`pokemon_t set_hp(pokemon_t p, int new_hp)`**
   Return a copy of `p` with its `hp` field set to `new_hp` and every other
   field unchanged. `p` arrives by value, so it is this function's own copy:
   change it and return it. The caller's variable does not change unless the
   caller stores the result, which `main.c` does (`pk = set_hp(pk, new_hp);`).
   No pointers; that is Lesson 20.

3. **`void print_pokemon(pokemon_t p)`**
   Print the pokemon's fields. Use exactly this format, one line per field,
   no trailing whitespace:
   ```
   pokedex_num: <int>
   hp: <int>
   attack: <int>
   defense: <int>
   catch_rate: <double, three decimal places>
   type: <one of FIRE, WATER, GRASS, ELECTRIC, PSYCHIC, NORMAL>
   ```
   For the `type` line, print the human-readable name (without the `TYPE_`
   prefix), not the integer. If the specifier for a fixed-precision double
   is not automatic by now, the QRG's Format Specifiers section has it.

`main` in `main.c` reads test cases and exercises your functions. You do not
need to edit `main.c`.

## Test it locally before you submit

Three sample test cases are provided in `tests/sample/`. Each has an input
file (`inputN.txt`) and an expected output (`expectedN.txt`). To run them:

```
make
./pokemon < tests/sample/input1.txt > my_output1.txt
diff my_output1.txt tests/sample/expected1.txt
```

The `<` feeds the input file to your program in place of the keyboard, and the
`>` captures what your program printed into a file so `diff` can compare it. See
"Redirecting input and output" on the Lesson 7 page if that syntax is unfamiliar.

A successful `diff` produces no output. If `diff` prints lines, your output
does not match: read carefully, find the difference, fix it, recompile, run
again. **Do not submit until all three sample diffs are clean.** Burning
Gradescope submissions on output-format issues is the most common way cadets
lose points on this lab.

The autograder runs six cases; these three samples are the subset you can run
before you submit. Nothing is hidden: every case's name and result show on
Gradescope after each submission. Match the output format exactly.

## How the header is graded

The autograder does two things with your `pokemon.h` before it builds anything:

- **Include guard (scored).** It compiles a small program that includes
  `pokemon.h` twice and checks for the `#ifndef` / `#define` / `#endif`
  pattern. Worth 10% of the functional score.
- **Interface probes (not scored, always shown).** One check each for the
  enum members and their order, the struct's fields and types, the typedef,
  and the three prototypes. If your build fails, read these first: they name
  the one piece of the header that is off.

## Build rules

The `Makefile` you write builds with `-Wall -Werror`. Warnings are treated as
errors. If your code produces a warning, your code does not compile, and the
autograder gives you zero. Get rid of the warning; do not work around it.

## Style requirements

- snake_case for variables and function names.
- SCREAMING_SNAKE_CASE for enum members and macros (the spec above follows
  this; keep it).
- The `_t` suffix on typedef names (`pokemon_t`).
- An include guard on every header you write, named after the file.
- No global variables.

## Documentation statement (5% of this lab)

The comment header of `pokemon.c` must contain a documentation statement: a line
beginning with `Documentation:` that lists ALL outside help you received on this
lab. That covers GenAI tools (documented per the course GenAI policy), internet
sources such as Stack Overflow, and help from any person (classmates, friends,
EI with your instructor). If you received no outside help, write exactly:

    Documentation: None

Keep the statement on the same line as `Documentation:`. Leaving the template
placeholder in place scores zero for this component.

## The Makefile (you write it)

Worth **0.20 of this lab**. Since Lesson 7 you have known how to write a Makefile, and from Lesson 9 on you write one for every lab. The stub lists what the project contains; you write the file. Open `Makefile` and fill it in before you start on the C.

The autograder checks that your Makefile:

- builds an executable named `pokemon`
- compiles each `.c` to its own `.o` and links them
- puts `-Wall` and `-Werror` in `CFLAGS`
- has a `clean` rule that removes `pokemon` and the `.o` files
- does nothing on a second `make` when nothing has changed

Put `-g` in `CFLAGS` too. It is not graded, but it is what lets `gdb` and `valgrind` show you file names and line numbers instead of `???`.

Recipe lines must start with a real tab character, not spaces. If `make` says `missing separator`, that is what happened. The Lesson 7 lab and the Makefile walkthrough on the Lesson 7 page are the reference.

If your C does not compile, this check is not counted against you: the build points here are about your Makefile, not your code.

## Your tests, with assert

From Lesson 18 on, every lab with functions to call asks you to prove them before Gradescope does. `test_lab19.c` has the Lesson 18 shape: no `main`, one static function per test, and one public `run_all_tests()` (prototype in the provided `tests.h`) that calls every test in order. The provided block at the top of `main` in `main.c` calls it when the program is built with `-D RUNTESTS`, which is what the provided `make run_tests` rule does; leave that block, `tests.h`, and the rule as they are, and keep `test_lab19.c` out of your object list. One finished test ships in it as the model; the stubs carry hints. You need **at least 4 `assert` calls, on `init_pokemon` and `set_hp`**, with a comment on each test naming the edge case it covers, and every test listed in `run_all_tests()` or it never runs. `make run_tests && ./run_tests` runs them; `make test` does too.

`assert(condition)` does nothing when the condition is true. When it is false, it prints the file and line and aborts, so a test program that runs to the end and exits 0 has proven every claim in it. A test is three moves: call the function with an input you chose, assert what must be true about the result, and free whatever the function handed you.

Three rules:

* **Work the expected value out first.** If you copy the function's own output into the assert, the test proves nothing.
* **A test that fails against correct code is itself the bug.** The autograder compiles your `test_lab19.c` with the instructor's `pokemon.c` and runs it. If an assert fails there, your expectation is wrong.
* **A failing assert skips everything below it**, including your frees, so a failing test program also trips valgrind. That is the test failing, not a memory bug.

Graded as 0.2 of the lab: 0.1 for a test file that exercises the named functions (comments stripped; a function named only in a TODO does not count) and 0.1 for those tests holding against the reference module. The second half is not scored until the first passes.

<!-- visible-tests:begin (generated) -->
## Visible tests

`run_local.sh` automates the run-and-diff loop over the sample cases shipped with this lab. Run it any time with

```
make test
```

(`make test` just runs `bash run_local.sh`, so either works. The script builds with your Makefile, falling back to a direct gcc build while your Makefile is unfinished, so you can always check your C.)

The samples are a subset of what the autograder runs. Passing them is necessary, not sufficient.

`make test` also compiles and runs your `test_lab19.c` and reports whether every assert held. The autograder grades that file separately (see "Your tests, with assert" above).
<!-- visible-tests:end -->

## Submission

Push to your assignment repository, then submit to Gradescope.
There is no submission limit; Gradescope grades your latest submission.

## Need help?

Schedule EI with your instructor. Bring a specific error message or a
specific sample output that does not match. Specific questions get unstuck
fast.
