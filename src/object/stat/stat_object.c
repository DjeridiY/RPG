/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** create_back.c
*/

#include "my.h"
#include "rpg.h"
#include "stat.h"
#include "print_stat.h"
#include "item.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

item_t *get_weapon(int i, item_t **item)
{
    for (int j = 0; j < item_nbr; j++) {
        if (my_strcmp(item[j]->name, weapon[i]) == 0) {
            return item[j];
        }
    }
    return item[0];
}

item_t *get_utility(int i, item_t **item)
{
    for (int j = 0; j < item_nbr; j++) {
        if (my_strcmp(item[j]->name, utility[i]) == 0) {
            return item[j];
        }
    }
    return item[0];
}

void raw_stat(stat_t *stat, int i)
{
    stat->strength = strength[i];
    stat->speed = speed[i];
    stat->defense = defense[i];
    stat->raw_strength = strength[i];
    stat->raw_speed = speed[i];
    stat->raw_defense = defense[i];
}

stat_t *create_stat(int i, item_t **item)
{
    stat_t *stat = malloc(sizeof(stat_t));

    stat->name = my_strdup((char *)(stat_name[i]));
    stat->weapon = get_weapon(i, item);
    stat->weapon->equiped = true;
    stat->weapon->pos = get_vector(280, 310);
    sfSprite_setPosition(stat->weapon->sprite, stat->weapon->pos);
    stat->utility = get_utility(i, item);
    stat->utility->equiped = true;
    stat->utility->pos = get_vector(463, 320);
    sfSprite_setPosition(stat->utility->sprite, stat->utility->pos);
    stat->lvl = lvl[i];
    stat->hp = hp[i];
    raw_stat(stat, i);
    stat->xp = xp[i];
    stat->max_hp = hp[i];
    stat->print_stat = get_printable_stat(i, stat);
    return stat;
}

void stat_object(stat_t **stat, item_t **item)
{
    for (int i = 0; i < stat_nbr; i++) {
        stat[i] = create_stat(i, item);
    }
}
