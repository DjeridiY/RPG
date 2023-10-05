/*
** PROJECT, 2022
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

void effect_player_next(entity_t *entity, rpg_t *game, sfVector2f middle_point)
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

int key_pressed(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        return 1;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        return 2;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        return 3;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        return 4;
    return 0;
}

sfVector2f direction_sword(sfVector2f middle_point, entity_t *entity)
{
    if (key_pressed() == 1) {
            sfSprite_setRotation(entity->entity_effect->sprite, -90);
            middle_point.y += 110;
    }
    if (key_pressed() == 2) {
        sfSprite_setRotation(entity->entity_effect->sprite, 90);
        middle_point.x += 110;
    }
    if (key_pressed() == 3) {
            sfSprite_setRotation(entity->entity_effect->sprite, 180);
            middle_point.x += 100;
            middle_point.y += 120;
    }
    if (key_pressed() == 4)
        sfSprite_setRotation(entity->entity_effect->sprite, 0);
    if (key_pressed() == 0) {
        sfSprite_setRotation(entity->entity_effect->sprite, 180);
        middle_point.x += 100;
        middle_point.y += 120;
    } return middle_point;
}

void effect_player(entity_t *entity, rpg_t *game)
{
    sfVector2f middle_point;

    middle_point.x = entity->pos.x -
    ((entity->entity_effect->textures.width / 2)
    * entity->entity_effect->scale.x)
    + ((16 / 2) * game->map->scale.x);
    middle_point.y = entity->pos.y -
    ((entity->entity_effect->textures.height / 2)
    * entity->entity_effect->scale.y) +
    ((16 / 2) * game->map->scale.y);
    middle_point = direction_sword(middle_point, entity);
    middle_point.x += 30;
    if (sfKeyboard_isKeyPressed(sfKeySpace) && !entity->entity_effect->show) {
        sfMusic_play(game->sound[0]->sound);
        sfMusic_setPlayingOffset(game->sound[0]->sound, sfTime_Zero);
        entity->entity_effect->show = true;
        entity->entity_effect->time_effect = 0;
        sfSprite_setPosition(entity->entity_effect->sprite, middle_point);
    }
    effect_player_next(entity, game, middle_point);
}
