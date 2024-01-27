/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** BlackRectangle
*/

#include "BlackRectangle.hpp"

BlackRectangle::BlackRectangle()
{

}

BlackRectangle::~BlackRectangle()
{

}

void BlackRectangle::update(sf::Time deltaTime)
{

}

void BlackRectangle::render(sf::RenderWindow &window)
{
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
    rectangle.setFillColor(sf::Color::Red);
    window.draw(rectangle);
}
