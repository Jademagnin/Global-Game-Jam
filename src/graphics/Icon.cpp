/*
** EPITECH PROJECT, 2024
** src
** File description:
** Icon.cpp
*/

#include "Icon.hpp"
#include <iostream>
#include "../text/Text.hpp"

Icon::Icon(std::string path, const std::string label, int n_frames) : Sprite(path, n_frames), _hovered(false), _moving(false)
{
    _text = new Text(label, sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + 50), 15, sf::Color::White);
    _text->setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + 50));
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
        mousePos.y >= iconPos.y - halfHeight && mousePos.y <= iconPos.y + halfHeight) {
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
        this->setPosition(window.mapPixelToCoords(mousePos));
    }
}

void Icon::checkDrop(sf::Vector2i mousePos, sf::RenderWindow &window)
{
    if (_moving) {
        this->setPosition(window.mapPixelToCoords(mousePos));
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

