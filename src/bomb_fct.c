/*
** EPITECH PROJECT, 2021
** bomb_fct
** File description:
** runner
*/

#include "../include/header.h"

void create_bomblist(gamestruct *game, int mode)
{
    int i = 0;
    sfVector2f posvector = {0, 0};
    int count;

    if (mode == 0)
        count = count_items(game->map, 0);
    if (mode == 1)
        count = 4;
    game->bomblist = malloc((count + 1) * sizeof(entitystruct));
    while (i < count) {
        game->bomblist[i].state = 0;
        game->bomblist[i].check = 0;
        game->bomblist[i].alive = (mode == 0 ? 1 : 0);
        i++;
    }
    game->bomblist[i].check = 1;
    if (mode == 0)
        fill_bomblist(game, game->map);
}

void handle_bomb(gamestruct *game)
{
    int i = 0;
    sfVector2f center = sfView_getCenter(game->view);

    while (game->bomblist[i].check == 0) {
        if (game->bomblist[i].pos.x < center.x - 900 - (SCALE * 0.7) * 45) {
            game->bomblist[i].alive = 0;
        }
        i++;
    }
    i = 0;
    while (game->bomblist[i].check == 0) {
        if (game->bomblist[i].alive == 0) {
            place_bomb(game, game->map, &(game->bomblist[i]));
        }
        i++;
    }
}

void clignote(gamestruct *game, int flag)
{
    int i = 0;

    while (game->bomblist[i].check == 0) {
        if (flag == 0 && game->bomblist[i].state == 0)
            game->bomblist[i].state = 1;
        if (flag == 1 && game->bomblist[i].state == 1)
            game->bomblist[i].state = 0;
        if (flag == 2 && game->bomblist[i].state > 1 &&
        game->bomblist[i].state < 4)
            game->bomblist[i].state += 1;
        i++;
    }
}

int place_bomb(gamestruct *game, char **map, entitystruct *bomb)
{
    sfVector2f center = sfView_getCenter(game->view);
    int i = 0;
    int j = (center.x + 1200) / (24 * SCALE);
    int compt = 0;
    int proba = rand() % (int)(1000 / game->speedview);

    if (proba > 2)
        return (0);
    while (map[i + 1][j] && map[i + 1][j] != '1') {
        i++;
    }
    if (map[i + 1][j] == '1' && check_pos(game, i, j, 0) == 1) {
        bomb->pos.y = i * 20 * SCALE + 7 * SCALE;
        bomb->pos.x = j * 24 * SCALE;
        bomb->alive = 1;
        bomb->state = 0;
    }
}

void display_bomb(gamestruct *game, sfRenderWindow *window)
{
    int i = 0;
    sfIntRect rect;

    while (game->bomblist[i].check == 0) {
        rect = adjust_rect(&mine_rect, game->bomblist[i].state);
        sfSprite_setTextureRect(game->sprite.mine.sprite, rect);
        sfSprite_setPosition(game->sprite.mine.sprite, game->bomblist[i].pos);
        if (game->bomblist[i].alive == 1)
            sfRenderWindow_drawSprite(window, game->sprite.mine.sprite, NULL);
        i++;
    }
}
