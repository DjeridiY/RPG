/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** button_hovered.c
*/

#include "rpg.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

void mouse_moved(rpg_t *game, sfEvent event)
{
    sfVector2f mouse_pos;

    if (sfEvtMouseMoved == event.type) {
        mouse_pos = sfRenderWindow_mapPixelToCoords(game->window,
        sfMouse_getPositionRenderWindow(game->window), NULL);
        option_hovered(game->drop, mouse_pos);
        button_hovered(game->button, mouse_pos);
    }
}
