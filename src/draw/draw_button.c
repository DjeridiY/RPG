/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** draw_rectangle.c
*/

#include "my.h"
#include "rpg.h"
#include "button.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void draw_button(button_t **button, sfRenderWindow *window)
{
    for (int i = 0; i < nbr_button; i++) {
        if (button[i]->visible) {
            sfRenderWindow_drawRectangleShape(window, button[i]->rect, NULL);
            sfRenderWindow_drawText(window, button[i]->text->title, NULL);
        }
    }
}
