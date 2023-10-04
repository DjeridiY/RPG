/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** colision
*/

#include "my.h"
#include "rpg.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <SFML/System/Clock.h>

void spawn_object(item_t **item, sfVector2f wall, rpg_t *game, int i)
{
    if (i == 30)
        return;
    i = i % item_nbr;
    if (item[i]->equiped == true || item[i]->visible == true) {
        spawn_object(item, wall, game, i + 1);
        return;
    }
    item[i]->pos = (sfVector2f) {game->entity[0]->pos.x + (8 *
        game->view->zoom.x), game->entity[0]->pos.y + (8 * game->view->zoom.y)};
    item[i]->visible = true;
    item[i]->used = false;
    item[i]->equiped = false;
    sfSprite_setPosition(item[i]->sprite, game->entity[0]->pos);
}

float colision_player_wall(rpg_t *game, float speed,
    sfVector2f wall, sfVector2f player)
{
    if (wall.x < 0 || wall.y < 0)
        return 0;
    if (game->map->map_tiles[(int) wall.y][(int) wall.x].nb_texture == 296) {
        game->map->map_tiles[(int) wall.y][(int) wall.x].nb_texture = 297;
        srand(game->clock->time_elapsed);
        spawn_object(game->item, wall, game, rand() % item_nbr);
        sfSprite_setTextureRect(game->map->map_tiles[(int) wall.y]
            [(int) wall.x].sprite_tile, game->map->textures[297]);
    }
    if (!game->map->map_tiles[(int) wall.y][(int) wall.x].colision)
        return speed;
    return 0;
}

float get_wall_pos(rpg_t *game, float speed, int movement, int i)
{
    float to_return = 0;
    entity_t *entity = game->entity[i];
    sfVector2f player = {entity->pos.x +
            (16 * (game->view->zoom.x / 1.8)), entity->pos.y +
            (16 * (game->view->zoom.y / 1.15))};
    sfVector2f wall = (sfVector2f) {(player.x / (16 * (game->view->zoom.x))),
            (player.y / (16 * (game->view->zoom.y)))};

    if (sfKeyboard_isKeyPressed(sfKeyX))
        return speed * 5;
    if (movement == 1)
        wall.y -= 0.2;
    if (movement == 2)
        wall.y += 0.2;
    if (movement == 3)
        wall.x -= 0.25;
    if (movement == 4)
        wall.x += 0.25;
    to_return = colision_player_wall(game, speed, wall, player);
    return to_return;
}
