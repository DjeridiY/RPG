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

void destroy_entity_single(entity_t *entity)
{
    sfSprite_destroy(entity->sprite);
    sfTexture_destroy(entity->texture);
    sfSprite_destroy(entity->entity_effect->sprite);
    free(entity);
}

void destroy_stat_single (stat_t *stat)
{
    for (int j = 0; j < print_nbr; j++) {
        destroy_text(stat->print_stat[j]);
    }
    free(stat->print_stat);
    free(stat->name);
    free(stat);
}

void entity_object_spawn(entity_t **entity, stat_t **stat, effect_t **effect,
    item_t **item)
{
    for (int i = 1; i < stat_nbr; i++) {
        destroy_stat_single(stat[i]);
        stat[i] = create_stat(i, item);
    }
    for (int i = 1; i < entity_nbr; i++) {
        destroy_entity_single(entity[i]);
        entity[i] = create_entity(i, stat[i], effect);
    }
}

void spawn_entities_suite(rpg_t *game, sfVector2f spawn)
{
    for (int i = 0; i < 4; i++)
        if (map_entity[game->current_room][i] != -1) {
            game->entity[map_entity[game->current_room][i]]->pos = spawn;
            game->entity[map_entity[game->current_room][i]]->status = 1;
            game->entity[map_entity[game->current_room][i]]->visible = true;
        }
}

void spawn_entities(rpg_t *game)
{
    int **room;
    sfVector2f spawn;

    if (!game->rooms[game->current_room]) {
        entity_object_spawn(game->entity, game->stat, game->effect,
            game->item);

        room = get_data_at_index(game->map->structures,
            game->map->order[game->current_room]);
        spawn = vector_spawn(room, 1, nbr_of_int_tab(room, 1));
        spawn.x = spawn.x * 16 * game->view->zoom.x;
        spawn.y = spawn.y * 16 * game->view->zoom.y +
                ((100 * game->current_room) * 16 * game->view->zoom.y);
        spawn_entities_suite(game, spawn);
        game->rooms[game->current_room] = true;
    }
}
