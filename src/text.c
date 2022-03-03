/*
** EPITECH PROJECT, 2021
** text
** File description:
** myrunner
*/

#include "../include/header.h"

textstruct create_text(void)
{
    textstruct text;

    text.font = sfFont_createFromFile("sprites/runnerfont.ttf");
    text.text = sfText_create();
    sfText_setFont(text.text, text.font);
    return (text);
}
