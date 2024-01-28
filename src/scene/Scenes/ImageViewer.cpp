/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** ImageViewer
*/

#include "ImageViewer.hpp"

ImageViewer::ImageViewer(sf::RenderWindow &window, const std::string &path) : _imagePath(path), _window(window)
{
    this->_image = new AssetsLoader<sf::Sprite>(_imagePath, sf::Vector2f(600, 100), sf::Vector2f(700, 900));
    this->_cross = new AssetsLoader<sf::Sprite>("red_cross.png", sf::Vector2f(1250, 110), sf::Vector2f(30, 30));
    this->_closeButton = sf::RectangleShape(sf::Vector2f(70, 75));
    this->_closeButton.setPosition(1230, 100);
}

ImageViewer::~ImageViewer()
{
}

void ImageViewer::render(sf::RenderWindow &window) {
    this->_image->draw(window);
    this->_cross->draw(window);
}

void ImageViewer::processEvents(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(_window));

            if (_closeButton.getGlobalBounds().contains(mousePos)) {
                _sceneManager.popScene();
            }
        }
    }
}
