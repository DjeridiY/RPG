/*
** EPITECH PROJECT, 2022
** flag_hexa_maj.c
** File description:
** convert decimal to hexa
*/

#include <stdarg.h>

int my_putnbr_base_hexa_maj(int nbr);

int flag_hexa_maj(va_list ap, int precis)
{
    unsigned int number = 0;
    int length = 0;

    number = va_arg(ap, unsigned int);
    length = my_putnbr_base_hexa_maj(number);
    return (length);
}
