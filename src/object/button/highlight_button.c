/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** highlight_button.c
*/

#include "my.h"
#include "rpg.h"
#include "button.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>

void highlight_bouton(button_t **button)
{
    sfColor temp_color;

    for (int i = 0; i < nbr_button; i++) {
        if (button[i]->hovered == true ||
        button[i]->clicked == true) {
            temp_color = button[i]->color;
            temp_color.r *= 3.5;
            temp_color.g *= 3.5;
            temp_color.b *= 3.5;
            sfRectangleShape_setFillColor(button[i]->rect,
            temp_color);
        } else {
            sfRectangleShape_setFillColor(button[i]->rect,
            button[i]->color);
        }
    }
}
