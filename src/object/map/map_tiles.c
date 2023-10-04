/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** map_tiles.c
*/

#include "my.h"
#include "rpg.h"
#include "map.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>

char *my_memset(char *str, char to_replace, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = to_replace;
    return str;
}

void tile_placement_malloc(int ***tile_placement)
{
    *tile_placement = malloc(sizeof(int *) * (map_size[1] + 1));
    for (int i = 0; i < map_size[1]; i++) {
        (*tile_placement)[i] = malloc(sizeof(int) * (map_size[0] + 1));
        for (int j = 0; j < map_size[0]; j++)
            (*tile_placement)[i][j] = 0;
    }
}

void make_tiles_condi(int *x, int *y, char tmp[10], int ***tile_placement)
{
    if (*x == map_size[0]) {
        *x = 0;
        (*y)++;
    }
    (*tile_placement)[*y][*x] = my_atoi(tmp);
    (*x)++;
}

void make_tiles(int ***tile_placement, char *file_str, char *map_info)
{
    char tmp[10];
    int cn = 0;
    int x = 0;
    int y = 0;

    tile_placement_malloc(tile_placement);
    my_memset(tmp, 0, 9);
    for (int i = 0; map_info[i] != 0; i++) {
        if (map_info[i] != ',') {
            tmp[cn] = map_info[i];
            cn++;
        }
        if (map_info[i] == ',') {
            make_tiles_condi(&x, &y, tmp, tile_placement);
            cn = 0;
            my_memset(tmp, 0, 9);
        }
    }
    free(map_info);
    free(file_str);
}
