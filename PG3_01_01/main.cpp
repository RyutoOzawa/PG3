#include<stdio.h>
#include"SceneManager.h"
#include"Enemy.h"



int main() {
	Enemy enemy;
	
	int input = 0;

	while (true)
	{


		printf("�C�ӂ̃L�[����œG�̍s�����ς��܂�\n1:�ڋ�\n2:�U��\n3:���E\n");
		printf("���݂̍s���ԍ�:%d\n", enemy.state);
		scanf_s("%d", &input);
		//���͒l�ɏ�ԕύX
		enemy.state = input-1;

		//�֐����s
		enemy.Update();
	}
	//printf("nowScene:%d\n", sceneManager->sceneNo);
	
	return 0;
}