/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** BlackRectangle
*/

#pragma once

// black rectangle scene for scene manager
#include "../Scene.hpp"

class BlackRectangle: public Scene {
    public:
        BlackRectangle();
        ~BlackRectangle();
        void render(sf::RenderWindow &window);
        void processEvents(sf::Event event);

    protected:
    private:
        sf::RectangleShape _rectangle;
};
