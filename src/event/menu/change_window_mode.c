/*
** PROJECT, 2022
** RPG
** File description:
** change_window_size.c
*/

#include "my.h"
#include "rpg.h"
#include "drop.h"
#include "back.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void adapt_to_desktop(rpg_t *game)
{
    sfVideoMode desktop_mode = sfVideoMode_getDesktopMode();
    sfVector2u window_size = {desktop_mode.width, desktop_mode.height};
    sfVector2f back_size;
    sfVector2f scaled_size;
    float scale_x = 0.0;
    float scale_y = 0.0;
    float scale = 0.0;

    for (int i = 0; i < back_nbr; i++) {
        back_size = get_vector(sfTexture_getSize(game->back[i]->texture).x,
        sfTexture_getSize(game->back[i]->texture).y);
        scale_x = window_size.x / back_size.x;
        scale_y = window_size.y / back_size.y;
        scale = scale_x > scale_y ? scale_x : scale_y;
        scaled_size = get_vector(window_size.x / scale, window_size.y / scale);
        sfSprite_setScale(game->back[i]->sprite, get_vector(scale, scale));
        sfSprite_setPosition(game->back[i]->sprite,
        get_vector((window_size.x - scaled_size.x) / 2,
        (window_size.y - scaled_size.y) / 2));
    }
}

void adapt_to_window(rpg_t *game)
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

void is_fullscreen(drop_t **drop, rpg_t *game, int i)
{
    sfVideoMode mode = {1280, 720, 32};

    if (my_strcmp(drop[1]->option[i]->name, "FULLSCREEN MODE") == 0) {
        if (game->fullscreen == false) {
            sfRenderWindow_close(game->window);
            game->window =
            sfRenderWindow_create(sfVideoMode_getDesktopMode(), "my_rpg",
            sfFullscreen, NULL);
            game->fullscreen = true;
            adapt_to_desktop(game);
        }
    } else {
        sfRenderWindow_close(game->window);
        game->window = sfRenderWindow_create(mode,
        "my_rpg", sfResize | sfClose, NULL);
        game->fullscreen = false;
        adapt_to_window(game);
    }
}

void change_window(drop_t **drop, sfRenderWindow *window, int i, rpg_t *game)
{
    if (drop[1]->option[i]->clicked) {
        is_fullscreen(drop, game, i);
    }
}

void change_window_mode(drop_t **drop, sfRenderWindow *window, rpg_t *game)
{
    if (drop[1]->clicked) {
        for (int i = 0; i < option_nbr[1]; i++) {
            change_window(drop, window, i, game);
        }
    }
}
