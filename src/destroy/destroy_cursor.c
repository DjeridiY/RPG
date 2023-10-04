/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** destroy_cursor.c
*/

#include "my.h"
#include "rpg.h"
#include "cursor.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void destroy_cursor(cursor_t **cursor)
{
    for (int i = 0; i < nbr_of_cursor; i++) {
        sfRectangleShape_destroy(cursor[i]->box);
        sfRectangleShape_destroy(cursor[i]->line);
        sfText_destroy(cursor[i]->text->title);
        sfFont_destroy(cursor[i]->text->font);
        free(cursor[i]->name);
        free(cursor[i]);
    }
    free(cursor);
}
