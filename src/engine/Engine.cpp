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
    _window.create(sf::VideoMode::getDesktopMode(), "Global Game Jam", sf::Style::Fullscreen);
    _window.setFramerateLimit(60);
    _window.setActive(true);
    _window.setVerticalSyncEnabled(true);
    std::cout << "Engine initialized successfully.\n";
}

Engine::~Engine()
{
}

void Engine::run()
{
    sf::Clock clock;
    while (_window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Engine::processEvents()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
    std::cout << "Events processed successfully.\n";
}

void Engine::update(sf::Time deltaTime)
{
    // Your update logic here...
    std::cout << "Update completed successfully.\n";
}

void Engine::render()
{
    _window.clear();
    // _sceneManager.render(_window);
    // start a simple black background
    sf::RectangleShape background(sf::Vector2f(1920, 1080));
    _window.display();
    std::cout << "Render completed successfully.\n";
}
