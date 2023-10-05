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

int **get_structure(map_t *map, sfVector2f coord,
    int **structure, sfVector2f pos)
{
    if (!is_valid(pos, 1000, 1000) ||
            structure[(int) coord.y][(int) coord.x] != 0
            || map->tile_placement[(int) coord.y][(int) coord.x] == 0)
        return structure;
    structure[(int) pos.y][(int) pos.x] =
        map->tile_placement[(int) coord.y][(int) coord.x];
    map->tile_placement[(int) coord.y][(int) coord.x] = 0;
    get_structure(map, ((sfVector2f) {coord.x - 1, coord.y}),
        structure, (sfVector2f) {pos.x - 1, pos.y});
    get_structure(map, ((sfVector2f) {coord.x + 1, coord.y}),
        structure, (sfVector2f) {pos.x + 1, pos.y});
    get_structure(map, ((sfVector2f) {coord.x, coord.y - 1}),
        structure, (sfVector2f) {pos.x, pos.y - 1});
    get_structure(map, ((sfVector2f) {coord.x, coord.y + 1}),
        structure, (sfVector2f) {pos.x, pos.y + 1});
    return structure;
}

void insert_int_tab(int **tab, int **to_insert, sfVector2f pos)
{
    for (int y = 0; y < 100; y++)
        for (int x = 0; x < 100; x++)
            tab[(int) pos.y + y][(int) pos.x + x] = to_insert[y][x];
}

int **get_data_at_index(list_t *liste, int index)
{
    list_t *tmp = liste;
    int count = 0;

    while (tmp != NULL) {
        if (count == index) {
            return tmp->data;
        }
        count++;
        tmp = tmp->next;
    }
    return NULL;
}

void make_tiles_structure(map_t *map, rpg_t *game, list_t *structure, int size)
{
    int **to_insert;

    for (int i = 0; i < size; i++) {
        to_insert = get_data_at_index(structure, map->order[i]);
        insert_int_tab(map->tile_placement, to_insert,
            (sfVector2f) {0, (100 * i)});
    }
}
