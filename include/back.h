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

#ifndef BACK_H_
    #define BACK_H_

static const int back_nbr = 3;

static const char *back_name[3] = {"menu_back", "ig_menu_back", "lose"};

static const char *back_sprite[3] = {"ressources/back/rpg_menu_back.png",
"ressources/back/inventory_bg.png", "ressources/back/end.jpg"};

static const float bacpos_x[3] = {0, 0, 0};
static const float bacpos_y[3] = {0, 0, 0};

static const float bacscale_x[3] = {1, 1, 1};
static const float bacscale_y[3] = {1, 1, 1};

static const bool visible[3] = {false, false, false};

#endif /* BACK_H_ */
