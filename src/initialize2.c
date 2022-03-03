/*
** EPITECH PROJECT, 2022
** initialize2
** File description:
** myrunner
*/

#include "../include/header.h"

void initialize_time(gamestruct *game)
{
    game->clock.gameclock = sfClock_create();
    game->clock.skyclock = sfClock_create();
    game->clock.bgclock = sfClock_create();
    game->clock.cycclock = sfClock_create();
    game->clock.jumpclock = sfClock_create();
    game->clock.barryclock = sfClock_create();
    game->clock.viewclock = sfClock_create();
    game->clock.dieclock = sfClock_create();
    game->clock.mineclock = sfClock_create();
    game->clock.boomclock = sfClock_create();
    game->clock.placeclock = sfClock_create();
    game->clock.coinclock = sfClock_create();
    game->clock.planeclock = sfClock_create();
}

void initialize_sound(gamestruct *game)
{
    game->sound.soundbuffer =
    sfSoundBuffer_createFromFile("sprites/coin_effect.wav");
    game->sound.coin_effect = sfSound_create();
    sfSound_setBuffer(game->sound.coin_effect, game->sound.soundbuffer);
    game->sound.music = sfMusic_createFromFile("sprites/music.wav");
    sfMusic_setLoop(game->sound.music, sfTrue);
}
