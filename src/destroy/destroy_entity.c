/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** destroy_back.c
*/

#include "my.h"
#include "entity.h"
#include "rpg.h"
#include <stdlib.h>

void destroy_entity(entity_t **entity)
{
    for (int i = 0; i < entity_nbr; i++) {
        sfSprite_destroy(entity[i]->sprite);
        sfTexture_destroy(entity[i]->texture);
        sfSprite_destroy(entity[i]->entity_effect->sprite);
        free(entity[i]);
    }
    free(entity);
}
