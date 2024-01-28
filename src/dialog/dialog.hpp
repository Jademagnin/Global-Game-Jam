/*
** EPITECH PROJECT, 2024
** GGJ
** File description:
** dialog
*/

#ifndef DIALOG_HPP_
#define DIALOG_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Dialog {
    public:
        Dialog(const std::string& dialogText, const sf::Font& font, const sf::Vector2f& position, const sf::Color& color);
        void displayDialog(sf::RenderWindow& window);
        bool isFullyDisplayed() const { return _isFullyDisplayed; };
        void addCharToDialog();
        
    private:
        sf::Clock clock;
        std::string dialogText;
        sf::Text dialogTextObject;
        char* dialogTextChar;
        char c;
        bool _isFullyDisplayed = false;
};

#endif /* !DIALOG_HPP_ */
