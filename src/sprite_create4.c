/*
** EPITECH PROJECT, 2022
** sprite_create4
** File description:
** myrunner
*/

#include "../include/header.h"

spritestruct create_pausebutton(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE * 0.8, SCALE * 0.8};
    sfVector2f posvector = {800, 27.2};
    sfIntRect rect = adjust_rect(&pausebutton_rect, 0);

    button.speedy = 0;
    button.speedx = 0;
    button.state = 0;
    button.pos = posvector;
    button.texture =
    sfTexture_createFromFile("sprites/runnerspritesheet.png", NULL);
    button.sprite = sfSprite_create();
    sfSprite_setTexture(button.sprite, button.texture, sfTrue);
    sfSprite_setTextureRect(button.sprite, rect);
    sfSprite_setPosition(button.sprite, button.pos);
    sfSprite_setScale(button.sprite, scavector);
    return (button);
}

spritestruct create_restartbutton(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE * 0.8, SCALE * 0.8};
    sfVector2f posvector = {500, 392};
    sfIntRect rect = adjust_rect(&restartbutton_rect, 0);

    button.speedy = 0;
    button.speedx = 0;
    button.state = 0;
    button.pos = posvector;
    button.texture =
    sfTexture_createFromFile("sprites/runnerspritesheet.png", NULL);
    button.sprite = sfSprite_create();
    sfSprite_setTexture(button.sprite, button.texture, sfTrue);
    sfSprite_setTextureRect(button.sprite, rect);
    sfSprite_setPosition(button.sprite, button.pos);
    sfSprite_setScale(button.sprite, scavector);
    return (button);
}

spritestruct create_spitfire(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE * -0.6, SCALE * 0.6};
    sfVector2f posvector = {500, 392};
    sfIntRect rect = adjust_rect(&spitfire_rect, 0);

    button.speedy = 0;
    button.speedx = 0;
    button.state = 0;
    button.pos = posvector;
    button.texture =
    sfTexture_createFromFile("sprites/runnerspritesheet.png", NULL);
    button.sprite = sfSprite_create();
    sfSprite_setTexture(button.sprite, button.texture, sfTrue);
    sfSprite_setTextureRect(button.sprite, rect);
    sfSprite_setPosition(button.sprite, button.pos);
    sfSprite_setScale(button.sprite, scavector);
    return (button);
}
