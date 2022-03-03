/*
** EPITECH PROJECT, 2022
** barry_fct2
** File description:
** myrunner
*/

#include "../include/header.h"

void barry_move4(gamestruct *game, int hmax)
{
    if (game->sprite.barry.pos.y > game->ymax)
        game->sprite.barry.pos.y -= 3;
    if (game->sprite.barry.pos.y == game->ymax && game->menuphase == 1) {
        game->menuphase = 0;
        game->speedview = 10;
        game->sprite.barry.state = 2;
    }
}
