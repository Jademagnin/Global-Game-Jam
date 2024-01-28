/*
** EPITECH PROJECT, 2024
** GGJ
** File description:
** HomePage
*/

#include "HomePage.hpp"

HomePage::HomePage(sf::RenderWindow &window) : _window(window)
{
    int defaultPaddingTop = 50;
    float defaultLeft = window.getSize().x / 2 - 500;
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
    rectangle.setFillColor(sf::Color::Red);
    _font.loadFromFile("assets/Aileron-SemiBold.ttf");

    std::vector<std::string> dialogText = {
        "J'ai trouve ce PC par terre, je me demande a qui il appartient...",
        "Je devrais peut-etre essayer de le deverrouiller.",
    };
    for (int i = 0; i < dialogText.size(); i++) {
        _dialogs.push_back(Dialog(dialogText[i], _font, sf::Vector2f(defaultLeft, window.getSize().y / 2 - defaultPaddingTop), sf::Color::Black));
        defaultPaddingTop -= 50;
    }
    _background = new AssetsLoader<sf::Sprite>("login_background.png", sf::Vector2f(0, 0), sf::Vector2f(1920, 1080));
    _login = new AssetsLoader<sf::Sprite>("login.png", sf::Vector2f(window.getSize().x / 2 - 250, window.getSize().y / 2 + 100), sf::Vector2f(1920 / 4, 1080 / 5));
}

HomePage::~HomePage()
{

}

void HomePage::render(sf::RenderWindow &window)
{
    _background->draw(window);
    _login->draw(window);
    for (int i = 0; i < _dialogs.size(); i++) {
        if (i && !_dialogs[i - 1].isFullyDisplayed())
            continue;
        _dialogs[i].displayDialog(window);
    }
}

void HomePage::processEvents(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.x >= _login->getPosition().x && event.mouseButton.x <= _login->getPosition().x + _login->getSize().x && event.mouseButton.y >= _login->getPosition().y && event.mouseButton.y <= _login->getPosition().y + _login->getSize().y) {
        _sceneManager.stageScene(std::make_unique<Desktop>(_window));
    }

}
