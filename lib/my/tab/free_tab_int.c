/*
** PROJECT, 2022
** my
** File description:
** free_tab_int.c
*/

#include <stdlib.h>

void free_tab_int(int **tab, int size)
{
    for (int i = 0; i < size - 1; i++) {
        free(tab[i]);
    }
    free(tab);
}
