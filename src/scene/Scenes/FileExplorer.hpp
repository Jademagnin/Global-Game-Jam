/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** FileExplorer
*/

#ifndef FILEEXPLORER_HPP_
#define FILEEXPLORER_HPP_

#include "../Scene.hpp"
#include "../../graphics/Icon.hpp"
#include "../../graphics/AssetsLoader.hpp"
#include "../../parsing/YmlParser.hpp"
#include <functional>

class FileExplorer: public Scene {
    public:
        FileExplorer(sf::RenderWindow &window, std::string &path);
        ~FileExplorer();
        void render(sf::RenderWindow &window);
        void processEvents(sf::Event event);

    protected:
    private:
        AssetsLoader<sf::Sprite>* _explorer;
        sf::RenderWindow &_window;
        YmlParser _yml;
        Text **_text;
        sf::RectangleShape _closeButton;
        SceneManager& _sceneManager = SceneManager::getInstance();
};

#endif
