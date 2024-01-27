/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** WhiteRectangle
*/

#pragma once

#include "../Scene.hpp"

class WhiteRectangle: public Scene {
    public:
        WhiteRectangle();
        ~WhiteRectangle();
        void render(sf::RenderWindow &window);
        void processEvents(sf::Event event);

    protected:
    private:
        sf::RectangleShape _rectangle;
};
