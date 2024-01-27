/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

void SceneManager::pushScene(std::unique_ptr<Scene> scene)
{
    scenes.push(std::move(scene));
}

void SceneManager::popScene()
{
    if (!scenes.empty())
    {
        scenes.pop();
    }
}

void SceneManager::switchScene(std::unique_ptr<Scene> scene)
{
    if (!scenes.empty())
    {
        popScene();
    }
    pushScene(std::move(scene));
}

Scene* SceneManager::getCurrentScene()
{
    if (scenes.empty())
    {
        return nullptr;
    }
    return scenes.top().get();
}
