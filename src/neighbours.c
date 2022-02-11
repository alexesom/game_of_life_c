#include "neighbours.h"

int calculate_neighbours(Map board, int i, int j) 
{
    int counter = 0;

    if (i > 0) 
    {
        if ((j > 0) && (board->old_matrix[i - 1][j - 1].is_live)) 
            counter++;

        if ((j < board->columns - 1) && (board->old_matrix[i - 1][j + 1].is_live)) 
            counter++;

        if (board->old_matrix[i - 1][j].is_live) 
            counter++;
    }

    if (i < board->rows-1) 
    {
        if ((j > 0) && (board->old_matrix[i + 1][j - 1].is_live)) 
            counter++;

        if ((j < board->columns- 1) && (board->old_matrix[i + 1][j + 1].is_live)) 
            counter++;

        if (board->old_matrix[i + 1][j].is_live) 
            counter++;
    }

    if ((j > 0) && (board->old_matrix[i][j - 1].is_live)) 
        counter++;

    if ((j < board->columns- 1) && (board->old_matrix[i][j + 1].is_live)) 
        counter++;

    return counter;
}