/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-myhunter-yanis.djeridi
** File description:
** get_position.c
*/

#include "rpg.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>

sfVector2f get_vector(float x, float y)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    return position;
}
