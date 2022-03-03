/*
** EPITECH PROJECT, 2022
** rect5
** File description:
** myrunner
*/

#include "../include/header.h"

sfIntRect quitbutton_rect(int state)
{
    sfIntRect rect = create_rect(45, 45, state);

    rect.top = 1295;
    return (rect);
}

sfIntRect pausebutton_rect(int state)
{
    sfIntRect rect = create_rect(16, 21, state);

    rect.top = 1340;
    return (rect);
}

sfIntRect restartbutton_rect(int state)
{
    sfIntRect rect = create_rect(45, 45, state);

    rect.top = 1361;
    return (rect);
}

sfIntRect spitfire_rect(int state)
{
    sfIntRect rect = create_rect(209, 68, state);

    rect.top = 1406;
    return (rect);
}
