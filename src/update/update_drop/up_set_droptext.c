/*
** PROJECT, 2022
** Paint
** File description:
** set_droptext.c
*/

#include "my.h"
#include "rpg.h"
#include "update_setting.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void up_set_droptext_position(drop_t *drop, text_t *text)
{
    sfFloatRect text_rect = sfText_getLocalBounds(text->title);
    sfVector2f rectangle_pos = sfRectangleShape_getPosition(drop->rect);
    sfVector2f rectangle_size = sfRectangleShape_getSize(drop->rect);
    int x = rectangle_pos.x + rectangle_size.x / 2 - text_rect.width / 2;
    int y = rectangle_pos.y + rectangle_size.y / 2 - text_rect.height / 2;
    sfVector2f text_pos = get_vector(x, y - 4);

    sfText_setPosition(text->title, text_pos);
}

void up_set_droptext(drop_t *drop, int i)
{
    sfText_setString(drop->text->title, drop->name);
    drop->text->color = get_color(up_char_red[i], up_char_green[i],
    up_char_blue[i], up_char_alpha[i]);
    sfText_setCharacterSize(drop->text->title, up_drop_size[i]);
    sfText_setFillColor(drop->text->title, drop->text->color);
    up_set_droptext_position(drop, drop->text);
}
