#include "alloc.h"

elem ** alloc_matrix(int rows, int columns)
{
    elem ** matrix = malloc(rows * sizeof(elem *));
    
    if(matrix == NULL)
        return NULL;
        
    for(int i = 0; i < columns; i++)
    {
        matrix[i] = malloc(columns * sizeof(elem));

        if(matrix[i] == NULL)
            return NULL;
    }
        
        return matrix;
}

Map alloc_Map(int rows, int columns)
{
    Map board = malloc(sizeof(struct square));
    
    if(board == NULL)
        return NULL;

    board->rows = rows;
    board->columns = columns;
    board->old_matrix = alloc_matrix(rows, columns);
    board->new_matrix = alloc_matrix(rows, columns);
    
    if(board->old_matrix != NULL && board->new_matrix != NULL)
        return board;
    else 
        return NULL;
}

Image alloc_Image(char * path_to_image, Map board, int channels)
{
    Image img = malloc(sizeof(struct Image_properties));

    if(img == NULL)
        return NULL;

    img->path_to_image = path_to_image;
    img->width = board->columns;
    img->height = board->rows;
    img->number_of_pixels = board->rows * board->columns;
    img->channels = channels;
    img->pixel_data = matrix2pixels(board, 3);

    if(img->path_to_image != NULL && img->pixel_data != NULL)
        return img;
    else 
        return NULL;
}

Config alloc_Config(int x, int y, at_list_t * at, int gen)
{
    Config conf = malloc(sizeof(struct Config_properties));
    
    if(conf == NULL)
        return NULL;

    conf->dimensions[0] = x;
    conf->dimensions[1] = y;
    conf->generations = gen;
    conf->active_tiles = at;
    
    return conf;
    /*if(conf->active_tiles != NULL)
        return conf;
    else 
        return NULL;*/
}

at_list_t * add_tile_to_list(at_list_t * at_list, int x, int y)
{
    at_list_t * new = malloc(sizeof(at_list_t));

    if(new == NULL)
        return NULL;

    new->x = x;
    new->y = y;
    new->next = at_list;

    return new;
}

Arguments alloc_Arguments(char * config_path, char * save_path, long * save_gen, int save_gen_c, long * save_img, int save_img_c, int step_by_step, int silent, int save_gif)
{
    Arguments new_arg = malloc(sizeof(struct command_line_arguments));

    if(new_arg == NULL)
        return NULL;

    new_arg->config_path = config_path;
    new_arg->save_path = save_path;
    new_arg->save_gen = save_gen;
    new_arg->save_gen_c = save_gen_c;
    new_arg->save_img = save_img;
    new_arg->save_img_c = save_img_c;
    new_arg->step_by_step = step_by_step;
    new_arg->silent = silent;
    new_arg->save_gif_c = save_gif;

    return new_arg;
}
