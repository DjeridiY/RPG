/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** update_camera.c
*/

#include "my.h"
#include "rpg.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void update_camera(rpg_t *game)
{
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    sfVector2f player_center = get_vector(
            game->entity[0]->pos.x + (8 * game->view->zoom.x),
            game->entity[0]->pos.y + (8 * game->view->zoom.y));

    if (game->back[1]->visible || game->back[2]->visible) {
        sfView_setCenter(game->view->camera,
                (sfVector2f) {1280 / 2, 720 / 2});
        sfRenderWindow_setView(game->window, game->view->camera);
        return;
    }
    sfView_setCenter(game->view->camera, player_center);
    sfRenderWindow_setView(game->window, game->view->camera);
}
