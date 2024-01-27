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
    #include "../../text/Text.hpp"
    #include "../../parsing/YmlParser.hpp"
    #include "../../scene/SceneManager.hpp"

    #include <functional>

    class Desktop : public Scene {
        public:
            Desktop(sf::RenderWindow &window);
            ~Desktop();
            void render(sf::RenderWindow &window);
            void processEvents(sf::Event event);
            template<typename... Funcs>
            void forEachIcon(Funcs... callbacks);
            void InitTextBelow();

        private:
            YmlParser _yml;
            Icon* _icon[21];
            sf::Vector2f _pos[21];
            sf::RenderWindow &_window;
            Text* _text[21];
            SceneManager& _sceneManager = SceneManager::getInstance();
    };

#endif /* _DESKTOP_HPP_ */
