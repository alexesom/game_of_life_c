#include "array_functions.h"

#ifndef PW_GAME_OF_LIFE_ALLOC_H
#define PW_GAME_OF_LIFE_ALLOC_H

Map alloc_Map(elem ** matrix, int rows, int columns);

Image alloc_Image(const char *, char *, int, int, int, int);

#endif