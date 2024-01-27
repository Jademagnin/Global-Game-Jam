/*
** EPITECH PROJECT, 2024
** src
** File description:
** Icon.cpp
*/

#include "Icon.hpp"
#include <iostream>

Icon::Icon(std::string path, Text *text, int n_frames) : Sprite(path, n_frames), _hovered(false), _moving(false), _text(text)
{
    sprite.setScale(0.2, 0.2);
}

void Icon::checkHover(sf::Vector2i mousePos)
{
    if (_moving) return;
    sf::Vector2f iconPos = sprite.getPosition();
    sf::Rect<float> rect = sprite.getGlobalBounds();
    float halfWidth = rect.width / 2;
    float halfHeight = rect.height / 2;
    if (mousePos.x >= iconPos.x - halfWidth && mousePos.x <= iconPos.x + halfWidth &&
        mousePos.y >= iconPos.y - halfHeight && mousePos.y <= iconPos.y + halfHeight + 100) {
        hover(true);
    } else {
        hover(false);
    }
}

void Icon::checkDrag(sf::Vector2i mousePos, sf::RenderWindow &window)
{
    if (sprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
        _moving = true;
    }
}

void Icon::checkMove(sf::Vector2i mousePos, sf::RenderWindow &window)
{
    if (_moving) {
        sprite.setPosition(mousePos.x, mousePos.y);
        _text->setPosition(sf::Vector2f(mousePos.x - 30, mousePos.y + 50));
    }
}

void Icon::checkDrop(sf::Vector2i mousePos, sf::RenderWindow &window)
{
    if (_moving) {
        sprite.setPosition(mousePos.x, mousePos.y);
        _text->setPosition(sf::Vector2f(mousePos.x - 30, mousePos.y + 50));
        _moving = false;
    }
}

void Icon::hover(bool hovered)
{
    if (hovered == _hovered) return;
    _hovered = hovered;
    if (_hovered)
        sprite.setScale(0.225, 0.225);
    else {
        sprite.setScale(0.2, 0.2);
        rect.left = 0;
    }
}

