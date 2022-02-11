#include <math.h>

#include "alloc.h"

#ifndef PW_GAME_OF_LIFE_SAVE2IMAGE_H
#define PW_GAME_OF_LIFE_SAVE2IMAGE_H

int save_to_png(Image img); 

int save_to_jpg(Image img); 

void image_path_change(Image img, char * path);

#endif