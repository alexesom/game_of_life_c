#include "save2image.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image/stb_image_write.h"


int save_to_png(Image img) 
{
    return stbi_write_png(img->path_to_image, img->width, img->height, img->channels, img->pixel_data, img->width * img->channels);
}

int save_to_jpg(Image img) 
{
    return stbi_write_jpg(img->path_to_image, img->width, img->height, img->channels, img->pixel_data, 100);
}