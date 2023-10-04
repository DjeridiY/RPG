/*
** EPITECH PROJECT, 2022
** flag_binary
** File description:
** convert decimal to binary
*/

#include <stdarg.h>

int my_putnbr_binary(int nbr);

int flag_binary(va_list ap, int precis)
{
    unsigned int number = 0;
    int length = 0;

    length = 0;
    number = va_arg(ap, unsigned int);
    length = my_putnbr_binary(number);
    return (length);
}
