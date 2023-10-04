/*
** EPITECH PROJECT, 2022
** my
** File description:
** my_putnbr.c
*/

#include "../my.h"

int my_putnbr(int nbr)
{
    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * -1;
    }
    if (nbr >= 10)
        my_putnbr(nbr / 10);
    my_putchar((nbr % 10) + 48);
    return 0;
}
