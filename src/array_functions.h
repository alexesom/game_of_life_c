#include "struct.h"

#ifndef PW_GAME_OF_LIFE_ARRAY_FUNCTIONS_H
#define PW_GAME_OF_LIFE_ARRAY_FUNCTIONS_H

unsigned char * array2pixel_transform(const void * initial_array, int number_of_pixels, int channels);

char * flatten_matrix(char ** matrix, int number_of_rows, int number_of_columns);

void set_with_zeros(elem ** matrix, int rows, int columns);

char ** elem2char_transform(elem ** matrix, int rows, int columns);

unsigned char * matrix2pixels(Map board, int channels);

void save_to_txt(Map board, char * file_name);

void save_current_gen(Map board, Config conf, char * conf_name, int gen);

#endif