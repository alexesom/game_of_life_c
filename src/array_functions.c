#include "array_functions.h"

unsigned char * array2pixel_transform(const void * initial_array, int number_of_pixels, int channels) 
{    
    unsigned char * new_array = calloc(sizeof(unsigned char), number_of_pixels * channels + 1);

    for (int i = 0; i < number_of_pixels * channels; i += channels)
        for(int j = 0; j < channels; j++)
            if(!*((unsigned char *) initial_array + i/channels))
                new_array[i+j] = 0;
            else new_array[i+j] = 255;
    new_array[number_of_pixels*channels] = '\000';

    free(initial_array);

    return new_array;
}

char * flatten_matrix(char ** matrix, int number_of_rows, int number_of_columns)
{
    int counter = 0;
    char * matrix_array = malloc(number_of_rows * number_of_columns * sizeof(char) + 1);
    for(int i = 0; i < number_of_rows; i++)
        for(int j = 0; j < number_of_columns; j++)
        {
            matrix_array[counter] = matrix[i][j];
            counter++;
        }
    matrix_array[number_of_rows * number_of_columns] = '\000';

    for(int i = 0; i < number_of_rows; i++)
        free(matrix[i]);

    return matrix_array;   
}

void set_with_zeros(elem ** matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            matrix[i][j].is_live = 0;
}

char ** elem2char_transform(elem ** matrix, int rows, int columns)
{
    char ** arr = malloc(rows * sizeof(char *));
    for(int i = 0; i < columns; i++)
        arr[i] = malloc(columns * sizeof(char));

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            arr[i][j] = matrix[i][j].is_live;

    return arr;
}

unsigned char * matrix2pixels(Map board, int channels)
{
    return array2pixel_transform(flatten_matrix(elem2char_transform(board->old_matrix, board->rows, board->columns), board->rows, board->columns), board->columns * board->rows, channels);
}

void save_to_txt(Map board, char * file_name)
{
    FILE * in = fopen(file_name, "w");

    for(int i = 0; i < board->rows; i++)
    {
        for(int j = 0; j < board->columns; j++)
            fprintf(in, "%d ", board->old_matrix[i][j].is_live);
        fprintf(in, "\n");
    }
    
    fclose(in);
}

void save_current_gen(Map board, Config conf, char * conf_name, int gen)
{
    FILE * in = fopen(conf_name, "w");
    int counter = 0;

    fprintf(in, "[Config]\n");
    fprintf(in, "dimensions = [ %d, %d ]\n", board->columns, board->rows);
    fprintf(in, "active-tiles = [ ");
    
    for(int i = 0; i < board->rows; i++)
        for(int j = 0; j < board->columns; j++)
            if(board->old_matrix[i][j].is_live)
                counter++;
    
    counter--;

    for(int i = 0; i < board->rows; i++)
        for(int j = 0; j < board->columns; j++)
            if(board->old_matrix[i][j].is_live && counter != 0)
            {
                fprintf(in, "[ %d, %d ], ", j, i);
                counter--;
            }
            else 
                if(board->old_matrix[i][j].is_live && counter == 0)
                    fprintf(in, "[ %d, %d ]", j, i);

    fprintf(in, " ]\n");
    fprintf(in, "generations = %d", conf->generations - gen);
    
    fflush(in);
    fclose(in);
}