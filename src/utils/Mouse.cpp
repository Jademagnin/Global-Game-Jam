/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** Mouse
*/

#include "Mouse.hpp"

Mouse::Mouse(sf::RenderWindow &window) : _window(window) {
    this->_mouse = new AssetsLoader<sf::Sprite>("assets/mouse.png", sf::Vector2f(0, 0), sf::Vector2f(75, 75));
    this->_mousePressed = new AssetsLoader<sf::Sprite>("assets/mouse_event.png", sf::Vector2f(0, 0), sf::Vector2f(75, 75));
    this->_mouseSprite = this->_mouse->getSprite();
    this->_mouseTexture = this->_mouse->getTexture();
    window.setMouseCursorVisible(false);
}

void Mouse::processEvents(sf::Event event) {

    if (event.type == sf::Event::MouseButtonPressed) {
        _mouseTexture = _mousePressed->getTexture();
    } else if (event.type == sf::Event::MouseButtonReleased) {
        _mouseTexture = _mouse->getTexture();
    }
    _mouseSprite.setTexture(_mouseTexture);
    sf::Vector2i mousePosition = sf::Mouse::getPosition(_window);

    _mouseSprite.setPosition(static_cast<sf::Vector2f>(mousePosition) - sf::Vector2f(_mouse->getSprite().getGlobalBounds().width / 2.f, _mouse->getSprite().getGlobalBounds().height / 2.f));
}

void Mouse::render(sf::RenderWindow &window) {
    window.draw(_mouseSprite);
}
