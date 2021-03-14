#include "generator.h"

void generate(Map board) 
{
    int x = rand();

    board->rows = x % 10 + 1;
    x = rand();

    board->columns = x % 10 + 1;
    board->matrix = alloc_Map(board->matrix, board->rows, board->columns);

    for (int i = 0 ; i < board->rows; i++) 
        for (int j = 0; j < board->columns; j++) 
        {
            x = rand();
            x %= 4;
            board->matrix[i][j].is_live = x == 0 ? 1 : 0;
        }
}
