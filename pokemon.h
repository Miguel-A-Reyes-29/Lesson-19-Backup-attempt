// pokemon.h
// CS210 Lesson 19 - Structs Introduction
//
// YOU WRITE THIS HEADER. main.c, your tests, and the autograder include it
// and use the exact names given below, so the names are fixed. The
// definitions are yours. Work the four TODOs top to bottom; the order is
// the order the compiler needs them in.
//
// The prototypes at the bottom are PROVIDED, with DFCS function headers.
// Leave their signatures alone; write headers in the same format above
// every function you implement in pokemon.c.

// ---- TODO 1 (open): include guard -------------------------------------
// Wrap this whole file in an include guard (DFCS standard 4.1, Lesson 18).
// The guard's macro name is the file name in SCREAMING_SNAKE_CASE with the
// dot replaced by an underscore. The autograder includes this file twice
// in one program; without a guard that program does not compile.
#ifndef POKEMON_H
#define POKEMON_H



// ---- TODO 2: enum PokemonType -----------------------------------------
// Six members, in exactly this order:
//     TYPE_FIRE, TYPE_WATER, TYPE_GRASS, TYPE_ELECTRIC, TYPE_PSYCHIC, TYPE_NORMAL
// The compiler numbers them 0 to 5 for you; do not write the numbers.
enum PokemonType{TYPE_FIRE, TYPE_WATER,TYPE_GRASS,TYPE_ELECTRIC,TYPE_PSYCHIC,TYPE_NORMAL};


// ---- TODO 3: struct Pokemon -------------------------------------------
// Six fields, in exactly this order and with these types:
//     int pokedex_num, int hp, int attack, int defense,
//     double catch_rate, enum PokemonType type
// The last field's type is the enum you just wrote; that is why the enum
// comes first.
struct Pokemon{
    int pokedex_num;
    int hp;
    int attack;
     int defense;
     double catch_rate;
      enum PokemonType type;
    };


// ---- TODO 4: typedef ---------------------------------------------------
// Make pokemon_t another name for struct Pokemon. It must come before the
// prototypes below, which use it.
typedef struct Pokemon pokemon_t;


// ---- PROVIDED: prototypes (do not change the signatures) ---------------

/**
* @brief builds a fully-initialized pokemon_t
* @param pokedex_num the Pokedex number
* @param hp hit points
* @param attack attack stat
* @param defense defense stat
* @param catch_rate catch rate between 0.0 and 1.0
* @param type the Pokemon's elemental type
* @return a pokemon_t with every field set from the arguments
*/
pokemon_t init_pokemon(int pokedex_num,
                       int hp,
                       int attack,
                       int defense,
                       double catch_rate,
                       enum PokemonType type);

/**
* @brief returns a copy of a pokemon with its hp replaced
* @param p the pokemon to start from (passed by value; the caller's copy is unchanged)
* @param new_hp the hit point value to store in the returned pokemon
* @return p with hp set to new_hp and every other field as it was
*/
pokemon_t set_hp(pokemon_t p, int new_hp);

/**
* @brief prints a pokemon's fields, one per line
* Uses the output format documented in README.md.
* @param p the pokemon to print (passed by value)
*/
void print_pokemon(pokemon_t p);

// ---- TODO 1 (close): end the include guard here ------------------------

#endif /*POKEMON_H*/
