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
	int nextScene = 0;

	int input = 0;

	while (true) {

		printf("1を押すと次のシーンへ移動します。\n");
		scanf_s("%d", &input);
		if (input == 1) {
			nextScene = sceneManager->sceneNo;
			nextScene++;
			if (nextScene > GameClear) {
				nextScene = Title;
			}
			sceneManager->ChangeScene(nextScene);
		}
		else {
			printf("シーンは移動しませんでした\n");
		}

		if (sceneManager->sceneNo == Title) {
			printf("現在のシーン:タイトル\n");
		}
		else if (sceneManager->sceneNo == NewGame) {
			printf("現在のシーン:ニューゲーム\n");
		}
		else if (sceneManager->sceneNo == GamePlay) {
			printf("現在のシーン:ゲームプレイ\n");
		}
		else if (sceneManager->sceneNo == GameClear) {
			printf("現在のシーン:ゲームクリア\n");
		}

	}
	//printf("nowScene:%d\n", sceneManager->sceneNo);
	
	return 0;
}