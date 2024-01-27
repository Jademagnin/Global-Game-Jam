/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** Button
*/

#include "Button.hpp"

void Button::clicked() {
    _onClick();
}

const std::string& Button::getLabel() const {
    return _label;
}

const sf::Rect<float>& Button::getPosition() const {
    return _position;
}
