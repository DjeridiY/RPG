/*
** PROJECT, 2022
** RPG
** File description:
** move_player.c
*/

#include "my.h"
#include "rpg.h"
#include "map.h"
#include "stat.h"
#include "print_stat.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <math.h>

sfVector2f change_pos(sfVector2f move)
{
    if (move.x != 0 && move.y != 0) {
        if (move.x < 0)
            move.x /= 1.45;
        if (move.x > 0)
            move.x /= 1.45;
        if (move.y < 0)
            move.y /= 1.45;
        if (move.y > 0)
            move.y /= 1.45;
    }
    return move;
}

void move_player(entity_t *player, rpg_t *game)
{
    float speed = game->clock->secondes;
    double velocity = (16) * (game->view->zoom.x + game->view->zoom.y)
    / 2 * player->stat->speed;
    sfVector2f move = {0, 0};

    player->time_pressing += game->clock->secondes;
    speed = game->clock->secondes * velocity / 25;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move.y -= get_wall_pos(game, speed, 1, 0) * 25;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move.y += get_wall_pos(game, speed, 2, 0) * 25;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move.x -= get_wall_pos(game, speed, 3, 0) * 25;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move.x += get_wall_pos(game, speed, 4, 0) * 25;
    move = change_pos(move);
    player->pos.x += move.x;
    player->pos.y += move.y;
    sfSprite_setPosition(player->sprite, player->pos);
    sfClock_restart(game->clock->clock);
}

bool enemy_in_room(rpg_t *game)
{
    for (int i = 1; i < entity_nbr; i++) {
        if (detection_range(game->entity[0]->sprite, game->entity[i]->sprite,
                3000) && game->entity[i]->status != 2) {
            return true;
        }
    }
    return false;
}

void move_entity(rpg_t *game)
{
    if (game->entity[0]->visible && game->entity[0]->status != 2) {
        move_player(game->entity[0], game);
        anime_sprite(game->entity[0], game, 0);
        effect_player(game->entity[0], game);
        if (!enemy_in_room(game))
            change_room(game->entity[0], game);
    }
}
