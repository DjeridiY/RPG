/*
** PROJECT, 2022
** RPG
** File description:
** create_window.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

sfRenderWindow *create_window(char *name, int size_x, int size_y)
{
    sfVideoMode mode = {size_x, size_y, 32};
    sfRenderWindow *window =
    sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    return window;
}
