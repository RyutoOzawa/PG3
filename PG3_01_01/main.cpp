#include<stdio.h>
#include"SceneManager.h"
#include"Enemy.h"



int main() {
	Enemy enemy1;
	Enemy enemy2;
	Enemy enemy3;
	
	int input = 0;


		printf("1�������ƓG���L�����܂��B\n");
		printf("���݂̓G�̐�:%d\n", Enemy::allEnemyCount);
		scanf_s("%d", &input);
		if (input == 1) {
			enemy1.Kill();
		}
		
		printf("���ׂĂ̓G���L�����܂���\n");
		printf("���݂̓G�̐�:%d\n", Enemy::allEnemyCount);

	//printf("nowScene:%d\n", sceneManager->sceneNo);
	
	return 0;
}