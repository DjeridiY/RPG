/*
** PROJECT, 2022
** RPG
** File description:
** draw_back.c
*/

#include "my.h"
#include "rpg.h"
#include "item.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void draw_item(item_t **item, sfRenderWindow *window)
{
    for (int i = 0; i < item_nbr; i++) {
        if (item[i]->visible) {
            sfRenderWindow_drawSprite(window, item[i]->sprite, NULL);
        }
    }
}
