/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** main.c
*/

#include "my.h"
#include "rpg.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

int my_rpg(void)
{
    rpg_t *game = malloc(sizeof(rpg_t));

    create(game);
    game_print(game);
    while (sfRenderWindow_isOpen(game->window)) {
        game->exit_code = event_handler(game);
        if (game->exit_code == 2 | game->exit_code == 1)
            break;
        sfRenderWindow_clear(game->window, get_color(58, 35, 48, 255));
        update(game);
        update_camera(game);
        game_draw(game);
        entity_comp(game);
        draw(game);
        sfRenderWindow_display(game->window);
    }
    return destroy(game);
}

int my_menu(void)
{
    rpg_t *game = malloc(sizeof(rpg_t));

    create(game);
    menu_interface(game);
    while (sfRenderWindow_isOpen(game->window)) {
        game->exit_code = menu_event_handler(game);
        sfRenderWindow_clear(game->window, sfBlack);
        draw(game);
        sfRenderWindow_display(game->window);
    }
    return destroy(game);
}

int main(int ac, char **av)
{
    if (my_menu() == 1) {
        while (my_rpg() == 2);
    }
    return 0;
}
