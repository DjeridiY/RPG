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

#ifndef UPDATE_SETTING
    #define UPDATE_SETTING

// CURSOR NAME
static const char *up_name_cursor[1] = {"Volume"};
// VISIBLE
static const bool up_visible_cursor[1] = {false};
// DIMENSION OF CURSOR
static const float up_box_x[1] = {15};
static const float up_box_y[1] = {30};
// SIZE OF TEXT
static const int up_text_size[1] = {50};
// COORD OF TEXT
static const float up_text_x[1] = {540};
static const float up_text_y[1] = {100};
// POINT OF 0
static const float up_start_x[1] = {630};
static const float up_start_y[1] = {200};
// POINT OF 1
static const float up_end_x[1] = {690};
static const float up_end_y[1] = {200};
// LINE LENGTH AND HEIGHT
static const float up_line_x[1] = {150};
static const float up_line_y[1] = {5};
// COLOR OF LINE
static const int up_line_red[1] = {255};
static const int up_line_green[1] = {255};
static const int up_line_blue[1] = {255};
static const int up_line_alpha[1] = {255};
// COLOR OF TEXT
static const int up_text_red[1] = {255};
static const int up_text_green[1] = {255};
static const int up_text_blue[1] = {255};
static const int up_text_alpha[1] = {255};
// COLOR OF CURSOR
static const int up_cursor_red[1] = {255};
static const int up_cursor_green[1] = {255};
static const int up_cursor_blue[1] = {255};
static const int up_cursor_alpha[1] = {255};


// SIZE OF TITLE
static const int up_title_size[2] = {45, 45};
// COLOR OF TITLE
static const int up_title_red[2] = {255, 255};
static const int up_title_green[2] = {255, 255};
static const int up_title_blue[2] = {255, 255};
static const int up_title_alpha[2] = {255, 255};
// BUTTON POSITION
static const float up_button_pos_x[2] = {450, 950};
static const float up_button_pos_y[2] = {172, 100};
// BUTTON SIZE
static const float up_button_size_x[2] = {110, 200};
static const float up_button_size_y[2] = {60, 60};
// BUTTON COLOR
static const int up_red[2] = {158, 158};
static const int up_green[2] = {158, 158};
static const int up_blue[2] = {158, 158};
static const int up_alpha[2] = {255, 255};


// NUMBER OF DROP MENU
static const int up_nbr_drop = 2;
// CHARACTERS SIZE OF DROP
static const int up_drop_size[2] = {30, 30};
// CHARACTERS COLOR
static const int up_char_red[2] = {255, 255};
static const int up_char_green[2] = {255, 255};
static const int up_char_blue[2] = {255, 255};
static const int up_char_alpha[2] = {255, 255};
// POSITION OF DROP
static const float up_droppos_x[2] = {100, 100};
static const float up_droppos_y[2] = {145, 245};
// SIZE OF DROP
static const float up_dropsize_x[2] = {200, 200};
static const float up_dropsize_y[2] = {40, 40};
// COLOR OF DROP
static const int up_drop_red[2] = {158, 158};
static const int up_drop_green[2] = {158, 158};
static const int up_drop_blue[2] = {158, 158};
static const int up_drop_alpha[2] = {255, 255};
// TOTAL NUMBER OF OPTION
static const int up_total_option = 4;
// OPTION CHARACTER SIZE
static const int up_option_size[4] = {20, 20, 20, 20};
// OPTION CHARACTER COLOR
static const int up_name_red[4] = {255, 255, 255, 255};
static const int up_name_green[4] = {255, 255, 255, 255};
static const int up_name_blue[4] = {255, 255, 255, 255};
static const int up_name_alpha[4] = {255, 255, 255, 255};
// NUMBER OF OPTION BY DROP
static const int up_option_nbr[2] = {2, 2};
// POSITION OF OPTION
static const float up_option_pos_x[4] = {100, 100, 100, 100};
static const float up_option_pos_y[4] = {183, 205, 283, 305};
// SIZE OF OPTION
static const float up_option_size_x[4] = {200, 200, 200, 200};
static const float up_option_size_y[4] = {20, 20, 20, 20};
// COLOR OF RECT OPTION
static const int up_option_red[4] = {158, 158, 158, 158};
static const int up_option_green[4] = {158, 158, 158, 158};
static const int up_option_blue[4] = {158, 158, 158, 158};
static const int up_option_alpha[4] = {255, 255, 255, 255};

#endif /* UPDATE_SETTING */
