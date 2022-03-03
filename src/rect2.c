/*
** EPITECH PROJECT, 2022
** rect2
** File description:
** myrunner
*/

#include "../include/header.h"

sfIntRect background_rect(int state)
{
    sfIntRect rect = create_rect(1000, 400, state);

    rect.top = 0;
    return (rect);
}

sfIntRect sky_rect(int state)
{
    sfIntRect rect = create_rect(1000, 400, state);

    rect.top = 400;
    return (rect);
}

sfIntRect road_rect(int state)
{
    sfIntRect rect = create_rect(30, 28, state);

    rect.top = 766;
    return (rect);
}

sfIntRect mine_rect(int state)
{
    sfIntRect rect = create_rect(46, 43, state);

    rect.top = 794;
    return (rect);
}

sfIntRect barry_rect(int state)
{
    sfIntRect rect = create_rect(45, 60, state);

    rect.top = 837;
    return (rect);
}
