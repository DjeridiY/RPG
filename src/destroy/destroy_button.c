/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** destroy_button.c
*/

#include "my.h"
#include "rpg.h"
#include "button.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void destroy_button(button_t **button)
{
    for (int i = 0; i < nbr_button; i++) {
        sfRectangleShape_destroy(button[i]->rect);
        sfText_destroy(button[i]->text->title);
        sfFont_destroy(button[i]->text->font);
        free(button[i]->text);
        free(button[i]->name);
        free(button[i]);
    }
    free(button);
}
