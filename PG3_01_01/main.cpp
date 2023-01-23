#include<stdio.h>
#include"SceneManager.h"
#include"Enemy.h"



int main() {
	Enemy enemy1;
	Enemy enemy2;
	Enemy enemy3;
	
	int input = 0;


		printf("1‚ð‰Ÿ‚·‚Æ“G‚ðƒLƒ‹‚µ‚Ü‚·B\n");
		printf("Œ»Ý‚Ì“G‚Ì”:%d\n", Enemy::allEnemyCount);
		scanf_s("%d", &input);
		if (input == 1) {
			enemy1.Kill();
		}
		
		printf("‚·‚×‚Ä‚Ì“G‚ðƒLƒ‹‚µ‚Ü‚µ‚½\n");
		printf("Œ»Ý‚Ì“G‚Ì”:%d\n", Enemy::allEnemyCount);

	//printf("nowScene:%d\n", sceneManager->sceneNo);
	
	return 0;
}