/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** button_text.c
*/

#include "my.h"
#include "rpg.h"
#include "button.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void set_text_position(button_t *button, text_t *text)
{
    sfFloatRect text_rect = sfText_getLocalBounds(text->title);
    sfVector2f rectangle_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f rectangle_size = sfRectangleShape_getSize(button->rect);
    int x = rectangle_pos.x + rectangle_size.x / 2 - text_rect.width / 2;
    int y = rectangle_pos.y + rectangle_size.y / 2 - text_rect.height / 2;
    sfVector2f text_pos = get_vector(x, y - 4);

    sfText_setPosition(text->title, text_pos);
}

void set_text(button_t *button, int i)
{
    button->text = malloc(sizeof(text_t));
    button->text->title = sfText_create();
    button->text->font = sfFont_createFromFile("ressources/font/fanta.ttf");
    sfText_setString(button->text->title, button->name);
    sfText_setFont(button->text->title, button->text->font);
    button->text->color = get_color(title_red[i], title_green[i],
    title_blue[i], title_alpha[i]);
    sfText_setCharacterSize(button->text->title, title_size[i]);
    sfText_setFillColor(button->text->title, button->text->color);
    set_text_position(button, button->text);
}
