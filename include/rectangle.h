/*
** PROJECT, 2022
** Paint
** File description:
** ui.h
*/

#ifndef RECTANGLE_H_
    #define RECTANGLE_H_

static const float rect_nbr = 16;

static const float rect_pos_x[16] = {360, 106, 106, 106, 820, 0, 0, 1230,
0, 156, 270, 450, 360, 410, 360, 425};
static const float rect_pos_y[16] = {115, 317.5, 347, 378.5, 0, 670, 0, 0,
0, 317.5, 299, 299, 170, 205, 200, 170};

static const float rect_size_x[16] = {145, 100, 100, 100, 90, 1280, 1280,
50, 50, 2, 145, 145, 145, 80, 145, 2};
static const float rect_size_y[16] = {48, 29, 29, 29, 720, 50, 50, 720,
720, 90, 145, 145, 70, 29, 2, 30};

static const int rect_red[16] = {194, 194, 194, 194, 204, 204, 204, 204,
204, 0, 194, 194, 194, 94, 0, 0};
static const int rect_green[16] = {178, 178, 178, 178, 205, 205, 205, 205,
205, 0, 178, 178, 178, 179, 0, 0};
static const int rect_blue[16] = {128, 128, 128, 128, 198, 198, 198, 198,
198, 0, 128, 128, 128, 57, 0, 0};
static const int rect_alpha[16] = {255, 255, 255, 255, 0, 0, 0, 0, 0, 255,
255, 255, 255, 255, 255, 255};

static const char *rect_name[16] = {"stat_name", "strength", "speed",
"defence", "split_screen", "Out_square1", "Out_square2",
"Out_square3", "Out_square4", "split_stat_rect", "middle_sqr1",
"middle_sqr2", "square_xp_hp_lvl", "HP_BAR", "split_xp_hp_lvl",
"split_lvl_xp"};

static const bool rect_visible[16] = {false, false, false, false, false,
false, false, false, false, false, false, false, false, false, false,
false};

#endif /* RECTANGLE_H_ */
