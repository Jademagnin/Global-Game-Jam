/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** FileExplorer
*/

#include "FileExplorer.hpp"

FileExplorer::FileExplorer(sf::RenderWindow &window) : _window(window)
{
    this->_explorer = new AssetsLoader<sf::Sprite>("explorer.png", sf::Vector2f(0, 0), sf::Vector2f(1100, 800));
}

FileExplorer::~FileExplorer()
{

}

void FileExplorer::render(sf::RenderWindow &window)
{
    _explorer->draw(window);
}

void FileExplorer::processEvents(sf::Event event) {

}

