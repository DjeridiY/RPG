/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** update_setting.c
*/

#include "my.h"
#include "rpg.h"
#include "update_setting.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void update_setting(rpg_t *game)
{
    update_cursor(game->cursor[0]);
    update_button(game->button[4], 0);
    update_button(game->button[2], 1);
    update_dropdown(game->drop);
}
