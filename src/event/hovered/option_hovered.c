/*
** PROJECT, 2022
** Paint
** File description:
** option_hovered.c
*/

#include "drop.h"
#include "rpg.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

void option_hover(sfVector2f mouse_pos, int i, drop_t **drop)
{
    sfFloatRect button_rect;

    for (int j = 0; j < option_nbr[i]; j++) {
        button_rect =
        sfRectangleShape_getGlobalBounds(drop[i]->option[j]->rect);
        if (sfFloatRect_contains(&button_rect, mouse_pos.x, mouse_pos.y)) {
            drop[i]->option[j]->hovered = true;
        } else {
            drop[i]->option[j]->hovered = false;
        }
    }
}

void option_hovered(drop_t **drop, sfVector2f mouse_pos)
{
    for (int i = 0; i < nbr_drop; i++) {
        if (drop[i]->clicked == true) {
            option_hover(mouse_pos, i, drop);
        }
    }
}
