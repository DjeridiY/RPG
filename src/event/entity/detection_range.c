/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** detection_range.c
*/

#include "my.h"
#include "rpg.h"
#include "entity.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>

bool detection_range(sfSprite *player, sfSprite *entity, float range)
{
    sfVector2f pos1 = sfSprite_getPosition(player);
    sfVector2f pos2 = sfSprite_getPosition(entity);
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos1.y;
    float distance = sqrtf(dx * dx + dy * dy);

    return distance <= range;
}
