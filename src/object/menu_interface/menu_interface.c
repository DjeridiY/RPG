/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** menu_interface.c
*/

#include "my.h"
#include "rpg.h"
#include "drop.h"
#include "button.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void menu_interface(rpg_t *game)
{
    for (int i = 0; i < menu_button; i++) {
        game->button[i]->visible = true;
    }
    game->music[0]->play = true;
    game->back[0]->visible = true;
    sfMusic_play(game->music[0]->music);
}
