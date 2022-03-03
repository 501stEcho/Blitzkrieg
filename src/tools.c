/*
** EPITECH PROJECT, 2021
** tools
** File description:
** hunter
*/

#include "../include/header.h"

int signe(float nb)
{
    if (nb < 0)
        return (-1);
    return (1);
}

int my_itoa_len(int nb)
{
    int i = 0;

    if (nb == 0)
        return (1);
    if (nb < 0) {
        nb *= -1;
        i++;
    }
    while (nb > 0) {
        i++;
        nb /= 10;
    }
    return (i);
}

char *my_itoa(int nb)
{
    int size = my_itoa_len(nb);
    char *str = creat_tab(size);
    int i = size - 1;

    if (nb < 0) {
        str[0] = '-';
        nb *= -1;
    }
    if (nb == 0)
        str[i] = 48;
    while (nb > 0) {
        str[i] = (nb % 10) + 48;
        i--;
        nb /= 10;
    }
    return (str);
}

char *creat_tab(int i)
{
    char *tab = NULL;

    tab = malloc((i + 1) * sizeof(char));
    tab[i] = 0;
    return (tab);
}

int is_hit(sfRenderWindow *window, sfSprite *sprite)
{
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect rec = sfSprite_getGlobalBounds(sprite);
    sfVector2f coord = sfRenderWindow_mapPixelToCoords(window, mousepos, NULL);
    if (sfFloatRect_contains(&rec, (int)coord.x, (int)coord.y) == sfTrue)
        return (1);
    return (0);
}
