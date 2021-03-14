#include "struct.h"

#ifndef PW_GAME_OF_LIFE_ARRAY_FUNCTIONS_H
#define PW_GAME_OF_LIFE_ARRAY_FUNCTIONS_H

unsigned char * array2pixel_transform(const void * initial_array, int number_of_pixels, int channels);

int * flatten_matrix(int ** matrix, int number_of_rows, int number_of_columns);

#endif