#include <time.h>
#include <math.h>

#include "alloc.h"

#ifndef PW_GAME_GENERATOR_H
#define PW_GAME_GENERATOR_H

void generate(Map board, int seed, int chance);

void generate_from_conf(Map board, Config config);

#endif

