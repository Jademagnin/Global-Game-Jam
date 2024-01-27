/*
** EPITECH PROJECT, 2024
** src
** File description:
** Icon.cpp
*/

#include "Icon.hpp"
#include <iostream>

Icon::Icon(std::string path) : Sprite(path)
{
    sprite.setScale(0.2, 0.2);
}

void Icon::hover(bool hovered)
{
    if (hovered == _hovered) return;
    _hovered = hovered;
    if (_hovered)
        sprite.setScale(0.225, 0.225);
    else
        sprite.setScale(0.2, 0.2);
}
