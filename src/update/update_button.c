/*
** PROJECT, 2022
** RPG
** File description:
** update_button.c
*/

#include "my.h"
#include "rpg.h"
#include "update_setting.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void update_text_position(button_t *button, text_t *text)
{
    sfFloatRect text_rect = sfText_getLocalBounds(text->title);
    sfVector2f rectangle_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f rectangle_size = sfRectangleShape_getSize(button->rect);
    int x = rectangle_pos.x + rectangle_size.x / 2 - text_rect.width / 2;
    int y = rectangle_pos.y + rectangle_size.y / 2 - text_rect.height / 2;
    sfVector2f text_pos = get_vector(x, y - 4);

    sfText_setPosition(text->title, text_pos);
}

void update_text(button_t *button, int i)
{
    button->text->color = get_color(up_title_red[i], up_title_green[i],
    up_title_blue[i], up_title_alpha[i]);
    sfText_setCharacterSize(button->text->title, up_title_size[i]);
    sfText_setFillColor(button->text->title, button->text->color);
    update_text_position(button, button->text);
}

void update_button(button_t *button, int i)
{
    button->size = get_vector(up_button_size_x[i], up_button_size_y[i]);
    button->pos = get_vector(up_button_pos_x[i], up_button_pos_y[i]);
    button->color = get_color(up_red[i], up_green[i], up_blue[i], up_alpha[i]);
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setSize(button->rect, button->size);
    update_text(button, i);
}
