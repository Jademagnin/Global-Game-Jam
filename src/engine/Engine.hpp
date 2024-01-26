/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** Engine.hpp
*/

#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include <SFML/Graphics.hpp>

class Engine {
    public:
        Engine();
        ~Engine() = default;

        int run();
        void processEvents();
        void update(sf::Time deltaTime);
        void render();

        class SceneManager {
            public:
                SceneManager();
                ~SceneManager();

            protected:
            private:
        };

    private:
        sf::RenderWindow _window;


};

#endif /* _ENGINE_HPP_ */
