/*
** EPITECH PROJECT, 2022
** count
** File description:
** can count number
*/

#include <stdio.h>

int count(int d)
{
    int b = 0;

    if (d < 0) {
        d = d * -1;
        b++;
    }
    while (d > 10) {
        d = d / 10;
        b++;
    }
    return (b + 1);
}
