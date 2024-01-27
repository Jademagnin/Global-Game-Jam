/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** YmlParser
*/

#include "YmlParser.hpp"

YmlParser::YmlParser() {
    this->_node = YAML::LoadFile("content/data.yml");
    std::cout << this->_node << std::endl;
}

YmlParser::~YmlParser()
{
}
