#include "memory_free.h"

void free_Map(Map board)
{
    for(int i = 0; i < board->rows; i++)
    {
        free(board->old_matrix[i]);
        free(board->new_matrix[i]);
    }
    free(board->old_matrix);
    free(board->new_matrix);
    free(board);
}

void free_Image(Image img)
{
    free(img->path_to_image);
    free(img->pixel_data);
    free(img);
}

void free_at_list(at_list_t * at_list)
{
    at_list_t * at = at_list;
    at_list_t * temp = NULL;

    while(at != NULL)
    {
        temp = at->next;
        free(at);
        at = temp;
    }
}

void free_Config(Config conf)
{
    free_at_list(conf->active_tiles);
    free(conf);
}

void free_Arguments(Arguments arg)
{
    free(arg->config_path);
    free(arg->save_path);
    free(arg->save_gen);
    free(arg->save_img);
    free(arg);
}