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
        void update(sf::Time deltaTime);
        void render(sf::RenderWindow &window);

    protected:
    private:
};
