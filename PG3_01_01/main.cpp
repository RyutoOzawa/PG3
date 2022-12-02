#include<stdio.h>
#include"List.h"


enum ListState {
	MENU,	//0,メニュー
	DISPLAY,//1,要素表示
	INSERT,	//2,挿入
	DELETE,	//3,削除
};

int main() {
	int inputNum = 0;
	int allCellCount = 0;
	CELL* cell = new CELL;
	cell->next = nullptr;
	List list;

	strcpy_s(cell->data, 6, "aiueo");
	list.Create(cell, "abcde");
	list.Create(cell, "aaaaa");
	list.Create(cell, "bbbbb");
	list.Create(cell, "ccccc");


	while (1)
	{
		//入力された番号によって表示変更
		if (inputNum == MENU) {

			printf("[要素の操作]\n");
			printf("1.要素の表示\n");
			printf("2.最後尾に要素の挿入\n");
			printf("3.最後尾の要素の削除\n");

			printf("\n");
			printf("-----------------------------\n");
			printf("操作を選択してください\n");
			scanf_s("%d", &inputNum);

		}
		else if (inputNum == DISPLAY) {

			printf("[要素の一覧表示]\n");
			printf("要素一覧:{\n");
			//要素の一覧表示をここに
			list.Index(cell);

			printf("\n");
			printf("-------------------------\n");
			printf("0.初期画面に戻る\n");
			scanf_s("%d", &inputNum);
			if (inputNum == 0) {
				inputNum = MENU;
			}
			else {
				printf("入力エラー\n");
				break;
			}

		}

		else if (inputNum == INSERT) {
			printf("[要素の挿入]\n");
		}
		else if (inputNum == DELETE) {
			printf("[要素の削除]\n");
		}
		else {
			printf("入力エラー");
			inputNum = 0;
		}
	}


	return 0;
}