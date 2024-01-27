/*
** EPITECH PROJECT, 2024
** src
** File description:
** Icon.hpp
*/

#ifndef _ICON_HPP_
#define _ICON_HPP_

#include <SFML/Graphics.hpp>
#include "../text/Text.hpp"
#include "Sprite.hpp"

    
class Icon : public Sprite {
    public:
        Icon(std::string path, const std::string label, int n_frames = 1);
        ~Icon() = default;
        void hover(bool hovered);
        void checkHover(sf::Vector2i mousePos);
        void checkDrag(sf::Vector2i mousePos, sf::RenderWindow &window);
        void checkDrop(sf::Vector2i mousePos, sf::RenderWindow &window);
        void checkMove(sf::Vector2i mousePos, sf::RenderWindow &window);
        void setPosition(sf::Vector2f pos) {
            sprite.setPosition(pos);
            _text->setPosition(sf::Vector2f(pos.x, pos.y + 60));
        };
        void moveFrame() {
            if (_hovered)
                Sprite::moveFrame();
        }
        void render(sf::RenderWindow &window) {
            Sprite::render(window);
            _text->draw(window);
        }
    private:
        bool _hovered;
        bool _moving;
        Text *_text;
};
    
#endif /* _ICON_HPP_ */
