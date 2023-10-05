/*
** PROJECT, 2022
** RPG
** File description:
** move_player.c
*/

#include "my.h"
#include "rpg.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <math.h>

int nbr_of_int_tab_suite(int **tab, int nb, sfVector2f pos, int cn)
{
    if (tab[(int) pos.y][(int) pos.x] == nb)
        return cn + 1;
    return cn;
}

int nbr_of_int_tab(int **tab, int nb)
{
    int cn = 0;

    for (int y = 0; y < 100; y++)
        for (int x = 0; x < 100; x++) {
            cn = nbr_of_int_tab_suite(tab, nb, (sfVector2f) {x, y}, cn);
        }
    return cn;
}

sfVector2f vector_spawn_suite(int **tab, int len, int y, int *cn)
{
    for (int x = 0; x < 100; x++) {
        if (tab[y][x] == 1)
            *cn += 1;
        if ((int) (len / 2) == *cn)
            return ((sfVector2f) {x, y});
    }
    return ((sfVector2f) {-1, -1});
}

sfVector2f vector_spawn(int **tab, int nb, int len)
{
    int cn = 0;
    sfVector2f retour;

    for (int y = 0; y < 100; y++) {
        retour = vector_spawn_suite(tab, len, y, &cn);
        if (retour.x != -1 && retour.y != -1)
            return retour;
    }
    return ((sfVector2f) {0, 0});
}
