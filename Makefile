# ============================================================
# CS210 Lesson 19 Lab - Makefile
#
# YOU WRITE THIS FILE.
#
# You learned how in Lesson 7. From Lesson 9 on, building the project is
# part of every lab. This file is worth 0.2 of this lab's 2 points,
# not enough to sink your grade. But the autograder does check that it
# works, and you cannot build, run, or debug your code without it.
#
# Recipe lines MUST start with a real TAB character. Spaces will not work,
# and many editors quietly turn tabs into spaces. If make says
# "missing separator", that is what happened.
# ============================================================
#
# WHAT THE AUTOGRADER CHECKS
#   1. The default target (the first one in the file) builds an
#      executable named `pokemon`.
#   2. Compile each .c to its own .o, then link the .o files together:
#      pokemon.o  main.o
#      One gcc command listing every .c at once does not count.
#   3. CFLAGS contains -Wall and -Werror.
#   4. A `clean` rule removes `pokemon` and the .o files.
#   5. Running `make` twice in a row does nothing the second time,
#      because nothing changed.
#
# FILES IN THIS PROJECT
#   main.c     includes pokemon.h, tests.h
#   pokemon.c  includes pokemon.h
#
# NOT CHECKED, BUT DO IT ANYWAY
#   Put -g in CFLAGS alongside -Wall -Werror. It costs nothing and it is
#   what lets gdb and valgrind show you file names and line numbers
#   instead of ???. Every course example uses -Wall -Werror -g.
#
# Anything else is up to you. A `run` target that builds and runs the
# program is a common convenience; it is not required.
# ============================================================
CFLAGS= -Wall -Werror -g
CC=gcc
# TODO: write the whole file:
#   variables, the default target, the object-file rules, and clean.
#   The contract is above; the shape of every rule is in your
#   Lesson 7 lab and the Makefile walkthrough on the Lesson 7 page.
pokemon: main.o pokemon.o test_lab19.o
	$(CC) main.o pokemon.o test_lab19.o -o pokemon
main.o: main.c pokemon.h tests.h
	$(CC) $(CFLAGS) -c main.c -o main.o
pokemon.o:pokemon.c pokemon.h
	$(CC) $(CFLAGS) -c pokemon.c -o pokemon.o
test_lab19.0:test_lab19.c pokemon.h tests.h
	$(CC) $(CFLAGS) -c test_lab19.c -o test_lab19.o
# ---- Your tests (PROVIDED - keep this; write your rules ABOVE it) ----
# `make run_tests` compiles every source, your test file included, in ONE
# gcc command with -D RUNTESTS, so main hands off to run_all_tests() (the
# Lesson 18 pattern). It does not reuse your .o files on purpose: those
# were compiled without the macro, and make cannot tell the difference.
# Have your clean rule remove run_tests too.
run_tests: main.c pokemon.c test_lab19.c tests.h
	gcc -Wall -Werror -g -D RUNTESTS -o run_tests main.c pokemon.c test_lab19.c
clean:
	rm -f *.o pokemon run_tests
# ---- Visible tests (PROVIDED - keep this; write your rules ABOVE it) ----
# `make test` runs the visible tests: run_local.sh builds your code,
# falling back to a direct gcc build while your Makefile is unfinished,
# so it works from your very first run.
test:
	bash run_local.sh
.PHONY: test
