/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** draw_back.c
*/

#include "my.h"
#include "rpg.h"
#include "image.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void draw_image(image_t **image, sfRenderWindow *window)
{
    for (int i = 0; i < img_nbr; i++) {
        if (image[i]->visible) {
            sfRenderWindow_drawSprite(window, image[i]->sprite, NULL);
        }
    }
}
