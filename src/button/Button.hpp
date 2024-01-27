/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>

class Button {
public:
    Button(const sf::Rect<float>& position, const std::function<void()>& onClick, const std::string& label = "Button")
        : _label(label), _onClick(onClick), _position(position) {}

    void clicked();

    const std::string& getLabel() const;
    const sf::Rect<float>& getPosition() const;

private:
    std::string _label;
    std::function<void()> _onClick;
    sf::Rect<float> _position;
};

#endif /* !BUTTON_HPP_ */
