/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** draw_game.c
*/

#include "my.h"
#include "rpg.h"
#include "entity.h"
#include "item.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void hide_item(rpg_t *game)
{
    for (int i = 0; i < item_nbr; i++) {
        if (game->item[i]->equiped == false) {
            game->item[i]->visible = false;
        }
    }
}

void game_draw(rpg_t *game)
{
    if (game->button[2]->visible == false)
        draw_map(game->map, game->window, get_vector(
        game->entity[0]->pos.x / (16 * game->view->zoom.x),
        game->entity[0]->pos.y / (16 * game->view->zoom.y)), 25);
    for (int i = 0; i < entity_nbr; i++) {
        game->entity[i]->visible = true;
    }
    if (game->button[2]->visible) {
        for (int i = 0; i < entity_nbr; i++) {
            game->entity[i]->visible = false;
        }
    }
    if (game->button[2]->visible) {
        hide_item(game);
    }
}
