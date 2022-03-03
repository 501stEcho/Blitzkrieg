/*
** EPITECH PROJECT, 2022
** score2
** File description:
** myrunner
*/

#include "../include/header.h"

char *get_score(int score, int flag)
{
    int i = nblen(score);
    int temp = 0;
    char *res;

    if (i <= 3)
        i = 3;
    if (flag == 1)
        i += 5;
    res = creat_tab(i);
    while (temp < i)
        res[temp++] = '0';
    temp -= 1;
    while (score > 0) {
        res[temp] = (score % 10) + 48;
        temp--;
        score /= 10;
    }
    if (flag == 1)
        res = scpy(res, "BEST ");
    return (res);
}

void display_coinscore(gamestruct *game, sfRenderWindow *window, int flag)
{
    sfColor color = sfColor_fromRGBA(255, 215, 0, 255);
    sfVector2f center = sfView_getCenter(game->view);
    sfVector2f vector = getvec(center.x - 880, center.y - 390);
    sfVector2f scavector = {1, 1};
    char *score = get_score(game->coinscore, 0);
    int size = 30;

    if (flag == 1) {
        size = 150;
        vector = getvec(center.x - 120, center.y + 120);
    }
    format_text(game->text.text, color, size, score);
    print_text(window, game->text.text, vector);
    free(score);
    if (flag == 0)
        display_coinlogo(game, window, flag);
}

void display_coinlogo(gamestruct *game, sfRenderWindow *window, int flag)
{
    sfIntRect rect = adjust_rect(&coin_rect, 0);
    sfVector2f scavector = {1, 1};
    sfVector2f center = sfView_getCenter(game->view);
    sfVector2f vector = getvec(center.x - 820, center.y - 390);

    sfSprite_setTextureRect(game->sprite.coin.sprite, rect);
    sfSprite_setScale(game->sprite.coin.sprite, scavector);
    sfSprite_setPosition(game->sprite.coin.sprite, vector);
    sfRenderWindow_drawSprite(window, game->sprite.coin.sprite, NULL);
    scavector = getvec(SCALE / 3, SCALE / 3);
    sfSprite_setScale(game->sprite.coin.sprite, scavector);
}
