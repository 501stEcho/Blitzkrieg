/*
** EPITECH PROJECT, 2021
** miscellaneous
** File description:
** myhunter
*/

#include "../include/header.h"

int display_commentary(void)
{
    FILE *fd = fopen("src/commentary.txt", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (fd == NULL)
        return (0);
    while ((read = getline(&line, &len, fd)) != -1) {
        my_putstr(line);
    }
    if (line)
        free(line);
    return (1);
}
