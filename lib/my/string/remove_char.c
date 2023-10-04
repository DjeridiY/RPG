/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-myls-yanis.djeridi
** File description:
** remove_char.c
*/

#include "../my.h"

char *remove_char2(char *str, char not_allowed_char, int len, int i)
{
    if (str[i] == not_allowed_char) {
        for (int j = i; j < len; j++) {
            str[j] = str[j + 1];
        }
        len--;
        i--;
    }
    return str;
}

char *remove_char(char *str, char not_allowed_char)
{
    int i = 0;
    int len = my_strlen(str);

    while (i < len) {
        remove_char2(str, not_allowed_char, len, i);
        i++;
    }
    return str;
}
