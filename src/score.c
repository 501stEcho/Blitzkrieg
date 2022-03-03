/*
** EPITECH PROJECT, 2021
** score
** File description:
** myrunner
*/

#include "../include/header.h"

void update_score(gamestruct *game)
{
    int x = (int)game->sprite.barry.pos.x / (24 * SCALE);

    game->score = x;
}

void display_score(gamestruct *game, sfRenderWindow *window, int flag)
{
    sfVector2f center = sfView_getCenter(game->view);
    sfVector2f vector = center;
    sfVector2f scavector = {1, 1};
    int size = 150;

    display_score1(game, window, flag);
    display_highscore(game, window, flag);
    display_coinscore(game, window, flag);
    scavector = getvec(SCALE / 3, SCALE / 3);
    sfSprite_setScale(game->sprite.coin.sprite, scavector);
    if (flag == 1) {
        if (game->win == 0) {
            vector = getvec(center.x - 180, center.y - 350);
            format_text(game->text.text, sfRed, size, "FAILED");
        } else {
            vector = getvec(center.x - 300, vector.y - 350);
            format_text(game->text.text, sfGreen, size, "COMPLETED");
        }
        print_text(window, game->text.text, vector);
    }
}

void display_score1(gamestruct *game, sfRenderWindow *window, int flag)
{
    sfColor color = sfColor_fromRGBA(255, 255, 255, 255);
    sfVector2f center = sfView_getCenter(game->view);
    sfVector2f vector = center;
    char *score = get_score(game->score, 0);
    int size = 0;

    if (flag == 1) {
        vector.x = center.x - 400;
        vector.y = center.y - 100;
        size = 150;
    } else {
        vector.x = center.x - 880;
        vector.y = center.y - 500;
        size = 80;
    }
    format_text(game->text.text, color, size, score);
    print_text(window, game->text.text, vector);
    free(score);
}

void display_highscore(gamestruct *game, sfRenderWindow *window, int flag)
{
    sfColor color = sfColor_fromRGBA(255, 255, 255, 255);
    sfVector2f center = sfView_getCenter(game->view);
    sfVector2f vector = center;
    char *score;
    int size = 0;

    if (flag == 1) {
        vector = getvec(center.x + 200, center.y - 100);
        score = get_score(game->highscore, 0);
        size = 150;
    } else {
        vector = getvec(center.x - 880, center.y - 420);
        score = get_score(game->highscore, 1);
        size = 30;
    }
    format_text(game->text.text, color, size, score);
    print_text(window, game->text.text, vector);
    free(score);
}
