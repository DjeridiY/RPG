/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** draw_ui.c
*/

#include "my.h"
#include "rpg.h"
#include "rectangle.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>

void draw_rectangle(rectangle_t **rect, sfRenderWindow *window)
{
    for (int i = 0; i < rect_nbr; i++) {
        if (rect[i]->visibility) {
            sfRenderWindow_drawRectangleShape(window, rect[i]->rect, NULL);
        }
    }
}
