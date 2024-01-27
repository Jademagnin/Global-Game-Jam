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
    std::vector<std::map<std::string, int>> files;
    for (int i = 0; i < 16; i++)
        files.push_back(std::map<std::string, int>{{"folder.png", 1}});
    files.push_back(std::map<std::string, int>{{"download.png", 8}});
    files.push_back(std::map<std::string, int>{{"random.png", 10}});
    files.push_back(std::map<std::string, int>{{"fesses.png", 6}});
    files.push_back(std::map<std::string, int>{{"musique.png", 14}});
    files.push_back(std::map<std::string, int>{{"horreur.png", 8}});

    int row = 0;
    int col = 0;

    InitTextBelow();
    for (int i = 0; i < 21; i++) {
        _icon[i] = new Icon(files[i].begin()->first, _text[i], files[i].begin()->second);
        _pos[i] = sf::Vector2f(50 + (col * 128), 50 + (row * 128));
        _icon[i]->sprite.setPosition(_pos[i]);
        row++;
        if (row == 7) {
            row = 0;
            col++;
        }
    }
}

Desktop::~Desktop()
{
    for (int i = 0; i < 21; i++) {
        delete _icon[i];
    }
}

void Desktop::InitTextBelow()
{
    int row = 0;
    int col = 0;
    auto folders = this->_yml.getDesktop();

    for (int i = 0; i < 21; i++) {
        _text[i] = new Text("folder", sf::Vector2f(20 + (col * 128), 50 + (row * 128) + 50), 15, sf::Color::White);
        row++;
        if (row == 7) {
            row = 0;
            col++;
        }
    }
}

void Desktop::render(sf::RenderWindow &window)
{
    for (int i = 0; i < 21; i++) {
        _icon[i]->moveFrame();
    }
    for (int i = 0; i < 21; i++) {
        window.draw(_icon[i]->sprite);
        _text[i]->draw(window);
    }
}

template<typename... Funcs>
void Desktop::forEachIcon(Funcs... callbacks)
{
    for (int i = 0; i < 21; i++) {
        ([&](auto callback) { callback(_icon[i]); }(callbacks), ...);
    }
    //when we wrote this, only god and we knew what it was
    //now, only god knows
}

void Desktop::processEvents(sf::Event event)
{
    sf::Vector2i pixelPos = sf::Mouse::getPosition(_window); // window coordinates

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        forEachIcon([&](Icon* icon) {
            icon->checkDrag(pixelPos, _window);
        });
    } else if (event.type == sf::Event::MouseMoved) {
        forEachIcon([&](Icon* icon) {
            icon->checkMove(pixelPos, _window);
            icon->checkHover(pixelPos);
        });
    } else if (event.type == sf::Event::MouseButtonReleased) {
        forEachIcon([&](Icon* icon) {
            icon->checkDrop(pixelPos, _window);
        });
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
        std::cout << "Right click" << std::endl;
    }
}
