/*
** EPITECH PROJECT, 2022
** tools6
** File description:
** myrunner
*/

#include "../include/header.h"

char *fill_line(char *mapline, int max_len, char *line)
{
    int i = slen(line) - 1;

    mapline = creat_tab(max_len);
    mapline = scpy(mapline, line);
    while (i < max_len) {
        mapline[i] = ' ';
        i++;
    }
    mapline[max_len] = 0;
    return (mapline);
}

int tabslen(char **tab)
{
    int i = 0;

    while (tab[i++])
        ;
    return (i);
}

void check_road(sfRenderWindow *window, int i, int j, gamestruct *game)
{
    if (j >= 0 && game->map[i][j] == '1')
        display_road(window, i, j, game);
}

void format_text(sfText *text, sfColor color, int size, char *string)
{
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, size);
    sfText_setString(text, string);
}

void print_text(sfRenderWindow *window, sfText *text, sfVector2f position)
{
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
}
