#include "nieghbors.h"

int calc_nieghbors(Map board, int i, int j) 
{
    int counter = 0;
    if (i > 0) 
    {
        if ((j > 0) && (board->matrix[i - 1][j - 1].is_live)) counter++;

        if ((j < board->columns - 1) && (board->matrix[i - 1][j + 1].is_live)) counter++;

        if (board->matrix[i - 1][j].is_live) counter++;
    }

    if (i < board->rows) 
    {
        if ((j > 0) && (board->matrix[i + 1][j - 1].is_live)) counter++;

        if ((j < board->columns- 1) && (board->matrix[i + 1][j + 1].is_live)) counter++;

        if (board->matrix[i + 1][j].is_live) counter++;
    }

    if ((j > 0) && (board->matrix[i][j - 1].is_live)) counter++;

    if ((j < board->columns- 1) && (board->matrix[i][j + 1].is_live)) counter++;

    return counter;
}