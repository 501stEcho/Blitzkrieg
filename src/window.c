/*
** EPITECH PROJECT, 2021
** window
** File description:
** bshunter
*/

#include "../include/header.h"

int main(int argc, char **argv)
{
    int length = 1800;
    int height = 1000;
    gamestruct game;
    sfRenderWindow *window;
    sfEvent event;

    if (preinitialize(argc, argv, &game) == 0)
        return (0);
    window = create_window(length, height);
    if (!window)
        return (EXIT_FAILURE);
    initialize_all(&game, window);
    give_skin(&game);
    srand(time(NULL));
    while (sfRenderWindow_isOpen(window)) {
        analyse_event(window, event, &game);
        menu_selecter(window, &game, event);
    }
    deinitialize_all(&game);
}

void analyse_event(sfRenderWindow *window, sfEvent event, gamestruct *game)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            close_window(window);
        if (event.type == sfEvtMouseButtonPressed)
            game->mousereleased = 0;
        if (event.type == sfEvtMouseButtonReleased)
            game->mousereleased = 1;
        if (game->mousereleased == 0)
            manage_mouse_click(event.mouseButton, game, window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace &&
        game->sprite.barry.isjumping == 0 && game->menuphase == 0) {
            game->sprite.barry.isjumping = 1;
            game->sprite.barry.speedy = -60;
        }
    }
}

void actions(sfRenderWindow *window, gamestruct *game)
{
    if (game->pause == 0)
        use_time(game, window);
}

sfRenderWindow *create_window(int length, int height)
{
    sfRenderWindow *window;

    sfVideoMode mode = {length, height, 32};
    sfUint32 options = sfResize | sfClose;
    window = sfRenderWindow_create(mode, "blitzkrieg2.exe", options, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
