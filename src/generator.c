#include "generator.h"
#include "time.h"

void generate(Map board, int seed, int chance) 
{
    if(seed == 0)
        srand(time(NULL));
    else 
        srand(seed);

    int x = 0;
    double int_max = 2147483647.0;

    for (int i = 0 ; i < board->rows; i++) 
        for (int j = 0; j < board->columns; j++) 
        {
            x = rand();
            board->old_matrix[i][j].is_live = ((double)x <= int_max * (double)chance/100 ) ? 1 : 0;
        }
    
}

void generate_from_conf(Map board, Config config)
{
    at_list_t * active = config->active_tiles;

    for (int i = 0 ; i < board->rows; i++) 
    {
        for (int j = 0; j < board->columns; j++)
        {
            board->old_matrix[i][j].is_live = 0;
        }
    }

    while(active != NULL)
    {
        board->old_matrix[active->y][active->x].is_live = 1;
        active = active->next;
    }
}