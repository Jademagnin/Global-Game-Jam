/*
** EPITECH PROJECT, 2024
** graphics
** File description:
** Sprite.hpp
*/

#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
    
class Sprite {
    public:
        Sprite(std::string path, int n_frames = 1);
        ~Sprite() = default;
        void hover();
        void moveFrame();
        sf::Sprite operator*() { return sprite; }
    public:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::IntRect rect{0, 0, 0, 0};
        sf::RectangleShape border;
        sf::Clock clock;
};
    
#endif /* _SPRITE_HPP_ */
