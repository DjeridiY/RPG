/*
** EPITECH PROJECT, 2022
** flag_hexa_min
** File description:
** convert decimal to hexa
*/

#include <stdarg.h>

int my_putnbr_base_hexa_min(int nbr);

int flag_hexa_min(va_list ap, int precis)
{
    unsigned int number = 0;
    int length = 0;

    number = va_arg(ap, unsigned int);
    length = my_putnbr_base_hexa_min(number);
    return (length);
}
