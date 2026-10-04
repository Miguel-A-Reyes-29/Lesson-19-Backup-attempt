// pokemon.c
// CS210 Lesson 19 - Structs Introduction
//
// Documentation: REPLACE with your documentation statement, or "None"
//   (see README "Documentation statement": covers GenAI, internet
//   sources, and help from any person; keep it on the line above)
//
// Implement the three functions declared in pokemon.h.
// See README.md for the exact print format and the test cases.
//
// Until pokemon.h has its types and init_pokemon returns something, this
// file does not compile under -Wall -Werror. That is expected: write the
// header first, then init_pokemon, and build after each one.

#include <stdio.h>
#include "pokemon.h"

pokemon_t init_pokemon(int pokedex_num,
                       int hp,
                       int attack,
                       int defense,
                       double catch_rate,
                       enum PokemonType type) {
    // TODO: build and return a pokemon_t whose fields hold these
    // arguments. Use a designated initializer (the form that names each
    // field as it initializes it); the struct section of the QRG and the
    // Lesson 19 notes both show the syntax.

    pokemon_t p = {
        .pokedex_num = pokedex_num,
        .hp = hp,
        .attack =attack,
        .defense= defense,
        .catch_rate = catch_rate,
        .type = type};
    return p;
}

pokemon_t set_hp(pokemon_t p, int new_hp) {
    // TODO: p is YOUR copy of the caller's pokemon (structs arrive by
    // value). Change its hp field, then return it; returning the changed
    // copy is how the new value gets back to the caller. No pointers.
    (void)new_hp;
p.hp=new_hp;
    return p;
}

const char *type_to_string(pokemon_t p){
    switch(p.type){
        case TYPE_FIRE: return "FIRE";
        case TYPE_WATER: return "WATER";
        case TYPE_NORMAL: return "NORMAL";
        case TYPE_GRASS: return "GRASS";
        case TYPE_ELECTRIC: return "ELECTRIC";
        case TYPE_PSYCHIC: return "PSYCHIC";
        default: return "UNKNOWN";
    }

}


void print_pokemon(pokemon_t p) {
    // TODO: print every field, one per line, in the order documented in
    // README.md. Match the format exactly (the autograder compares byte
    // by byte). catch_rate prints with three decimal places (see the
    // README for the spec). Print the type as a name
    // (FIRE, WATER, GRASS, ELECTRIC, PSYCHIC, NORMAL), not as an integer.
    (void)p;
printf("pokedex_num: %d\n",p.pokedex_num);
printf("hp: %d\n",p.hp);
printf("attack: %d\n", p.attack);
printf("defense: %d\n",p.defense);
printf("catch_rate: %.3f\n",p.catch_rate);
printf("type: %s\n", type_to_string(p));
}
