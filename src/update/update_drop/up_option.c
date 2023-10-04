/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** option.c
*/

#include "my.h"
#include "rpg.h"
#include "update_setting.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void up_set_option(button_t *option)
{
    sfRectangleShape_setPosition(option->rect, option->pos);
    sfRectangleShape_setSize(option->rect, option->size);
    sfRectangleShape_setFillColor(option->rect, option->color);
}

void update_option(int rank, button_t *option)
{
    option->size = get_vector(up_option_size_x[rank], up_option_size_y[rank]);
    option->pos = get_vector(up_option_pos_x[rank], up_option_pos_y[rank]);
    option->color = get_color(up_option_red[rank], up_option_green[rank],
    up_option_blue[rank], up_option_alpha[rank]);
    up_set_option(option);
    up_set_optiontext(option, rank);
}
