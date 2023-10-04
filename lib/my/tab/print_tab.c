/*
** EPITECH PROJECT, 2022
** my
** File description:
** print_tab.c
*/

#include "../my.h"

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_printf("%s\n", tab[i]);
    }
}
