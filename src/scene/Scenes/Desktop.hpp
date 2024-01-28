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
    #include "../../graphics/AssetsLoader.hpp"
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
            void setBackGround();
            void ChangeIcon();

        private:
            YmlParser _yml;
            Icon** _icon;
            sf::Vector2f *_pos;
            sf::RenderWindow &_window;
            int _folderNumber;
            Icon* _hoveredFolder = nullptr;
            Icon* _draggedFolder = nullptr;
            AssetsLoader<sf::Sprite>* _background;
            AssetsLoader<sf::Sprite>* _toolbar;
            AssetsLoader<sf::Sprite>* _volume;
            AssetsLoader<sf::Sprite>* _message;
            // bool isActif = true;
            AssetsLoader<sf::Sprite>* _message2;
            int isActif;

            SceneManager& _sceneManager = SceneManager::getInstance();
    };

#endif /* _DESKTOP_HPP_ */
