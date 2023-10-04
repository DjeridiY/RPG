/*
** EPITECH PROJECT, 2022
** flag_octal
** File description:
** convert decimal to octal
*/

#include <stdarg.h>

int count(int d);
int my_putnbr_base8(int nbr);

int flag_octal(va_list ap, int precis)
{
    unsigned int number = 0;
    int length = 0;

    number = va_arg(ap, unsigned int);
    my_putnbr_base8(number);
    length = count(number);
    return (length);
}
