#include <stdio.h>
#include <stdlib.h>

#ifndef PW_GAME_OF_LIFE_STRUCT_H
#define PW_GAME_OF_LIFE_STRUCT_H

typedef struct element {
    int live;
} elem;

typedef struct square {
    int n;
    int m;
    elem **arr;
} map;

typedef struct Image_properties {
    const char * path_to_image;
    unsigned char * pixel_data;
    int number_of_pixels;
    int width;
    int height;
    int channels;
} * Image;

#endif
