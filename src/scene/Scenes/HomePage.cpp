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
    //init button
        // Button(const sf::Rect<float>& position, const std::function<void()>& onClick, const std::string& label = "Button")
    _button = new Button(sf::Rect<float>(sf::Vector2f(100, 100), sf::Vector2f(100, 100)), []() {
        std::cout << "Button clicked" << std::endl;
    }, "Button");
}

HomePage::~HomePage()
{

}

void HomePage::render(sf::RenderWindow &window)
{
    _background->draw(window);
    for (int i = 0; i < _dialogs.size(); i++) {
        if (i && !_dialogs[i - 1].isFullyDisplayed())
            continue;
        _dialogs[i].displayDialog(window);
    }
}

void HomePage::processEvents(sf::Event event)
{

}
