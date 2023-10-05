/*
** PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** entty_comp.c
*/

#include "my.h"
#include "rpg.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void entity_comp(rpg_t *game)
{
    for (int i = 1; i < entity_nbr; i++) {
        if (game->entity[i]->status == 0 &&
                detection_range(game->entity[0]->sprite,
                game->entity[i]->sprite, 3000)) {
            game->entity[i]->status = 1;
        }
        if (game->entity[i]->status == 1 && game->entity[0]->status != 2
                && game->button[2]->visible == false)
            chase_player(game->entity[i], game->entity[0], game, i);
        if (game->entity[i]->status != 2)
            effect_entity(game->entity[i], game);
    }
}
