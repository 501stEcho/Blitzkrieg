/*
** EPITECH PROJECT, 2022
** button_fct2
** File description:
** myrunner
*/

#include "../include/header.h"

void display_pause(sfRenderWindow *window, gamestruct *game)
{
    sfIntRect rect;
    sfVector2f vector = sfView_getCenter(game->view);
    vector.x -= game->rectview.width / 2;
    vector.y -= game->rectview.height / 2;

    game->sprite.pausebutton.state = game->pause;
    game->sprite.pausebutton.pos.x = vector.x + 1700;
    game->sprite.pausebutton.pos.y = vector.y + 27.2;
    sfSprite_setPosition(
    game->sprite.pausebutton.sprite, game->sprite.pausebutton.pos);
    rect = adjust_rect(&pausebutton_rect, game->sprite.pausebutton.state);
    sfSprite_setTextureRect(game->sprite.pausebutton.sprite, rect);
    sfRenderWindow_drawSprite(window, game->sprite.pausebutton.sprite, NULL);
}

void display_settings(sfRenderWindow *window, gamestruct *game)
{
    sfVector2f posvec = game->sprite.settingsmenu.pos;
    sfVector2f posvec2 = game->sprite.settingsmenu.pos;
    sfVector2f vector = sfView_getCenter(game->view);
    vector.x -= game->rectview.width / 2;
    vector.y -= game->rectview.height / 2;

    game->sprite.settingsmenu.pos.x = vector.x + 850;
    game->sprite.settingsmenu.pos.y = vector.y + 70;
    posvec.y += (SCALE * 0.7) * 16;
    posvec2.y += (SCALE * 0.7) * 21;
    posvec.x += (SCALE * 0.7) * sfMusic_getVolume(game->sound.music) * 0.89 +
    (53 * SCALE * 0.7);
    posvec2.x += (SCALE * 0.7) * 57;
    sfSprite_setPosition(
    game->sprite.settingsmenu.sprite, game->sprite.settingsmenu.pos);
    sfRenderWindow_drawSprite(window, game->sprite.settingsmenu.sprite, NULL);
    game->sprite.cursor.pos = posvec;
    sfSprite_setPosition(game->sprite.musicbarre.sprite, posvec2);
    sfRenderWindow_drawSprite(window, game->sprite.musicbarre.sprite, NULL);
    display_settings2(window, game, posvec, posvec2);
}

void display_settings2(sfRenderWindow *window, gamestruct *game,
sfVector2f posvec, sfVector2f posvec2)
{
    sfSprite_setPosition(game->sprite.cursor.sprite, game->sprite.cursor.pos);
    sfRenderWindow_drawSprite(window, game->sprite.cursor.sprite, NULL);
    posvec.y += (SCALE * 0.7) * 50;
    posvec.x = game->sprite.settingsmenu.pos.x;
    posvec.x +=
    (SCALE * 0.7) * sfSound_getVolume(game->sound.coin_effect) * 0.89 +
    (53 * SCALE * 0.7);
    posvec2.y += (SCALE * 0.7) * 50;
    game->sprite.cursor.pos = posvec;
    sfSprite_setPosition(game->sprite.soundbarre.sprite, posvec2);
    sfRenderWindow_drawSprite(window, game->sprite.soundbarre.sprite, NULL);
    sfSprite_setPosition(game->sprite.cursor.sprite, game->sprite.cursor.pos);
    sfRenderWindow_drawSprite(window, game->sprite.cursor.sprite, NULL);
}

void menu_display(sfRenderWindow *window, gamestruct *game)
{
    sfIntRect rect;

    if (is_hit(window, game->sprite.menubutton.sprite)) {
        game->sprite.menubutton.state = 1;
    } else
        game->sprite.menubutton.state = 0;
    rect = adjust_rect(&menubutton_rect, game->sprite.menubutton.state);
    sfSprite_setTextureRect(game->sprite.menubutton.sprite, rect);
    sfRenderWindow_drawSprite(window, game->sprite.menubutton.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->sprite.title.sprite, NULL);
}

void display_end(sfRenderWindow *window, gamestruct *game)
{
    sfIntRect rect;

    game->sprite.restartbutton.pos.x = game->sprite.background.pos.x + 792;
    game->sprite.restartbutton.pos.y = game->sprite.background.pos.y + 392;
    sfSprite_setPosition(
    game->sprite.restartbutton.sprite, game->sprite.restartbutton.pos);
    if (is_hit(window, game->sprite.restartbutton.sprite)) {
        game->sprite.restartbutton.state = 1;
    } else
        game->sprite.restartbutton.state = 0;
    rect = adjust_rect(&restartbutton_rect, game->sprite.restartbutton.state);
    sfSprite_setTextureRect(game->sprite.restartbutton.sprite, rect);
    sfRenderWindow_drawSprite(window, game->sprite.restartbutton.sprite, NULL);
}
