/*
** PROJECT, 2022
** RPG
** File description:
** create.c
*/

#include "my.h"
#include "rpg.h"
#include "effect.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void effect_object(effect_t **effect)
{
    sfIntRect rect;

    for (int i = 0; i < effect_nbr; i++) {
        effect[i] = malloc(sizeof(effect_t));
        effect[i]->max_frames = effect_max_frames[i];
        rect.height = effect_size_y[i];
        rect.width = effect_size_x[i] / effect[i]->max_frames;
        rect.top = 0;
        rect.left = 0;
        effect[i]->textures = rect;
        effect[i]->effect_tileset =
                sfTexture_createFromFile(effect_sprite[i], NULL);
    }
}
