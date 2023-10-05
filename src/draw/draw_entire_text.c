/*
** PROJECT, 2022
** RPG
** File description:
** draw_stat.c
*/

#include "my.h"
#include "rpg.h"
#include "text.h"
#include "print_stat.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void draw_entire_text(text_t **text, sfRenderWindow *window)
{
    for (int i = 0; i < text_nbr; i++) {
        draw_text(text[i], window);
    }
}
