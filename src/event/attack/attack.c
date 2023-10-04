/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** button_pressed.c
*/

#include "rpg.h"
#include "my.h"
#include "entity.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void that_it(entity_t **entity, sfFloatRect player, int i)
{
    sfFloatRect entity_sprite;

    entity_sprite = sfSprite_getGlobalBounds(entity[i]->sprite);
    if (sfFloatRect_intersects(&player, &entity_sprite, NULL)) {
        entity[i]->stat->hp -= roundf(entity[0]->stat->strength *
        0.5 / (entity[i]->stat->defense * 0.6));
        sfSprite_setPosition(entity[i]->sprite, entity[i]->pos);
        if (entity[i]->stat->hp <= 0) {
            entity[0]->stat->xp += entity[i]->stat->lvl;
        }
    }
}

void attack_entity(entity_t **entity)
{
    sfFloatRect player =
    sfSprite_getGlobalBounds(entity[0]->entity_effect->sprite);
    sfFloatRect entity_sprite;

    for (int i = 1; i < entity_nbr; i++) {
        if (entity[i]->status != 2) {
            that_it(entity, player, i);
        }
    }
}

void attack(rpg_t *game, sfEvent event)
{
    sfVector2f mouse_pos;

    if (sfKeyboard_isKeyPressed(sfKeySpace))
        attack_entity(game->entity);
}
