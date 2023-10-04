/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** button_clicked.c
*/

#include "rpg.h"
#include "my.h"
#include "item.h"
#include "stat.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>
#include <stdlib.h>

void item_click(item_t **item, sfVector2f mouse_pos,
entity_t *player, rpg_t *game)
{
    sfFloatRect item_rect;

    for (int i = 0; i < item_nbr; i++) {
        if (item[i]->visible == false) {
            continue;
        }
        item_rect = sfSprite_getGlobalBounds(item[i]->sprite);
        if (sfFloatRect_contains(&item_rect, mouse_pos.x, mouse_pos.y)) {
            defensive_item(item[i], player, item[0], game);
            attack_item(item[i], player, item[0]);
            break;
        }
    }
}
