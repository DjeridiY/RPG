/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** dropdown.h
*/

#include <stdbool.h>

#ifndef DROP_H_
    #define DROP_H_

// NUMBER OF DROP MENU
static const int nbr_drop = 2;
// DROP NAME
static const char *drop_name[2] = {"RESOLUTION", "MODE"};
// CHARACTERS SIZE OF DROP
static const int drop_size[2] = {30, 30};
// CHARACTERS COLOR
static const int char_red[2] = {255, 255};
static const int char_green[2] = {255, 255};
static const int char_blue[2] = {255, 255};
static const int char_alpha[2] = {255, 255};
// POSITION OF DROP
static const float droppos_x[2] = {720, 720};
static const float droppos_y[2] = {145, 245};
// SIZE OF DROP
static const float dropsize_x[2] = {200, 200};
static const float dropsize_y[2] = {40, 40};
// DROP VISIBLE
static const bool drop_visible[2] = {false, false};
// COLOR OF DROP
static const int drop_red[2] = {158, 158};
static const int drop_green[2] = {158, 158};
static const int drop_blue[2] = {158, 158};
static const int drop_alpha[2] = {255, 255};

// TOTAL NUMBER OF OPTION
static const int total_option = 4;
// NAME OF OPTION
static const char *option_name[4] = {"1920x1080", "1280x720",
"WINDOW MODE", "FULLSCREEN MODE"};
// OPTION CHARACTER SIZE
static const int option_size[4] = {20, 20, 20, 20};
// OPTION CHARACTER COLOR
static const int name_red[4] = {255, 255, 255, 255};
static const int name_green[4] = {255, 255, 255, 255};
static const int name_blue[4] = {255, 255, 255, 255};
static const int name_alpha[4] = {255, 255, 255, 255};
// NUMBER OF OPTION BY DROP
static const int option_nbr[2] = {2, 2};
// POSITION OF OPTION
static const float option_pos_x[4] = {720, 720, 720, 720};
static const float option_pos_y[4] = {183, 205, 283, 305};
// SIZE OF OPTION
static const float option_size_x[4] = {200, 200, 200, 200};
static const float option_size_y[4] = {20, 20, 20, 20};
// COLOR OF RECT OPTION
static const int option_red[4] = {158, 158, 158, 158};
static const int option_green[4] = {158, 158, 158, 158};
static const int option_blue[4] = {158, 158, 158, 158};
static const int option_alpha[4] = {255, 255, 255, 255};

#endif /* DROP_H_ */
