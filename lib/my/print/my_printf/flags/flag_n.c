/*
** EPITECH PROJECT, 2022
** flag_n.c
** File description:
** function for flag n
*/

#include <stdarg.h>
#include <stdio.h>

int recup_va_arg(int o, va_list ap)
{
    int length = 0;

    o = o + 1;
    *va_arg(ap, int *) = o;
    return (0);
}

void flag_n(const char *format, int i, va_list ap, int precis)
{
    int o = 0;
    int length = 0;

    i = 0;
    while (format[i] != '%') {
        if (format[i + 1] != 'n') {
            o++;
        }
        i++;
    }
    if (format[i] == '%' && format[i + 1] == 'n') {
        length += recup_va_arg(o, ap);
    }
}
