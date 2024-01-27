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
            ~YmlParser();

        protected:
        private:
            YAML::Node _node;
    };

#endif /* !YMLPARSER_HPP_ */
