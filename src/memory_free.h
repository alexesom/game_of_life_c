#include "struct.h"

#ifndef PW_GAME_MEMORY_FREE_H
#define PW_GAME_MEMORY_FREE_H

void free_Map(Map board);

void free_Image(Image img);

void free_at_list(at_list_t * at_list);

void free_Config(Config conf);

void free_Arguments(Arguments arg);

#endif