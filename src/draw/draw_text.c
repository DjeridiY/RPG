/*
** PROJECT, 2022
** RPG
** File description:
** draw_back.c
*/

#include "my.h"
#include "rpg.h"
#include "back.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void draw_text(text_t *text, sfRenderWindow *window)
{
    if (text->visible == true) {
        sfRenderWindow_drawText(window, text->title, NULL);
    }
}
