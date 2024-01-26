/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** Engine.cpp
*/

#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Engine::Engine()
{
    _window.create(sf::VideoMode(1920, 1080), "Global Game Jam");
    _window.setFramerateLimit(60);
    _window.setActive(true);
    _window.setVerticalSyncEnabled(true);
}

int Engine::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    while (_window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
    return 0;
}
