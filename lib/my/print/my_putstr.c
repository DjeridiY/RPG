/*
** PROJECT, 2022
** my_putstr
** File description:
** my_putstr function
*/

#include <unistd.h>

int my_strlen(const char *str);

int my_putstr(char *str)
{
    int i = 0;
    int length = my_strlen(str);

    write(1, str, length);
    return 0;
}
