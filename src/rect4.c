/*
** EPITECH PROJECT, 2022
** rect4
** File description:
** myrunner
*/

#include "../include/header.h"

sfIntRect returnbutton_rect(int state)
{
    sfIntRect rect = create_rect(45, 45, state);

    rect.top = 1086;
    return (rect);
}

sfIntRect settingsmenu_rect(int state)
{
    sfIntRect rect = create_rect(170, 96, state);

    rect.top = 1131;
    return (rect);
}

sfIntRect musicbarre_rect(int state)
{
    sfIntRect rect = create_rect(89, 5, state);

    rect.top = 1227;
    return (rect);
}

sfIntRect soundbarre_rect(int state)
{
    sfIntRect rect = create_rect(89, 5, state);

    rect.top = 1232;
    return (rect);
}

sfIntRect cursor_rect(int state)
{
    sfIntRect rect = create_rect(5, 13, state);

    rect.top = 1282;
    return (rect);
}
