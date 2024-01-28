/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** FileExplorer
*/

#include "FileExplorer.hpp"
#include "../../parsing/YmlParser.hpp"
#include "../../text/Text.hpp"

FileExplorer::FileExplorer(sf::RenderWindow &window, std::string &path) : _window(window)
{
    this->_explorer = new AssetsLoader<sf::Sprite>("explorer.png", sf::Vector2f(0, 0), sf::Vector2f(1100, 800));
    std::unordered_map<std::string, std::string> folder = this->_yml.getFolderContent("Notes", false);
    _text = new Text*[folder.size()];
    int i = 0;
    int y = 10;
    int columnWidth = 500; // Adjust this value to change the space between columns
    int rowHeight = 50; // Adjust this value to change the space between rows
    for (const auto& file : folder) {
        int x = (i % 2) * columnWidth + 100; // Calculate x position based on index
        _text[i] = new Text(file.first, sf::Vector2f(x, y), 10, sf::Color::Black, "assets/Aileron-SemiBold.ttf");
        if (i % 2 == 1) {
            y += rowHeight; // Move to the next row after every second file
        }
        i++;
    }
}

FileExplorer::~FileExplorer()
{

}

void FileExplorer::render(sf::RenderWindow &window)
{
    _explorer->draw(window);
    for (int i = 0; i < 5; i++) {
        _text[i]->draw(window);
    }
}

void FileExplorer::processEvents(sf::Event event) {

}

