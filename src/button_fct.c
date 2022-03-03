/*
** EPITECH PROJECT, 2021
** button_fct
** File description:
** myrunner
*/

#include "../include/header.h"

void display_button(sfRenderWindow *window, gamestruct *game)
{
    if (game->menustate == 2)
        menu_display(window, game);
    if (game->menustate == 1 || game->menustate == 10 || game->pause == 1)
        display_selection(window, game);
    if (game->menustate == 10 || game->pause == 1)
        display_settings(window, game);
    if (game->menustate == 0)
        display_pause(window, game);
    if (game->menustate == -1)
        display_end(window, game);
}

void display_selection(sfRenderWindow *window, gamestruct *game)
{
    sfIntRect rect;
    sfVector2f vector = game->sprite.sky.pos;

    if (is_hit(window, game->sprite.playbutton.sprite)) {
        game->sprite.playbutton.state = 1;
    } else
        game->sprite.playbutton.state = 0;
    game->sprite.playbutton.pos = getvec(vector.x + 50, vector.y + 513.6);
    rect = adjust_rect(&playbutton_rect, game->sprite.playbutton.state);
    sfSprite_setTextureRect(game->sprite.playbutton.sprite, rect);
    if (game->pause == 0)
        sfRenderWindow_drawSprite(
        window, game->sprite.playbutton.sprite, NULL);
    display_selection2(window, game);
}

void display_selection2(sfRenderWindow *window, gamestruct *game)
{
    sfIntRect rect;
    sfVector2f vector = game->sprite.background.pos;

    if (is_hit(window, game->sprite.settingsbutton.sprite) ||
    game->menustate == 10) {
        game->sprite.settingsbutton.state = 1;
    } else
        game->sprite.settingsbutton.state = 0;
    game->sprite.settingsbutton.pos = getvec(vector.x + 50, vector.y + 270.4);
    rect =
    adjust_rect(&settingsbutton_rect, game->sprite.settingsbutton.state);
    sfSprite_setTextureRect(game->sprite.settingsbutton.sprite, rect);
    if (game->pause == 0)
        sfRenderWindow_drawSprite(
        window, game->sprite.settingsbutton.sprite, NULL);
    display_selection3(window, game);
}

void display_selection3(sfRenderWindow *window, gamestruct *game)
{
    sfIntRect rect;
    sfVector2f vector = sfView_getCenter(game->view);
    vector.x -= game->rectview.width / 2;
    vector.y -= game->rectview.height / 2;

    if (is_hit(window, game->sprite.returnbutton.sprite)) {
        game->sprite.returnbutton.state = 1;
    } else
        game->sprite.returnbutton.state = 0;
    game->sprite.returnbutton.pos.x = vector.x + 50;
    game->sprite.returnbutton.pos.y = vector.y + 27.2;
    sfSprite_setPosition(
    game->sprite.returnbutton.sprite, game->sprite.returnbutton.pos);
    rect = adjust_rect(&returnbutton_rect, game->sprite.returnbutton.state);
    sfSprite_setTextureRect(game->sprite.returnbutton.sprite, rect);
    sfRenderWindow_drawSprite(window, game->sprite.returnbutton.sprite, NULL);
    display_selection4(window, game);
}

void display_selection4(sfRenderWindow *window, gamestruct *game)
{
    sfIntRect rect;
    sfVector2f vector = sfView_getCenter(game->view);
    vector.x -= game->rectview.width / 2;
    vector.y -= game->rectview.height / 2;

    if (is_hit(window, game->sprite.quitbutton.sprite)) {
        game->sprite.quitbutton.state = 1;
    } else
        game->sprite.quitbutton.state = 0;
    game->sprite.quitbutton.pos.x = vector.x + 50;
    game->sprite.quitbutton.pos.y = vector.y + 756.8;
    sfSprite_setPosition(
    game->sprite.quitbutton.sprite, game->sprite.quitbutton.pos);
    rect = adjust_rect(&quitbutton_rect, game->sprite.quitbutton.state);
    sfSprite_setTextureRect(game->sprite.quitbutton.sprite, rect);
    sfRenderWindow_drawSprite(window, game->sprite.quitbutton.sprite, NULL);
}
