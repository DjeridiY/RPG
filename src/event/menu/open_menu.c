/*
** PROJECT, 2022
** RPG
** File description:
** open_menu.c
*/

#include "rpg.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>


bool key_released(sfKeyCode key, sfEvent event)
{
    if (event.type == sfEvtKeyReleased && event.key.code == key) {
        return true;
    }
    return false;
}

void open_menu(rpg_t *game, sfEvent event)
{
    if (key_released(sfKeyEscape, event)) {
        game->back[1]->visible = !game->back[1]->visible;
        game->button[2]->visible = !game->button[2]->visible;

    }
    if (game->back[1]->visible == false)
        game->button[2]->clicked = false;
}
