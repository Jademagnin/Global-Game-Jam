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
        Text(const std::string& string, const sf::Vector2f& position, int fontSize = 20, const sf::Color& color = sf::Color::Black, const std::string& path = "assets/Aileron-SemiBold.ttf")
            : _string(string), _position(position), _fontSize(fontSize), _color(color) {

            if (!_font.loadFromFile(path)) {
                std::cerr << "Error: cannot find font path" << std::endl;
            }
            _text.setFont(_font);
            _text.setString(_string);
            _text.setCharacterSize(_fontSize);
            _text.setFillColor(_color);
            _text.setOrigin(_text.getGlobalBounds().width / 2, _text.getGlobalBounds().height / 2);
            _text.setPosition(_position);
        }

        void draw(sf::RenderWindow& window) const;
        void changeFont(std::string& newPath);
        void setPosition(const sf::Vector2f& position) { _text.setPosition(position); }

    private:
        sf::Font _font;
        sf::Text _text;
        std::string _string;
        sf::Vector2f _position;
        int _fontSize;
        sf::Color _color;
};

class TextArray {
    public:
        TextArray(const std::vector<std::string>& strings, const sf::Vector2f& position, int fontSize = 20, const sf::Color& color = sf::Color::Black, const std::string& path = "assets/Aileron-SemiBold.ttf")
            : _strings(strings), _position(position), _fontSize(fontSize), _color(color) {

            if (!_font.loadFromFile(path)) {
                std::cerr << "Error: cannot find font path" << std::endl;
            }
            for (int i = 0; i < _strings.size(); i++) {
                sf::Text text;
                text.setFont(_font);
                text.setString(_strings[i]);
                text.setCharacterSize(_fontSize);
                text.setFillColor(_color);
                text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
                text.setPosition(_position.x, _position.y + ((i + 1) * 20));
                _texts.push_back(text);
            }
        }

        void draw(sf::RenderWindow& window) const {
            for (int i = 0; i < _texts.size(); i++) {
                window.draw(_texts[i]);
            }
        };
        void changeFont(std::string& newPath) {
            if (!_font.loadFromFile(newPath)) {
                std::cerr << "Error: cannot find font path" << std::endl;
            }
            for (int i = 0; i < _texts.size(); i++) {
                _texts[i].setFont(_font);
            }
        }
        void setPosition(const sf::Vector2f& position) {
            _position = position;
            for (int i = 0; i < _texts.size(); i++) {
                _texts[i].setPosition(_position.x, _position.y + ((i + 1) * 20));
            }
        }

    private:
        sf::Font _font;
        std::vector<sf::Text> _texts;
        std::vector<std::string> _strings;
        sf::Vector2f _position;
        int _fontSize;
        sf::Color _color;
};


#endif
