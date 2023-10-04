/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** defensive_item.c
*/

#include "rpg.h"
#include "my.h"
#include "item.h"
#include "stat.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>
#include <stdlib.h>

void collect_attack_item(entity_t *player, item_t *item)
{
    sfFloatRect bounds1 = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect bounds2 = sfSprite_getGlobalBounds(item->sprite);
    sfVector2f position_in = player->stat->weapon->pos;
    sfVector2f position_out = item->pos;

    if (sfFloatRect_intersects(&bounds1, &bounds2, NULL)) {
        player->stat->weapon->equiped = false;
        player->stat->weapon->visible = true;
        player->stat->weapon->pos = position_out;
        item->pos = position_in;
        sfSprite_setPosition(player->stat->weapon->sprite,
        player->stat->weapon->pos);
        sfSprite_setPosition(item->sprite, item->pos);
        player->stat->weapon = item;
        player->stat->weapon->equiped = true;
        item->visible = true;
    }
}

void attack_item(item_t *item, entity_t *player, item_t *nothing)
{
    if (my_strcmp(item->utility, "attack") != 0) {
        return;
    }
    if (item->equiped == false) {
        collect_attack_item(player, item);
    }
}
