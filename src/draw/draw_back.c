/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** draw_back.c
*/

#include "my.h"
#include "rpg.h"
#include "back.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void draw_back(back_t **back, sfRenderWindow *window)
{
    for (int i = 0; i < back_nbr; i++) {
        if (back[i]->visible) {
            sfRenderWindow_drawSprite(window, back[i]->sprite, NULL);
        }
    }
}
