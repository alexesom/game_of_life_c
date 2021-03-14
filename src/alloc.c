#include "alloc.h"

Map alloc_Map(elem ** matrix, int rows, int columns)
{
    Map board = (Map)malloc(sizeof(Map));
    board->rows = rows;
    board->columns = columns;
    matrix = (elem **)malloc(sizeof(elem *) * rows);

    for (int i = 0; i < rows; i++) 
        matrix[i] = (elem*)malloc(sizeof(elem *) * columns);

    return board;
}

Image alloc_Image(const char * path_to_image, char * pixels_data, int number_of_pixels, int width, int height, int channels)
{
    Image img = malloc(sizeof(Image));
    img->path_to_image = path_to_image;
    img->pixel_data = array2pixel_transform((unsigned char *)pixels_data, number_of_pixels, channels);
    img->number_of_pixels = number_of_pixels;
    img->width = width;
    img->height = height;
    img->channels = channels;
    
    return img;
}
