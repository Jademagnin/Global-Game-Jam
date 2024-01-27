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
}

template<typename... Funcs>
void Desktop::forEachIcon(Funcs... callbacks)
{
    for (int i = 0; i < 21; i++) {
        ([&](auto callback) { callback(_icon[i]); }(callbacks), ...);
    } 
    //when we wrote this, only god and we knew what it was
    //now, only god knows
}

void Desktop::processEvents(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        forEachIcon([&](Icon* icon) {
            icon->checkDrag(sf::Mouse::getPosition(_window), _window);
        });
    } else if (event.type == sf::Event::MouseMoved) {
        forEachIcon([&](Icon* icon) {
            icon->checkMove(sf::Mouse::getPosition(_window), _window);
            icon->checkHover(sf::Mouse::getPosition(_window));
        });
    } else if (event.type == sf::Event::MouseButtonReleased) {
        forEachIcon([&](Icon* icon) {
            icon->checkDrop(sf::Mouse::getPosition(_window), _window);
        });
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
        std::cout << "Right click" << std::endl;
    }
    
}
