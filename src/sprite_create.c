/*
** EPITECH PROJECT, 2021
** sprite_create
** File description:
** hunter
*/

#include "../include/header.h"

spritestruct create_barry(void)
{
    spritestruct barry;
    sfVector2f scavector = {SCALE / 2, SCALE / 2};
    sfVector2f posvector = {2 * SCALE * 24, 500};

    barry.speedy = -3;
    barry.speedx = 0;
    barry.state = 8;
    barry.isjumping = 0;
    barry.pos = posvector;
    barry.texture =
    sfTexture_createFromFile("sprites/runnerspritesheet.png", NULL);
    barry.sprite = sfSprite_create();
    sfSprite_setTexture(barry.sprite, barry.texture, sfTrue);
    sfSprite_setScale(barry.sprite, scavector);
    return (barry);
}

spritestruct create_road(void)
{
    spritestruct road;
    sfVector2f scavector = {SCALE, SCALE};

    road.speedy = 0;
    road.speedx = 0;
    road.state = 0;
    road.texture =
    sfTexture_createFromFile("sprites/runnerspritesheet.png", NULL);
    road.sprite = sfSprite_create();
    sfSprite_setTexture(road.sprite, road.texture, sfTrue);
    sfSprite_setScale(road.sprite, scavector);
    return (road);
}

spritestruct create_mine(void)
{
    spritestruct mine;
    sfVector2f scavector = {SCALE * 0.7, SCALE * 0.7};

    mine.speedy = 0;
    mine.speedx = 0;
    mine.state = 0;
    mine.texture =
    sfTexture_createFromFile("sprites/runnerspritesheet.png", NULL);
    mine.sprite = sfSprite_create();
    sfSprite_setTexture(mine.sprite, mine.texture, sfTrue);
    sfSprite_setScale(mine.sprite, scavector);
    return (mine);
}

spritestruct create_coin(void)
{
    spritestruct coin;
    sfVector2f scavector = {SCALE / 3, SCALE / 3};

    coin.speedy = 0;
    coin.speedx = 0;
    coin.state = 0;
    coin.texture =
    sfTexture_createFromFile("sprites/runnerspritesheet.png", NULL);
    coin.sprite = sfSprite_create();
    sfSprite_setTexture(coin.sprite, coin.texture, sfTrue);
    sfSprite_setScale(coin.sprite, scavector);
    return (coin);
}
