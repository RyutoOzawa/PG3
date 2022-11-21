#include "SceneManager.h"

SceneManager::~SceneManager()
{
}

SceneManager* SceneManager::GetInstance()
{
    //ŠÖ”“àstatic•Ï”‚Æ‚µ‚ÄéŒ¾‚·‚é
    static SceneManager instance;

    return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
    this->sceneNo = sceneNo;
}
