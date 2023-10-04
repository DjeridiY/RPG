/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** adapt_item.c
*/

#include "my.h"
#include "rpg.h"
#include "item.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void adapt_item(item_t **item)
{
    for (int i = 0; i < item_nbr; i++) {
        if (item[i]->visible == true && item[i]->equiped == false
        && my_strcmp(item[i]->utility, "attack") == 0)
            sfSprite_setScale(item[i]->sprite, get_vector(0.1, 0.1));
        if (item[i]->visible == true && item[i]->equiped == true
        && my_strcmp(item[i]->utility, "attack") == 0)
            sfSprite_setScale(item[i]->sprite, get_vector(0.27, 0.27));
        if (item[i]->visible == true && item[i]->equiped == false
        && my_strcmp(item[i]->utility, "defense") == 0)
            sfSprite_setScale(item[i]->sprite, get_vector(0.2, 0.2));
        if (item[i]->visible == true && item[i]->equiped == true
        && my_strcmp(item[i]->utility, "defense") == 0)
            sfSprite_setScale(item[i]->sprite, get_vector(0.7, 0.7));
    }
}
