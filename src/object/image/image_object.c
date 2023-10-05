/*
** PROJECT, 2022
** RPG
** File description:
** create_back.c
*/

#include "my.h"
#include "rpg.h"
#include "image.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

image_t *create_image(int i)
{
    image_t *image = malloc(sizeof(image_t));

    image->sprite = sfSprite_create();
    image->texture = sfTexture_createFromFile(img_sprite[i], NULL);
    image->name = my_strdup((char *)(img_name[i]));
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    image->pos = get_vector(imgpos_x[i], imgpos_y[i]);
    image->scale = get_vector(imgscale_x[i], imgscale_y[i]);
    sfSprite_setPosition(image->sprite, image->pos);
    sfSprite_setScale(image->sprite, image->scale);
    image->visible = img_visible[i];
    return image;
}

void image_object(image_t **image)
{
    for (int i = 0; i < img_nbr; i++) {
        image[i] = create_image(i);
    }
}
