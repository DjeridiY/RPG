/*
** PROJECT, 2022
** Paint
** File description:
** interface.c
*/

#include "my.h"
#include "rpg.h"
#include "rectangle.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void set_rect(rectangle_t *rect)
{
    sfRectangleShape_setPosition(rect->rect, rect->pos);
    sfRectangleShape_setSize(rect->rect, rect->size);
    sfRectangleShape_setFillColor(rect->rect, rect->color);
}

rectangle_t *create_rectangle(int i)
{
    rectangle_t *rect = malloc(sizeof(rectangle_t));

    rect->rect = sfRectangleShape_create();
    rect->size = get_vector(rect_size_x[i], rect_size_y[i]);
    rect->pos = get_vector(rect_pos_x[i], rect_pos_y[i]);
    rect->color = get_color(rect_red[i], rect_green[i],
    rect_blue[i], rect_alpha[i]);
    rect->visibility = rect_visible[i];
    rect->name = my_strdup((char *)(rect_name[i]));
    set_rect(rect);
    return rect;
}

void rectangle_object(rectangle_t **rect)
{
    for (int i = 0; i < rect_nbr; i++) {
        rect[i] = create_rectangle(i);
    }
}
