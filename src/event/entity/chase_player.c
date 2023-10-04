/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** chase_player.c
*/

#include "my.h"
#include "rpg.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>

int set_player_texture_y_entity(double angle)
{
    if (angle <= -112.5 && angle >= -157.5)
        return 8;
    if (angle <= -22.5 && angle >= -67.5)
        return 9;
    if (angle <= 157.5 && angle >= 112.5)
        return 6;
    if (angle <= 67.5 && angle >= 22.5)
        return 7;
    if (angle <= -67.5 && angle >= -112.5)
        return 5;
    if (angle <= 112.5 && angle >= 67.5)
        return 4;
    if (angle <= 22.5 && angle >= -22.5)
        return 3;
    if ((angle <= -157.5 && angle >= -200) || (angle <= 200 && angle >= 157.5))
        return 2;
    return 0;
}

int set_player_texture_x_entity(entity_t *entity, int y)
{
    if (y == 0) {
        entity->time_pressing = 0;
        return 0;
    }
    if ((int) (entity->time_pressing * 10) % 10 >= 3
            && (int) (entity->time_pressing * 10) % 10 <= 5)
        return 1;
    if ((int) (entity->time_pressing * 10) % 10 >= 5
            && (int) (entity->time_pressing * 10) % 10 <= 7)
        return 2;
    if ((int) (entity->time_pressing * 10) % 10 >= 7
            && (int) (entity->time_pressing * 10) % 10 <= 10)
        return 3;
    return 0;
}

void anime_entity(entity_t *player, rpg_t *game, int i, double angle)
{
    player->texture_pos.y =
            set_player_texture_y_entity(angle) + sprite_rank_y[i] * 16;
    player->texture_pos.x =
            set_player_texture_x_entity(player, player->texture_pos.y);
    sfSprite_setTextureRect(player->sprite,
            player->textures[(((int) player->texture_pos.y)
            * (player_size_x[i] / 32)) + (int) player->texture_pos.x]);
}

sfVector2f colisions_entity(sfVector2f move, entity_t *entity,
    rpg_t *game, int i)
{
    if (move.x > 0) {
        move.x = get_wall_pos(game, move.x, 4, i);
    } if (move.x < 0) {
        move.x = get_wall_pos(game, move.x, 3, i);
    } if (move.y > 0) {
        move.y = get_wall_pos(game, move.y, 2, i);
    } if (move.y < 0) {
        move.y = get_wall_pos(game, move.y, 1, i);
    }
    return move;
}

void chase_player(entity_t *entity, entity_t *player, rpg_t *game, int i)
{
    sfVector2f movement;
    sfVector2f entity_pos = sfSprite_getPosition(entity->sprite);
    sfVector2f target_pos = sfSprite_getPosition(player->sprite);
    sfVector2f direction = {target_pos.x - entity_pos.x,
            target_pos.y - entity_pos.y};
    float length =
            sqrtf(direction.x * direction.x + direction.y * direction.y);
    double velocity = (16) * (game->view->zoom.x + game->view->zoom.y)
            / 2 * entity->stat->speed;
    float speed = game->clock->secondes * (velocity / 10);

    entity->time_pressing += game->clock->secondes;
    direction.x /= length;
    direction.y /= length;
    movement = get_vector(direction.x * speed, direction.y * speed);
    movement = colisions_entity(movement, entity, game, i);
    anime_entity(entity, game, i, atan2(movement.y, movement.x) * 180 / 3.14);
    entity->pos.x += movement.x;
    entity->pos.y += movement.y;
    sfSprite_setPosition(entity->sprite, entity->pos);
}
