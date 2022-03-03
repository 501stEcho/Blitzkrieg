/*
** EPITECH PROJECT, 2021
** coin_fct
** File description:
** myrunner
*/

#include "../include/header.h"

void fill_coinlist(gamestruct *game, char **map)
{
    int i = 0;
    int j = 0;
    int compt = 0;

    while (game->map[i]) {
        coin_line(game, game->map[i], &compt, i);
        i++;
    }
    i = 0;
    while (game->coinlist[i].check == 0) {
        game->coinlist[i].pos.x *= (SCALE * 24);
        game->coinlist[i].pos.y *= (SCALE * 20);
        i++;
    }
}

void coin_line(gamestruct *game, char *line, int *compt, int i)
{
    int j = 0;

    while (line[j]) {
        if (line[j] == '3') {
            game->coinlist[*compt].pos.x = j;
            game->coinlist[*compt].pos.y = i;
            (*compt)++;
        }
        j++;
    }
}

void check_coin(gamestruct *game)
{
    int i = 0;
    int x = 0;
    int y = 0;

    while (game->coinlist[i].check == 0 && game->health >= 1) {
        x = game->coinlist[i].pos.x / (SCALE * 24);
        y = game->coinlist[i].pos.y / (SCALE * 20);
        if (check_item(y, x, game, 1) == 1 && game->coinlist[i].alive == 1) {
            game->coinscore += 1;
            sfSound_play(game->sound.coin_effect);
            game->coinlist[i].alive = -51;
        }
        i++;
    }
}

void restart_coin(gamestruct *game)
{
    int i = 0;

    while (game->coinlist[i].check == 0) {
        if (game->mode == 0)
            game->coinlist[i].alive = 1;
        if (game->mode == 1)
            game->coinlist[i].alive = 0;
        if (game->mode == 0)
            fill_coinlist(game, game->map);
        i++;
    }
}
