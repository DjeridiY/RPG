/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** update_stat.c
*/

#include "my.h"
#include "rpg.h"
#include "stat.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void lvl_up(stat_t **stat, rpg_t *game)
{
for (int i = 0; i < stat_nbr; i++) {
    if (stat[i]->xp >= 10) {
            sfMusic_play(game->sound[3]->sound);
            sfMusic_setPlayingOffset(game->sound[3]->sound, sfTime_Zero);
            stat[i]->lvl += 1;
            stat[i]->max_hp += 2;
            stat[i]->raw_strength += 1;
            stat[i]->raw_speed += 1;
            stat[i]->defense += 1;
            stat[i]->xp = stat[i]->xp - 10;
        }
    }
}

void update_speed_strength(stat_t **stat, int i)
{
    stat[i]->strength = stat[i]->raw_strength + stat[i]->weapon->damage;
    stat[i]->speed = stat[i]->raw_speed + stat[i]->weapon->speed;
    if (stat[i]->strength <= 0) {
        stat[i]->strength = 1;
    }
    if (stat[i]->speed <= 0) {
        stat[i]->speed = 1;
    }
    if (stat[i]->hp < 0) {
        stat[i]->hp = 0;
    }
}

void xp_and_hp_case(stat_t **stat, int i)
{
    if (stat[i]->xp == 0) {
        sfText_setString(stat[i]->print_stat[3]->title, "0");
    } else {
        sfText_setString(stat[i]->print_stat[3]->title, my_itoa(stat[i]->xp));
    }
    sfText_setString(stat[i]->print_stat[4]->title, my_itoa(stat[i]->lvl));
    if (stat[i]->hp == 0) {
        sfText_setString(stat[i]->print_stat[5]->title, "0");
    } else {
        sfText_setString(stat[i]->print_stat[5]->title, my_itoa(stat[i]->hp));
    }
}

void update_stat(stat_t **stat, rpg_t *game)
{
    lvl_up(stat, game);
    for (int i = 0; i < stat_nbr; i++) {
        update_speed_strength(stat, i);
        sfText_setString(stat[i]->print_stat[0]->title, stat[i]->name);
        sfText_setString(stat[i]->print_stat[1]->title, stat[i]->weapon->name);
        sfText_setString(stat[i]->print_stat[2]->title, stat[i]->utility->name);
        xp_and_hp_case(stat, i);
        sfText_setString(stat[i]->print_stat[6]->title,
        my_itoa(stat[i]->strength));
        sfText_setString(stat[i]->print_stat[7]->title,
        my_itoa(stat[i]->speed));
        sfText_setString(stat[i]->print_stat[8]->title,
        my_itoa(stat[i]->defense));
    }
}
