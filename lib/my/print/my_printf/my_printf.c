/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf major project
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../flag_myprintf.h"

void my_putchar(char c);
void flag_n(const char *format, int i, va_list ap);

char recup_index(const char *format, int *test, va_list ap, int precis)
{
    int len = 0;
    int i = *test;

    for (int index = 0; index < 17; index++) {
        if (format[i + 1] == tab_function[index].character) {
            len += tab_function[index].cmp(ap, precis);
        }
    } return (len);
}

int precis_balance(const char *format, va_list ap, int i)
{
    int precis = 0;
    int verif = 0;
    int d = 0;
    int l = i;

    for (; format[i - 1] != '.' && format[i] != '\0'; i++) {
        if (format[i] == '.') {
            verif = 1;
            d = i + 1;
        }
    }
    for (; verif == 1 && format[d] >= '0' && format[d] <= '9'; d++) {
        l += 1;
    }
    l += verif;
    return (l);
}

int recup_precis(const char *format, va_list ap, int i)
{
    int precis = 0;
    int verif = 0;
    int d = 0;

    for (; format[i - 1] != '.' && format[i] != '\0'; i++) {
        if (format[i] == '.') {
            verif = 1;
            d = i + 1;
        }
    }
    for (; verif == 1 && format[d] >= '0' && format[d] <= '9'; d++) {
        precis *= 10;
        precis += format[d] - 48;
    }
    if (precis == 0)
        precis += 6;
    return (precis);
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int length = 0;
    int precis = 0;
    va_start(ap, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            precis = recup_precis(format, ap, i);
            i = precis_balance(format, ap, i);
            length += recup_index(format, &i, ap, precis);
            i++;
        } else {
            my_putchar(format[i]);
            length++;
        }
        i++;
    }
    flag_n(format, i, ap);
    va_end(ap);
    return (length);
}
