/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** draw_drop.c
*/

#include "my.h"
#include "rpg.h"
#include "drop.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void draw_option(button_t **option, drop_t *drop,
sfRenderWindow *window, int i)
{
    if (drop->clicked == true) {
        for (int j = 0; j < option_nbr[i]; j++) {
            sfRenderWindow_drawRectangleShape(window, option[j]->rect, NULL);
            sfRenderWindow_drawText(window, option[j]->text->title, NULL);
        }
    }
}

void draw_drop(drop_t **drop, sfRenderWindow *window, rpg_t *game)
{
    for (int i = 0; i < nbr_drop; i++) {
        if (drop[i]->visible) {
            sfRenderWindow_drawRectangleShape(window, drop[i]->rect, NULL);
            sfRenderWindow_drawText(window, drop[i]->text->title, NULL);
            draw_option(drop[i]->option, drop[i], window, i);
        }
    }
}
