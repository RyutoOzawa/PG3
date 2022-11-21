#include<stdio.h>
#include"SceneManager.h"

enum sceneIndex {
	Title,
	NewGame,
	GamePlay,
	GameClear,
};

int main() {
	SceneManager* sceneManager = SceneManager::GetInstance();
	int nextNum = 0;



	printf("nowScene:%d\n", sceneManager->sceneNo);
	
	return 0;
}