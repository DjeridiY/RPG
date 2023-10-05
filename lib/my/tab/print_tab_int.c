/*
** PROJECT, 2022
** my
** File description:
** free_tab_int.c
*/

#include "../my.h"

void print_tab_int(int **tab, int size, int length)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < length; j++) {
            my_printf("%d\n", tab[i][j]);
        }
    }
}
