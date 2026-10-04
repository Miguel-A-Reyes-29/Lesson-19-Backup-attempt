/* test_lab19.c  --  YOUR assert tests for the Lesson 19 lab.
 *
 * The Lesson 18 shape: no main here. Every test is a static function, and
 * run_all_tests() at the bottom calls them in order. The program's main
 * calls run_all_tests() and stops when it is built with -D RUNTESTS:
 *
 *     make run_tests && ./run_tests     (the run_tests rule is provided)
 *     make test                         (the visible tests; runs this too)
 *
 * If it runs to the end and exits 0, every claim in it held. An assert
 * that fails prints the file and line and aborts. A test you write but
 * never list in run_all_tests() compiles and never runs.
 *
 * A test is three moves: call the function with an input YOU chose,
 * assert what must be true about the result, free whatever the function
 * handed you. Work each expected value out by hand BEFORE you write the
 * assert; copying the function's own output into it proves nothing. The
 * autograder also runs this file against the instructor's module: a test
 * that fails there has a wrong expectation.
 *
 * Required: at least 4 assert calls, on init_pokemon and set_hp, with a
 * comment on each test naming its edge case.
 *
 * One finished test is below as the model. Write the rest in the same
 * shape, then make sure run_all_tests() calls every one.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"
#include "tests.h"

/* MODEL: init_pokemon sets every field from its arguments. Read this
 * one, then write the rest in the same shape. */
static void test_init_sets_every_field(void) {
    pokemon_t p = init_pokemon(25, 35, 55, 40, 0.19, TYPE_ELECTRIC);   // call it
    assert(p.pokedex_num == 25);                                       // claims
    assert(p.hp == 35 && p.attack == 55 && p.defense == 40);
    assert(p.catch_rate > 0.18 && p.catch_rate < 0.20);                // doubles: a range, never ==
    assert(p.type == TYPE_ELECTRIC);
    printf("test_init_sets_every_field passed\n");
}

/* TODO: init a pokemon p, then q = set_hp(p, 10). Assert q.hp is 10 AND q's
 * other fields match p's. set_hp hands back a whole new struct value. */
static void test_set_hp_returns_updated_copy(void) {
    /* your code here */
    pokemon_t p=init_pokemon(20,20,20,20,.20,TYPE_GRASS);
    pokemon_t q=set_hp(p,10);

    assert(q.hp!=p.hp);
     assert(q.pokedex_num==p.pokedex_num);
      assert(q.attack==p.attack);
       assert(q.defense==p.defense);
        assert(q.catch_rate==p.catch_rate);
         assert(q.type==p.type);

}

/* TODO: same call, then assert p.hp is STILL what init gave it. p went in by
 * value, so set_hp worked on a copy; your variable never changed. */
static void test_set_hp_leaves_caller_alone(void) {
    /* your code here */
    pokemon_t p=init_pokemon(20,20,20,20,.20,TYPE_GRASS);
    pokemon_t q=set_hp(p,10);
    assert(q.hp!=p.hp);
    assert(p.hp == 20);


}

/* TODO: 0 is a legal hp (a fainted pokemon). Assert set_hp stores it. */
static void test_set_hp_to_zero(void) {
    /* your code here */
    pokemon_t p=init_pokemon(20,20,20,20,.20,TYPE_GRASS);
    pokemon_t q=set_hp(p,0);
    assert(q.hp==0);
}

/* The one public function: every case, in order. Add each new test
 * here or it never runs. */
void run_all_tests(void) {
    test_init_sets_every_field();
    test_set_hp_returns_updated_copy();
    test_set_hp_leaves_caller_alone();
    test_set_hp_to_zero();
    printf("all tests passed\n");
}
