/*
** EPITECH PROJECT, 2024
** GGJ
** File description:
** AssetsLoader
*/

#ifndef ASSETSLOADER_HPP_
#define ASSETSLOADER_HPP_

#include "../engine/Engine.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <functional>
#include <filesystem>

template<typename T>
class AssetsLoader {
public:
    AssetsLoader(const std::string& filename, const sf::Vector2f& position, const sf::Vector2f& size);

    void draw(sf::RenderWindow& window);

    void setPosition(const sf::Vector2f& position);

    void setSize(const sf::Vector2f& size);

    sf::Vector2f getPosition();

    sf::Vector2f getSize();

    std::string findFile(const std::string& filename);

    T getSprite() { return sprite; }

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif /* !ASSETSLOADER_HPP_ */
