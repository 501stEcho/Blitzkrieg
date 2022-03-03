/*
** EPITECH PROJECT, 2022
** mouse_selecter2
** File description:
** myrunner
*/

#include "../include/header.h"

void manage_mouse_pause(sfRenderWindow *window, gamestruct *game)
{
    if (is_hit(window, game->sprite.pausebutton.sprite) == 1) {
        if (game->pause == 0) {
            game->pause = 1;
        } else if (game->pause == 1)
            game->pause = 0;
    }
}

void manage_mouse_end(sfRenderWindow *window, gamestruct *game)
{
    if (is_hit(window, game->sprite.restartbutton.sprite) == 1) {
        deinitialize_all(game);
        initialize_all(game, window);
        sfMusic_play(game->sound.music);
        game->menustate = 0;
    }
}

void manage_mouse_begin(sfRenderWindow *window, gamestruct *game)
{
    if (is_hit(window, game->sprite.menubutton.sprite) == 1)
        game->menustate = 1;
}
