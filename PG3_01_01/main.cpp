#include<stdio.h>
#include"SceneManager.h"
#include"Enemy.h"



int main() {
	Enemy enemy1;
	Enemy enemy2;
	Enemy enemy3;
	
	int input = 0;


		printf("1を押すと敵をキルします。\n");
		printf("現在の敵の数:%d\n", Enemy::allEnemyCount);
		scanf_s("%d", &input);
		if (input == 1) {
			enemy1.Kill();
		}
		
		printf("すべての敵をキルしました\n");
		printf("現在の敵の数:%d\n", Enemy::allEnemyCount);

	//printf("nowScene:%d\n", sceneManager->sceneNo);
	
	return 0;
}