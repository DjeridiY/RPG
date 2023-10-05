/*
** PROJECT, 2022
** RPG
** File description:
** update colide.c
*/

#include "my.h"
#include "rpg.h"
#include "item.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <math.h>

float distance_between_points(sfVector2f point1, sfVector2f point2)
{
    float dx = point2.x - point1.x;
    float dy = point2.y - point1.y;

    return sqrtf(dx * dx + dy * dy);
}

float get_wall_pos_modified(rpg_t *game, float speed, sfVector2f pos)
{
    float to_return = 0;
    sfVector2f player = { pos.x + (16 * (game->view->zoom.x / 1.8)),
        pos.y + (16 * (game->view->zoom.y / 1.15)) };
    sfVector2f wall = (sfVector2f) { (player.x / (16 * (game->view->zoom.x))),
        (player.y / (16 * (game->view->zoom.y))) };

    to_return = colision_player_wall(game, speed, wall, player);
    return to_return;
}

bool is_wall_collision(rpg_t *game, sfVector2f pos)
{
    float speed = 1.0;
    float adjusted_speed = get_wall_pos_modified(game, speed, pos);

    return adjusted_speed == 0;
}

bool collide(entity_t *entity1, entity_t *entity2, rpg_t *game)
{
    if (distance_between_points(entity1->pos, entity2->pos) > 50)
        return false;

    sfVector2f direction = {entity2->pos.x - entity1->pos.x,
        entity2->pos.y - entity1->pos.y};
    float magnitude = sqrtf(direction.x * direction.x +
        direction.y * direction.y);
    sfVector2f normalized_direction = {direction.x / magnitude,
        direction.y / magnitude};
    sfVector2f new_pos1 = {entity1->pos.x - normalized_direction.x * 20,
        entity1->pos.y - normalized_direction.y * 20};
    sfVector2f new_pos2 = {entity2->pos.x + normalized_direction.x * 20,
        entity2->pos.y + normalized_direction.y * 20};

    if (!is_wall_collision(game, new_pos1))
        entity1->pos = new_pos1;
    if (!is_wall_collision(game, new_pos2))
        entity2->pos = new_pos2;
    return true;
}
