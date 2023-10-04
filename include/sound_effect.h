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

#ifndef SOUND_EFFECT_H_
    #define SOUND_EFFECT_H_

static const int sound_nbr = 5;

static const char *sound_name[5] = {"epee effect", "ennemi effect",
"click", "lvlup", "drink"};
static const char *sound_file[5] = {"ressources/sound/epee2.ogg",
"ressources/sound/epee1.ogg", "ressources/sound/click.ogg",
"ressources/sound/lvl_up.ogg", "ressources/sound/drink.ogg"};

static const float sound_volume[5] = {30, 30, 30, 30, 70};

#endif /* SOUND_EFFECT_H_ */
