/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** Engine.hpp
*/

#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include <SFML/Graphics.hpp>
#include "../shape/Shape.hpp"
#include "../scene/SceneManager.hpp"

class Engine {
    public:
        Engine();
        ~Engine();

        void run();
        void processEvents();
        void render();

    private:
        sf::RenderWindow _window;
        sf::Clock _clock;
        sf::Time _timeSinceLastUpdate;
        sf::Time _timePerFrame;
        SceneManager _sceneManager = UniqueSceneManager::getInstance();

};

#endif /* _ENGINE_HPP_ */
