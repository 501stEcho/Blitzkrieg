/*
** EPITECH PROJECT, 2021
** display
** File description:
** bshunter
*/

#include "../include/header.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb <= 9)
        my_putchar(nb + 48);
    if (nb > 9) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
}

void display_tab(char **tab)
{
    int i = 0;

    while (tab[i]) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
}
