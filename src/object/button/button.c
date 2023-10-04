/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** create_button.c
*/

#include "my.h"
#include "rpg.h"
#include "button.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void set_button(button_t *button)
{
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setSize(button->rect, button->size);
}

void set_texture_on_square(int i, button_t *button)
{
    sfTexture* texture;

    if (my_strcmp(path[i], "ressources/NULL.png") == 0) {
        sfRectangleShape_setFillColor(button->rect, button->color);
    } else {
        texture = sfTexture_createFromFile(path[i], NULL);
        sfRectangleShape_setTexture(button->rect, texture, sfTrue);
    }
}

button_t *create_button(int i)
{
    button_t *button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    button->size = get_vector(button_size_x[i], button_size_y[i]);
    button->pos = get_vector(button_pos_x[i], button_pos_y[i]);
    button->color = get_color(red[i], green[i], blue[i], alpha[i]);
    button->name = malloc(sizeof(char) * (my_strlen(button_name[i]) + 1));
    button->name = my_strcpy(button->name, button_name[i]);
    button->pressed = false;
    button->hovered = false;
    button->clicked = false;
    button->visible = visible_button[i];
    set_texture_on_square(i, button);
    set_button(button);
    set_text(button, i);
    return button;
}

void button_object(button_t **button)
{
    for (int i = 0; i < nbr_button; i++) {
        button[i] = create_button(i);
    }
}
