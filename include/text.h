/*
** EPITECH PROJECT, 2022
** my
** File description:
** my.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "stat.h"
#include "my.h"
#include <stdbool.h>

#ifndef TEXT_H_
    #define TEXT_H_

static const int text_nbr = 17;

static const char *text_title[17] = {"LVL", "HP", "EXP", "STR", "SPD",
"DEF", " / ", "2", "UP", "LEFT", "DOWN", "RIGHT", "INTERACT", "ATTACK",
"Hi Lucina, I don't have time to explain \nit all but you have to rescue the",
"princess held at the top of the tower, beware\n the enemies are powerful",
"you can train on the dummy at the entrance\nif you want by pressing SPACE !"};

static const float text_pos_x[17] = {360, 360, 430, 106, 106, 106, 443,
455, 600, 600, 720, 720, 690, 700, 300, 300, 300};
static const float text_pos_y[17] = {175, 205, 175, 317.5, 346, 374.5,
205, 205, 160, 230, 160, 240, 400, 310, 700, 500, 300};

static const float t_size[17] = {20, 20, 20, 20, 20, 20, 20, 20, 20,
20, 20, 20, 20, 20, 20, 20, 20};

static const int t_red[17] = {100, 100, 100, 0, 0, 0, 0, 0, 255,
255, 255, 255, 255, 255, 255, 255, 255};
static const int t_green[17] = {84.3, 84.3, 84.3, 0, 0, 0, 0, 0, 255,
255, 255, 255, 255, 255, 255, 255, 255};
static const int t_blue[17] = {0, 0, 0, 0, 0, 0, 0, 0, 255, 255,
255, 255, 255, 255, 255, 255, 255};
static const int t_alpha[17] = {255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

static const bool text_visible[17] = {false, false, false, false,
false, false, false, false, false, false, false, false, false,
false, false, false, false};

#endif /* TEXT_H_ */
