/*
** EPITECH PROJECT, 2021
** mouse_selecter
** File description:
** hunter
*/

#include "../include/header.h"

void manage_mouse_click(
sfMouseButtonEvent event, gamestruct *game, sfRenderWindow *window)
{
    if (game->menustate == 2)
        manage_mouse_begin(window, game);
    if ((game->menustate != 2 && game->menustate >= 0) || game->pause == 1)
        manage_mouse_select(window, game);
    if (game->menustate == 10 || game->pause == 1)
        manage_mouse_settings(window, game);
    if (game->menustate == 0)
        manage_mouse_pause(window, game);
    if (game->menustate == -1)
        manage_mouse_end(window, game);
}

void manage_mouse_settings(sfRenderWindow *window, gamestruct *game)
{
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(window);

    if (is_hit(window, game->sprite.musicbarre.sprite) == 1) {
        sfMusic_setVolume(
        game->sound.music, (mousepos.x - 1090) * 0.26809651474);
    }
    if (is_hit(window, game->sprite.soundbarre.sprite) == 1) {
        sfSound_setVolume(
        game->sound.coin_effect, (mousepos.x - 1090) * 0.26809651474);
    }
}

void manage_mouse_select(sfRenderWindow *window, gamestruct *game)
{
    if (is_hit(window, game->sprite.quitbutton.sprite) == 1)
        sfRenderWindow_close(window);
    if (is_hit(window, game->sprite.playbutton.sprite) == 1 &&
    game->pause == 0) {
        game->menustate = 0;
        sfMusic_play(game->sound.music);
    }
    if (is_hit(window, game->sprite.settingsbutton.sprite) == 1 &&
    game->pause == 0)
        game->menustate = 10;
    manage_mouse_select2(window, game);
}

void manage_mouse_select2(sfRenderWindow *window, gamestruct *game)
{
    if (is_hit(window, game->sprite.returnbutton.sprite) == 1 &&
    game->menustate <= 2) {
        if (game->menustate == 0) {
            restart(game, window);
        }
        game->menustate += 1;
        game->pause = 0;
    } else if (is_hit(window, game->sprite.returnbutton.sprite) == 1) {
        game->menustate = 2;
        game->pause = 0;
    }
}
