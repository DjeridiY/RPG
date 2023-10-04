/*
** EPITECH PROJECT, 2022
** test 2
** File description:
** test2
*/

#include <stdio.h>
#include <stdlib.h>

int my_putnbr(long long int nbr);

int my_putnbr_base8(int nbr)
{
    int quotient = nbr;
    int octal_num = 0;
    char Octal_conv[10000];
    int i = 1;
    int j;

    while (quotient != 0) {
        Octal_conv[i] = quotient % 8;
        quotient = quotient / 8;
        i++;
    }
    j = i - 1;
    while (j > 0) {
        octal_num = octal_num * 10 + Octal_conv[j];
        j--;
    }
    my_putnbr(octal_num);
    return 0;
}
