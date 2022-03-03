/*
** EPITECH PROJECT, 2021
** initialize
** File description:
** runner
*/

#include "../include/header.h"

void initialize_all(gamestruct *game, sfRenderWindow *window)
{
    initialize_game(game, window);
    initialize_sprite(game);
    initialize_time(game);
    initialize_sound(game);
}

void initialize_game(gamestruct *game, sfRenderWindow *window)
{
    game->mode = 0;
    game->rectview.width = 1800;
    game->rectview.height = 1000;
    game->rectview.top = 0;
    game->rectview.left = 0;
    game->view = sfView_create();
    game->view = sfView_createFromRect(game->rectview);
    sfRenderWindow_setView(window, game->view);
    game->speedview = 10;
    game->health = 1;
    game->menustate = 2;
    game->menuphase = 1;
    game->boomtime = 0;
    game->boomswitch = 0;
    game->boompos.x = -84;
    game->boompos.y = -84;
    game->score = 0;
    game->coinscore = 0;
    game->mousereleased = 1;
    initialize_game2(game);
}

void initialize_game2(gamestruct *game)
{
    game->text = create_text();
    game->pause = 0;
    game->highscore = get_highscore(game, 1);
    create_bomblist(game, game->mode);
    create_coinlist(game, game->mode);
    game->win = 0;
}

void initialize_sprite(gamestruct *game)
{
    game->sprite.background = create_background();
    game->sprite.sky = create_sky();
    game->sprite.barry = create_barry();
    game->sprite.barry.pos = find_spawn(game->map);
    game->sprite.road = create_road();
    game->sprite.mine = create_mine();
    game->sprite.coin = create_coin();
    game->sprite.title = create_title();
    game->sprite.menubutton = create_menubutton();
    game->sprite.playbutton = create_playbutton();
    game->sprite.settingsbutton = create_settingsbutton();
    game->sprite.returnbutton = create_returnbutton();
    game->sprite.settingsmenu = create_settingsmenu();
    game->sprite.musicbarre = create_musicbarre();
    game->sprite.soundbarre = create_soundbarre();
    game->sprite.cursor = create_cursor();
    game->sprite.quitbutton = create_quitbutton();
    game->sprite.pausebutton = create_pausebutton();
    game->sprite.restartbutton = create_restartbutton();
    initialize_sprite2(game);
}

void initialize_sprite2(gamestruct *game)
{
    game->sprite.spitfire = create_spitfire();
    place_spitfire(game, game->map);
    game->sprite.barry.pos = find_spawn(game->map);
}
