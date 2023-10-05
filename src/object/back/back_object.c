/*
** PROJECT, 2022
** RPG
** File description:
** create_back.c
*/

#include "my.h"
#include "rpg.h"
#include "back.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

back_t *create_back(int i)
{
    back_t *back = malloc(sizeof(back_t));

    back->sprite = sfSprite_create();
    back->texture = sfTexture_createFromFile(back_sprite[i], NULL);
    back->name = my_strdup((char *)(back_name[i]));
    sfSprite_setTexture(back->sprite, back->texture, sfTrue);
    back->pos = get_vector(bacpos_x[i], bacpos_y[i]);
    back->scale = get_vector(bacscale_x[i], bacscale_y[i]);
    sfSprite_setPosition(back->sprite, back->pos);
    sfSprite_setScale(back->sprite, back->scale);
    back->visible = visible[i];
    return back;
}

void back_object(back_t **back)
{
    for (int i = 0; i < back_nbr; i++) {
        back[i] = create_back(i);
    }
}
