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
    int y = 180; // Increase this value to move the text down
    int columnWidth = 500; // Decrease this value to bring the columns closer together
    int rowHeight = 300; // Decrease this value to bring the texts closer together
    for (const auto& file : folder) {
        int x = (i % 2) * columnWidth + 400; // Calculate x position based on index
        _text[i] = new Text(file.first, sf::Vector2f(x, y), 15, sf::Color::Black, "assets/Aileron-SemiBold.ttf");
        if (i % 2 == 1) {
            y += rowHeight - 100; // Move to the next row after every second file
        }
        i++;
    }

    _closeButton.setSize(sf::Vector2f(50, 50));
    _closeButton.setFillColor(sf::Color::Transparent);
    _closeButton.setPosition(sf::Vector2f(1015, 40));
    _image1 = new AssetsLoader<sf::Sprite>("back.png", sf::Vector2f(350, 200), sf::Vector2f(100, 100));
    _image2 = new AssetsLoader<sf::Sprite>("shower.png", sf::Vector2f(850, 200), sf::Vector2f(100, 100));
    _image3 = new AssetsLoader<sf::Sprite>("president.png", sf::Vector2f(350, 400), sf::Vector2f(100, 100));
    _image4 = new AssetsLoader<sf::Sprite>("user.png", sf::Vector2f(850, 400), sf::Vector2f(100, 100));
    _image5 = new AssetsLoader<sf::Sprite>("game.png", sf::Vector2f(350, 600), sf::Vector2f(100, 100));
}

FileExplorer::~FileExplorer()
{
    delete _explorer;
    for (int i = 0; i < 5; i++) {
        delete _text[i];
    }
    delete[] _text;
}

void FileExplorer::render(sf::RenderWindow &window)
{
    _explorer->draw(window);
    for (int i = 0; i < 5; i++) {
        _text[i]->draw(window);
    }
    window.draw(_closeButton);
    _image1->draw(window);
    _image2->draw(window);
    _image3->draw(window);
    _image4->draw(window);
    _image5->draw(window);
}

void FileExplorer::processEvents(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i pixelPos = sf::Mouse::getPosition(_window);
        if (_closeButton.getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
            _sceneManager.popScene();
        }
    }
}
