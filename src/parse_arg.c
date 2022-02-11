#include "parse_arg.h"
#include <string.h>

Arguments parse_arguments(char ** argv, int argc)
{
    int conf_path_ok = 0;
    int i = 1;

    char * conf_path;
    char * save_path;
    long * save_gen = NULL; // if -1 then save all
    int save_gen_c = 0;
    long * save_img = NULL; // if -1 then save all
    int save_img_c = 0;
    int step_by_step = 0;
    int silent = 0;
    int save_gif = 0;

    Arguments arguments = NULL;

    if(argc == 1){
        printf("No arguments provided!\n");
        return NULL;
    }

    while(i < argc)
    {
        if(!strcmp(argv[i], "--config"))
        {
            if(i == argc - 1)
            {
                printf("No config path given!\n");
                return NULL;
            }
            conf_path_ok = 1;
            conf_path = argv[++i];
            i++;
        } 
        else if (!strcmp(argv[i], "--save"))
        {
            if(i == argc - 1)
            {
                printf("No save path given!\n");
                return NULL;
            }
            save_path = argv[++i];
            i++;
        }
        else if (!strcmp(argv[i], "--save-gen"))
        {
            if(i != argc - 1)
                save_gen = parse_string_to_long(argv[++i], &save_gen_c);
            if(save_gen == NULL)
            {
                save_gen = malloc(sizeof(long));
                save_gen[0] = -1;
                save_gen_c = 1;
                continue;
            }
            i++;
        }
        else if (!strcmp(argv[i], "--save-img"))
        {   
            if(i != argc - 1)
                save_img = parse_string_to_long(argv[++i], &save_img_c);
            if(save_img == NULL)
            {
                save_img = malloc(sizeof(long));
                save_img[0] = -1;
                save_img_c = 1;
                continue;
            }
            i++;
        }
        else if (!strcmp(argv[i], "--step-by-step"))
        {
            step_by_step = 1;
            i++;
        }
        else if (!strcmp(argv[i], "--silent"))
        {
            silent = 1;
            i++;
        }
        else if (!strcmp(argv[i], "--save-gif"))
        {
            save_gif = 1;
            i++;
        }
        else
        {
            printf("Incorrect argument: %s!\n", argv[i]);
            return NULL;
        }
    }

    if(!conf_path_ok)
    {
        printf("No config path!\n");
        return NULL;
    }

    arguments = alloc_Arguments(
        conf_path,
        save_path,
        save_gen,
        save_gen_c,
        save_img,
        save_img_c,
        step_by_step,
        silent,
        save_gif
    );

    return arguments;
}

long * parse_string_to_long(char * gen_string, int * counter)
{   
    if(gen_string[0] == '-')
        return 0;

    long * gen = NULL;
    char * p = gen_string;
    int gen_c = 0;

    while(strlen(p))
    {
        const long temp = strtol(p, &p, 10);
        gen = realloc(gen, (sizeof(long) * (gen_c + 1)));
        gen[gen_c++] = temp;
    }

    *counter = gen_c;
    return gen;
}