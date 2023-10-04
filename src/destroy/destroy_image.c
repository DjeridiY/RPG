/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** destroy_back.c
*/

#include "my.h"
#include "image.h"
#include "rpg.h"
#include <stdlib.h>

void destroy_image(image_t **image)
{
    for (int i = 0; i < img_nbr; i++) {
        sfSprite_destroy(image[i]->sprite);
        sfTexture_destroy(image[i]->texture);
        free(image[i]->name);
        free(image[i]);
    }
    free(image);
}
