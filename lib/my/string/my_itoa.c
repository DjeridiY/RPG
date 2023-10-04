/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-myradar-yanis.djeridi
** File description:
** int_to_string.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count(int d)
{
    int b = 0;

    if (d < 0) {
        d = d * -1;
        b++;
    }
    while (d > 0) {
        d = d / 10;
        b++;
    }
    return b;
}

char *my_itoa(int number)
{
    int len = count(number);
    char *str = malloc(sizeof(char) * (len + 1));
    int i = len - 1;

    if (number < 0) {
        str[0] = '-';
        number = number * -1;
    }
    while (number > 0) {
        str[i] = (int)((number % 10) + '0');
        number = number / 10;
        i--;
    }
    str[len] = '\0';
    return str;
}
