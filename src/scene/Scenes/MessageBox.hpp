/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** MessageBox
*/

#pragma once

#include "../Scene.hpp"
#include "../../text/Text.hpp"
#include "../../graphics/Icon.hpp"

class MessageBox : public Scene {
    public:
        MessageBox(sf::RenderWindow &window,
            const std::string title, const std::string message,
            const sf::Vector2f &position,
            const sf::Vector2i &size = sf::Vector2i(200, 100));
        ~MessageBox();
        void render(sf::RenderWindow &window);
        void processEvents(sf::Event event);

    protected:
    private:
        sf::RectangleShape _topBar;
        sf::RectangleShape _body;
        Text *_title;
        Text *_text;
        sf::Font _font;
        sf::RenderWindow &_window;
        sf::Vector2f _position;
        sf::Vector2i _size;
        Icon *_icon;
        Icon *_closeIcon;
};
