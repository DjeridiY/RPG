/*
** EPITECH PROJECT, 2022
** my_putnbr_base_hexa
** File description:
** convert decimal to hexadecimal
*/

#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);

int my_putnbr_base_hexa_min(int nbr)
{
    long int quotient = nbr;
    long int reste;
    int i = 0;
    int count = 0;
    char hexa_num [10000];

    while (quotient != 0) {
        reste = quotient % 16;
        if (reste < 10)
            hexa_num[i++] = 48 + reste;
        else
            hexa_num[i++] = 87 + reste;
        quotient = quotient / 16;
    } i = i - 1;
    while (i >= 0) {
        my_putchar(hexa_num[i]);
        i--;
        count++;
    }
    return (count);
}
