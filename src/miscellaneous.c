/*
** EPITECH PROJECT, 2022
** miscelanneous
** File description:
** myrunner
*/

#include "../include/header.h"

void restart(gamestruct *game, sfRenderWindow *window)
{
    game->sprite.barry.pos = find_spawn(game->map);
    game->rectview.top = 0;
    game->rectview.left = 0;
    game->view = sfView_createFromRect(game->rectview);
    sfRenderWindow_setView(window, game->view);
    game->menustate = 0;
    game->menuphase = 1;
    game->health = 1;
    game->sprite.barry.state = 8;
    game->coinscore = 0;
    restart_bomb(game);
    restart_coin(game);
}

void give_skin(gamestruct *game)
{
    if (game->barryskin == 1)
        sfSprite_setColor(game->sprite.barry.sprite, sfRed);
    if (game->barryskin == 2)
        sfSprite_setColor(game->sprite.barry.sprite, sfGreen);
    if (game->barryskin == 3)
        sfSprite_setColor(game->sprite.barry.sprite, sfBlue);
}
