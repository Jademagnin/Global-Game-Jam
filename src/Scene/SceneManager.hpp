/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <stack>
#include <memory>
#include "Scene.hpp"

class SceneManager
{
    public:
        void pushScene(std::unique_ptr<Scene> scene);
        void popScene();
        void switchScene(std::unique_ptr<Scene> scene);
        Scene* getCurrentScene();

    private:
        std::stack<std::unique_ptr<Scene>> scenes;
};

#endif /* !SCENEMANAGER_HPP_ */
