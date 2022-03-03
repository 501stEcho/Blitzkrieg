/*
** EPITECH PROJECT, 2021
** deinitialize
** File description:
** hunter
*/

#include "../include/header.h"

void deinitialize_time(gamestruct *game)
{
    sfClock_destroy(game->clock.gameclock);
    sfClock_destroy(game->clock.bgclock);
    sfClock_destroy(game->clock.skyclock);
    sfClock_destroy(game->clock.cycclock);
    sfClock_destroy(game->clock.jumpclock);
    sfClock_destroy(game->clock.barryclock);
    sfClock_destroy(game->clock.viewclock);
    sfClock_destroy(game->clock.dieclock);
    sfClock_destroy(game->clock.mineclock);
    sfClock_destroy(game->clock.boomclock);
    sfClock_destroy(game->clock.placeclock);
    sfClock_destroy(game->clock.coinclock);
    sfClock_destroy(game->clock.planeclock);
}

void deinitialize_sprite(gamestruct *game)
{
    sfSprite_destroy(game->sprite.background.sprite);
    sfSprite_destroy(game->sprite.sky.sprite);
    sfSprite_destroy(game->sprite.barry.sprite);
    sfSprite_destroy(game->sprite.road.sprite);
    sfSprite_destroy(game->sprite.mine.sprite);
    sfSprite_destroy(game->sprite.coin.sprite);
    sfSprite_destroy(game->sprite.title.sprite);
    sfSprite_destroy(game->sprite.menubutton.sprite);
    sfSprite_destroy(game->sprite.playbutton.sprite);
    sfSprite_destroy(game->sprite.settingsbutton.sprite);
    sfSprite_destroy(game->sprite.returnbutton.sprite);
    sfSprite_destroy(game->sprite.settingsmenu.sprite);
    sfSprite_destroy(game->sprite.musicbarre.sprite);
    sfSprite_destroy(game->sprite.soundbarre.sprite);
    sfSprite_destroy(game->sprite.cursor.sprite);
    sfSprite_destroy(game->sprite.pausebutton.sprite);
    sfSprite_destroy(game->sprite.restartbutton.sprite);
    sfSprite_destroy(game->sprite.spitfire.sprite);
}

void deinitialize_all(gamestruct *game)
{
    deinitialize_time(game);
    deinitialize_text(game);
    deinitialize_sprite(game);
    deinitialize_sound(game);
    deinitialize_game(game);
}
