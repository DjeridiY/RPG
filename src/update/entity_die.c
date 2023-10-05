/*
** PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** player_die.c
*/

#include "my.h"
#include "rpg.h"
#include "item.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void entity_die(entity_t **entity)
{
    for (int i = 0; i < entity_nbr; i++) {
        if (entity[i]->stat->hp <= 0) {
            entity[i]->status = 2;
        }
    }
}
