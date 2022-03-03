/*
** EPITECH PROJECT, 2021
** bomb_fct
** File description:
** runner
*/

#include "../include/header.h"

void fill_bomblist(gamestruct *game, char **map)
{
    int i = 0;
    int j = 0;
    int compt = 0;

    while (game->map[i]) {
        bomb_line(game, game->map[i], &compt, i);
        i++;
    }
    i = 0;
    while (game->bomblist[i].check == 0) {
        game->bomblist[i].pos.x *= (SCALE * 24);
        game->bomblist[i].pos.y *= (SCALE * 20);
        game->bomblist[i].pos.y += (SCALE * 7);
        i++;
    }
}

void bomb_line(gamestruct *game, char *line, int *compt, int i)
{
    int j = 0;

    while (line[j]) {
        if (line[j] == '2') {
            game->bomblist[*compt].pos.x = j;
            game->bomblist[*compt].pos.y = i;
            (*compt)++;
        }
        j++;
    }
}

void check_explode(gamestruct *game)
{
    int i = 0;
    int x = 0;
    int y = 0;

    game->boomswitch = 0;
    while (game->bomblist[i].check == 0 && game->health >= 1) {
        x = game->bomblist[i].pos.x / (SCALE * 24);
        y = game->bomblist[i].pos.y / (SCALE * 20);
        if (check_item(y, x, game, 0) == 1 && game->bomblist[i].alive == 1) {
            game->bomblist[i].state = 2;
            game->health -= 1;
        }
        i++;
    }
    if (game->boomswitch == 0 && game->health >= 1)
        game->boomtime = 0;
}

void restart_bomb(gamestruct *game)
{
    int i = 0;

    while (game->bomblist[i].check == 0) {
        if (game->mode == 0) {
            game->bomblist[i].alive = 1;
            game->bomblist[i].state = 0;
        }
        if (game->mode == 1)
            game->bomblist[i].alive = 0;
        i++;
    }
}
