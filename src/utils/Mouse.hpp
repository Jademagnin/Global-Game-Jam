/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** Mouse
*/

#ifndef MOUSE_HPP_
    #define MOUSE_HPP_

    #include "../graphics/AssetsLoader.hpp"
    #include "../scene/Scene.hpp"
    #include <SFML/Graphics.hpp>

    class Mouse : public Scene {
        public:
            Mouse(sf::RenderWindow &window);
            ~Mouse() = default;
            void processEvents(sf::Event event);
            void render(sf::RenderWindow &window);

        protected:
        private:
            AssetsLoader<sf::Sprite>* _mouse;
            AssetsLoader<sf::Sprite>* _mousePressed;
            sf::Sprite _mouseSprite;
            sf::Texture _mouseTexture;
            sf::RenderWindow &_window;
    };

#endif /* !MOUSE_HPP_ */
