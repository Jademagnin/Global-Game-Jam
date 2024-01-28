/*
** EPITECH PROJECT, 2024
** src
** File description:
** Icon.cpp
*/

#include "Icon.hpp"
#include <iostream>
#include "../text/Text.hpp"

std::vector<std::string> formatLabel(std::string label)
{
    std::vector<std::string> lines;
    std::string line = "";
    int i = 0;
    while (i < label.size()) {
        if (label[i] == ' ') {
            lines.push_back(line);
            line = "";
        } else {
            line += label[i];
        }
        i++;
    }
    lines.push_back(line);
    return lines;
}

Icon::Icon(std::string path, const std::string label, std::shared_ptr<Scene> scene,int n_frames) : Sprite(path, n_frames), _hovered(false), _moving(false), _label(label), _scene(scene)
{
    _text = new TextArray(formatLabel(label), sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + 20), 15, sf::Color::White);
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
        mousePos.y >= iconPos.y - halfHeight + 20 && mousePos.y <= iconPos.y + halfHeight) {
        hover(true);
    } else {
        hover(false);
    }
}

bool Icon::checkDrag(sf::Vector2i mousePos, sf::RenderWindow &window)
{
    if (sprite.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
        _moving = true;
        return true;
    }
    return false;
}

void Icon::checkMove(sf::Vector2i mousePos, sf::RenderWindow &window)
{
    (void)window;
    if (_moving) {
        this->setPosition(window.mapPixelToCoords(mousePos));
    }
}

void Icon::checkDrop(sf::Vector2i mousePos, sf::RenderWindow &window)
{
    (void)window;
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

