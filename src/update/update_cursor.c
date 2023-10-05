/*
** PROJECT, 2022
** RPG
** File description:
** update_cursor.c
*/

#include "my.h"
#include "rpg.h"
#include "update_setting.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void update_cursor_size(cursor_t *cursor, float size)
{
    sfVector2f middle;
    sfVector2f center;

    center.x = cursor->box_size.x / 2;
    center.y = cursor->box_size.y / 2;
    middle.x = cursor->start.x + size / 2;
    middle.y = cursor->start.y;
    sfRectangleShape_setSize(cursor->box, cursor->box_size);
    sfRectangleShape_setOrigin(cursor->box, center);
    sfRectangleShape_setFillColor(cursor->box, cursor->color);
    sfRectangleShape_setPosition(cursor->box, middle);
}

void update_cursor_title(cursor_t *cursor)
{
    sfText_setString(cursor->text->title, cursor->name);
    sfText_setFont(cursor->text->title, cursor->text->font);
    cursor->text->color = get_color(up_text_red[0], up_text_green[0],
    up_text_blue[0], up_text_alpha[0]);
    sfText_setCharacterSize(cursor->text->title, up_text_size[0]);
    sfText_setFillColor(cursor->text->title, cursor->text->color);
    cursor->text->pos = get_vector(up_text_x[0], up_text_y[0]);
    sfText_setPosition(cursor->text->title, cursor->text->pos);
}

void update_cursor(cursor_t *cursor)
{
    free(cursor->name);
    cursor->name = malloc(sizeof(char) * (my_strlen(up_name_cursor[0]) + 1));
    cursor->name = my_strcpy(cursor->name, up_name_cursor[0]);
    cursor->box_size = get_vector(up_box_x[0], up_box_y[0]);
    cursor->color = get_color(up_cursor_red[0], up_cursor_green[0],
    up_cursor_blue[0], up_cursor_alpha[0]);
    cursor->start = get_vector(up_start_x[0], up_start_y[0]);
    cursor->end = get_vector(up_end_x[0], up_end_y[0]);
    sfRectangleShape_setPosition(cursor->line, cursor->start);
    sfRectangleShape_setSize(cursor->line,
    get_vector(up_line_x[0], up_line_y[0]));
    sfRectangleShape_setFillColor(cursor->line,
    get_color(up_line_red[0], up_line_green[0],
    up_line_blue[0], up_line_alpha[0]));
    update_cursor_size(cursor, up_line_x[0]);
    update_cursor_title(cursor);
}
