/*
** EPITECH PROJECT, 2022
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

void change_room_next(entity_t *entity, rpg_t *game, int nb_texture)
{
    if (entity->teleported)
        if (nb_texture != 290 && nb_texture != 291)
            entity->teleported = false;
    if (!entity->teleported)
        if (nb_texture == 290) {
            entity->pos = tp_next(entity, game);
            game->rooms[game->current_room] = true;
            game->current_room = game->current_room + 1;
            sfSprite_setPosition(entity->sprite, entity->pos);
            entity->teleported = true;
            spawn_entities(game);
            sfClock_restart(game->clock->clock);
        }
    if (!entity->teleported)
        if (nb_texture == 291) {
            entity->pos = tp_prev(entity, game);
            game->current_room = game->current_room - 1;
            sfSprite_setPosition(entity->sprite, entity->pos);
            entity->teleported = true;
        }
}

void change_room(entity_t *entity, rpg_t *game)
{
    sfVector2f player = {entity->pos.x +
            (16 * (game->view->zoom.x / 1.8)), entity->pos.y +
            (16 * (game->view->zoom.y / 1.15))};
    sfVector2f wall = (sfVector2f) {(player.x / (16 * (game->view->zoom.x))),
            (player.y / (16 * (game->view->zoom.y)))};
    int nb_texture =
        game->map->map_tiles[(int) wall.y][(int) wall.x].nb_texture;

    change_room_next(entity, game, nb_texture);
}
