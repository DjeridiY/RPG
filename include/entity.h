/*
** PROJECT, 2022
** my
** File description:
** my.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

#ifndef ENTITY_H_
    #define ENTITY_H_

static const int entity_nbr = 7;

static const char *entity_sprite[7] = {"ressources/sprite_sheet/player.png",
"ressources/sprite_sheet/boss.png", "ressources/sprite_sheet/enemy.png",
"ressources/sprite_sheet/enemy.png", "ressources/sprite_sheet/anna.png",
"ressources/sprite_sheet/sorciere.png", "ressources/sprite_sheet/dummy.png"};

static const int player_size_x[7] = {384, 384, 1152, 1152, 384, 384, 384};
static const int player_size_y[7] = {512, 512, 13826, 13826, 4608, 3584, 512};

static const int sprite_rank_x[7] = {4, 0, 4, 16, 0, 0, 0};
static const int sprite_rank_y[7] = {0, 0, 0, 7, 5, 5, 0};

static const float entity_x[7] = {1330, 100, 400, 300, 500, 300, 2000};
static const float entity_y[7] = {480, 100, 400, 300, 100, 500, 200};

static const float entity_scale_x[7] = {0.2, 3.5, 2, 2.5, 2.5, 2.5, 2.5};
static const float entity_scale_y[7] = {0.2, 3.5, 2, 2.5, 2.5, 2.5, 2.5};

static const float effect_scale_x[7] = {0.3, 0.5, 0.24, 0.3, 0.24, 0.24, 0.24};
static const float effect_scale_y[7] = {0.3, 0.5, 0.24, 0.3, 0.24, 0.24, 0.24};

static const int entity_effect_use[7] = {0, 1, 1, 1, 1, 1, 1};

static const int status[7] = {0, 2, 2, 2, 2, 2, 2};

static const bool entity_visible[7] = {false, false, false, false,
false, false, false};

#endif /* ENTITY_H_ */
