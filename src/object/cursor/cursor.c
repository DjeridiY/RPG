/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** cursor.c
*/

#include "my.h"
#include "rpg.h"
#include "cursor.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void set_cursor(cursor_t *cursor, float size)
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

void set_cursor_title(cursor_t *cursor, int i)
{
    cursor->text = malloc(sizeof(text_t));
    cursor->text->title = sfText_create();
    cursor->text->font = sfFont_createFromFile("ressources/font/fanta.ttf");
    sfText_setString(cursor->text->title, cursor->name);
    sfText_setFont(cursor->text->title, cursor->text->font);
    cursor->text->color = get_color(text_red[i], text_green[i],
    text_blue[i], text_alpha[i]);
    sfText_setCharacterSize(cursor->text->title, text_size[i]);
    sfText_setFillColor(cursor->text->title, cursor->text->color);
    cursor->text->pos = get_vector(text_x[i], text_y[i]);
    sfText_setPosition(cursor->text->title, cursor->text->pos);
}

cursor_t *create_cursor(int i)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    cursor->box = sfRectangleShape_create();
    cursor->line = sfRectangleShape_create();
    cursor->name = malloc(sizeof(char) * (my_strlen(name_cursor[i]) + 1));
    cursor->name = my_strcpy(cursor->name, name_cursor[i]);
    cursor->box_size = get_vector(box_x[i], box_y[i]);
    cursor->color = get_color(cursor_red[i], cursor_green[i],
    cursor_blue[i], cursor_alpha[i]);
    cursor->value = 0.5;
    cursor->start = get_vector(start_x[i], start_y[i]);
    cursor->end = get_vector(end_x[i], end_y[i]);
    cursor->visible = visible_cursor[i];
    sfRectangleShape_setPosition(cursor->line, cursor->start);
    sfRectangleShape_setSize(cursor->line, get_vector(line_x[i], line_y[i]));
    sfRectangleShape_setFillColor(cursor->line,
    get_color(line_red[i], line_green[i], line_blue[i], line_alpha[i]));
    set_cursor(cursor, line_x[i]);
    set_cursor_title(cursor, i);
    return cursor;
}

void cursor_object(cursor_t **cursor)
{
    for (int i = 0; i < nbr_of_cursor; i++) {
        cursor[i] = create_cursor(i);
    }
}
