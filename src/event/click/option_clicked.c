/*
** PROJECT, 2022
** Paint
** File description:
** option_clicked.c
*/

#include "rpg.h"
#include "my.h"
#include "drop.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdbool.h>

void find_option(sfVector2f mouse_pos, int i, drop_t **drop)
{
    sfFloatRect button_rect;

    for (int j = 0; j < option_nbr[i]; j++) {
        button_rect =
        sfRectangleShape_getGlobalBounds(drop[i]->option[j]->rect);
        if (sfFloatRect_contains(&button_rect, mouse_pos.x, mouse_pos.y)) {
            drop[i]->option[j]->clicked = !drop[i]->option[j]->clicked;
        }
    }
}

void option_clicked(drop_t **drop, sfVector2f mouse_pos, rpg_t *game)
{
    for (int i = 0; i < nbr_drop; i++) {
        if (drop[i]->clicked == true) {
            find_option(mouse_pos, i, drop);
        }
    }
    change_window_size(drop, game->window, game);
    change_window_mode(drop, game->window, game);

}
