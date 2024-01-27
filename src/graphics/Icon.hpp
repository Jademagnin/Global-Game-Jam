/*
** EPITECH PROJECT, 2024
** src
** File description:
** Icon.hpp
*/

#ifndef _ICON_HPP_
#define _ICON_HPP_

#include <SFML/Graphics.hpp>
#include "graphics/Sprite.hpp"

    
class Icon : public Sprite {
    public:
        Icon(std::string path);
        ~Icon() = default;
};
    
#endif /* _ICON_HPP_ */
