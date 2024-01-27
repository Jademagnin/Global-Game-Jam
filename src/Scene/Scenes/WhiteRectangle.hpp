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
        void update(sf::Time deltaTime);
        void render(sf::RenderWindow &window);

    protected:
    private:
};
