/*
** PROJECT, 2022
** RPG
** File description:
** game_print.c
*/

#include "my.h"
#include "rpg.h"
#include <SFML/Audio.h>
#include "stat.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void game_print(rpg_t *game)
{
    game->music[1]->play = true;
    sfMusic_play(game->music[1]->music);
    update_setting(game);
}
