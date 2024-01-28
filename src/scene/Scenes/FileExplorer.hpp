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
#include "../../graphics/AssetsLoader.hpp"
#include <functional>
#include "../../scene/SceneManager.hpp"
#include "ImageViewer.hpp"

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
        AssetsLoader<sf::Sprite>* _image1;
        AssetsLoader<sf::Sprite>* _image2;
        AssetsLoader<sf::Sprite>* _image3;
        AssetsLoader<sf::Sprite>* _image4;
        AssetsLoader<sf::Sprite>* _image5;
        AssetsLoader<sf::Sprite>* _message;
        bool isActif = true;
        std::string _path;
};

#endif
