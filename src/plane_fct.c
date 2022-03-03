/*
** EPITECH PROJECT, 2022
** plane_fct
** File description:
** myrunner
*/

#include "../include/header.h"

void plane_cycle(gamestruct *game)
{
    if (game->sprite.spitfire.state == 5)
        game->sprite.spitfire.state = 0;
    else
        game->sprite.spitfire.state += 1;
}

void plane_display(gamestruct *game, sfRenderWindow *window)
{
    sfIntRect rect = adjust_rect(&spitfire_rect, game->sprite.spitfire.state);

    game->sprite.spitfire.pos.x += game->sprite.spitfire.speedx;
    sfSprite_setPosition(
    game->sprite.spitfire.sprite, game->sprite.spitfire.pos);
    sfSprite_setTextureRect(game->sprite.spitfire.sprite, rect);
    sfRenderWindow_drawSprite(window, game->sprite.spitfire.sprite, NULL);
}

void plane_move(gamestruct *game)
{
    game->sprite.spitfire.speedx *= 1.05;
    if (game->sprite.spitfire.speedx == 0)
        game->sprite.spitfire.speedx = 1;
}
