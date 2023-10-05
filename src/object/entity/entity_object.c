/*
** PROJECT, 2022
** RPG
** File description:
** create_back.c
*/

#include "my.h"
#include "rpg.h"
#include "entity.h"
#include "effect.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void make_player_textures(sfIntRect **textures, int i)
{
    sfIntRect *texture;
    sfIntRect selection;

    *textures = malloc(sizeof(sfIntRect) *
            (player_size_y[i] / 32) * (player_size_x[i] / 32) + 1);
    selection.height = 32;
    selection.width = 32;
    for (int y = 0; y < player_size_y[i] / 32; y++)
        for (int x = 0; x < player_size_x[i] / 32; x++) {
            selection.top = y * selection.height;
            selection.left = x * selection.width;
            (*textures)[(y * (player_size_x[i] / 32)) + x] = selection;
        }
}

entity_effect_t *create_effect_entity(entity_effect_t *entity_effect, int i,
    sfVector2f pos, effect_t **effect)
{
    entity_effect = malloc(sizeof(entity_effect_t));
    entity_effect->pos = pos;
    entity_effect->sprite = sfSprite_create();
    sfSprite_setPosition(entity_effect->sprite, entity_effect->pos);
    sfSprite_setTexture(entity_effect->sprite,
        effect[entity_effect_use[i]]->effect_tileset, sfFalse);
    sfSprite_setTextureRect(entity_effect->sprite,
        effect[entity_effect_use[i]]->textures);
    entity_effect->scale = (sfVector2f) {effect_scale_x[i], effect_scale_y[i]};
    sfSprite_setScale(entity_effect->sprite, entity_effect->scale);
    entity_effect->fps = effect_fps[entity_effect_use[i]];
    entity_effect->max_frames = effect[entity_effect_use[i]]->max_frames;
    entity_effect->time_effect = 0;
    entity_effect->show = false;
    entity_effect->textures = effect[entity_effect_use[i]]->textures;
    return entity_effect;
}

entity_t *create_entity(int i, stat_t *stat, effect_t **effect)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->stat = stat;
    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromFile(entity_sprite[i], NULL);
    make_player_textures(&entity->textures, i);
    sfSprite_setTextureRect(entity->sprite, entity->textures[sprite_rank_x[i]]);
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    entity->pos = get_vector(entity_x[i], entity_y[i]);
    entity->scale = get_vector(entity_scale_x[i], entity_scale_y[i]);
    sfSprite_setPosition(entity->sprite, entity->pos);
    sfSprite_setScale(entity->sprite, entity->scale);
    sfSprite_setTextureRect(entity[0].sprite,
        entity->textures[(sprite_rank_y[i] * (16 * 16)) + sprite_rank_x[i]]);
    entity->visible = entity_visible[i];
    entity->status = status[i];
    entity->entity_effect =
        create_effect_entity(entity->entity_effect, i, entity->pos, effect);
    entity->teleported = false;
    return entity;
}

void entity_object(entity_t **entity, stat_t **stat, effect_t **effect)
{
    for (int i = 0; i < entity_nbr; i++) {
        entity[i] = create_entity(i, stat[i], effect);
    }
}
