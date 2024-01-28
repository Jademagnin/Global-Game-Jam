/*
** EPITECH PROJECT, 2024
** GGJ
** File description:
** button
*/

#include "button.hpp"

void Button::clicked() {
    _onClick();
}

const std::string& Button::getLabel() const {
    return _label;
}

const sf::Rect<float>& Button::getPosition() const {
    return _position;
}