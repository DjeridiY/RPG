/*
** EPITECH PROJECT, 2022
** float
** File description:
** float
*/

#include <stdarg.h>
#include <stdio.h>

void my_putchar(char c);
int my_putnbr(long long int nbr);
int count(int d);

int calculs_float(double f, long long int nd, int precis)
{
    nd = f;
    double fi = f - nd;
    int length;
    int cpy;
    if (f < 0) {
        f = -f;
        my_putchar('-');
    }
    my_putnbr(nd);
    my_putchar('.');
    for (int o = 0; o < precis; o++)
        fi = fi * 10;
    cpy = fi;
    cpy = cpy % 10;
    if (cpy >= 5)
        fi = fi + 10;
    fi = fi / 10;
    my_putnbr(fi);
    length = count(fi) + count(nd) + 1;
    return (length);
}

int flag_float(va_list ap, int precis)
{
    double f = va_arg(ap, double);
    long long int nd = f;
    int length;

    precis++;
    length = calculs_float(f, nd, precis);
    return (length);
}
