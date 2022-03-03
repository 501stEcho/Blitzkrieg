/*
** EPITECH PROJECT, 2021
** time2
** File description:
** runner
*/

#include "../include/header.h"

void use_time4(gamestruct *game, sfRenderWindow *window)
{
    float seconds;

    seconds = get_seconds(game->clock.cycclock);
    if (seconds > 0.03 &&
    (game->sprite.barry.state == 1 || game->sprite.barry.state == 3)) {
        barry_cycle(game);
        sfClock_restart(game->clock.cycclock);
    } else if (seconds > 0.06) {
        barry_cycle(game);
        sfClock_restart(game->clock.cycclock);
    }
    use_time4bis(game, window);
}

void use_time4bis(gamestruct *game, sfRenderWindow *window)
{
    float seconds = get_seconds(game->clock.jumpclock);

    if (seconds > 0.03) {
        if (game->menuphase == 1)
            game->sprite.barry.speedy = 6;
        else if (game->sprite.barry.pos.y < game->ymax) {
            game->sprite.barry.speedy += 6;
        } else
            game->sprite.barry.speedy = -3;
        sfClock_restart(game->clock.jumpclock);
    }
    use_time5(game, window);
}

void use_time5(gamestruct *game, sfRenderWindow *window)
{
    float seconds;

    seconds = get_seconds(game->clock.mineclock);
    if (seconds > 0.1)
        clignote(game, 1);
    if (seconds > 0.8) {
        clignote(game, 0);
        sfClock_restart(game->clock.mineclock);
    }
    seconds = get_seconds(game->clock.placeclock);
    if (seconds > 0.5 && game->mode == 1) {
        handle_bomb(game);
        handle_coin(game);
        sfClock_restart(game->clock.placeclock);
    }
    use_time6(game, window);
}

void use_time6(gamestruct *game, sfRenderWindow *window)
{
    float seconds;

    seconds = get_seconds(game->clock.boomclock);
    if (seconds > 0.1) {
        clignote(game, 2);
        sfClock_restart(game->clock.boomclock);
    }
    seconds = get_seconds(game->clock.coinclock);
    if (seconds > 0.001)
        coin_cycle(game, 1);
    if (seconds > 0.07) {
        coin_cycle(game, 0);
        sfClock_restart(game->clock.coinclock);
    }
    use_time7(game, window);
}

void use_time7(gamestruct *game, sfRenderWindow *window)
{
    float seconds;

    seconds = get_seconds(game->clock.boomclock);
    if (seconds > 0.01) {
        plane_cycle(game);
        if (game->win == 1)
            plane_move(game);
        sfClock_restart(game->clock.planeclock);
    }
}
