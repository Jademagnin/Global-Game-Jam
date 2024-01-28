/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>


class Text {
    public:
        Text(const std::string& string, const sf::Vector2f& position,
            int fontSize = 20, const sf::Color& color = sf::Color::Black,
            const std::string& path = "assets/Aileron-SemiBold.ttf")
            : _string(string), _position(position), _fontSize(fontSize),
            _color(color) {

            if (!_font.loadFromFile(path)) {
                std::cerr << "Error: cannot find font path" << std::endl;
            }
            _text.setFont(_font);
            _text.setString(_string);
            _text.setCharacterSize(_fontSize);
            _text.setFillColor(_color);
            _text.setPosition(_position);
            _text.setOrigin(_text.getGlobalBounds().width / 2, _text.getGlobalBounds().height / 2);
        }

        void draw(sf::RenderWindow& window) const;
        void changeFont(std::string& newPath);
        void setPosition(const sf::Vector2f& position) { _text.setPosition(position); }
        sf::Text& getText() { return _text; }

    private:
        sf::Font _font;
        sf::Text _text;
        std::string _string;
        sf::Vector2f _position;
        int _fontSize;
        sf::Color _color;
};

#endif
