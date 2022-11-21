#include "SceneManager.h"

SceneManager::~SceneManager()
{
}

SceneManager* SceneManager::GetInstance()
{
    //�֐���static�ϐ��Ƃ��Đ錾����
    static SceneManager instance;

    return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
    this->sceneNo = sceneNo;
}