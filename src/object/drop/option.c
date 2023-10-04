/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** option.c
*/

#include "my.h"
#include "rpg.h"
#include "drop.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void set_option(button_t *option)
{
    sfRectangleShape_setPosition(option->rect, option->pos);
    sfRectangleShape_setSize(option->rect, option->size);
    sfRectangleShape_setFillColor(option->rect, option->color);
}

button_t *create_option(int rank)
{
    button_t *option = malloc(sizeof(button_t));

    option->rect = sfRectangleShape_create();
    option->size = get_vector(option_size_x[rank], option_size_y[rank]);
    option->pos = get_vector(option_pos_x[rank], option_pos_y[rank]);
    option->color = get_color(option_red[rank], option_green[rank],
    option_blue[rank], option_alpha[rank]);
    option->name = malloc(sizeof(char) * (my_strlen(option_name[rank]) + 1));
    option->name = my_strcpy(option->name, option_name[rank]);
    option->pressed = false;
    option->hovered = false;
    option->clicked = false;
    set_option(option);
    set_optiontext(option, rank);
    return option;
}
