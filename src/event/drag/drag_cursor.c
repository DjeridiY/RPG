/*
** PROJECT, 2022
** Paint
** File description:
** drag_cursor.c
*/

#include "rpg.h"
#include "cursor.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdbool.h>

float verif_border(float new_cursor_x, sfVector2f start, sfVector2f end)
{
    if (new_cursor_x < start.x) {
        new_cursor_x = start.x;
    }
    if (new_cursor_x > end.x) {
        new_cursor_x = end.x;
    }
    return new_cursor_x;
}

void drag_cursor(cursor_t **cursor, sfVector2f mouse_pos)
{
    sfFloatRect button_rect;
    float new_cursor_x = mouse_pos.x;

    for (int i = 0; i < nbr_of_cursor; i++) {
        if (cursor[i]->visible == false) {
            continue;
        }
        button_rect = sfRectangleShape_getGlobalBounds(cursor[i]->box);
        if (sfFloatRect_contains(&button_rect, mouse_pos.x, mouse_pos.y)) {
            new_cursor_x =
            verif_border(new_cursor_x, cursor[i]->start, cursor[i]->end);
            sfRectangleShape_setPosition(cursor[i]->box,
            get_vector(new_cursor_x, cursor[i]->end.y));
            cursor[i]->value = (new_cursor_x - cursor[i]->start.x) /
            (cursor[i]->end.x - cursor[i]->start.x);
        }
    }
}
