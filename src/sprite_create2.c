/*
** EPITECH PROJECT, 2021
** sprite_create2
** File description:
** myrunner
*/

#include "../include/header.h"

spritestruct create_title(void)
{
    spritestruct title;
    sfVector2f scavector = {SCALE, SCALE};
    sfVector2f posvector = {321, 250};
    sfIntRect rect = adjust_rect(&title_rect, 0);

    title.rect = rect;
    title.speedy = 0;
    title.speedx = 0;
    title.state = 0;
    title.pos = posvector;
    title.texture =
    sfTexture_createFromFile("sprites/runnerspritesheet.png", NULL);
    title.sprite = sfSprite_create();
    sfSprite_setTexture(title.sprite, title.texture, sfTrue);
    sfSprite_setTextureRect(title.sprite, title.rect);
    sfSprite_setPosition(title.sprite, title.pos);
    sfSprite_setScale(title.sprite, scavector);
    return (title);
}

spritestruct create_menubutton(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE, SCALE};
    sfVector2f posvector = {800, 600};

    button.speedy = 0;
    button.speedx = 0;
    button.state = 0;
    button.pos = posvector;
    button.texture =
    sfTexture_createFromFile("sprites/runnerspritesheet.png", NULL);
    button.sprite = sfSprite_create();
    sfSprite_setTexture(button.sprite, button.texture, sfTrue);
    sfSprite_setPosition(button.sprite, button.pos);
    sfSprite_setScale(button.sprite, scavector);
    return (button);
}

spritestruct create_playbutton(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE * 0.8, SCALE * 0.8};
    sfVector2f posvector = {50, 513.6};
    sfIntRect rect = adjust_rect(&playbutton_rect, 0);

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

spritestruct create_settingsbutton(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE * 0.8, SCALE * 0.8};
    sfVector2f posvector = {50, 270.4};
    sfIntRect rect = adjust_rect(&settingsbutton_rect, 0);

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

spritestruct create_returnbutton(void)
{
    spritestruct button;
    sfVector2f scavector = {SCALE * 0.8, SCALE * 0.8};
    sfVector2f posvector = {50, 27.2};
    sfIntRect rect = adjust_rect(&returnbutton_rect, 0);

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
