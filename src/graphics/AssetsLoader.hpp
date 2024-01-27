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
    AssetsLoader(const std::string& filename, const sf::Vector2f& position, const sf::Vector2f& size) {
        std::string path = findFile(filename);
        if (path == "") {
            std::cerr << "Error loading texture from file: " << filename << std::endl;
            return;
        }

        if (!texture.loadFromFile(path)) {
            std::cerr << "Error loading texture from file: " << filename << std::endl;
            return;
        }

        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(size.x / sprite.getLocalBounds().width, size.y / sprite.getLocalBounds().height);
    }


    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    void setPosition(const sf::Vector2f& position) {
        sprite.setPosition(position);
    }

    void setSize(const sf::Vector2f& size) {
        sprite.setScale(size.x / sprite.getLocalBounds().width, size.y / sprite.getLocalBounds().height);
    }

    sf::Vector2f getPosition() {
        return sprite.getPosition();
    }

    sf::Vector2f getSize() {
        return sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height);
    }

    std::string findFile(const std::string& filename) {
        std::string path = "";
        std::string currentPath = std::filesystem::current_path();
        if (std::filesystem::exists(currentPath + "/" + filename)) {
            path = currentPath + "/" + filename;
        } else {
            std::cout << "file not found" << std::endl;
            for (const auto& entry : std::filesystem::recursive_directory_iterator(currentPath)) {
                std::cout << entry.path() << std::endl;
                if (entry.path().filename() == filename) {
                    path = entry.path();
                    break;
                }
            }
        }
        return path;
    }


private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif /* !ASSETSLOADER_HPP_ */
