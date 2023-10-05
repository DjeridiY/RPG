/*
** PROJECT, 2022
** Paint
** File description:
** highlight_option.c
*/

#include "my.h"
#include "rpg.h"
#include "drop.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void change_option_color(int i, drop_t **drop)
{
    sfColor temp_color;

    for (int j = 0; j < option_nbr[i]; j++) {
        temp_color = drop[i]->option[j]->color;
        if (drop[i]->option[j]->hovered == true) {
            temp_color.r *= 2;
            temp_color.g *= 2;
            temp_color.b *= 2;
            sfRectangleShape_setFillColor(drop[i]->option[j]->rect,
            temp_color);
        } else {
            sfRectangleShape_setFillColor(drop[i]->option[j]->rect,
            drop[i]->option[j]->color);
        }
    }
}

void change_dropdown_color(drop_t *drop)
{
    sfColor temp_color = drop->color;

    temp_color.r *= 3.5;
    temp_color.g *= 3.5;
    temp_color.b *= 3.5;
    sfRectangleShape_setFillColor(drop->rect,
    temp_color);
}

void highlight_drop(drop_t **drop)
{
    for (int i = 0; i < nbr_drop; i++) {
        if (drop[i]->clicked == true) {
            change_dropdown_color(drop[i]);
            change_option_color(i, drop);
        } else {
            sfRectangleShape_setFillColor(drop[i]->rect,
            drop[i]->color);
        }
    }
}
