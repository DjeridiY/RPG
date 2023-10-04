/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** destroy_ui.c
*/

#include "my.h"
#include "rpg.h"
#include "rectangle.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void destroy_rectangle(rectangle_t **rect)
{
    for (int i = 0; i < rect_nbr; i++) {
        sfRectangleShape_destroy(rect[i]->rect);
        free(rect[i]->name);
        free(rect[i]);
    }
    free(rect);
}
