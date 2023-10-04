/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** dropdown.c
*/

#include "my.h"
#include "rpg.h"
#include "drop.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>

button_t **option_object(button_t **option, int i)
{
    int rank = 0;
    int reach = 0;
    int temp = 0;

    for (int k = 0; k < i; k++)
        rank += option_nbr[k];
    for (int t = 0; t <= i; t++)
        reach += option_nbr[t];
    option = malloc(sizeof(button_t *) * (option_nbr[i] + 1));
    temp = reach - rank;
    for (int j = 0; j < temp; j++) {
        option[j] = create_option(rank);
        rank++;
    }
    return option;
}

void set_drop(drop_t *drop)
{
    sfRectangleShape_setPosition(drop->rect, drop->pos);
    sfRectangleShape_setSize(drop->rect, drop->size);
    sfRectangleShape_setFillColor(drop->rect, drop->color);
}

drop_t *create_drop(int i)
{
    drop_t *drop = malloc(sizeof(drop_t));

    drop->rect = sfRectangleShape_create();
    drop->size = get_vector(dropsize_x[i], dropsize_y[i]);
    drop->pos = get_vector(droppos_x[i], droppos_y[i]);
    drop->color = get_color(drop_red[i], drop_green[i],
    drop_blue[i], drop_alpha[i]);
    drop->name = malloc(sizeof(char) * (my_strlen(drop_name[i]) + 1));
    drop->name = my_strcpy(drop->name, drop_name[i]);
    drop->pressed = false;
    drop->hovered = false;
    drop->clicked = false;
    drop->visible = drop_visible[i];
    drop->option = option_object(drop->option, i);
    set_drop(drop);
    set_droptext(drop, i);
    return drop;
}

void dropdown_object(drop_t **drop)
{
    for (int i = 0; i < nbr_drop; i++) {
        drop[i] = create_drop(i);
    }
}
