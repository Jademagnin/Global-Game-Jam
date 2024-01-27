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
#include "../../graphics/AssetsLoader.cpp"
#include <functional>

class FileExplorer: public Scene {
    public:
        FileExplorer(sf::RenderWindow &window);
        ~FileExplorer();
        void render(sf::RenderWindow &window);
        void processEvents(sf::Event event);

    protected:
    private:
        AssetsLoader<sf::Sprite>* _explorer;
        bool _isOpen = false;
        int _fileId = 0;
        sf::RenderWindow &_window;
};

#endif