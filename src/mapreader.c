/*
** EPITECH PROJECT, 2021
** mapreader
** File description:
** myrunner
*/

#include "../include/header.h"

void display_map(sfRenderWindow *window, char **map, gamestruct *game)
{
    int i = tabslen(map) - 2;
    sfVector2f center = sfView_getCenter(game->view);
    int j = (center.x - 900) / (24 * SCALE) - 1;

    while (i >= 0 && map[i]) {
        j = (center.x - 900) / (24 * SCALE) - 1;
        while (j < slen(map[i]) && j < (center.x + 900) / (24 * SCALE) + 1) {
            check_road(window, i, j, game);
            j++;
        }
        i--;
    }
    check_explode(game);
    check_coin(game);
    display_bomb(game, window);
    display_coin(game, window);
    display_score(game, window, 0);
    sfRenderWindow_drawSprite(window, game->sprite.spitfire.sprite, NULL);
}

void display_road(sfRenderWindow *window, int i, int j, gamestruct *game)
{
    sfVector2f vector;
    sfIntRect rect = define_rect(game->map, i, j);
    int x = (int)(game->sprite.barry.pos.x + SCALE * 9) / (SCALE * 24);

    vector.x = j * SCALE * 24;
    vector.y = i * SCALE * 20;
    sfSprite_setTextureRect(game->sprite.road.sprite, rect);
    sfSprite_setPosition(game->sprite.road.sprite, vector);
    sfRenderWindow_drawSprite(window, game->sprite.road.sprite, NULL);
}

char **create_map(char *path)
{
    FILE *fd = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_nb = 0;
    int max_len = find_maxlen2(path);
    char **map = malloc((get_linenb(path) + 1) * sizeof(char *));
    int i = 0;

    if (fd == NULL)
        return (0);
    while ((read = getline(&line, &len, fd)) != -1) {
        map[line_nb] = fill_line(map[line_nb], max_len, line);
        line_nb++;
    }
    map[line_nb] = 0;
    if (line)
        free(line);
    return (map);
}
