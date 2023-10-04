/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** draw_cursor.c
*/

#include "my.h"
#include "rpg.h"
#include "cursor.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void draw_cursor(cursor_t **cursor, sfRenderWindow *window)
{
    for (int i = 0; i < nbr_of_cursor; i++) {
        if (cursor[i]->visible) {
            sfRenderWindow_drawText(window, cursor[i]->text->title, NULL);
            sfRenderWindow_drawRectangleShape(window, cursor[i]->line, NULL);
            sfRenderWindow_drawRectangleShape(window, cursor[i]->box, NULL);
        }
    }
}
