#include<stdio.h>
#include"SceneManager.h"
#include"Enemy.h"



int main() {
	Enemy enemy;
	
	int input = 0;

	while (true)
	{


		printf("任意のキー操作で敵の行動が変わります\n1:接近\n2:攻撃\n3:離脱\n");
		printf("現在の行動番号:%d\n", enemy.state);
		scanf_s("%d", &input);
		//入力値に状態変更
		enemy.state = input-1;

		//関数実行
		enemy.Update();
	}
	//printf("nowScene:%d\n", sceneManager->sceneNo);
	
	return 0;
}