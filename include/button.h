/*
** PROJECT, 2022
** Paint
** File description:
** button_info.h
*/

#include "stdbool.h"

#ifndef BUTTON_H_
    #define BUTTON_H_

static const int menu_button = 4;
static const int nbr_button = 11;
// BUTTON NAME
static const char *button_name[11] = {"START", "RESUME", "SETTING",
"QUIT", "MUTE", "COMMANDS LIST", "SAVING", "LOADING",
"LEAVE", "RESTART", "QUIT"};
// PATH
static const char *path[11] = {"ressources/NULL.png", "ressources/NULL.png",
"ressources/NULL.png", "ressources/NULL.png", "ressources/image/mute.png",
"ressources/NULL.png", "ressources/NULL.png", "ressources/NULL.png",
"ressources/NULL.png",
"ressources/NULL.png", "ressources/NULL.png"};
// VISIBLE
static const bool visible_button[11] = {false, false, false,
false, false, false, false, false, false, false, false};
// SIZE OF TITLE
static const int title_size[11] = {45, 45, 45, 45, 45, 30, 45, 45, 45, 45, 45};
// COLOR OF TITLE
static const int title_red[11] = {255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255};
static const int title_green[11] = {255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255};
static const int title_blue[11] = {255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255};
static const int title_alpha[11] = {255, 255, 255, 255, 0, 255, 255, 255,
255, 255, 255};
// BUTTON POSITION
static const float button_pos_x[11] = {200, 200, 200, 200, 665, 600, 950,
950, 950, 400, 700};
static const float button_pos_y[11] = {170, 270, 370, 470, 420, 100, 250,
350, 500, 500, 500};
// BUTTON SIZE
static const float button_size_x[11] = {200, 200, 200, 200, 110, 100, 200,
200, 200, 200, 200};
static const float button_size_y[11] = {60, 60, 60, 60, 96, 50, 60, 60, 60,
60, 60};
// BUTTON COLOR
static const int red[11] = {158, 53, 158, 158, 255, 255, 53, 53,
158, 158, 158};
static const int green[11] = {158, 53, 158, 158, 255, 255, 53, 53,
158, 158, 158};
static const int blue[11] = {158, 53, 158, 158, 255, 255, 53, 53,
158, 158, 158};
static const int alpha[11] = {255, 255, 255, 255, 255, 0, 255, 255,
255, 255, 255};

#endif /* BUTTON_H_ */
