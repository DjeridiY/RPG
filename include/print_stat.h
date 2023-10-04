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

#ifndef PRINT_STAT_T
    #define PRINT_STAT_T

static const int print_nbr = 10;

static const float p_size[9] = {50, 20, 20, 20, 20, 20, 20, 20, 20};

static const float p_pos_x[9] = {360, 305, 485, 480, 410, 430, 175, 175, 175};
static const float p_pos_y[9] = {100, 295, 295, 175, 175, 205, 317.5,
347, 378.5};

static const int p_red[9] = {255, 0, 0, 0, 0, 0, 0, 0, 0};
static const int p_green[9] = {215, 0, 0, 0, 0, 0, 0, 0, 0};
static const int p_blue[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
static const int p_alpha[9] = {255, 255, 255, 255, 255, 255, 255, 255, 255};

static const bool p_visbility[9] = {false, false, false, false, false, false,
false, false, false};

#endif /* PRINT_STAT_T */
