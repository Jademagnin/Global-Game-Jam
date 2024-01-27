/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** Engine.cpp
*/

#include "Engine.hpp"
#include "../Logging.hpp"
#include "../Scene/Scenes/WhiteRectangle.hpp"
#include "../Scene/Scenes/BlackRectangle.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Engine::Engine()
{
    _window.create(sf::VideoMode(1920, 1080), "Global Game Jam");
    _window.setFramerateLimit(60);
    _window.setActive(true);
    _window.setVerticalSyncEnabled(true);
    // std::cout << "Engine initialized successfully.\n";
}

Engine::~Engine()
{

}

void Engine::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f/60.f); // 60 fps

    while (_window.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        update(TimePerFrame);
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

    Scene* currentScene = _sceneManager.getCurrentScene();
    if (currentScene != nullptr) {
        currentScene->processEvents(event);
    }
    // std::cout << "Events processed successfully.\n";
}

void Engine::update(sf::Time deltaTime)
{
    Scene* currentScene = _sceneManager.getCurrentScene();
    if (currentScene != nullptr) {
        currentScene->update(deltaTime);
    }
}

void Engine::render()
{
    static bool isWhite = true;
    _window.clear();

    if (isWhite) {
        _sceneManager.switchScene(std::make_unique<WhiteRectangle>());
    } else {
        _sceneManager.switchScene(std::make_unique<BlackRectangle>());
    }

    Scene* currentScene = _sceneManager.getCurrentScene();
    if (currentScene != nullptr) {
        currentScene->render(_window);
    }

    _window.display();
    isWhite = !isWhite;
}
