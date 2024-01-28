/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
// ** File description:
** SceneManager
*/

#include "SceneManager.hpp"

void SceneManager::popScene() {
    if (!_stagedScenes.empty()) {
        _stagedScenes.pop_back();
    }
}

void SceneManager::switchScene(std::shared_ptr<Scene> scene)
{
    _unstagedScenes.push_back(std::move(_stagedScenes.back()));
    _stagedScenes.pop_back();
    _stagedScenes.push_back(std::move(scene));
}

Scene* SceneManager::getTopScene()
{
    return _stagedScenes.back().get();
}

void SceneManager::stageScene(std::shared_ptr<Scene> scene)
{
    // Find the scene in the _unstagedScenes vector
    auto it = std::find(_unstagedScenes.begin(), _unstagedScenes.end(), scene);

    // If the scene is found, move it to the _stagedScenes vector
    if (it != _unstagedScenes.end()) {
        _stagedScenes.push_back(std::move(*it));
        _unstagedScenes.erase(it);
    } else {
        // If the scene is not found, add it to the _stagedScenes vector
        _stagedScenes.push_back(std::move(scene));
    }
}

void SceneManager::unstageScene(std::shared_ptr<Scene> scene)
{
    // Find the scene in the _stagedScenes vector
    auto it = std::find(_stagedScenes.begin(), _stagedScenes.end(), scene);

    // If the scene is found, move it to the _unstagedScenes vector
    if (it != _stagedScenes.end()) {
        _unstagedScenes.push_back(std::move(*it));
        _stagedScenes.erase(it);
    } else {
        // If the scene is not found, add it to the _unstagedScenes vector
        _unstagedScenes.push_back(std::move(scene));
    }
}
