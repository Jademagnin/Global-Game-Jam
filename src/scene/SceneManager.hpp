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
        static SceneManager& getInstance()
        {
            static SceneManager instance;
            return instance;
        }
        void switchScene(std::shared_ptr<Scene> scene);
        void popScene();
        Scene* getTopScene();
        void stageScene(std::shared_ptr<Scene> scene);
        void unstageScene(std::shared_ptr<Scene> scene);
        std::vector<std::shared_ptr<Scene>> getStagedScenes() const { return _stagedScenes; };
        std::vector<std::shared_ptr<Scene>> getUnstagedScenes() const { return _unstagedScenes; };
        void setMouseScene(std::shared_ptr<Scene> scene) { _mouseScene = scene; };
        std::shared_ptr<Scene> getMouseScene() const { return _mouseScene; };

    private:
        SceneManager() {};
        SceneManager(SceneManager const&) = delete;
        void operator=(SceneManager const&) = delete;

        std::vector<std::shared_ptr<Scene>> _stagedScenes;
        std::vector<std::shared_ptr<Scene>> _unstagedScenes;
        std::shared_ptr<Scene> _mouseScene;
};

// class UniqueSceneManager
// {
//     public:
//         static SceneManager& getInstance()
//         {
//             static SceneManager instance;
//             return instance;
//         }
//         SceneManager instance = SceneManager();
//     private:
//         UniqueSceneManager() {};
// };

#endif /* !SCENEMANAGER_HPP_ */
