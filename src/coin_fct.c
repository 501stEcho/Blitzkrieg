/*
** EPITECH PROJECT, 2021
** coin_fct
** File description:
** runner
*/

#include "../include/header.h"

void create_coinlist(gamestruct *game, int mode)
{
    int i = 0;
    sfVector2f posvector = {0, 0};
    int count;

    if (mode == 0)
        count = count_items(game->map, 1);
    if (mode == 1)
        count = 4;
    game->coinlist = malloc((count + 1) * sizeof(entitystruct));
    while (i < count) {
        game->coinlist[i].state = 0;
        game->coinlist[i].pos = posvector;
        game->coinlist[i].check = 0;
        game->coinlist[i].alive = (mode == 0 ? 1 : 0);
        i++;
    }
    game->coinlist[i].check = 1;
    if (mode == 0)
        fill_coinlist(game, game->map);
}

void handle_coin(gamestruct *game)
{
    int i = 0;
    sfVector2f center = sfView_getCenter(game->view);

    while (game->coinlist[i].check == 0) {
        if (game->coinlist[i].pos.x < center.x - 900 - (SCALE * 0.7) * 45) {
            game->coinlist[i].alive = 0;
        }
        i++;
    }
    i = 0;
    while (game->coinlist[i].check == 0) {
        if (game->coinlist[i].alive == 0) {
            place_coin(game, game->map, &(game->coinlist[i]));
        }
        i++;
    }
}

int place_coin(gamestruct *game, char **map, entitystruct *coin)
{
    sfVector2f center = sfView_getCenter(game->view);
    int i = 0;
    int j = (center.x + 1200) / (24 * SCALE);
    int compt = 0;
    int proba = rand() % 10;

    if (proba > 2)
        return (0);
    while (map[i + 2][j] != '1' && map[i + 2][j]) {
        i++;
    }
    if (map[i + 2][j] == '1' && check_pos(game, i + 2, j, 0) == 1) {
        coin->pos.y = i * 20 * (SCALE);
        coin->pos.x = j * 24 * (SCALE);
        coin->alive = 1;
    }
}

void coin_cycle(gamestruct *game, int flag)
{
    int i = 0;

    while (game->coinlist[i].check == 0) {
        if (game->coinlist[i].state < 5 && flag == 0)
            game->coinlist[i].state += 1;
        else if (flag == 0)
            game->coinlist[i].state = 0;
        if (flag == 1 && game->coinlist[i].alive < 0) {
            game->coinlist[i].alive +=
            (game->coinlist[i].alive + 10 > 0 ? 0 - game->coinlist[i].alive: 6);
            game->coinlist[i].pos.y += (game->coinlist[i].alive * 1.2);
        }
        i++;
    }
}

void display_coin(gamestruct *game, sfRenderWindow *window)
{
    int i = 0;
    sfIntRect rect;
    sfColor color = sfColor_fromRGBA(255, 255, 255, 255);

    while (game->coinlist[i].check == 0) {
        rect = adjust_rect(&coin_rect, game->coinlist[i].state);
        sfSprite_setTextureRect(game->sprite.coin.sprite, rect);
        sfSprite_setPosition(game->sprite.coin.sprite, game->coinlist[i].pos);
        if (game->coinlist[i].alive < 0) {
            color.a = (game->coinlist[i].alive * -5);
            sfSprite_setColor(game->sprite.coin.sprite, color);
        }
        if (game->coinlist[i].alive != 0)
            sfRenderWindow_drawSprite(window, game->sprite.coin.sprite, NULL);
        color.a = 255;
        sfSprite_setColor(game->sprite.coin.sprite, color);
        i++;
    }
}
