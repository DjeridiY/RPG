/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** update_effect_player.c
*/

#include "my.h"
#include "rpg.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <math.h>

void effect_entity_next(entity_t *entity, rpg_t *game, sfVector2f middle_point)
{
    if (entity->entity_effect->show) {
        entity->entity_effect->textures.left = ((int)
    (entity->entity_effect->time_effect * entity->entity_effect->fps)) *
    (entity->entity_effect->textures.width);
        sfSprite_setTextureRect(entity->entity_effect->sprite,
    entity->entity_effect->textures);
        sfSprite_setPosition(entity->entity_effect->sprite, middle_point);
        entity->entity_effect->time_effect +=
    game->clock->time.microseconds / 1000000.0;
    }
    if (entity->entity_effect->time_effect >=
            (entity->entity_effect->max_frames / entity->entity_effect->fps))
        entity->entity_effect->show = false;
}

void effect_entity(entity_t *entity, rpg_t *game)
{
    sfVector2f middle_point;

    middle_point.x = entity->pos.x - ((entity->entity_effect->textures.width
/ 2) * entity->entity_effect->scale.x) + ((16 / 2) * game->map->scale.x);
    middle_point.y = entity->pos.y - ((entity->entity_effect->textures.height
/ 2) * entity->entity_effect->scale.y) + ((16 / 2) * game->map->scale.y);
    if (sfKeyboard_isKeyPressed(sfKeyE) && !entity->entity_effect->show) {
        entity->entity_effect->show = true;
        entity->entity_effect->time_effect = 0;
        sfSprite_setPosition(entity->entity_effect->sprite, middle_point);
    }
    effect_entity_next(entity, game, middle_point);
}
