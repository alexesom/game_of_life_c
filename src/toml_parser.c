#include "toml_parser.h"
#include "toml/toml.h"

Config read_config(char * conf_file)
{
    FILE * f;
    char errbuf[200];
    
    Config * config;
    int dim[2];
    int gen;
    at_list_t * active_tiles = NULL;
    
    f = fopen(conf_file, "r");
    if(!f)
    {
        printf("Cannot open the configuration file!");
        return NULL;
    }
    
    toml_table_t * t_pars = toml_parse_file(f, errbuf, sizeof(errbuf));
    flose(f);
    
    if(!conf)
    {
        printf("Cannot parse the file!");
        return NULL;
    }
    
    toml_table_t * config_toml = toml_table_in(t_pars, "Config");
    if(!config_toml)
    {
        printf("Missing section [Config]!");
        return NULL;
    }
    
    toml_array_t * dim_array = toml_array_in(config_toml, "dimensions");
    if(!dim_array)
    {
        printf("Missing value 'dimensions'");
        return NULL;
    }
    
    toml_array_t * active_array = toml_array_in(config_toml, "active-tiles");
    if(!active_array)
    {
        printf("Missing value 'active-tiles'");
        return NULL;
    }
    
    toml_datum_t * gen_dat = toml_int_in(config_toml, "generations");
    if(!gen_dat)
    {
        printf("Missing value 'generations'");
        return NULL;
    }
    
    // dim[2]
    for(int i = 0; i < 2; i++)
    {
        toml_datum_t one_dim = toml_int_at(dim_array, i);
        if(!one_dim.ok)
        {
            printf("Error while reading 'dimensions'");
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
    for(int i = 0; ; i++)
    {
        toml_array_t tile_pos = toml_array_at(active_array, i);
        if(!tile_pos.ok)
        {
            printf("Error while reading 'active-tiles', pos:%d!", i);
            break;
        }
        else
        {
            toml_datum_t tile_x = toml_int_at(tile_pos, 0);
            toml_datum_t tile_y = toml_int_at(tile_pos, 1);
            if(!tile_x.ok || !tile_y)
                printf("Error while reading 'active-tiles', pos:%d!", i);
            else
            {
                add_tile_to_list(active_tiles, (int)tile_x.u.i, (int)tile_y.u.i);
            }
        }
    }
    
    config = config_new(dim[0], dim[1], active_tiles, gen);
    return config;
}

void add_tile_to_list(at_list_t * at_list, int x, int y)
{
    at_list_t * new = malloc(sizeof(at_list_t));
    new->tile[0] = x;
    new->tile[1] = y;
    new->next = NULL;
    
    if(at_list == NULL)
    {
        at_list = new;
    }
    else
    {
        new->next = at_list;
        at_list = new;
    }
};

Config * config_new(int x, int y, at_list_t * at, int gen)
{
    Config * conf = malloc(sizeof(Config));
    
    conf->dimensions[0] = x;
    conf->dimensions[1] = y;
    conf->generations = gen;
    conf->active_tiles = at;
    
    return conf;
}