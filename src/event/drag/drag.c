/*
** PROJECT, 2022
** Paint
** File description:
** drag_cursor.c
*/

#include "rpg.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drag(rpg_t *game, sfEvent event)
{
    sfVector2f mouse_pos;

    if (event.type == sfEvtMouseMoved && sfMouse_isButtonPressed(sfMouseLeft)) {
        mouse_pos = sfRenderWindow_mapPixelToCoords(game->window,
        sfMouse_getPositionRenderWindow(game->window), NULL);
        drag_cursor(game->cursor, mouse_pos);
    }
}
