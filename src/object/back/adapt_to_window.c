/*
** PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** adapt_to_window.c
*/

#include "my.h"
#include "rpg.h"
#include "back.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void adapt_back_to_screen(rpg_t *game)
{
    sfVector2f window_size;
    sfVector2f back_size;
    sfVector2f scale;

    for (int i = 0; i < back_nbr; i++) {
        window_size = get_vector(sfRenderWindow_getSize(game->window).x,
        sfRenderWindow_getSize(game->window).y);
        back_size = get_vector(sfTexture_getSize(game->back[i]->texture).x,
        sfTexture_getSize(game->back[i]->texture).y);
        scale = get_vector(window_size.x / back_size.x,
        window_size.y / back_size.y);
        sfSprite_setScale(game->back[i]->sprite, scale);
    }
}
