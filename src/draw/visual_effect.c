/*
** PROJECT, 2022
** RPG
** File description:
** visual_effect.c
*/

#include "back.h"
#include "rpg.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void visual_effect(rpg_t *game)
{
    highlight_drop(game->drop);
    highlight_bouton(game->button);
}
