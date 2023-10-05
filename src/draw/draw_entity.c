/*
** PROJECT, 2022
** RPG
** File description:
** draw_back.c
*/

#include "my.h"
#include "rpg.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void draw_entity(entity_t **entity, sfRenderWindow *window)
{
    for (int i = 0; i < entity_nbr; i++)
    {
        if (entity[i]->entity_effect->show && (entity[i]->visible && entity[i]->status != 2))
        {
            sfRenderWindow_drawSprite(window,
                                      entity[i]->entity_effect->sprite, NULL);
        }
    }
    for (int i = 0; i < entity_nbr; i++)
    {
        if (entity[i]->visible && entity[i]->status != 2)
        {
            sfRenderWindow_drawSprite(window, entity[i]->sprite, NULL);
        }
    }
}
