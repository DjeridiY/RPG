/*
** PROJECT, 2022
** Paint
** File description:
** set_droptext.c
*/

#include "my.h"
#include "rpg.h"
#include "drop.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void set_droptext_position(drop_t *drop, text_t *text)
{
    sfFloatRect text_rect = sfText_getLocalBounds(text->title);
    sfVector2f rectangle_pos = sfRectangleShape_getPosition(drop->rect);
    sfVector2f rectangle_size = sfRectangleShape_getSize(drop->rect);
    int x = rectangle_pos.x + rectangle_size.x / 2 - text_rect.width / 2;
    int y = rectangle_pos.y + rectangle_size.y / 2 - text_rect.height / 2;
    sfVector2f text_pos = get_vector(x, y - 4);

    sfText_setPosition(text->title, text_pos);
}

void set_droptext(drop_t *drop, int i)
{
    drop->text = malloc(sizeof(text_t));
    drop->text->title = sfText_create();
    drop->text->font = sfFont_createFromFile("ressources/font/fanta.ttf");
    sfText_setString(drop->text->title, drop->name);
    sfText_setFont(drop->text->title, drop->text->font);
    drop->text->color = get_color(char_red[i], char_green[i],
    char_blue[i], char_alpha[i]);
    sfText_setCharacterSize(drop->text->title, drop_size[i]);
    sfText_setFillColor(drop->text->title, drop->text->color);
    set_droptext_position(drop, drop->text);
}
