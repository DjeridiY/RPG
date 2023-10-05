/*
** PROJECT, 2022
** RPG
** File description:
** create_back.c
*/

#include "my.h"
#include "rpg.h"
#include "item.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

item_t *create_item(int i)
{
    item_t *item = malloc(sizeof(item_t));

    item->name = my_strdup((char *)(item_name[i]));
    item->sprite = sfSprite_create();
    item->texture = sfTexture_createFromFile(item_texture[i], NULL);
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    item->utility = my_strdup((char *)(item_utility[i]));
    item->lvl = item_lvl[i];
    item->damage = item_damage[i];
    item->speed = item_speed[i];
    item->scale = get_vector(item_scale_x[i], item_scale_y[i]);
    sfSprite_setScale(item->sprite, item->scale);
    item->equiped = equiped[i];
    item->visible = item_visbility[i];
    item->pos = get_vector(item_pos_x[i], item_pos_y[i]);
    sfSprite_setPosition(item->sprite, item->pos);
    item->used = item_used[i];
    return item;
}

void item_object(item_t **item)
{
    for (int i = 0; i < item_nbr; i++) {
        item[i] = create_item(i);
    }
}
