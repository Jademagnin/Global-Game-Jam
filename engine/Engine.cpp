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
    _window.setKeyRepeatEnabled(false);
    _window.setMouseCursorVisible(false);
    _window.setActive(true);
    _window.setVerticalSyncEnabled(true);
}
