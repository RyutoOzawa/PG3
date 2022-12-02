#include<stdio.h>
#include"List.h"


enum ListState {
	MENU,	//0,メニュー
	DISPLAY,//1,要素表示
	INSERT,	//2,挿入
	EDIT,	//3,編集
	DELETE,	//4,削除
	SORT,	//5,並び替え
};

int main() {
	int inputNum = 0;
	int allCellCount = 0;
	CELL* cell = new CELL;
	cell->next = nullptr;
	List list;
	strcpy_s(cell->data, 6, "aiueo");
	list.Create(cell, "ABC");
	while (1)
	{
		//入力された番号によって表示変更
		if (inputNum == MENU) {

			printf("[要素の操作]\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");
			printf("3.要素の編集\n");

			//要素が1以上の時のみ表示
			if (cell) {
				printf("4.要素の削除\n");
				printf("5.要素の並び替え(オプション)\n");
			}

			printf("\n");
			printf("-----------------------------\n");
			printf("操作を選択してください\n");
			scanf_s("%d", &inputNum);

		}
		else if (inputNum == DISPLAY) {
			int disprayInput = 0;
			printf("[要素の表示]\n");
			printf("1.要素の一覧表示\n");
			printf("2.要素を指定して要素を表示\n");
			printf("9.要素操作に戻る\n");
			printf("\n");
			printf("操作を選択してください\n");
			scanf_s("%d", &disprayInput);
			while (disprayInput != 1 && disprayInput != 2 && disprayInput != 9) {
				printf("入力エラー:操作を入力してください\n");
				scanf_s("%d", &disprayInput);
			}
			if (disprayInput == 1) {
				printf("[要素の一覧表示]\n");
				printf("要素一覧:{\n");
				//要素の一覧表示をここに
				list.Index(cell);

				printf("\n");
				printf("-------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");
				scanf_s("%d", &inputNum);
				if (inputNum == 1) {
					inputNum = DISPLAY;
				}
				else if (inputNum == 2) {
					inputNum = MENU;
				}

			}
			else if (disprayInput == 2) {
				printf("[順番を指定して要素を表示]\n");
				printf("表示したい要素の順番を指定してください\n");
				int datanum = 0;
				scanf_s("%d", &datanum);
				//データ番号使って要素を表示
				//要素の数を調べる
				allCellCount = list.GetAllCell(cell);
				printf("\n");
				if (datanum <= allCellCount) {
					CELL* displayCell = cell;
					for (int i = 0; i < datanum-1; i++) {
						displayCell = displayCell->next;
					}
					printf("%d : %s\n", datanum, displayCell->data);
				}
				else {
					printf("指定要素が範囲外です");
				}
				printf("\n");
				printf("-------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");
				scanf_s("%d", &inputNum);

			}
			else if (disprayInput == 9) {
				inputNum = MENU;
			}


		}
		else if (inputNum == EDIT) {
			printf("[要素の編集]\n");
			printf("編集したい要素の番号を指定してください\n");
			int editInput = 0;
			int cellCount = 0;
			char insertStr[8]{};
			CELL* insertCell;
			scanf_s("%d" ,&editInput);
			//入力番号にセルがあるか探索
			insertCell = list.GetInsertCellAdress(cell, editInput-1);
			cellCount = list.GetAllCell(cell);
			//要素がある場合
			if(cellCount > editInput-1){
				printf("新しい要素を入力してください\n");
				scanf_s("%s", &insertStr, 8);
				//選んだ要素の文字列を書き換える
				strcpy_s(insertCell->data, 8, insertStr);
				printf("要素は編集されました\n\n");

			}
			//要素がない場合
			else {
				printf("要素が見つかりませんでした\n");
			}

			//メニューに戻る
			inputNum = MENU;
		}
		else if (inputNum == INSERT) {
		int insertNum = 0;
		char insertStr[8]{};
		CELL* insertCell;
		int cellCount = list.GetAllCell(cell);
			printf("[要素の挿入]\n");
			printf("要素を追加する場所を指定してください。最後尾に追加する場合は「-1」を入力してください\n");
			scanf_s("%d", &insertNum);
			//入力がセルの最大数以上か-1なら最大数に
			if (cellCount < insertNum || insertNum == -1) {
				insertNum = cellCount;
			}
			printf("追加する要素の値を入力してください\n");
			scanf_s("%s", &insertStr,8);

			//指定場所にセルを作成
			insertCell = list.GetInsertCellAdress(cell, insertNum);
			list.Create(insertCell, insertStr);
	
			//メニューに戻る
			printf("要素は追加されました\n");
			inputNum = MENU;
		}
		else if (inputNum == DELETE) {
			printf("[要素の削除]\n");
			int deleteInput = 0;
			int cellCount = 0;
			CELL* deleteCell;
			printf("削除したい要素を選択してください\n");
			scanf_s("%d", &deleteInput);
			
			//セルがあるか調べる(なかったらメニューに戻る)
			deleteCell = list.GetInsertCellAdress(cell, deleteInput-1);
			cellCount = list.GetAllCell(cell);
			if (deleteInput < cellCount) {
				list.DeleteCell(cell, deleteInput-1);

				printf("要素は削除されました\n\n");

			}
			else {
				printf("要素が見つかりませんでした\n\n");
			}

			inputNum = MENU;

		}
		else if (inputNum == SORT) {
			printf("[要素の並び替え]\n");
			printf("要素の並び替えは未実装です；；\n\n");
			inputNum = MENU;

		}
		else {
			printf("入力エラー\n\n");
			inputNum = 0;
		}
	}


	return 0;
}