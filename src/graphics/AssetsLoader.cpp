/*
** EPITECH PROJECT, 2024
** GGJ
** File description:
** AssetsLoader
*/

#include "AssetsLoader.hpp"

template<typename T>
AssetsLoader<T>::AssetsLoader(const std::string& filename, const sf::Vector2f& position, const sf::Vector2f& size) {
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

template<typename T>
void AssetsLoader<T>::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

template<typename T>
void AssetsLoader<T>::setPosition(const sf::Vector2f& position) {
    sprite.setPosition(position);
}

template<typename T>
void AssetsLoader<T>::setSize(const sf::Vector2f& size) {
    sprite.setScale(size.x / sprite.getLocalBounds().width, size.y / sprite.getLocalBounds().height);
}

template<typename T>
sf::Vector2f AssetsLoader<T>::getPosition() {
    return sprite.getPosition();
}

template<typename T>
sf::Vector2f AssetsLoader<T>::getSize() {
    return sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height);
}

template<typename T>
std::string AssetsLoader<T>::findFile(const std::string& filename) {
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