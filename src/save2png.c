#include "save2png.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image/stb_image_write.h"

unsigned char *array_transform(const void *initial_array, int initial_array_size, int channels) {

    unsigned char *new_array = (unsigned char *) malloc(initial_array_size * 3);

    for (int i = 0; i < initial_array_size; i += channels) {

        new_array[i] = *((unsigned char *) initial_array + i);
        new_array[i + 1] = *((unsigned char *) initial_array + i);
        new_array[i + 2] = *((unsigned char *) initial_array + i);

    }

    return new_array;
}

int save_to_png(const unsigned char *array, const char *png_path, int width, int height, int channels) {

    return stbi_write_png(png_path, width, height, channels, array, width * channels);

}

