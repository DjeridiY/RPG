/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** move_player.c
*/

#include "my.h"
#include "rpg.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <math.h>

int set_player_texture_y(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyQ))
        return 8;
    if (sfKeyboard_isKeyPressed(sfKeyZ) &&
            sfKeyboard_isKeyPressed(sfKeyD))
        return 9;
    if (sfKeyboard_isKeyPressed(sfKeyS) &&
            sfKeyboard_isKeyPressed(sfKeyQ))
        return 6;
    if (sfKeyboard_isKeyPressed(sfKeyS) &&
            sfKeyboard_isKeyPressed(sfKeyD))
        return 7;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        return 5;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        return 4;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        return 2;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        return 3;
    return 0;
}

int set_player_texture_x(entity_t *player, int y)
{
    if (y == 0) {
        player->time_pressing = 0;
        return 0;
    }
    if ((int) (player->time_pressing * 10) % 10 >= 3
            && (int) (player->time_pressing * 10) % 10 <= 5)
        return 1;
    if ((int) (player->time_pressing * 10) % 10 >= 5
            && (int) (player->time_pressing * 10) % 10 <= 7)
        return 2;
    if ((int) (player->time_pressing * 10) % 10 >= 7
            && (int) (player->time_pressing * 10) % 10 <= 10)
        return 3;
    return 0;
}

void anime_sprite(entity_t *player, rpg_t *game, int i)
{
    player->texture_pos.y = set_player_texture_y() + sprite_rank_y[i] * 16;
    player->texture_pos.x = set_player_texture_x(player,
            player->texture_pos.y) + sprite_rank_x[i];
    sfSprite_setTextureRect(player->sprite,
            player->textures[(((int) player->texture_pos.y)
            * (player_size_x[i] / 32)) + (int) player->texture_pos.x]);
}
