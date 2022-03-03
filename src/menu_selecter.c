/*
** EPITECH PROJECT, 2021
** menuselecter
** File description:
** hunter
*/

#include "../include/header.h"

void menu_selecter(sfRenderWindow *window, gamestruct *game, sfEvent event)
{
    sfVector2f vector = find_spawn(game->map);
    sfVector2f center = {900, 500};

    sfRenderWindow_clear(window, sfBlack);
    check_window_size(window);
    sky_display(window, game);
    if (game->menustate != 0)
        use_time3(game, window);
    if (game->menustate == 0)
        handle_main(window, game);
    if (game->menustate == -1) {
        background_display(window, game);
        display_map(window, game->map, game);
        display_score(game, window, 1);
    }
    display_button(window, game);
    get_highscore(game, 0);
    game->highscore = get_highscore(game, 1);
    sfRenderWindow_display(window);
}

void handle_main(sfRenderWindow *window, gamestruct *game)
{
    background_display(window, game);
    display_map(window, game->map, game);
    update_score(game);
    game->ymax = get_posy(game->map, game);
    game->xmax = get_posx(game->map, game);
    if (game->health >= 1)
        display_barry(window, game);
    actions(window, game);
    plane_display(game, window);
}
