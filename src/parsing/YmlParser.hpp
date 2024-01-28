/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** YmlParser
*/

#ifndef YMLPARSER_HPP_
    #define YMLPARSER_HPP_

    #include <iostream>
    #include <unordered_map>
    #include <yaml-cpp/yaml.h>

    class YmlParser {
        public:
            YmlParser();
            ~YmlParser() = default;
            int getNbOfFolderDesktop() const;
            std::vector<std::string> getDesktop() const;
            std::unordered_map<std::string, std::string> getFolderContent(const std::string& folderName, bool recursive = false) const;
            YAML::Node getInfoFromName(const std::string& name) const;
        protected:
        private:
            void getFolderContentRecursive(const std::vector<std::string>& folders, int index, const YAML::Node& currentNode, std::unordered_map<std::string, std::string>& folderContent, bool recursive) const;
            YAML::Node _node;
            int _NbFldrDesktop;
    };

#endif /* !YMLPARSER_HPP_ */
