/*
** EPITECH PROJECT, 2021
** time
** File description:
** huntet
*/

#include "../include/header.h"

void use_time(gamestruct *game, sfRenderWindow *window)
{
    float seconds;
    float gameseconds = get_seconds(game->clock.gameclock);

    if (gameseconds > 3 && game->health >= 1) {
        game->speedview += 2;
        sfClock_restart(game->clock.gameclock);
    }
    seconds = get_seconds(game->clock.dieclock);
    if (seconds > 0.5 && game->health <= 0) {
        game->speedview -= 2;
        if (game->speedview <= 0)
            game->menustate -= 1;
        sfClock_restart(game->clock.dieclock);
    }
    use_time2(game, window);
}

void use_time2(gamestruct *game, sfRenderWindow *window)
{
    float seconds = get_seconds(game->clock.viewclock);
    sfVector2f vector = getvec(game->speedview, 0);
    sfVector2f vector2 = sfView_getCenter(game->view);
    sfVector2f viewsize =
    getvec(game->rectview.width * 1, game->rectview.height * 1);

    if (seconds > 0.03) {
        if ((vector2.y + (game->rectview.height / 2)) <
        game->ymax + (2 * SCALE * 20) &&
        game->sprite.barry.isjumping == 0)
            vector.y += 10;
        if ((vector2.y + (game->rectview.height / 2)) >= game->ymax + 100 &&
        vector2.y - 250 > game->sprite.barry.pos.y && game->menuphase == 0)
            vector.y -= 10;
        use_time2bis(game, window, viewsize, vector);
        sfView_move(game->view, vector);
        sfRenderWindow_setView(window, game->view);
        sfClock_restart(game->clock.viewclock);
    }
    use_time3(game, window);
}

void use_time2bis(gamestruct *game, sfRenderWindow *window,
sfVector2f viewsize, sfVector2f vector)
{
    game->sprite.background.pos.x += vector.x;
    game->sprite.background.pos.y += vector.y;
    game->sprite.sky.pos.x += vector.x;
    game->sprite.sky.pos.y += vector.y;
    sfView_setSize(game->view, viewsize);
}

void use_time3(gamestruct *game, sfRenderWindow *window)
{
    float seconds;

    seconds = get_seconds(game->clock.bgclock);
    if (seconds > 0.04 && game->menustate == 0) {
        game->sprite.background.state += 1;
        if (game->sprite.background.state >= 1400)
            game->sprite.background.state = 0;
        sfClock_restart(game->clock.bgclock);
    }
    seconds = get_seconds(game->clock.barryclock);
    if (seconds > 0.03 && game->health >= 1 && game->menustate == 0) {
        barry_move(game);
        sfClock_restart(game->clock.barryclock);
    }
    use_time3bis(game, window);
}

void use_time3bis(gamestruct *game, sfRenderWindow *window)
{
    float seconds = get_seconds(game->clock.skyclock);

    if (seconds > 0.08) {
        game->sprite.sky.state += 1;
        if (game->sprite.sky.state >= 2400)
            game->sprite.sky.state = 0;
        sfClock_restart(game->clock.skyclock);
    }
    if (game->menustate == 0)
        use_time4(game, window);
}
