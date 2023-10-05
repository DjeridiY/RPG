/*
** PROJECT, 2022
** RPG
** File description:
** text_object.c
*/

#include "rpg.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

text_t *create_text(bool visibilty, int size,
sfVector2f position, sfColor color)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile("ressources/font/fanta.ttf");
    text->title = sfText_create();
    sfText_setString(text->title, "9");
    sfText_setFont(text->title, text->font);
    sfText_setCharacterSize(text->title, size);
    text->pos = position;
    text->color = color;
    sfText_setPosition(text->title, text->pos);
    sfText_setColor(text->title, text->color);
    text->visible = visibilty;
    return text;
}
