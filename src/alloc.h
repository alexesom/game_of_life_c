#include "array_functions.h"

#ifndef PW_GAME_OF_LIFE_ALLOC_H
#define PW_GAME_OF_LIFE_ALLOC_H

elem ** alloc_matrix(int rows, int columns);

Map alloc_Map(int rows, int columns);

Image alloc_Image(char * path_to_image, Map board, int channels);

Config alloc_Config(int x, int y, at_list_t * at, int gen);

at_list_t * add_tile_to_list(at_list_t * at_list, int x, int y);

Arguments alloc_Arguments(char * config_path, char * save_path, long * save_gen, int save_gen_c, long * save_img, int save_img_c, int step_by_step, int silent, int save_gif_c);

#endif