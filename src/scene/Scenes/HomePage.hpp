/*
** EPITECH PROJECT, 2024
** GGJ
** File description:
** HomePage
*/

#ifndef HOMEPAGE_HPP_
#define HOMEPAGE_HPP_

#include "../Scene.hpp"


#include "../Scene.hpp"
#include "../../graphics/Icon.hpp"
#include "../../graphics/AssetsLoader.hpp"
#include "../../graphics/AssetsLoader.cpp"
#include "../../button/button.hpp"
#include "../../dialog/dialog.hpp"
#include <functional>
#include <vector>
#include <SFML/Graphics.hpp>

class HomePage: public Scene {
    public:
        HomePage(sf::RenderWindow &window);
        ~HomePage();
        void render(sf::RenderWindow &window);
        void processEvents(sf::Event event);


    protected:
    private:
        sf::Font _font;
        sf::RenderWindow &_window;
        bool isLoaded = false;
        Dialog *_dialog;
        Dialog *_dialog2;
        AssetsLoader<sf::Sprite> *_background;
        // Button *_button;
        std::vector<Dialog> _dialogs;
        AssetsLoader<sf::Sprite> *_login;
};


#endif /* !HOMEPAGE_HPP_ */
