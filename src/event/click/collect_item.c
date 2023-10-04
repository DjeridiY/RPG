/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** collect_item.c
*/

#include "rpg.h"
#include "my.h"
#include "item.h"
#include "stat.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>
#include <stdlib.h>

void collect_item(entity_t *player, item_t *item)
{
    sfFloatRect bounds1 = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect bounds2 = sfSprite_getGlobalBounds(item->sprite);
    sfVector2f position_in = player->stat->utility->pos;
    sfVector2f position_out = item->pos;

    if (sfFloatRect_intersects(&bounds1, &bounds2, NULL)) {
        player->stat->utility->equiped = false;
        player->stat->utility->visible = true;
        player->stat->utility->pos = position_out;
        item->pos = position_in;
        sfSprite_setPosition(player->stat->utility->sprite,
        player->stat->utility->pos);
        sfSprite_setPosition(item->sprite, item->pos);
        player->stat->utility = item;
        player->stat->utility->equiped = true;
        item->visible = false;
    }
}
