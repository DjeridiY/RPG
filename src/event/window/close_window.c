/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** close_window.c
*/

#include "rpg.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

void close_window(sfEvent event, rpg_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLControl)) {
        sfRenderWindow_close(game->window);
    }
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->window);
    }
}
