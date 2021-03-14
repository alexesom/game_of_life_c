unsigned char * array2pixel_transform(const void * initial_array, int number_of_pixels, int channels) 
{    
    unsigned char *new_array = (unsigned char *)calloc(sizeof(unsigned char), number_of_pixels * channels);

    for (int i = 0; i < number_of_pixels * channels; i += channels)
        for(int j = 0; j < channels; j++)
            if(*((unsigned char *) initial_array + i/channels))
                new_array[i+j] = 0;
            else new_array[i+j] = 255;

    return new_array;
}

char * flatten_matrix(char ** matrix, int number_of_rows, int number_of_columns)
{
    int counter = 0;
    char * matrix_array = (char *)malloc(number_of_rows * number_of_columns * sizeof(char));
    for(int i = 0; i < number_of_rows; i++)
        for(int j = 0; j < number_of_columns; j++)
        {
            matrix_array[counter] = matrix[i][j];
            counter++;
        }

    return matrix_array;   
}