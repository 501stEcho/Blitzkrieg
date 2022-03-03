/*
** EPITECH PROJECT, 2022
** tools5
** File description:
** myrunner
*/

#include "../include/header.h"

int is_in(char elem, char *list)
{
    int i = 0;

    while (list[i]) {
        if (elem == list[i]) {
            return (1);
        }
        i++;
    }
    return (0);
}

int place_spitfire(gamestruct *game, char **map)
{
    int maxlen = find_maxlen(map) - 2;
    int i = 0;
    int len = 0;

    while (map[len++]);
    while (maxlen >= 0) {
        if (map[i][maxlen] == ' ' && map[i + 1][maxlen] == '1') {
            game->sprite.spitfire.pos.x = maxlen * SCALE * 24;
            game->sprite.spitfire.pos.y = i * SCALE * 20;
            sfSprite_setPosition(
            game->sprite.spitfire.sprite, game->sprite.spitfire.pos);
            return (0);
        }
        if (i + 2 == len) {
            i = -1;
            maxlen--;
        }
        i++;
    }
    return (0);
}

int collide(sfSprite *sprite1, sfSprite *sprite2)
{
    const sfFloatRect rect1 = sfSprite_getGlobalBounds(sprite1);
    const sfFloatRect rect2 = sfSprite_getGlobalBounds(sprite2);

    if (sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue)
        return (1);
    return (0);
}

void check_window_size(sfRenderWindow *window)
{
    sfVector2u vector = sfRenderWindow_getSize(window);
    sfVector2u sizevec = vector;

    if (vector.x < 800)
        sizevec.x = 800;
    if (vector.x > 1920)
        sizevec.x = 1920;
    if (vector.y < 600)
        sizevec.y = 600;
    if (vector.y > 1080)
        sizevec.y = 1080;
    sfRenderWindow_setSize(window, sizevec);
}

int get_linenb(char *path)
{
    FILE *fd = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_nb = 0;

    while ((read = getline(&line, &len, fd)) != -1)
        line_nb++;
    return (line_nb);
}
