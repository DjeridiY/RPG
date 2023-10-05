/*
** PROJECT, 2022
** Paint
** File description:
** button_clicked.c
*/

#include "rpg.h"
#include "my.h"
#include "button.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>
#include <stdlib.h>


void button_clicked(button_t **button, sfVector2f mouse_pos)
{
    sfFloatRect button_rect;

    for (int i = 0; i < nbr_button; i++) {
        if (button[i]->visible == false) {
            continue;
        }
        button_rect = sfRectangleShape_getGlobalBounds(button[i]->rect);
        if (sfFloatRect_contains(&button_rect, mouse_pos.x, mouse_pos.y)) {
            button[i]->clicked = !button[i]->clicked;
        }
    }
}
