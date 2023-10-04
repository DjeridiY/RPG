/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** event.c
*/

#include "my.h"
#include "rpg.h"
#include <stdlib.h>

int menu_event_handler(rpg_t *game)
{
    sfEvent event;
    sfVideoMode mode = {1280, 720, 32};
    int recup = 0;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        close_window(event, game);
        mouse_release(game, event);
        mouse_moved(game, event);
        drag(game, event);
        recup = menu(event, game);
    }
    menu_setting(game->music, game);
    return recup;
}
