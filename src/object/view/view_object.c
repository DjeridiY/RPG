/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** view_object.c
*/

#include "my.h"
#include "rpg.h"
#include "back.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void view_object(view_world_t *view, rpg_t *game)
{
    sfVector2u window_size;

    view->zoom = get_vector(3.8, 3.8);
    sfSprite_setScale(game->entity[0]->sprite,
            get_vector(view->zoom.x / 1.8, view->zoom.y / 1.8));
    view->camera = sfView_create();

    window_size = sfRenderWindow_getSize(game->window);
    sfView_setSize(view->camera, get_vector(window_size.x, window_size.y));
}
