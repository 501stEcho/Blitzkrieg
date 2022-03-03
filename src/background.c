/*
** EPITECH PROJECT, 2021
** background
** File description:
** hunter
*/

#include "../include/header.h"

spritestruct create_background(void)
{
    spritestruct background;
    sfVector2f vector = {3, 3};
    sfVector2f posvector = {0, 0};
    sfIntRect rect = adjust_rect(&background_rect, 0);

    background.rect = rect;
    background.state = 0;
    background.sprite = sfSprite_create();
    background.pos = posvector;
    background.texture =
    sfTexture_createFromFile("sprites/runnerspritesheet.png", NULL);
    sfSprite_setTexture(background.sprite, background.texture, sfTrue);
    sfSprite_setTextureRect(background.sprite, background.rect);
    sfTexture_setRepeated(background.texture, sfTrue);
    return (background);
}

spritestruct create_sky(void)
{
    spritestruct sky;
    sfVector2f vector = {3, 3};
    sfVector2f posvector = {0, 0};
    sfIntRect rect = adjust_rect(&sky_rect, 0);

    sky.rect = rect;
    sky.state = 0;
    sky.sprite = sfSprite_create();
    sky.pos = posvector;
    sky.texture =
    sfTexture_createFromFile("sprites/runnerspritesheet.png", NULL);
    sfSprite_setTexture(sky.sprite, sky.texture, sfTrue);
    sfSprite_setTextureRect(sky.sprite, sky.rect);
    sfTexture_setRepeated(sky.texture, sfTrue);
    return (sky);
}

void background_display(sfRenderWindow *window, gamestruct *game)
{
    sfVector2f posvector = sfView_getCenter(game->view);
    sfVector2f scavector = {3, 3};

    posvector.x -= game->rectview.width / 2;
    posvector.y -= game->rectview.height / 2;
    sfSprite_setTextureRect(
    game->sprite.background.sprite, game->sprite.background.rect);
    sfSprite_setPosition(game->sprite.background.sprite, posvector);
    sfSprite_setScale(game->sprite.background.sprite, scavector);
    game->sprite.background.rect.left = game->sprite.background.state;
    sfRenderWindow_drawSprite(window, game->sprite.background.sprite, NULL);
}

void sky_display(sfRenderWindow *window, gamestruct *game)
{
    sfVector2f posvector = sfView_getCenter(game->view);
    sfVector2f scavector = {3, 3};

    posvector.x -= game->rectview.width / 2;
    posvector.y -= game->rectview.height / 2;
    sfSprite_setTextureRect(game->sprite.sky.sprite, game->sprite.sky.rect);
    sfSprite_setPosition(game->sprite.sky.sprite, posvector);
    sfSprite_setScale(game->sprite.sky.sprite, scavector);
    game->sprite.sky.rect.left = game->sprite.sky.state;
    sfRenderWindow_drawSprite(window, game->sprite.sky.sprite, NULL);
}
