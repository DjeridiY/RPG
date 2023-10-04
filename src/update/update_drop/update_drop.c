/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** dropdown.c
*/

#include "my.h"
#include "rpg.h"
#include "update_setting.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>

void up_option_object(button_t **option, int i)
{
    int rank = 0;
    int reach = 0;
    int temp = 0;

    for (int k = 0; k < i; k++)
        rank += up_option_nbr[k];
    for (int t = 0; t <= i; t++)
        reach += up_option_nbr[t];
    temp = reach - rank;
    for (int j = 0; j < temp; j++) {
        update_option(rank, option[j]);
        rank++;
    }
}

void up_set_drop(drop_t *drop)
{
    sfRectangleShape_setPosition(drop->rect, drop->pos);
    sfRectangleShape_setSize(drop->rect, drop->size);
    sfRectangleShape_setFillColor(drop->rect, drop->color);
}

void update_drop(int i, drop_t *drop)
{
    drop->size = get_vector(up_dropsize_x[i], up_dropsize_y[i]);
    drop->pos = get_vector(up_droppos_x[i], up_droppos_y[i]);
    drop->color = get_color(up_drop_red[i], up_drop_green[i],
    up_drop_blue[i], up_drop_alpha[i]);
    up_option_object(drop->option, i);
    up_set_drop(drop);
    up_set_droptext(drop, i);
}

void update_dropdown(drop_t **drop)
{
    for (int i = 0; i < up_nbr_drop; i++) {
        update_drop(i, drop[i]);
    }
}
