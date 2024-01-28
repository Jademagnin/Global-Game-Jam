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

std::unordered_map<std::string, std::string> YmlParser::getFolderContent(const std::string& folderPath) const {
    std::unordered_map<std::string, std::string> folderContent;
    std::vector<std::string> folders;
    std::stringstream ss(folderPath);
    std::string folder;

    while (std::getline(ss, folder, '/'))
        folders.push_back(folder);

    getFolderContentRecursive(folders, 0, _node, folderContent);
    return folderContent;
}

void YmlParser::getFolderContentRecursive(const std::vector<std::string>& folders, int index, const YAML::Node& currentNode, std::unordered_map<std::string, std::string>& folderContent) const {
    if (index >= folders.size())
        return;

    for (const auto& node : currentNode) {
        if (node["type"].as<std::string>() == "folder" && node["name"].as<std::string>() == folders[index]) {
            if (index == folders.size() - 1) {
                for (const auto& file : node["files"])
                    folderContent[file["name"].as<std::string>()] = file["type"].as<std::string>();
            } else if (node["files"]) {
                getFolderContentRecursive(folders, index + 1, node["files"], folderContent);
            }
            break;
        }
    }
}

YAML::Node YmlParser::getInfoFromName(const std::string& name) const {
    for (const auto& node : _node)
        if (node["name"].as<std::string>() == name)
            return node;
    return YAML::Node();
}
