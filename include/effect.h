/*
** PROJECT, 2022
** effect
** File description:
** effect.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

#ifndef EFFECT_H_
    #define EFFECT_H_

static const int effect_nbr = 2;

static const char *effect_sprite[2] = {
"ressources/sprite_sheet/slash_player.png",
"ressources/sprite_sheet/slash_enemi.png"};

static const int effect_size_x[2] = {3312, 3312};
static const int effect_size_y[2] = {402, 402};
static const float effect_max_frames[2] = {6, 6};

static const float effect_fps[2] = {12, 12};

#endif /* EFFECT_H_ */
