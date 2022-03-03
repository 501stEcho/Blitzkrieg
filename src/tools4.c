/*
** EPITECH PROJECT, 2021
** tools4
** File description:
** runner
*/

#include "../include/header.h"

int check_pos(gamestruct *game, int i, int j, int flag)
{
    int compt = 0;
    int x;
    int y;

    while (compt < 4) {
        if (flag == 0) {
            x = (int)game->bomblist[compt].pos.x / (24 * SCALE);
            y = (int)game->bomblist[compt].pos.y / (20 * SCALE);
        }
        if (flag == 1) {
            x = (int)game->coinlist[compt].pos.x / (45 * SCALE);
            x = (int)game->coinlist[compt].pos.y / (45 * SCALE);
        }
        if (x == j && y == i) {
            return (0);
        }
        compt++;
    }
    return (1);
}

int count_items(char **map, int flag)
{
    int i = 0;
    int count = 0;

    while (map[i]) {
        count += search_items(map[i], flag);
        i++;
    }
    return (count);
}

int search_items(char *line, int flag)
{
    int i = 0;
    int count = 0;

    while (line[i]) {
        if (flag == 0 && line[i] == '2')
            count++;
        if (flag == 1 && line[i] == '3')
            count++;
        i++;
    }
    return (count);
}

float get_seconds(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    return (seconds);
}

int find_maxlen2(char *path)
{
    FILE *fd = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int max_len = 0;

    while ((read = getline(&line, &len, fd)) != -1) {
        if (read - 1 > max_len)
            max_len = read - 1;
    }
    return (max_len);
}
