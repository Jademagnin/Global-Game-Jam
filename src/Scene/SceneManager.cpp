/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

// void SceneManager::popScene()
// {
//     if (!scenes.empty())
//     {
//         scenes.pop();
//     }
// }

void SceneManager::pushScene(std::unique_ptr<Scene> scene)
{
    _scenes.push(std::move(scene));
    _currentScene = _scenes.top().get(); // Update the current scene
}

void SceneManager::switchScene(std::unique_ptr<Scene> scene)
{
    _scenes.push(std::move(scene));
    _currentScene = _scenes.top().get(); // Update the current scene
}

Scene* SceneManager::getCurrentScene()
{
    return _currentScene;
}
