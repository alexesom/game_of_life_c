#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "toml_parser.h"
#include "parse_arg.h"
#include "generator.h"
#include "evolve.h"
#include "array_functions.h"
#include "save2image.h"
#include "neighbours.h"
#include "memory_free.h"
#include "alloc.h"

#ifndef PW_GAME_OF_LIFE_TESTER_H
#define PW_GAME_OF_LIFE_TESTER_H

int toml_parser_test(void);

int save_to_txt_test(void);

int arg_parser_test(void);

#endif