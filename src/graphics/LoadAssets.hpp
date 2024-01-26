/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** LoadAssets
*/

#ifndef LOADASSETS_HPP_
#define LOADASSETS_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

//class for loading assets
class LoadAssets {
    public:
    //take file path, position and size of the asset
        LoadAssets(std::string path, sf::Vector2f pos, sf::Vector2f size);
        ~LoadAssets();

    protected:
    private:
};

#endif /* !LOADASSETS_HPP_ */
