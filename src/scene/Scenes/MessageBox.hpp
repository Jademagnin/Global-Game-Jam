/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** MessageBox
*/

#pragma once

#include "../Scene.hpp"

class MessageBox : public Scene {
    public:
        MessageBox(sf::RenderWindow &window, std::string message,
            int width = 250, int height = 100);
        ~MessageBox();
        void render(sf::RenderWindow &window);
        void processEvents(sf::Event event);

    protected:
    private:
        sf::RectangleShape _rectangle;
        sf::Text _text;
        sf::Font _font;
        sf::RenderWindow &_window;
        int _width;
        int _height;
};
