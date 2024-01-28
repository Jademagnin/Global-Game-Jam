/*
** EPITECH PROJECT, 2024
** GGJ
** File description:
** dialog
*/

#include "dialog.hpp"
#include <string>
#include <thread>
#include <chrono>
#include <cstring>

Dialog::Dialog(const std::string& dialogText, const sf::Font& font, const sf::Vector2f& position, const sf::Color& color) : dialogText(dialogText) {
    dialogTextObject.setFont(font);
    dialogTextObject.setCharacterSize(24);
    dialogTextObject.setFillColor(color);
    dialogTextObject.setPosition(position);
    dialogTextChar = strdup(dialogText.c_str());
}

void Dialog::addCharToDialog() {
    if (clock.getElapsedTime().asMilliseconds() < 50 || _isFullyDisplayed)
        return;
    dialogTextObject.setString(dialogTextObject.getString() + *dialogTextChar++);
    if (dialogTextObject.getString().getSize() == dialogText.size())
        _isFullyDisplayed = true;
    clock.restart();
}

void Dialog::displayDialog(sf::RenderWindow& window) {
    addCharToDialog();
    window.draw(dialogTextObject);
}
