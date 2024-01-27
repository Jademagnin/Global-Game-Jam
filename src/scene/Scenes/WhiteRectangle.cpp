/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** WhiteRectangle
*/

#include "WhiteRectangle.hpp"

WhiteRectangle::WhiteRectangle()
{
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
    rectangle.setFillColor(sf::Color::White);
    _rectangle = rectangle;
}

WhiteRectangle::~WhiteRectangle()
{
}

void WhiteRectangle::render(sf::RenderWindow &window)
{
    window.draw(_rectangle);
}

void WhiteRectangle::processEvents(sf::Event event)
{
}
