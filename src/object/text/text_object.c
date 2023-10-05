/*
** PROJECT, 2022
** RPG
** File description:
** text_object.c
*/

#include "rpg.h"
#include "text.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

text_t *text_create(int i)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile("ressources/font/fanta.ttf");
    text->title = sfText_create();
    sfText_setString(text->title, text_title[i]);
    sfText_setFont(text->title, text->font);
    text->size = t_size[i];
    sfText_setCharacterSize(text->title, text->size);
    text->pos = get_vector(text_pos_x[i], text_pos_y[i]);
    text->color = get_color(t_red[i], t_green[i], t_blue[i], t_alpha[i]);
    sfText_setPosition(text->title, text->pos);
    sfText_setColor(text->title, text->color);
    text->visible = text_visible[i];
    return text;
}

void text_object(text_t **text)
{
    for (int i = 0; i < text_nbr; i++) {
        text[i] = text_create(i);
    }
}
