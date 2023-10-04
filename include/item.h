/*
** EPITECH PROJECT, 2022
** my
** File description:
** my.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

#ifndef ITEM_H_
    #define ITEM_H_

static const int item_nbr = 11;

static const char *item_name[11] = {"nothing", "falchion",
"heal potion", "Ragnell", "Old Falchion", "bluel", "yellow", "Binding Blade",
"speed potion", "defense potion", "magic potion"};

static const char *item_texture[11] = {"ressources/defense/nothing.png",
"ressources/sword/falchion.png", "ressources/defense/heal_potion.png",
"ressources/sword/ragnell.png", "ressources/sword/marth.png",
"ressources/sword/bluel.png", "ressources/sword/yellow.png",
"ressources/sword/roy.png", "ressources/defense/speed_potion.png",
"ressources/defense/defense_potion.png", "ressources/defense/magic_potion.png"};
static const char *item_utility[11] = {"defense", "attack",
"defense", "attack", "attack", "attack", "attack", "attack",
"defense", "defense", "defense"};

static const int item_lvl[11] = {0, 2, 1, 3, 5, 3, 3, 4, 1, 1, 10};

static const float item_damage[11] = {1, 7, 5, 15, 15, 5, 11, 3, 4, 10};

static const float item_speed[11] = {1, 3, 1, -3, 8, 10, 5, 6, 4, 4, 0};

static const float item_scale_x[11] = {1, 0.09, 0.7, 0.09, 0.09, 0.09,
0.09, 0.09, 0.7, 0.7, 0.7};
static const float item_scale_y[11] = {1, 0.09, 0.7, 0.09, 0.09, 0.09,
0.09, 0.09, 0.7, 0.7, 0.7};

static const float item_pos_x[11] = {100, 100, 100, 500, 400, 300, 200,
200, 400, 400, 500};
static const float item_pos_y[11] = {100, 100, 100, 500, 300, 300, 200,
300, 400, 500, 400};

static const bool equiped[11] = {false, false, false, false, false, false,
false, false, false, false, false};

static const bool item_visbility[11] = {false, false, false, false, false,
false, false, false, false, false, false};

static const bool item_used[11] = {false, false, false, false, false, false,
false, false, false, false, false};

#endif /* ITEM_H_ */
