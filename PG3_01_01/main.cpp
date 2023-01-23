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

	printf("1を押すと次のシーンへ移動します。\n");
	if (sceneManager->sceneNo == Title) {
		printf("現在のシーン:タイトル\n");
	}
	else if (sceneManager->sceneNo == NewGame) {
		printf("現在のシーン:ニューゲーム\n");
	}
	else if (sceneManager->sceneNo == GamePlay) {
		printf("現在のシーン:げーむぷれい\n");
	}
	else if (sceneManager->sceneNo == GameClear) {
		printf("現在のシーン:タイトル\n");
	}


	printf("nowScene:%d\n", sceneManager->sceneNo);
	
	return 0;
}