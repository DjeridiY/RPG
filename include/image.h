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

#ifndef IMAGE_H_
    #define IMAGE_H_

static const int img_nbr = 8;

static const char *img_name[8] = {"Lucina portrait", "Z_KEY", "Q_KEY",
"S_KEY", "D_KEY", "LEFT_CLICK_KEY", "portrait_frame", "SPACE_KEY"};

static const char *img_sprite[8] = {"ressources/image/Lucina.png",
"ressources/image/Z_KEY.png", "ressources/image/Q_KEY.png",
"ressources/image/S_KEY.png",
"ressources/image/D_KEY.png", "ressources/image/LEFT_CLICK_KEY.png",
"ressources/image/portrait_frame.png", "ressources/image/SPACE_KEY.png"};

static const float imgpos_x[8] = {145, 550, 550, 665, 665, 610, 93, 600};
static const float imgpos_y[8] = {115, 150, 220, 150, 220, 370, 71, 300};

static const float imgscale_x[8] = {0.65, 0.70, 0.70, 0.70, 0.70, 0.20, 0.45,
0.70};
static const float imgscale_y[8] = {0.65, 0.70, 0.70, 0.70, 0.70, 0.20, 0.45,
0.70};

static const bool img_visible[8] = {false, false, false, false, false,
false, false, false};

#endif /* IMAGE_H_ */
