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

	printf("1�������Ǝ��̃V�[���ֈړ����܂��B\n");
	if (sceneManager->sceneNo == Title) {
		printf("���݂̃V�[��:�^�C�g��\n");
	}
	else if (sceneManager->sceneNo == NewGame) {
		printf("���݂̃V�[��:�j���[�Q�[��\n");
	}
	else if (sceneManager->sceneNo == GamePlay) {
		printf("���݂̃V�[��:���[�ނՂꂢ\n");
	}
	else if (sceneManager->sceneNo == GameClear) {
		printf("���݂̃V�[��:�^�C�g��\n");
	}


	printf("nowScene:%d\n", sceneManager->sceneNo);
	
	return 0;
}