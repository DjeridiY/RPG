/*
** PROJECT, 2022
** Radar
** File description:
** get_time.c
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "rpg.h"
#include "my.h"
#include <stdio.h>

void get_time(clock_rpg_t *clock)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->time_elapsed += clock->time.microseconds;
    clock->secondes = sfTime_asSeconds(clock->time);
}
