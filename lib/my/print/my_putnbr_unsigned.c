/*
** EPITECH PROJECT, 2022
** lib
** File description:
** lib
*/

void my_putchar(char c);

int my_putrnbr_unsigned(unsigned nbr)
{
    int count = 0;
    char str[100]; int i = 0; int l = 0;
    unsigned copie = nbr; int r;

    if (nbr <= 9) {
        my_putchar(nbr + 48);
        return (0);
    }
    for (;copie > 0; l++) {
        copie = copie / 10;
    }
    for (; i < l; i++) {
        str[i] = nbr % 10 + 48;
        nbr = nbr / 10;
    } r = l - 1;
        while (r >= 0) {
        my_putchar(str[r]);
        count++;
        r--;
    } return count;
}

char my_putnbr_unsigned(unsigned nbr)
{
    if (nbr < 0) {
        my_putchar('-');
        my_putrnbr_unsigned(nbr * -1);
    } else
        my_putrnbr_unsigned(nbr);
}
