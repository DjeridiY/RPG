/*
** PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** draw_map.c
*/

#include "my.h"
#include "rpg.h"
#include "item.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

int sup(int nb)
{
    if (nb < 0)
        return 0;
    return nb;
}

void draw_tile(map_t *map, sfRenderWindow *window, int x, int y)
{
    if (map->map_tiles[y][x].render == true) {
        sfRenderWindow_drawSprite(window,
        map->map_tiles[y][x].sprite_tile, NULL);
    }
}

void draw_map(map_t *map, sfRenderWindow *window,
sfVector2f position, int radius)
{
    for (int y = sup(position.y - radius); y < position.y + radius; y++) {
        for (int x = sup(position.x - radius); x < position.x + radius; x++) {
            draw_tile(map, window, x, y);
        }
    }
}
