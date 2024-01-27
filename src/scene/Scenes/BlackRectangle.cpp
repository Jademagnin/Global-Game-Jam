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
    // load texture using assets loader
    _assetsLoader = new AssetsLoader<sf::Sprite>("assets/texture.png", sf::Vector2f(0, 0), sf::Vector2f(100, 100));
}

BlackRectangle::~BlackRectangle()
{

}

void BlackRectangle::render(sf::RenderWindow &window)
{
    window.draw(_rectangle);
    _assetsLoader->draw(window);
}

void BlackRectangle::processEvents(sf::Event event)
{

}