/*
** PROJECT, 2022
** isnum
** File description:
** isnum
*/

int my_str_isnum(char *str)
{
        int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
        } else
            return 0;
        i++;
    }
    return 1;
}
