/*
** EPITECH PROJECT, 2022
** preinitialize
** File description:
** myrunner
*/

#include "../include/header.h"

int preinitialize(int argc, char **argv, gamestruct *game)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        display_commentary();
        return (0);
    }
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'e') {
        game->map = get_infinitemap();
    } else if (argc == 2 && argv[1][0] != '-')
        game->map = create_map(argv[1]);
    else
        game->map = create_map("maps/map1.txt");
    if (argc == 2 || argc == 3) {
        game->barryskin = 0;
        if (argv[argc - 1][0] == '-' && argv[argc - 1][1] == 'r')
            game->barryskin = 1;
        if (argv[argc - 1][0] == '-' && argv[argc - 1][1] == 'g')
            game->barryskin = 2;
        if (argv[argc - 1][0] == '-' && argv[argc - 1][1] == 'b')
            game->barryskin = 3;
    }
    return (1);
}
