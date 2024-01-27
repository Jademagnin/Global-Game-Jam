/*
** EPITECH PROJECT, 2024
** graphics
** File description:
** Sprite.cpp
*/

    #include "Sprite.hpp"
    #include <iostream>


Sprite::Sprite(std::string path, int n_frames)
{
    std::string root = "assets";
    path = root + (path.starts_with("/") ? path : "/" + path);
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error: could not load texture from file " << path << std::endl;
        exit(84);
    }
    sprite.setTexture(texture);
    rect.height = texture.getSize().y;
    rect.width = texture.getSize().x / n_frames;
    sprite.setTextureRect(rect);
    sprite.setOrigin(rect.width / 2, rect.height / 2);
}

void Sprite::moveFrame()
{
    if (clock.getElapsedTime().asMilliseconds() < 100)
        return;
    rect.left += rect.width;
    if (rect.left >= texture.getSize().x)
        rect.left = 0;
    sprite.setTextureRect(rect);
    clock.restart();
}
