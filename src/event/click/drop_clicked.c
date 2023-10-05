/*
** PROJECT, 2022
** Paint
** File description:
** dropdown_clicked.c
*/

#include "rpg.h"
#include "my.h"
#include "drop.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

void drop_clicked(drop_t **drop, sfVector2f mouse_pos)
{
    sfFloatRect button_rect;

    for (int i = 0; i < nbr_drop; i++) {
        button_rect = sfRectangleShape_getGlobalBounds(drop[i]->rect);
        if (sfFloatRect_contains(&button_rect, mouse_pos.x, mouse_pos.y)) {
            drop[i]->clicked = !drop[i]->clicked;
        } else {
            drop[i]->clicked = false;
        }
    }
}
