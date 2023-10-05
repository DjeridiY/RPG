/*
** PROJECT, 2022
** Paint
** File description:
** get_color.c
*/

#include "my.h"
#include "rpg.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>

sfColor get_color(int red, int green, int blue, int alpha)
{
    sfColor color = {red, green, blue, alpha};
    return color;
}
