/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** destroy_back.c
*/

#include "my.h"
#include "back.h"
#include "rpg.h"
#include "stat.h"
#include "print_stat.h"
#include <stdlib.h>

void destroy_stat(stat_t **stat)
{
    for (int i = 0; i < stat_nbr; i++) {
        for (int j = 0; j < print_nbr; j++) {
            destroy_text(stat[i]->print_stat[j]);
        }
        free(stat[i]->print_stat);
        free(stat[i]->name);
        free(stat[i]);
    }
    free(stat);
}
