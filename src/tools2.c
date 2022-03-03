/*
** EPITECH PROJECT, 2021
** tools
** File description:
** hunter
*/

#include "../include/header.h"

int getnbr(char *str)
{
    int i = 0;
    int signe = 1;
    int res = 0;

    if (str[0] == '-') {
        signe *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res *= 10;
        res += str[i] - 48;
        i++;
    }
    return (res * signe);
}

int slen(char *str)
{
    int len = 0;

    while (str[len]) {
        len++;
    }
    return (len);
}

char *scpy(char *dest, char *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}

float get_posy(char **map, gamestruct *game)
{
    int j = (int)(game->sprite.barry.pos.x + SCALE * 9) / (24 * SCALE);
    int len = tabslen(map) - 1;
    int i = len - 1;
    int maxlen = find_maxlen(map);

    if (game->sprite.barry.pos.y < 0 || game->sprite.barry.pos.y < 0)
        return (500);
    if (len == 0)
        return (672);
    while (j < maxlen &&
    i > (int)((game->sprite.barry.pos.y + (30 * SCALE / 2)) / (20 * SCALE)) &&
    map[i][j])
        i--;
    while (i < len) {
        if (map[i][j] == '1')
            return ((i - 1) * SCALE * 20);
        i++;
    }
    return (len * SCALE * 20 - 20 * SCALE);
}

float get_posx(char **map, gamestruct *game)
{
    int j = (int)(game->sprite.barry.pos.x + SCALE * 9) / (24 * SCALE);
    int i = (int)(game->sprite.barry.pos.y + (30 * SCALE / 2)) / (20 * SCALE);
    int len = find_maxlen(map);

    if (i < 0 || j < 0)
        return (500);
    while (j < len) {
        if (map[i][j] == '1') {
            return (j * SCALE * 24 - ((SCALE / 2 * 40) - (3 * SCALE)));
        }
        j++;
    }
    return (len * SCALE * 30);
}
