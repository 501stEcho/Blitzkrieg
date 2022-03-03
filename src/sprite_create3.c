/*
** EPITECH PROJECT, 2022
** sprite_create3
** File description:
** myrunner
*/

#include "../include/header.h"

spritestruct create_settingsmenu(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE * 0.7, SCALE * 0.7};
    sfVector2f posvector = {850, 70};
    sfIntRect rect = adjust_rect(&settingsmenu_rect, 0);

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

spritestruct create_musicbarre(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE * 0.7, SCALE * 0.7};
    sfVector2f posvector = {850, 70};
    sfIntRect rect = adjust_rect(&musicbarre_rect, 0);

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

spritestruct create_soundbarre(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE * 0.7, SCALE * 0.7};
    sfVector2f posvector = {850, 70};
    sfIntRect rect = adjust_rect(&soundbarre_rect, 0);

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

spritestruct create_cursor(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE * 0.7, SCALE * 0.7};
    sfVector2f posvector = {850, 70};
    sfIntRect rect = adjust_rect(&cursor_rect, 0);

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

spritestruct create_quitbutton(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE * 0.8, SCALE * 0.8};
    sfVector2f posvector = {50, 756.8};
    sfIntRect rect = adjust_rect(&quitbutton_rect, 0);

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
