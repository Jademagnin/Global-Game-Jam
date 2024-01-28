/*
** EPITECH PROJECT, 2024
** Scenes
** File description:
** Desktop.cpp
*/

#include "Desktop.hpp"
#include "WhiteRectangle.hpp"
#include "FileExplorer.hpp"
#include "../../utils/Logging.hpp"
#include <iostream>
#include <vector>
#include <map>
#include "../../sound/Sound.hpp"
#include "../../graphics/AssetsLoader.hpp"
#include <SFML/Audio.hpp>
#include "../../music/Music.hpp"
#include <thread>
// #include "SFML/

Desktop::Desktop(sf::RenderWindow &window) : _window(window)
{
    //string is the name of the file, int is the number of frames
    _folderNumber = this->_yml.getNbOfFolderDesktop();
    _icon = new Icon*[_folderNumber];
    _pos = new sf::Vector2f[_folderNumber];

    std::vector<std::string> folders = this->_yml.getDesktop();

    int maxIconByRow = 7;
    int row = 0;
    int col = 0;
    setBackGround();
    for (int i = 0; i < _folderNumber; i++) {
        _icon[i] = new Icon("folder.png", folders[i], std::make_unique<FileExplorer>(window), 1);
        _pos[i] = sf::Vector2f(50 + (col * 128), 50 + (row * 128));
        _icon[i]->sprite.setScale(0.2, 0.2);
        _icon[i]->setPosition(_pos[i]);
        row++;
        if (row == maxIconByRow) {
            row = 0;
            col++;
        }
    }
}

Desktop::~Desktop()
{
    for (int i = 0; i < _folderNumber; i++) {
        delete _icon[i];
    }
    delete[] _icon;
    delete _background;
}

void Desktop::render(sf::RenderWindow &window)
{
    _background->draw(window);
    _toolbar->draw(window);
    _volume->draw(window);
     for (int i = 0; i < _folderNumber; i++) {
        _icon[i]->moveFrame();
    }
    for (int i = 0; i < _folderNumber; i++) {
         if (_icon[i] != _draggedFolder)
            _icon[i]->render(window);
    }
    if (_draggedFolder != nullptr) {
        _draggedFolder->render(window);
    }
}

template<typename... Funcs>
void Desktop::forEachIcon(Funcs... callbacks)
{
    for (int i = 0; i < _folderNumber; i++) {
        ([&](auto callback) { callback(_icon[i]); }(callbacks), ...);
    }
    //when we wrote this, only god and we knew what it was
    //now, only god knows
}

void Desktop::processEvents(sf::Event event)
{
    static sf::Clock clickClock;
    static bool isSingleClick = false;
    sf::Vector2i pixelPos = sf::Mouse::getPosition(_window);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (!_draggedFolder) {
            for (int i = 0; i < _folderNumber; i++) {
                if (_icon[i]->checkDrag(pixelPos, _window)) {
                    _draggedFolder = _icon[i];
                    break;
                }
        }
        }
        if (clickClock.getElapsedTime().asMilliseconds() < 200) {
            isSingleClick = false;
            if (_draggedFolder)
                _draggedFolder->click(pixelPos, _window);
        } else {
            isSingleClick = true;
            clickClock.restart();
        }
    } else if (event.type == sf::Event::MouseMoved) {
        if (_draggedFolder != nullptr) {
            _draggedFolder->checkMove(pixelPos, _window);
        } else {
            for (int i = 0; i < _folderNumber; i++)
                _icon[i]->checkHover(pixelPos);
        }
    } else if (event.type == sf::Event::MouseButtonReleased) {
        if (_draggedFolder != nullptr) {
            _draggedFolder->checkDrop(pixelPos, _window);
            _draggedFolder = nullptr;
        }

    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
        LOG("Right click");
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (pixelPos.x >= 1800 && pixelPos.x <= 1880 && pixelPos.y >= 995 && pixelPos.y <= 1075)
        {
            Sound sound("assets/music/scream.ogg", 50, 2000);
            sound.playSound();
            std::cout << "Volume" << std::endl;
        }
    }
}

void Desktop::setBackGround()
{
    _background = new AssetsLoader<sf::Sprite>("background.png", sf::Vector2f(0, 0), sf::Vector2f(1920, 1080));
    _toolbar = new AssetsLoader<sf::Sprite>("toolbar.png", sf::Vector2f(0, 990), sf::Vector2f(1920, 1080 / 12));
    _volume = new AssetsLoader<sf::Sprite>("volume.png", sf::Vector2f(1800, 995), sf::Vector2f(80, 80));
}
