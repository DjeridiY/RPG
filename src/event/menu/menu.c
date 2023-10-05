/*
** PROJECT, 2022
** RPG
** File description:
** menu.c
*/

#include "my.h"
#include "rpg.h"
#include <stdlib.h>

int menu(sfEvent event, rpg_t *game)
{
    if (game->button[0]->clicked) {
        sfRenderWindow_close(game->window);
        return 1;
    }
    if (game->button[3]->clicked) {
        sfRenderWindow_close(game->window);
    }
    return 0;
}
