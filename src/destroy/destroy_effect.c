/*
** PROJECT, 2022
** Paint
** File description:
** destroy_effect.c
*/

#include "my.h"
#include "rpg.h"
#include "effect.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void destroy_effect(effect_t **effect)
{
    for (int i = 0; i < effect_nbr; i++) {
        sfTexture_destroy(effect[i]->effect_tileset);
        free(effect[i]);
    }
    free(effect);
}
