/*
** PROJECT, 2022
** Minishell1
** File description:
** bubble_sort.c
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int my_to_lower(int c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int compare(char *str1, char *str2)
{
    while (tolower(*str1) == tolower(*str2)) {
        if (*str1 == '\0') {
            return 0;
        }
        str1++;
        str2++;
    }
    return tolower(*str1) - tolower(*str2);
}

void check_diff(char **tab, int j)
{
    char *temp;

    if (compare(tab[j], tab[j + 1]) > 0) {
        temp = tab[j];
        tab[j] = tab[j + 1];
        tab[j + 1] = temp;
    }
}

void bubble_sort_array(char **tab, int size_of_tab)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < size_of_tab - 1; i++) {
        for (j = 0; j < size_of_tab - i - 1; j++) {
            check_diff(tab, j);
        }
    }
}
