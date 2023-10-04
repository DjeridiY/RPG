/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** button_info.h
*/

#include <stdbool.h>

#ifndef CURSOR_H_
    #define CURSOR_H_

// NUMBER OF CURSOR
static const int nbr_of_cursor = 1;
// CURSOR NAME
static const char *name_cursor[1] = {"Volume"};
// VISIBLE
static const bool visible_cursor[1] = {false};
// DIMENSION OF CURSOR
static const float box_x[1] = {15};
static const float box_y[1] = {30};
// SIZE OF TEXT
static const int text_size[1] = {50};
// COORD OF TEXT
static const float text_x[1] = {744};
static const float text_y[1] = {330};
// POINT OF 0
static const float start_x[1] = {810};
static const float start_y[1] = {465};
// POINT OF 1
static const float end_x[1] = {960};
static const float end_y[1] = {465};
// LINE LENGTH AND HEIGHT
static const float line_x[1] = {150};
static const float line_y[1] = {5};
// COLOR OF LINE
static const int line_red[1] = {255};
static const int line_green[1] = {255};
static const int line_blue[1] = {255};
static const int line_alpha[1] = {255};
// COLOR OF TEXT
static const int text_red[1] = {255};
static const int text_green[1] = {255};
static const int text_blue[1] = {255};
static const int text_alpha[1] = {255};
// COLOR OF CURSOR
static const int cursor_red[1] = {18};
static const int cursor_green[1] = {238};
static const int cursor_blue[1] = {150};
static const int cursor_alpha[1] = {255};

#endif /* CURSOR_H_ */
