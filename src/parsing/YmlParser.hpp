/*
** EPITECH PROJECT, 2024
** Global-Game-Jam
** File description:
** YmlParser
*/

#ifndef YMLPARSER_HPP_
    #define YMLPARSER_HPP_

    #include <iostream>
    #include "yaml-cpp/yaml.h"

    class YmlParser {
        public:
            YmlParser();
            ~YmlParser() = default;
            int getNbOfFolderDesktop() const;
            std::vector<std::string> getDesktop() const;

        protected:
        private:
            YAML::Node _node;
            int _NbFldrDesktop;
    };

#endif /* !YMLPARSER_HPP_ */

/*
for (YAML::const_iterator it = this->_node.begin(); it != this->_node.end(); ++it) {
        const YAML::Node& item = *it;
        std::string name = item["name"].as<std::string>();
        std::cout << name << std::endl;
    }
*/
