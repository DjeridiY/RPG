/*
** EPITECH PROJECT, 2022
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

void free_struct(int **structure)
{
    for (int i = 0; i < 1000; i++)
        free(structure[i]);
    free(structure);
}

list_t *make_structure_suite(map_t *map, rpg_t *game, list_t **liste,
    sfVector2f pos)
{
    int **structure;
    int **populated_structure;

    if (map->tile_placement[(int) pos.y][(int) pos.x] != 0) {
        structure = malloc_structure(1000, 1000);
        populated_structure = get_structure(map, ((sfVector2f) {pos.x, pos.y}),
            structure, (sfVector2f) {0, 0});
        if (!is_structure_empty(populated_structure, 1000, 1000))
            add_to_list(liste, populated_structure);
        if (is_structure_empty(populated_structure, 1000, 1000))
            free_struct(structure);
    }
}

list_t *make_structure(map_t *map, rpg_t *game)
{
    list_t *liste = NULL;
    int **structure;
    int **populated_structure;

    for (int y = 0; y < map_size[1]; y++)
        for (int x = 0; x < map_size[0]; x++)
            make_structure_suite(map, game, &liste, (sfVector2f) {x, y});
    return liste;
}

bool is_structure_empty_suite(int **structure, int y, int width)
{
    for (int x = 0; x < width; x++)
        if (structure[y][x] != 0)
            return false;
    return true;
}

bool is_structure_empty(int **structure, int width, int height)
{
    for (int y = 0; y < height; y++)
        if (!is_structure_empty_suite(structure, y, width))
            return false;
    return true;
}
