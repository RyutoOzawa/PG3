#include "SceneManager.h"

SceneManager::~SceneManager()
{
}

SceneManager* SceneManager::GetInstance()
{
    //関数内static変数として宣言する
    static SceneManager instance;

    return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
    this->sceneNo = sceneNo;
}
