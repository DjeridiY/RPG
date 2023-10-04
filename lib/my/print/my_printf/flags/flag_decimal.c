/*
** EPITECH PROJECT, 2022
** flag decimal
** File description:
** print decimal number
*/

#include <stdarg.h>

int my_putnbr(int nb);
int count(int d);

int flag_decimal(va_list ap, int precis)
{
    int number = 0;
    int length = 0;

    number = va_arg(ap, int);
    my_putnbr(number);
    length = count(number);
    return (length);
}
