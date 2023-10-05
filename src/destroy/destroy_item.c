/*
** PROJECT, 2022
** RPG
** File description:
** destroy_back.c
*/

#include "my.h"
#include "item.h"
#include "rpg.h"
#include <stdlib.h>

void destroy_item(item_t **item)
{
    for (int i = 0; i < item_nbr; i++) {
        sfSprite_destroy(item[i]->sprite);
        sfTexture_destroy(item[i]->texture);
        free(item[i]->name);
        free(item[i]->utility);
        free(item[i]);
    }
    free(item);
}
