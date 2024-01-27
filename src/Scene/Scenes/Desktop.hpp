/*
** EPITECH PROJECT, 2024
** Scenes
** File description:
** Desktop.hpp
*/

    #ifndef _DESKTOP_HPP_
    #define _DESKTOP_HPP_

    #include "../Scene.hpp"
    #include "../../graphics/Icon.hpp"
    
class Desktop : public Scene {
        public:
            Desktop(sf::RenderWindow &window);
            ~Desktop();
            void update(sf::Time deltaTime);
            void render(sf::RenderWindow &window);
        private:
            Icon* _icon[21];
            sf::Vector2f _pos[21];
            sf::RenderWindow &_window;
    };
    
#endif /* _DESKTOP_HPP_ */
