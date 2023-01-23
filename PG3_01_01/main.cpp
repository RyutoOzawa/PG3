#include<stdio.h>
#include"SceneManager.h"
#include"Enemy.h"



int main() {
	Enemy enemy;
	
	int input = 0;

	while (true)
	{


		printf("”CˆÓ‚ÌƒL[‘€ì‚Å“G‚Ìs“®‚ª•Ï‚í‚è‚Ü‚·\n1:Ú‹ß\n2:UŒ‚\n3:—£’E\n");
		printf("Œ»Ý‚Ìs“®”Ô†:%d\n", enemy.state);
		scanf_s("%d", &input);
		//“ü—Í’l‚Éó‘Ô•ÏX
		enemy.state = input-1;

		//ŠÖ”ŽÀs
		enemy.Update();
	}
	//printf("nowScene:%d\n", sceneManager->sceneNo);
	
	return 0;
}