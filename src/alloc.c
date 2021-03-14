#include "array_functions.h"

elem** get_memory(elem **arr, int n, int m)
{
    arr = (elem**)malloc(sizeof(elem*) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (elem*)malloc(sizeof(elem*) * m);
    }
    return arr;
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
