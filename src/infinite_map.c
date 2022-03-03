/*
** EPITECH PROJECT, 2022
** infinite_map
** File description:
** myrunner
*/

#include "../include/header.h"

char **get_infinitemap()
{
    char **map;
    int line_nb = get_linenb("maps/mod1.txt");
    int i = 0;
    int mapnb = 0;
    int maxlen = find_maxlen2("maps/mod1.txt") - 1;

    map = malloc((line_nb + 1) * sizeof(char *));
    map[line_nb] = 0;
    while (i < line_nb) {
        map[i] = creat_tab(20 * maxlen);
        i++;
    }
    while (mapnb < 20) {
        map = randmod(map, maxlen * mapnb);
        mapnb++;
    }
    return (map);
}

char **randmod(char **map, int len)
{
    char **mod1 = create_map("maps/mod1.txt");
    char **mod2 = create_map("maps/mod2.txt");
    char **mod3 = create_map("maps/mod3.txt");
    int line_nb = get_linenb("maps/mod1.txt");
    int proba;

    proba = rand() % 3;
    if (proba == 0)
        map = scat_map(map, mod1, len);
    if (proba == 1)
        map = scat_map(map, mod2, len);
    if (proba == 2)
        map = scat_map(map, mod3, len);
    return (map);
}
