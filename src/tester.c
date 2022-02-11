#include "tester.h"

int toml_parser_test(void)
{
    printf("\nTesting TOML parser\n");

    int passed = 0;
    Config config = NULL;
    config = read_config("../tests/test_conf.toml");

    if(config->dimensions[0] != 50 || config->dimensions[1] != 50)
    {
        printf("Toml parser test failed: incorrect dimensions\n");
        passed = 1;
    }
    else
    {
        printf("Toml parser test: correct dimensions\n");
    }

    int active[5][2] = { { 2, 2 }, { 1, 2 }, { 0, 2 }, { 2, 1 }, { 1, 0 }  };
    at_list_t * a = config->active_tiles;

    for(int i = 0; i < 5; i++)
    {
        if(active[i][0] != a->x || active[i][1] != a->y)
        {
           printf("Toml parser test failed: incorrect active tile %d\n", i);
           passed = 1;
        }
        else
        {
            printf("Toml parser test: correct active tile %d\n", i);
        }

        a = a->next;
    }

    if(config->generations != 25)
    {
        printf("Toml parser test failed: incorrect generations\n");
        passed = 1;
    }
    else
    {
        printf("Toml parser test: correct generations\n");
    }

    if(!passed)
        printf("Toml parser test: OK\n\n");
    else
        printf("Toml parser test: FAIL\n\n");

    return passed;
}

int save_to_txt_test(void)
{
    Config config = NULL;
    config = read_config("../tests/test_conf.toml");


    Map board = alloc_Map(config->dimensions[1], config->dimensions[0]);
    set_with_zeros(board->old_matrix, board->rows, board->columns);
    
    at_list_t * a = config->active_tiles;

    for(int i = 0; i < config->dimensions[0]; i++)
    {
        if(a == NULL) break;
        board->old_matrix[a->x][a->y].is_live = 1;
        a = a->next;
    }

    save_to_txt(board, "./boards/hello.txt");

    free_Config(config);
    free_Map(board);
    
    return 1;
}

int arg_parser_test(void)
{
    int passed = 0;
    Arguments args = NULL;
    char * argv[9] = {
        "game.out", 
        "--save", "life/saves", 
        "--save-gen", "1 3 10 21", 
        "--config", "life/conf.toml", 
        "--step-by-step",
        "--save-img"};
    int argc = 9;

    printf("\nTesting argument parser\n");

    args = parse_arguments(argv, argc);
    if(args == NULL)
    {
        printf("Failed to parse arguments!\n");
        return 1;
    }
    else
    {
        printf("Arguments parsed\n");
    }

    if(strcmp(args->config_path, argv[6]))
    {
        printf("Incorrect config path!\n");
        passed = 1;
    } 
    else 
    {
        printf("Correct config path\n");
    }

    if(strcmp(args->save_path, argv[2]))
    {
        printf("Incorrect save path!\n");
        passed = 1;
    }
    else
    {
        printf("Correct save path\n");
    }

    if(args->save_gen_c != 0)
    {
        long gen_v[4] = {1, 3, 10, 21};
        for(int i = 0; i < args->save_gen_c; i++)
        {
            if(gen_v[i] != args->save_gen[i])
            {
                printf("Incorrect gen number: %ld, expected: %ld!\n", args->save_gen[i], gen_v[i]);
                passed = 1;
            }
            else
            {
                printf("Correct gen number %d\n", i);
            }
        }
    }
    else
    {
        printf("Incorrect interpretation of save-gen: save all!\n");
        passed = 1;
    }
    
    if(args->save_img_c != 0)
    {
        printf("Incorrect interpretation of save-img: save specific!\n");
    }
    else
    {
        if(args->save_img[0] != -1)
        {
            printf("Save all img didn't work!\n");
            passed = 1;
        }
        else
        {
            printf("Save all img: OK\n");
        }
    }

    if(args->step_by_step == 0)
    {
        printf("Step-by-step didn't work!\n");
        passed = 1;
    }
    else
    {
        printf("Step-by-step: OK\n");
    }

    if(args->silent == 1)
    {
        printf("Silent didn't work!\n");
        passed = 1;
    }
    else
    {
        printf("Silent: OK\n");
    }

    if(!passed)
        printf("Argument parser test: OK\n");
    else
        printf("Argument parser test: FAIL\n");

    return passed;
}