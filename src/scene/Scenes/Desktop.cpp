/*
** EPITECH PROJECT, 2024
** Scenes
** File description:
** Desktop.cpp
*/

#include "Desktop.hpp"
#include "WhiteRectangle.hpp"
#include <iostream>
#include <vector>
#include <map>

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
    for (int i = 0; i < _folderNumber; i++) {
        _pos[i] = sf::Vector2f(50 + (col * 128), 50 + (row * 128));
        _icon[i] = new Icon("folder.png", folders[i], 1);
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
}

void Desktop::render(sf::RenderWindow &window)
{
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
    sf::Vector2i pixelPos = sf::Mouse::getPosition(_window); // window coordinates

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        for (int i = 0; i < _folderNumber; i++) {
            if (_icon[i]->checkDrag(pixelPos, _window)) {
                _draggedFolder = _icon[i];
                break;
            }
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
            _draggedFolder->setMoving(false);
            _draggedFolder = nullptr;
        }
    }
}
