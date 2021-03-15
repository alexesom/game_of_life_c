#include "struct.h"

#ifndef PW_GAME_OF_LIFE_TOML_PARSER_H
#define PW_GAME_OF_LIFE_TOML_PARSER_H

Config * read_config(char * conf_path);

Config * config_new(int x, int y, at_list_t * at, int gen);

void add_tile_to_list(at_list_t * at_list, int x, int y);

#endif