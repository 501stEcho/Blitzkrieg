/*
** EPITECH PROJECT, 2021
** barry
** File description:
** runner
*/

#include "../include/header.h"

void display_barry(sfRenderWindow *window, gamestruct *game)
{
    sfIntRect rect = adjust_rect(&barry_rect, game->sprite.barry.state);

    sfSprite_setTextureRect(game->sprite.barry.sprite, rect);
    sfSprite_setPosition(game->sprite.barry.sprite, game->sprite.barry.pos);
    sfRenderWindow_drawSprite(window, game->sprite.barry.sprite, NULL);
}

void barry_cycle(gamestruct *game)
{
    if (game->sprite.barry.state == 7) {
        game->sprite.barry.state = 0;
    } else if (game->sprite.barry.state < 7)
        game->sprite.barry.state += 1;
    if (game->sprite.barry.pos.y < game->ymax && game->menuphase == 0)
        game->sprite.barry.state = 4;
    if (game->sprite.barry.state == 10) {
        game->sprite.barry.state = 9;
    } else if (game->sprite.barry.state >= 8 && game->sprite.barry.state <= 10)
        game->sprite.barry.state += 1;
}

void barry_move(gamestruct *game)
{
    int hmax = 0;
    sfVector2f center = sfView_getCenter(game->view);

    if (game->menuphase == 1)
        game->speedview = 3;
    if (game->sprite.barry.pos.x < center.x - 900 - (40 * SCALE / 2)) {
        game->health -= 1;
        game->win = 0;
    }
    if (game->sprite.barry.pos.x < center.x - 700)
        game->sprite.barry.speedx += 0.05;
    if (game->sprite.barry.pos.x > center.x - 700 &&
    game->sprite.barry.speedx > 0)
        game->sprite.barry.speedx -= 0.08;
    while (game->map[hmax])
        hmax++;
    barry_move2(game, hmax);
}

void barry_move2(gamestruct *game, int hmax)
{
    if (game->sprite.barry.pos.y > game->ymax)
        game->sprite.barry.pos.x -= game->speedview;
    if (game->sprite.barry.pos.x + game->sprite.barry.speedx <= game->xmax)
        game->sprite.barry.pos.x +=
        game->speedview + game->sprite.barry.speedx;
    if (collide(game->sprite.barry.sprite, game->sprite.spitfire.sprite) ==
    1) {
        game->health = 0;
        game->win = 1;
        game->speedview /= 2;
    }
    barry_move3(game, hmax);
}

void barry_move3(gamestruct *game, int hmax)
{
    if (game->sprite.barry.pos.y + 3 + game->sprite.barry.speedy <= game->ymax)
        game->sprite.barry.pos.y += game->sprite.barry.speedy + 3;
    else {
        if (game->sprite.barry.pos.y <= game->ymax)
            game->sprite.barry.pos.y +=
            (game->ymax - game->sprite.barry.pos.y);
    }
    if (game->sprite.barry.pos.y == game->ymax)
        game->sprite.barry.isjumping = 0;
    if (game->sprite.barry.pos.y >= (hmax - 1) * 20 * SCALE) {
        game->health -= 1;
        game->win = 0;
    }
    barry_move4(game, hmax);
}
