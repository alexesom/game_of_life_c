#include "struct.h"
#include "alloc.h"

#ifndef PW_GAME_OF_LIFE_PARSE_ARG_H
#define PW_GAME_OF_LIFE_PARSE_ARG_H

// returns NULL if it wasn't successful
Arguments parse_arguments(char ** argv, int argc);

// internal use
long * parse_string_to_long(char * gen_string, int * gen_c);

#endif
