/*
** EPITECH PROJECT, 2024
** src
** File description:
** Icon.cpp
*/

#include "Icon.hpp"
#include <iostream>

Icon::Icon(std::string path) : Sprite(path), _hovered(false), _moving(false)
{
    sprite.setScale(0.2, 0.2);
}

void Icon::checkHover(sf::Vector2i mousePos)
{
    if (_moving) return;
    sf::Vector2f iconPos = sprite.getPosition();
    if (mousePos.x >= iconPos.x && mousePos.x <= iconPos.x + 100 &&
        mousePos.y >= iconPos.y && mousePos.y <= iconPos.y + 100) {
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
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sprite.setPosition(mousePos.x, mousePos.y);
    }
}

void Icon::checkDrop(sf::Vector2i mousePos, sf::RenderWindow &window)
{
    if (_moving) {
        sprite.setPosition(mousePos.x, mousePos.y);
        _moving = false;
    }
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

