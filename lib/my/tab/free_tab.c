/*
** PROJECT, 2022
** my
** File description:
** free_tab.c
*/

#include <stddef.h>
#include <stdlib.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}
