/*
** EPITECH PROJECT, 2021
** tools3
** File description:
** runner
*/

#include "../include/header.h"

int find_maxlen(char **map)
{
    int i = 0;
    int j = 0;
    int len = 0;

    while (map[i]) {
        j = 0;
        while (map[i][j])
            j++;
        if (j > len)
            len = j;
        i++;
    }
    return (len);
}

sfVector2f find_spawn(char **map)
{
    int i = 0;
    int j = 0;
    int len = 0;
    sfVector2f vector = {0, -200};

    return (vector);
    while (map[len])
        len++;
    while (i < len) {
        if (map[i][j] == ' ') {
            vector.x = j * SCALE * 24 + SCALE * 24;
            vector.y = i * SCALE * 20;
            return (vector);
        }
        if (i + 1 == len) {
            i = 0;
            j++;
        }
        i++;
    }
}

int check_item(int i, int j, gamestruct *game, int flag)
{
    float x = game->sprite.barry.pos.x;
    float y = game->sprite.barry.pos.y;
    int checkx;
    int checky;

    j *= SCALE * 24;
    i *= SCALE * 20;
    checkx = check_itemx(x, j, flag);
    checky = check_itemy(y, i, flag);
    if (checkx == 1 && checky == 1)
        return (1);
    return (0);
}

int check_itemx(float x, int j, int flag)
{
    int endj = j + (SCALE / 3 * 24);
    int endx = x + (SCALE / 2 * 44);

    if (flag == 0) {
        endj = j + (SCALE * 0.7) * 24;
        j += (SCALE * 0.7) * 9;
    }
    if (flag == 1)
        endj = j + (SCALE / 3) * 45;
    while (x < endx) {
        if (x >= j && x <= endj)
            return (1);
        x++;
    }
    return (0);
}

int check_itemy(float y, int i, int flag)
{
    int endi;
    int endy = y + (SCALE / 2 * 60);

    if (flag == 0) {
        endi = i + SCALE * 0.7 * 43;
        i += 18 * SCALE * 0.7;
    }
    if (flag == 1)
        endi = i + SCALE / 3 * 45;
    while (y < endy) {
        if (y >= i && y <= endi)
            return (1);
        y++;
    }
    return (0);
}
