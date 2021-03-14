#include "evolve.h"

void evolve(Map board) 
{
    elem ** new = (elem **)malloc(sizeof(elem *) * board->rows);

    for (int i = 0; i < board->rows; i++) 
    {
        new[i] = (elem *)malloc(sizeof(elem *) * board->columns);
        
        for (int j = 0; j < board->columns; j++) 
        {
            int neighbors = calculate_neighbors(&board, i, j);
            new[i][j] = board->matrix[i][j];

            if (neighbors == 3) 
                new[i][j].is_live = 1;

            if (neighbors < 2 || neighbors > 3) 
                new[i][j].is_live = 0;
        }
    }
}