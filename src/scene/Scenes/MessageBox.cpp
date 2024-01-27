/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** MessageBox
*/

#include "MessageBox.hpp"
#include "../../text/Text.hpp"

MessageBox::MessageBox(sf::RenderWindow &window, std::string message,
    int width, int height): _window(window), _width(width), _height(height)
{
    // TODO: init Text object
}

MessageBox::~MessageBox()
{
}

void MessageBox::render(sf::RenderWindow &window)
{
    window.draw(_rectangle);
    window.draw(_text);
}

void MessageBox::processEvents(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
            _window.close();
    }
}
