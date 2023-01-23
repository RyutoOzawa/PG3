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

		printf("1�������Ǝ��̃V�[���ֈړ����܂��B\n");
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
			printf("�V�[���͈ړ����܂���ł���\n");
		}

		if (sceneManager->sceneNo == Title) {
			printf("���݂̃V�[��:�^�C�g��\n");
		}
		else if (sceneManager->sceneNo == NewGame) {
			printf("���݂̃V�[��:�j���[�Q�[��\n");
		}
		else if (sceneManager->sceneNo == GamePlay) {
			printf("���݂̃V�[��:�Q�[���v���C\n");
		}
		else if (sceneManager->sceneNo == GameClear) {
			printf("���݂̃V�[��:�Q�[���N���A\n");
		}

	}
	//printf("nowScene:%d\n", sceneManager->sceneNo);
	
	return 0;
}