/*
** PROJECT, 2022
** RPG
** File description:
** game_print.c
*/

#include "my.h"
#include "rpg.h"
#include "item.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>

static void player_hitbox(entity_t *player, rpg_t *game)
{
    for (int i = 1; i < entity_nbr; i++) {
        if (game->entity[i]->status == 2)
            continue;
        if (collide(player, game->entity[i], game) &&
        !game->entity[i]->entity_effect->show) {
            sfMusic_play(game->sound[1]->sound);
            sfMusic_setPlayingOffset(game->sound[1]->sound, sfTime_Zero);
            player->stat->hp -= roundf(game->entity[i]->stat->strength
            * 0.4 / (game->entity[0]->stat->defense * 0.4));
            game->entity[i]->entity_effect->time_effect = 0;
            game->entity[i]->entity_effect->show = true;
        }
        if (collide(player, game->entity[i], game))
            sfSprite_setPosition(player->sprite, player->pos);
    }
}

static void enemie_hitbox(entity_t *enemie, entity_t *slash, rpg_t *game)
{
    if (collide(enemie, slash, game)) {
        sfSprite_setPosition(enemie->sprite, enemie->pos);
    }
}

void entity_hitbox(rpg_t *game)
{
    player_hitbox(game->entity[0], game);
    for (int i = 1; i < entity_nbr; i++) {
        if (game->entity[i]->status != 2) {
            enemie_hitbox(game->entity[i], game->entity[0], game);
        }
    }
}
