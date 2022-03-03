/*
** EPITECH PROJECT, 2022
** deinitialize2
** File description:
** myrunner
*/

#include "../include/header.h"

void deinitialize_text(gamestruct *game)
{
    sfText_destroy(game->text.text);
    sfFont_destroy(game->text.font);
}

void deinitialize_sound(gamestruct *game)
{
    sfMusic_destroy(game->sound.music);
    sfSound_destroy(game->sound.coin_effect);
    sfSoundBuffer_destroy(game->sound.soundbuffer);
}

void deinitialize_game(gamestruct *game)
{
    free(game->bomblist);
    free(game->coinlist);
}
