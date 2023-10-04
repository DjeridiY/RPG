/*
** EPITECH PROJECT, 2022
** flag_pointer
** File description:
** print address pointer in hexa
*/

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

void my_putchar(char c);
int my_putstr(char const str);

void flag_pointer2(long long int nbr)
{
    char *base_hexa = "0123456789abcdef";
    char result_convert[12];
    int i = 11;

    while ((nbr / 16) > 0 || i >= 11) {
        result_convert[i] = base_hexa[(nbr % 16)];
        nbr = nbr / 16;
        i--;
    }
    result_convert[i] = base_hexa[(nbr % 16)];
    my_putchar('0');
    my_putchar('x');
    for (;i < 12; i++) {
        my_putchar(result_convert[i]);
    }
}

int flag_pointer(va_list ap, int precis)
{
    flag_pointer2(va_arg(ap, long long int));
}
