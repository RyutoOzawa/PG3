#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

typedef void (*Pfunc)(int);

//コールバック関数
void Dice(int num) {
	//ランダムな値を返す
	int randNum;
	randNum = rand() % 6 + 1;
	printf("さいころの結果:%d\n", randNum);
	if (randNum % 2 == num % 2) {
		printf("プレイヤーの勝ち\n");
	}
	else {
		printf("プレイヤーの負け");
	}
}

void SetTimeOut(Pfunc p, int second,int num) {
	//引数秒待機
	printf("待機中...\n");
	Sleep(second * 1000);
	//コールバック関数の呼び出し
	p(num);
}

int main() {
	
	srand(time(nullptr));
	Pfunc p;
	p = Dice;
	int num = 0;
	printf("奇数だと思うならば1,偶数だと思うならば2を押してください;\n");
	while (true) {
		scanf_s("%d", &num);
		if (num == 1 || num == 2) {
			break;
		}
		else {
			printf("入力値エラー:1か2を入力してください");
		}
	}
	SetTimeOut(p, 3,num);
	return 0;
}