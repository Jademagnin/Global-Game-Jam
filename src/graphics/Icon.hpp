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
#include "../scene/SceneManager.hpp"
#include "../scene/Scene.hpp"
#include <memory>

    
class Icon : public Sprite {
    public:
        Icon(std::string path, const std::string label, std::shared_ptr<Scene> Scene,int n_frames = 1);
        ~Icon() {
            if (_text)
                delete _text;
        }
        void hover(bool hovered);
        void checkHover(sf::Vector2i mousePos);
        bool checkDrag(sf::Vector2i mousePos, sf::RenderWindow &window);
        void checkDrop(sf::Vector2i mousePos, sf::RenderWindow &window);
        void checkMove(sf::Vector2i mousePos, sf::RenderWindow &window);
        void setHovered(bool hovered) { _hovered = hovered; };
        void setMoving(bool moving) { _moving = moving; };
        void setPosition(sf::Vector2f pos) {
            sprite.setPosition(pos);
            _text->setPosition(sf::Vector2f(pos.x, pos.y + 42.5));
        };
        void moveFrame() {
            if (_hovered)
                Sprite::moveFrame();
        }
        void render(sf::RenderWindow &window) {
            Sprite::render(window);
            _text->draw(window);
        }
        void click(sf::Vector2i mousePos, sf::RenderWindow &window) {
            if (sprite.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
                std::cout << _label << " clicked" << std::endl;
                _sceneManager.switchScene(_scene);
            }
        }
    private:
        bool _hovered;
        bool _moving;
        TextArray *_text;
        std::string _label;
        std::shared_ptr<Scene> _scene;
        SceneManager &_sceneManager = SceneManager::getInstance();
};
    
#endif /* _ICON_HPP_ */
