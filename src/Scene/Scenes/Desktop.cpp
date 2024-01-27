/*
** EPITECH PROJECT, 2024
** Scenes
** File description:
** Desktop.cpp
*/

#include "Desktop.hpp"
#include <iostream>

Desktop::Desktop(sf::RenderWindow &window) : _window(window)
{
    int row = 0;
    int col = 0;
    for (int i = 0; i < 21; i++) {
        _icon[i] = new Icon("folder.png");
        _pos[i] = sf::Vector2f(50 + (col * 128), 50 + (row * 128));
        _icon[i]->sprite.setPosition(_pos[i]);
        row++;
        if (row == 7) {
            row = 0;
            col++;
        }
    }
}

Desktop::~Desktop()
{
    for (int i = 0; i < 21; i++) {
        delete _icon[i];
    }
}


void Desktop::render(sf::RenderWindow &window)
{
    for (int i = 0; i < 21; i++) {
        window.draw(_icon[i]->sprite);
    }
}

void Desktop::update(sf::Time deltaTime)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
    for (int i = 0; i < 21; i++) {
        sf::Vector2f iconPos = _icon[i]->sprite.getPosition();
        if (mousePos.x >= iconPos.x && mousePos.x <= iconPos.x + 100 &&
            mousePos.y >= iconPos.y && mousePos.y <= iconPos.y + 100) {
            _icon[i]->hover(true);
        } else {
            _icon[i]->hover(false);
        }
    }
}
