#include <string.h>
#include "gifenc/gifenc.h"
#include "array_functions.h"
#include "evolve.h"
#include "save2image.h"
#include "neighbours.h"
#include "tester.h"
#include "generator.h"
#include "memory_free.h"
#include "alloc.h"
#include "parse_arg.h"
#include "toml_parser.h"

void print_board(Map board)
{
    for(int i = 0; i < board->rows; i++)
    {
        for(int j = 0; j < board->columns; j++)
            printf(board->old_matrix[i][j].is_live ? "\033[07m \033[m" : " ");
        printf("\n");
    }
}

int check_if_save(int gen, long * vec, int vec_c)
{
    for(int i = 0; i < vec_c; i++)
    {
        if(vec[i] == (long)gen)
            return 1;
    }
    return 0;
}

int main(int argc, char ** argv)
{
    Arguments arg = parse_arguments(argv, argc);
    if(arg == NULL)
    {
        printf("Program was unable to parse arguments!\n");
        return 1;
    }

    Config conf = read_config(arg->config_path);
    if(conf == NULL)
    {
        printf("Program was unable to parse the config file!\n");
        return 1;
    }

    Map board = alloc_Map(conf->dimensions[1], conf->dimensions[0]);
    if(board == NULL)
    {
        printf("Program cannot allocate memory for board!\n");
        return 1;
    }
    
    ge_GIF * gif = NULL;
    int pass = 0;

    int save_all_gen = arg->save_gen_c == 1 && arg->save_gen[0] == -1 ? 1 : 0;
    int save_all_img = arg->save_img_c == 1 && arg->save_img[0] == -1 ? 1 : 0; 

    generate_from_conf(board, conf);

    if(arg->save_gif_c == 1)
    {
        char * gif_name = malloc(sizeof(char) * (strlen(arg->save_path) + 15));
        sprintf(gif_name, "%sanimation.gif", arg->save_path);

        gif = ge_new_gif(
            gif_name, 
            board->columns, board->rows,
            (uint8_t[]) {
                0x00, 0x00, 0x00,
                0xFF, 0xFF, 0xFF
            },
            1,
            0
        );
    }
    for(int gen = 0; gen <= conf->generations; gen++)
    {
        if(save_all_gen || check_if_save(gen, arg->save_gen, arg->save_gen_c))
        {
            char * file_name = malloc(sizeof(char) * (strlen(arg->save_path) + 100));
            sprintf(file_name, "%sconf_%d.toml", arg->save_path, gen);
            save_current_gen(board, conf, file_name, gen);
            sprintf(file_name, "%sboard_%d.txt", arg->save_path, gen);
            save_to_txt(board, file_name);
            
        }

        if(save_all_img || check_if_save(gen, arg->save_img, arg->save_img_c))
        {
            char * img_name = malloc(sizeof(char) * (strlen(arg->save_path) + 100));
            sprintf(img_name, "%simg_%d.jpg", arg->save_path, gen);
            Image img = alloc_Image(img_name, board, 3);
            save_to_jpg(img);
            free_Image(img);
        }

        if(!arg->silent && pass != 0)
        {
            printf("Generation %d:\n", gen);
            print_board(board);
            printf("\n");
        }

        if(arg->step_by_step && pass != 0 && !arg->silent)
        {
            char buff;
            printf("Press ENTER to progress...\n");
            scanf("%c", &buff);
        }
        
        if(arg->save_gif_c && pass != 0)
        {
            gif->frame = flatten_matrix(elem2char_transform(board->old_matrix, board->rows, board->columns), board->rows, board->columns);
            ge_add_frame(gif, 10);
        }
            

       pass = evolve(board);
    }

    ge_close_gif(gif);

    return 0;
}