#include <stdio.h>
#include <stdlib.h>

#ifndef PW_GAME_OF_LIFE_STRUCT_H
#define PW_GAME_OF_LIFE_STRUCT_H

typedef struct element 
{
    char is_live;
} elem;

typedef struct square 
{
    int rows;
    int columns;
    elem ** old_matrix;
    elem ** new_matrix;
} * Map;

typedef struct Image_properties 
{
    char * path_to_image;
    unsigned char * pixel_data;
    int number_of_pixels;
    int width;
    int height;
    int channels;
} * Image;

typedef struct active_tiles_list 
{
    int x;
    int y;
    struct active_tiles_list * next;
} at_list_t;

typedef struct Config_properties
{
    int dimensions[2];
    at_list_t * active_tiles;
    int generations;
} * Config;

typedef struct command_line_arguments
{
    char * config_path;
    char * save_path;
    long * save_gen;
    int save_gen_c;
    long * save_img;
    int save_img_c;
    int step_by_step;
    int silent;
    int save_gif_c;
} * Arguments;

#endif
