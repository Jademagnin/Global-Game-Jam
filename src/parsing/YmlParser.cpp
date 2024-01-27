/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** YmlParser
*/

#include "YmlParser.hpp"
#include "unordered_map"
#include <iostream>
#include <string>

YmlParser::YmlParser() {
    this->_node = YAML::LoadFile("content/data.yml")["desktop"];
    this->_NbFldrDesktop = std::count_if(_node.begin(), _node.end(), [](const YAML::Node& item){
        return item["type"].as<std::string>() == "folder";
    });
}

int YmlParser::getNbOfFolderDesktop() const {
    return this->_NbFldrDesktop;
}

std::vector<std::string> YmlParser::getDesktop() const {
    std::vector<std::string> vec;

    for (YAML::const_iterator it = this->_node.begin(); it != this->_node.end(); ++it)
        vec.push_back((*it)["name"].as<std::string>());
    return vec;
}
