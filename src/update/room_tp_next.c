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

sfVector2f tp_next_suite(entity_t *entity, rpg_t *game, int y, int **room)
{
    sfVector2f pos = {0, 0};

    for (int x = 0; x < 100; x++)
        if (room[y][x] == 292) {
            pos.x = (x * 16 * game->view->zoom.x);
            pos.y = (y * 16 * game->view->zoom.y) +
                (100 * (game->current_room + 1) * 16 * game->view->zoom.y);
            return pos;
        }
    return ((sfVector2f) {-1, -1});
}

sfVector2f tp_next(entity_t *entity, rpg_t *game)
{
    int **room = get_data_at_index(game->map->structures,
        game->map->order[game->current_room + 1]);
    sfVector2f retour = {0, 0};

    for (int y = 0; y < 100; y++) {
        retour = tp_next_suite(entity, game, y, room);
        if (retour.x != -1 && retour.y != -1)
            return retour;
    }
    game->current_room = game->current_room + 1;
    return tp_next(entity, game);
}

sfVector2f tp_prev_suite(entity_t *entity, rpg_t *game, int y, int **room)
{
    sfVector2f pos = {0, 0};

    for (int x = 0; x < 100; x++)
        if (room[y][x] == 291) {
            pos.x = (x * 16 * game->view->zoom.x);
            pos.y = (y * 16 * game->view->zoom.y) +
                (100 * (game->current_room - 1) * 16 * game->view->zoom.y);
            return pos;
        }
    return ((sfVector2f) {-1, -1});
}

sfVector2f tp_prev(entity_t *entity, rpg_t *game)
{
    int **room = get_data_at_index(game->map->structures,
        game->map->order[game->current_room - 1]);
    sfVector2f retour = {0, 0};

    for (int y = 0; y < 100; y++) {
        retour = tp_prev_suite(entity, game, y, room);
        if (retour.x != -1 && retour.y != -1)
            return retour;
    }
    game->current_room = game->current_room - 1;
    return tp_prev(entity, game);
}
