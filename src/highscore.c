/*
** EPITECH PROJECT, 2021
** highscore
** File description:
** runner
*/

#include "../include/header.h"

int get_highscore(gamestruct *game, int mode)
{
    char high_score[10];
    char *score;
    int res;
    int fd = open("src/data", O_RDWR);
    int size = read(fd, high_score, 10);

    high_score[size] = 0;
    res = getnbr(high_score);
    close(fd);
    if (mode == 1)
        return (res);
    if (mode == 0 && getnbr(high_score) < game->score) {
        score = my_itoa(game->score);
        fd = open("src/data", O_TRUNC);
        close(fd);
        fd = open("src/data", O_RDWR);
        write(fd, score, slen(score));
        close(fd);
        free(score);
    }
}
