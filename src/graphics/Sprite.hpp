/*
** EPITECH PROJECT, 2024
** graphics
** File description:
** Sprite.hpp
*/

#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include <SFML/Graphics.hpp>
    
class Sprite {
    public:
        Sprite(std::string path);
        ~Sprite() = default;
        void hover();
        void moveFrame();
        sf::Sprite operator*() { return sprite; }
    public:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::IntRect rect{0, 0, 20, 5};
        sf::RectangleShape border;
};
    
#endif /* _SPRITE_HPP_ */
