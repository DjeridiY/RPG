/*
** EPITECH PROJECT, 2022
** Librairy
** File description:
** my_strdup_array_of_string.c
*/

#include <stdlib.h>
#include <string.h>
#include "../my.h"

char **my_tabdup(char **array)
{
    int size = size_of_tab(array);
    char **tab = malloc(sizeof(char *) * (size));
    int i = 0;

    while (i < size) {
        tab[i] = my_strdup(array[i]);
        i++;
    }
    tab[i] = NULL;
    return tab;
}
