/*
** EPITECH PROJECT, 2022
** c-library
** File description:
** size_of_tab.c
*/

#include "../my.h"
#include <stddef.h>
#include <stdlib.h>

int size_of_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        i++;
    }
    return i;
}
