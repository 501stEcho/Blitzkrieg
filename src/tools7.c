/*
** EPITECH PROJECT, 2022
** tools7
** File description:
** myrunner
*/

#include "../include/header.h"

sfVector2f getvec(float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

int nblen(int nb)
{
    int i = 1;

    while (nb > 9) {
        i++;
        nb /= 10;
    }
    return (i);
}

char **scat_map(char **map, char **mod, int maxlen)
{
    int i = 0;

    while (mod[i]) {
        map[i] = my_strcat(map[i], mod[i], maxlen);
        i++;
    }
    return (map);
}

char *my_strcat(char *dest, char *from, int i)
{
    int j = 0;

    while (from[j]) {
        dest[i] = from[j];
        i++;
        j++;
    }
    return (dest);
}
