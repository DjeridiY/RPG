/*
** PROJECT, 2022
** my
** File description:
** my.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

#ifndef STAT_H_
    #define STAT_H_

static const int stat_nbr = 7;

static const char *stat_name[7] = {"Lucina", "Boss", "assassin", "tank",
"normal", "sorciere", "dummy"};

static const char *weapon[7] = {"falchion", "nothing", "nothing", "nothing",
"nothing", "nothing", "nothing"};

static const char *utility[7] = {"nothing", "nothing", "nothing", "nothing",
"nothing", "nothing", "nothing"};

static const int lvl[7] = {2, 6, 3, 4, 4, 4, 0};

static const float hp[7] = {10, 200, 10, 30, 20, 15, 30};

static const float strength[7] = {3, 32, 7, 22, 18, 25, 0};

static const float speed[7] = {3, 18, 53, 5, 25, 20, 0};

static const float defense[7] = {3, 15, 1, 7, 5, 3, 2};

static const float xp[7] = {0, 0, 0, 0, 0, 0};

#endif /* STAT_H_ */
