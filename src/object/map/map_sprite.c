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

bool colision(int tile_placement)
{
    for (int i = 0; i < tile_colision_nbr; i++)
        if (tile_colision[i] - 1 == tile_placement) {
            return false;
        }
    return true;
}

void make_map_sprites_condi(map_t *map, tile_t *tmp, int x, int y)
{
    if (map->tile_placement[y][x] <= 0 || map->tile_placement[y][x] >
            ((tileset_size[0][1] / 16) * (tileset_size[0][0] / 16)))
        tmp->render = false;
    if (tmp->render == true) {
        sfSprite_setTextureRect(tmp->sprite_tile,
                map->textures[map->tile_placement[y][x] - 1]);
        sfSprite_setTexture(tmp->sprite_tile, map->map_tileset, sfFalse);
        sfSprite_setScale(tmp->sprite_tile, map->scale);
    }
}

void make_map_sprites(map_t *map)
{
    tile_t tmp;

    map->map_tiles = malloc(sizeof(tile_t *) * (map_size[1] + 1));
    for (int i = 0; i < map_size[1]; i++)
        map->map_tiles[i] = malloc(sizeof(tile_t) * (map_size[0] + 1));
    for (int y = 0; y < map_size[1]; y++)
        for (int x = 0; x < map_size[0]; x++) {
            tmp.sprite_tile = sfSprite_create();
            tmp.colision = colision(map->tile_placement[y][x] - 1);
            tmp.render = true;
            tmp.position = (sfVector2f) {x * 16 * map->scale.x,
                    y * 16 * map->scale.y};
            tmp.nb_texture = map->tile_placement[y][x] - 1;
            make_map_sprites_condi(map, &tmp, x, y);
            sfSprite_setPosition(tmp.sprite_tile, tmp.position);
            map->map_tiles[y][x] = tmp;
        }
}
