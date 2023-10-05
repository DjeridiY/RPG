/*
** PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** map_object.c
*/

#include "my.h"
#include "rpg.h"
#include "map.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>

char *get_map_info(char *str)
{
    char **parsed_map = str_to_word_array(str, "\n");
    char **map_info = malloc(sizeof(char *) * (map_size[1] + 1));
    int cn = 5;
    int size = 0;
    char *to_return;

    for (int i = 0; i < map_size[1]; i++) {
        map_info[i] = parsed_map[i + cn];
        size += my_strlen(map_info[i]);
    }
    to_return = malloc(sizeof(char) * (size + 1));
    to_return[0] = '\0';
    for (int i = 0; i < map_size[1]; i++) {
        my_strcat(to_return, map_info[i]);
    }
    free_tab(parsed_map);
    free(map_info);
    return to_return;
}

void make_textures(sfIntRect **textures)
{
    sfIntRect *texture;
    sfIntRect selection;

    *textures = malloc(sizeof(sfIntRect) *
    (tileset_size[0][1] / 16) * (tileset_size[0][0] / 16) + 1);
    selection.height = 16;
    selection.width = 16;
    for (int y = 0; y < tileset_size[0][1] / 16; y++) {
        for (int x = 0; x < tileset_size[0][0] / 16; x++) {
            selection.top = y * selection.height;
            selection.left = x * selection.width;
            (*textures)[(y * (tileset_size[0][0] / 16)) + x] = selection;
        }
    }
}

void map_object(map_t *map, rpg_t *game)
{
    char *file_str;
    list_t *structure;

    game->current_room = 0;
    srand((int) sfClock_getElapsedTime(game->clock->clock).microseconds);
    map->scale = game->view->zoom;
    map->map_tileset = sfTexture_createFromFile(tileset[0], NULL);
    make_textures(&map->textures);
    file_str = file_to_string((char *) map_path);
    make_tiles(&map->tile_placement, file_str, get_map_info(file_str));
    structure = make_structure(map, game);
    game->map->structures = structure;
    game->rooms = malloc(sizeof(bool) * nb_rooms);
    for (int i = 0; i < nb_rooms; i++)
        game->rooms[i] = false;
    map->order = order_map[rand() % nb_rooms];
    make_tiles_structure(map, game, structure, 9);
    make_map_sprites(map);
}
