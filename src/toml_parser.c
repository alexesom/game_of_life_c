#include "toml_parser.h"
#include "toml/toml.h"
#include "toml/toml.c"

Config read_config(char * conf_file)
{
    FILE * f;
    char errbuf[200];
    
    Config config;
    int dim[2];
    int gen;
    int at_n;
    at_list_t * active_tiles = NULL;
    
    f = fopen(conf_file, "r");
    if(!f)
    {
        printf("Cannot open the configuration file!\n");
        return NULL;
    }
    
    toml_table_t * t_pars = toml_parse_file(f, errbuf, sizeof(errbuf));
    fclose(f);

    if(!t_pars)
    {
        printf("Cannot parse the file!\n");
        return NULL;
    }

    toml_table_t * config_toml = toml_table_in(t_pars, "Config");
    if(!config_toml)
    {
        printf("Missing section [Config]!\n");
        return NULL;
    }
    
    toml_array_t * dim_array = toml_array_in(config_toml, "dimensions");
    if(!dim_array)
    {
        printf("Missing value 'dimensions'\n");
        return NULL;
    }
    
    toml_array_t * active_array = toml_array_in(config_toml, "active-tiles");
    if(!active_array)
    {
        printf("Missing value 'active-tiles'\n");
        return NULL;
    }
    
    toml_datum_t gen_dat = toml_int_in(config_toml, "generations");
    if(!gen_dat.ok)
    {
        printf("Missing value 'generations'\n");
        return NULL;
    }
    
    // dim[2]
    for(int i = 0; i < 2; i++)
    {
        toml_datum_t one_dim = toml_int_at(dim_array, i);
        if(!one_dim.ok)
        {
            printf("Error while reading 'dimensions'\n");
            return NULL;
        } 
        else 
        {
            dim[i] = (int)one_dim.u.i;
        }
    }
    
    // gen
    gen = (int)gen_dat.u.i;

    // active_tiles
    at_n = toml_array_nelem(active_array);
    for(int i = 0; i < at_n; i++)
    {
        toml_array_t * tile_pos = toml_array_at(active_array, i);
        if(!tile_pos)
        {
            printf("Error while reading 'active-tiles', pos:%d!\n", i);
            break;
        }
        else
        {
            toml_datum_t tile_x = toml_int_at(tile_pos, 0);
            toml_datum_t tile_y = toml_int_at(tile_pos, 1);
            if(!tile_x.ok || !tile_y.ok)
                printf("Error while reading 'active-tiles', pos:%d!\n", i);
            else
            {
                active_tiles = add_tile_to_list(active_tiles, (int)tile_x.u.i, (int)tile_y.u.i);
            }
        }
    }

    config = alloc_Config(dim[0], dim[1], active_tiles, gen);

    toml_free(t_pars);
    return config;
}
