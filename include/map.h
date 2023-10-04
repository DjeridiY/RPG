/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** ressources
*/

#ifndef RESOURCES_H
    #define RESOURCES_H

static const int tileset_size[1][2] = {{768, 352}};

static const char *tileset[1] = {"ressources/tileset/colored_packed.png"};

static const char *map_path = "ressources/map/map.tmx";

static const int map_size[2] = {1000, 1000};

static const int tile_colision_nbr = 30;

static const int tile_colision[30] = {1, 8, 290, 417, 7, 721, 6, 601, 2,
    726, 105, 9, 782, 725, 97, 291, 292, 253, 722, 255, 297, 857, 852, 853,
    998, 856, 855, 997, 948, 851};

static const int nb_rooms = 25;

static const int order_map[25][9] = {{0, 25, 21, 34, 10, 14, 27, 9, 1},
    {0, 24, 2, 6, 14, 21, 27, 2, 1}, {0, 28, 21, 14, 8, 14, 4, 8, 1},
    {0, 5, 28, 23, 22, 11, 5, 19, 1}, {0, 14, 32, 34, 2, 7, 18, 3, 1},
    {0, 3, 7, 18, 15, 28, 16, 22, 1}, {0, 6, 26, 12, 30, 17, 9, 23, 1},
    {0, 10, 24, 7, 13, 29, 11, 5, 1}, {0, 8, 16, 25, 31, 20, 14, 4, 1},
    {0, 15, 19, 22, 33, 27, 3, 11, 1}, {0, 9, 17, 5, 14, 23, 20, 28, 1},
    {0, 21, 11, 27, 4, 8, 26, 15, 1}, {0, 29, 18, 32, 12, 6, 19, 23, 1},
    {0, 20, 30, 24, 7, 16, 22, 10, 1}, {0, 13, 2, 10, 17, 27, 31, 14, 1},
    {0, 31, 25, 15, 18, 3, 28, 11, 1}, {0, 16, 6, 19, 23, 29, 24, 8, 1},
    {0, 22, 9, 11, 5, 32, 21, 7, 1}, {0, 12, 27, 8, 30, 14, 25, 19, 1},
    {0, 4, 14, 26, 20, 9, 13, 17, 1}, {0, 33, 3, 21, 11, 15, 23, 29, 1},
    {0, 7, 23, 1, 27, 31, 20, 4, 1}, {0, 17, 8, 29, 22, 12, 16, 24, 1},
    {0, 11, 19, 31, 15, 25, 5, 10, 1}, {0, 26, 5, 17, 6, 2, 30, 18, 1}};

static const int map_entity[9][4] = {{6, -1, -1, -1}, {2, -1, -1, -1},
    {2, -1, -1, -1}, {2, 3, -1, -1}, {4, 2, -1, -1}, {5, 2, -1, -1},
    {5, 2, 3, -1}, {5, 2, 3, 4}, {1, -1, -1, -1}};

#endif /* RESOURCES_H */