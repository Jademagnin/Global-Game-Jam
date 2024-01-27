/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** Engine.cpp
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine.hpp"
#include "../Logging.hpp"
#include "../scene/Scenes/WhiteRectangle.hpp"
#include "../scene/Scenes/BlackRectangle.hpp"
#include "../scene/Scenes/Desktop.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Engine::Engine()
    : _window(sf::VideoMode::getDesktopMode(), "Global Game Jam", sf::Style::Fullscreen)
{
    _window.setFramerateLimit(60);
    _window.setActive(true);
    _window.setVerticalSyncEnabled(true);

    // init all scenes
    // Default scene
    _sceneManager.stageScene(std::make_unique<Desktop>(_window));

    // Secondary scenes
    _sceneManager.unstageScene(std::make_unique<WhiteRectangle>());
    _sceneManager.unstageScene(std::make_unique<BlackRectangle>());

    LOG("Engine initialized successfully.");
}

Engine::~Engine()
{
    _sceneManager.getStagedScenes().clear();
    _sceneManager.getUnstagedScenes().clear();
    LOG("Engine destroyed successfully.");
}

void Engine::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f/60.f); // 60 fps
    while (_window.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
        }
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

    // Loop into staged scenes and process events
    for (auto& scene : _sceneManager.getStagedScenes()) {
        scene->processEvents(event);
    }

}

void Engine::render()
{
    _window.clear();

    for (auto& scene : _sceneManager.getStagedScenes()) {
        scene->render(_window);
    }

    _window.display();
}
