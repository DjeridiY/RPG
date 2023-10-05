/*
** PROJECT, 2022
** RPG
** File description:
** destroy_back.c
*/

#include "my.h"
#include "back.h"
#include "rpg.h"
#include <stdlib.h>

void destroy_back(back_t **back)
{
    for (int i = 0; i < back_nbr; i++) {
        sfSprite_destroy(back[i]->sprite);
        sfTexture_destroy(back[i]->texture);
        free(back[i]->name);
        free(back[i]);
    }
    free(back);
}
