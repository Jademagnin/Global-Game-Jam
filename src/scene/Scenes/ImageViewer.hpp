/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** ImageViewer
*/

#pragma once

#include "../Scene.hpp"
#include "../../graphics/Icon.hpp"
#include "../../graphics/AssetsLoader.hpp"
#include "../../parsing/YmlParser.hpp"
#include <functional>

class ImageViewer: public Scene {
    public:
        ImageViewer(sf::RenderWindow &window, const std::string &path);
        ~ImageViewer();
        void render(sf::RenderWindow &window);
        void processEvents(sf::Event event);

    protected:
    private:
        const std::string _imagePath;
        AssetsLoader<sf::Sprite>* _image;
        AssetsLoader<sf::Sprite>* _cross;
        sf::RenderWindow &_window;
        sf::RectangleShape _closeButton;
        SceneManager& _sceneManager = SceneManager::getInstance();
};
