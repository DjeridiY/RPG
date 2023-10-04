/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** button_pressed.c
*/

#include "rpg.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdbool.h>

void mouse_release(rpg_t *game, sfEvent event)
{
    sfVector2f mouse_pos;

    if (event.type == sfEvtMouseButtonReleased) {
        sfMusic_play(game->sound[2]->sound);
        sfMusic_setPlayingOffset(game->sound[2]->sound, sfTime_Zero);
        mouse_pos = sfRenderWindow_mapPixelToCoords(game->window,
        sfMouse_getPositionRenderWindow(game->window), NULL);
        option_clicked(game->drop, mouse_pos, game);
        button_clicked(game->button, mouse_pos);
        drop_clicked(game->drop, mouse_pos);
        item_click(game->item, mouse_pos, game->entity[0], game);
    }
}
