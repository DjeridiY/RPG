/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** event.c
*/

#include "my.h"
#include "rpg.h"
#include <stdlib.h>

int game_over(rpg_t *game)
{
    if (game->entity[0]->status == 2 || game->entity[1]->stat->hp <= 0) {
        sfView_setCenter(game->view->camera, (sfVector2f) {0, 0});
        game->button[9]->visible = true;
        game->button[10]->visible = true;
        game->back[2]->visible = true;
        if (game->button[9]->clicked == true)
            return 2;
        if (game->button[10]->clicked == true)
            return 1;
    }
    if (game->button[8]->clicked == true) {
        return 1;
    }
    return 0;
}

int event_handler(rpg_t *game)
{
    sfEvent event;
    sfVideoMode mode = {1280, 720, 32};
    int recup = 0;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        close_window(event, game);
        mouse_release(game, event);
        mouse_moved(game, event);
        attack(game, event);
        open_menu(game, event);
        recup = game_over(game);
    }
    game_setting_management(game->music, game);
    return recup;
}
