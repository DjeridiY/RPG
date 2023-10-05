/*
** PROJECT, 2022
** isalpha
** File description:
** isalpha.c
*/

int my_str_isalpha(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90)) {
        } else
            return 0;
        i++;
    }
    return 1;
}
