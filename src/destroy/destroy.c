/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** destroy.c
*/

#include "my.h"
#include "rpg.h"
#include "map.h"
#include <stdlib.h>

void destroy_map(map_t *map)
{
    for (int i = 0; i < map_size[1]; i++) {
        for (int j = 0; j < map_size[0]; j++) {
            sfSprite_destroy(map->map_tiles[i][j].sprite_tile);
        }
        free(map->map_tiles[i]);
    }
    free(map->map_tiles);
    free(map->textures);
    for (int i = 0; i < map_size[1]; i++) {
        free(map->tile_placement[i]);
    }
    free(map->tile_placement);
    free(map);
}

void destroy_view(view_world_t *view)
{
    sfView_destroy(view->camera);
    free(view);
}

int destroy(rpg_t *game)
{
    int recup = game->exit_code;
    destroy_drop(game->drop);
    destroy_back(game->back);
    destroy_music(game->music);
    destroy_button(game->button);
    destroy_cursor(game->cursor);
    destroy_item(game->item);
    destroy_stat(game->stat);
    destroy_image(game->image);
    destroy_rectangle(game->rect);
    destroy_entity(game->entity);
    destroy_map(game->map);
    destroy_effect(game->effect);
    destroy_sound(game->sound);
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock->clock);
    free(game->clock);
    destroy_view(game->view);
    free(game);
    return recup;
}
