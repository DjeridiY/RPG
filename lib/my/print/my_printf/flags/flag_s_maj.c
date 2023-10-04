/*
** EPITECH PROJECT, 2022
** flag_s.c
** File description:
** man 3 printf
*/

#include <stdarg.h>
#include <stdio.h>

void my_putchar(char c);
int my_putnbr_base8_modif(int nbr);

int flag_s(char *s)
{
    int length = 0;
    int m = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] < 32 || s[i] >= 127) {
            my_putchar('/');
            length += 1;
            m = my_putnbr_base8_modif(s[i]);
            length += m;
        } else {
            my_putchar(s[i]);
            length += 1;
        }
    }
    return (length);
}

int flag_s_maj(va_list ap, int precis)
{
    char *m;
    int length = 0;

    m = va_arg(ap, char *);
    length = flag_s(m);
    return (length);
}
