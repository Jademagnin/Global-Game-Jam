/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** WhiteRectangle
*/

#include "WhiteRectangle.hpp"

WhiteRectangle::WhiteRectangle()
{
}

WhiteRectangle::~WhiteRectangle()
{
}

void WhiteRectangle::update(sf::Time deltaTime)
{
}

void WhiteRectangle::render(sf::RenderWindow &window)
{
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
    rectangle.setFillColor(sf::Color::White);
    window.draw(rectangle);
}
