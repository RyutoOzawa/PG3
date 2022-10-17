#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

typedef void (*Pfunc)();

//コールバック関数
void Callback() {
	//ランダムな値を返す
	printf("結果:%d\n",rand());
}

void SetTimeOut(Pfunc p, int second) {
	//引数秒待機
	printf("待機中...\n");
	Sleep(second * 1000);
	//コールバック関数の呼び出し
	p();
}

int main() {
	
	srand(time(nullptr));
	
	
	Pfunc p;
	p = Callback;
	printf("値を入力して下さい\n");
	int num = 0;
	scanf_s("%d", &num);

	SetTimeOut(p, 3);

	//結果が偶数の場合
	if (num %2 ==0) {
		printf("入力された値は偶数です\n");
	}
	else {
		printf("入力された値は奇数です\n");
	}


	return 0;
}