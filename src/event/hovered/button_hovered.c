/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** button_hovered.c
*/

#include "rpg.h"
#include "button.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

void button_hovered(button_t **button, sfVector2f mouse_pos)
{
    sfFloatRect button_rect;

    for (int i = 0; i < nbr_button; i++) {
        if (button[i]->visible == false) {
            continue;
        }
        button_rect = sfRectangleShape_getGlobalBounds(button[i]->rect);
        if (sfFloatRect_contains(&button_rect, mouse_pos.x, mouse_pos.y)) {
            button[i]->hovered = true;
        } else {
            button[i]->hovered = false;
        }
    }
}
