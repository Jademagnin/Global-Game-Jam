/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** Text
*/

#include "Text.hpp"

void Text::draw(sf::RenderWindow& window) const {
    window.draw(this->_text);
}

void Text::changeFont(std::string& newPath) {
    if (!this->_font.loadFromFile(newPath)) {
        std::cerr << "Error: cannot find font path" << std::endl;
    }
    this->_text.setFont(_font);
}
