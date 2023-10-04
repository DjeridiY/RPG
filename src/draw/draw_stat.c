/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** draw_stat.c
*/

#include "my.h"
#include "rpg.h"
#include "stat.h"
#include "print_stat.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void draw_stat(stat_t **stat, sfRenderWindow *window)
{
    for (int i = 0; i < stat_nbr; i++) {
        for (int j = 0; j < print_nbr; j++) {
            draw_text(stat[i]->print_stat[j], window);
        }
    }
}
