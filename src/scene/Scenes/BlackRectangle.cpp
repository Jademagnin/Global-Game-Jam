/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** BlackRectangle
*/

#include "BlackRectangle.hpp"

BlackRectangle::BlackRectangle()
{
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
    rectangle.setFillColor(sf::Color::Red);
    _rectangle = rectangle;
}

BlackRectangle::~BlackRectangle()
{

}

void BlackRectangle::render(sf::RenderWindow &window)
{
    window.draw(_rectangle);
}

void BlackRectangle::processEvents(sf::Event event)
{

}