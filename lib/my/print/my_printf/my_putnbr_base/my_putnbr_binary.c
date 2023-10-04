/*
** EPITECH PROJECT, 2022
** test 2
** File description:
** test2
*/

#include <stdio.h>

int my_putnbr(long long int nbr);

int my_putnbr_binary(int nbr)
{
    int binary_nbr[32];
    int i = 0;
    int count = 0;
    int j;

    if (nbr == 0) {
        my_putnbr(0);
        return (1);;
    }
    while (nbr > 0) {
        binary_nbr[i++] = nbr % 2;
        nbr /= 2;
    }
    j = i - 1;
    while (j >= 0) {
        my_putnbr(binary_nbr[j]);
        count++;
        j--;
    }
    return (count);
}
