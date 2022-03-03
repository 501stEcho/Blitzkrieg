/*
** EPITECH PROJECT, 2022
** rect3
** File description:
** myrunner
*/

#include "../include/header.h"

sfIntRect coin_rect(int state)
{
    sfIntRect rect = create_rect(45, 45, state);

    rect.top = 897;
    return (rect);
}

sfIntRect title_rect(int state)
{
    sfIntRect rect = create_rect(194, 29, 0);

    rect.top = 942;
    return (rect);
}

sfIntRect menubutton_rect(int state)
{
    sfIntRect rect = create_rect(25, 25, state);

    rect.top = 971;
    return (rect);
}

sfIntRect playbutton_rect(int state)
{
    sfIntRect rect = create_rect(45, 45, state);

    rect.top = 996;
    return (rect);
}

sfIntRect settingsbutton_rect(int state)
{
    sfIntRect rect = create_rect(45, 45, state);

    rect.top = 1041;
    return (rect);
}
