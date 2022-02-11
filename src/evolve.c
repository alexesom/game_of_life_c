#include "evolve.h"
#include "alloc.h"
#include "memory_free.h"

int evolve(Map board) 
{    
    for (int i = 0; i < board->rows; i++) 
    {
        for (int j = 0; j < board->columns; j++) 
        {
            int neighbours = calculate_neighbours(board, i, j);
            board->new_matrix[i][j] = board->old_matrix[i][j];

            if (neighbours == 3) 
            {
                board->new_matrix[i][j].is_live = 1;
            }

            if (neighbours < 2 || neighbours > 3) 
            {
                board->new_matrix[i][j].is_live = 0;
            }
        }
    }

    int k = 0;

    for (int i = 0; i < board->rows; i++) 
    {
        for (int j = 0; j < board->columns; j++) 
        {
            if (board->new_matrix[i][j].is_live != board->old_matrix[i][j].is_live) 
            {
                k = 1;
                break;
            }
        }
    }

    for(int i = 0; i < board->rows; i++)
        for(int j = 0; j < board->columns; j++)
            board->old_matrix[i][j].is_live = board->new_matrix[i][j].is_live;

    set_with_zeros(board->new_matrix, board->rows, board->columns);

    return k;
}

