/*
** EPITECH PROJECT, 2024
** graphics
** File description:
** Sprite.cpp
*/

    #include "Sprite.hpp"
    #include <iostream>


Sprite::Sprite(std::string path)
{
    std::string root = "./content/assets";
    path = root + (path.starts_with("/") ? path : "/" + path);
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error: could not load texture from file " << path << std::endl;
        exit(84);
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    border.setFillColor(sf::Color::Blue);
    sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    border.setSize({spriteBounds.width, spriteBounds.height});
}
