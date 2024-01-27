/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** Scene
*/

#pragma once

#include <SFML/Graphics.hpp>

class Scene
{
    public:
        virtual ~Scene() = default;
        virtual void render(sf::RenderWindow &window) = 0;
        virtual void processEvents(sf::Event event) = 0;
    protected:
};
