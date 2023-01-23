#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<functional>

typedef void (*Pfunc)(int);

//コールバック関数
void Dice(int num) {
	//ランダムな値を返す
	int randNum = rand();
	randNum  %= 6 + 1;
	printf("さいころの結果:%d\n",randNum);
	
	if (num % 2 == randNum % 2) {
		printf("プレイヤーの勝ちです");
	}
	else {
		printf("プレイヤーの負けです");
	}


}

//void SetTimeOut(Pfunc p, int second,int num) {
//	//引数秒待機
//	printf("待機中...\n");
//	Sleep(second * 1000);
//	//コールバック関数の呼び出し
//	p(num);
//}

int main(int argc,const char *argv[]) {
	
	srand(time(nullptr));
	
	
	Pfunc diceFuncP;
	diceFuncP = Dice;
	int num = 0;
	printf("奇数だと思うならば1,偶数だと思うならば2を押してください\n");
	while (true) {
		scanf_s("%d", &num);
		//入力値が2か1ならループ終わり
		if (num == 2 || num == 1) {
			break;
		}
		else {
			//設定値以外ならエラーメッセージ
			printf("入力値エラー:1か2を入力してください\n");
		}
	}

	//タイムアウト関数
	std::function<void(Pfunc ,int)> SetTimeOut= [=](Pfunc func, int second) {
		//待機後に実行
		printf("待機中...\n");
		Sleep(second);
		func(num);
	};
	SetTimeOut(diceFuncP, 3000);


	return 0;
}