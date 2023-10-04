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

#ifndef MUSIC_H_
    #define MUSIC_H_

static const int music_nbr = 2;

static const char *music_name[2] = {"menu", "game"};

static const char *music_file[2] = {"ressources/sound/menu.ogg",
"ressources/sound/game.ogg"};

static const float volume[2] = {50, 35};

static const bool play[2] = {false, false};

#endif /* MUSIC_H_ */
