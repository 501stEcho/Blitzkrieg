/*
** EPITECH PROJECT, 2021
** rect
** File description:
** hunter
*/

#include "../include/header.h"

sfIntRect create_rect(int width, int height, int state)
{
    sfIntRect rect;

    rect.width = width;
    rect.height = height;
    rect.top = 0;
    rect.left = state * width;
    return (rect);
}

sfIntRect adjust_rect(sfIntRect (*fct)(int), int state)
{
    sfIntRect rect = fct(state);

    return (rect);
}

sfIntRect define_rect(char **map, int i, int j)
{
    sfIntRect rect;
    int check = 0;

    if (i == 0) {
        rect = adjust_rect(&road_rect, 4);
        check = 1;
    }
    if (j == 0 && map[i - 1][j] == ' ' && check == 0) {
        rect = adjust_rect(&road_rect, 0);
        check = 1;
    }
    if (j == 0 && map[i - 1][j] == '1' && check == 0) {
        rect = adjust_rect(&road_rect, 4);
        check = 1;
    }
    if (check == 0)
        define_rect2(map, i, j, &rect);
    return (rect);
}

sfIntRect define_rect2(char **map, int i, int j, sfIntRect *rect)
{
    int check = 0;

    if (i >= 2 && map[i - 1][j] == '1' && map[i - 2][j] != '1' && check == 0) {
        *rect = adjust_rect(&road_rect, 4);
        check = 1;
    }
    if (i >= 2 && map[i - 1][j] == '1' && map[i - 2][j] == '1' && check == 0) {
        *rect = adjust_rect(&road_rect, 5);
        check = 1;
    }
    if (i >= 1 && map[i - 1][j] == '1' && check == 0) {
        *rect = adjust_rect(&road_rect, 4);
        check = 1;
    }
    if (check == 0)
        define_rect3(map, i, j, rect);
}

sfIntRect define_rect3(char **map, int i, int j, sfIntRect *rect)
{
    int check = 0;

    if (map[i][j - 1] == '1' && map[i][j + 1] == '1') {
        *rect = adjust_rect(&road_rect, 0);
        check = 1;
    }
    if (map[i][j - 1] != '1' && map[i][j + 1] == '1' && check == 0) {
        *rect = adjust_rect(&road_rect, 1);
        check == 1;
    }
    if (map[i][j - 1] == '1' && map[i][j + 1] != '1' && check == 0) {
        *rect = adjust_rect(&road_rect, 2);
        check == 1;
    }
    if (map[i][j - 1] != '1' && map[i][j + 1] != '1' && check == 0) {
        *rect = adjust_rect(&road_rect, 3);
        check == 1;
    }
}
