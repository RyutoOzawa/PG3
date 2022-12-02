#pragma once
#include<vector>
#include<string>

struct CELL {
	char data[8];
	CELL* next = nullptr;
};


class List
{
public:
	//リストの生成
	void Create(CELL* currentCell, const char* data) {
		CELL* newCell;
		//新規セルのメモリ確保
		newCell = (CELL*)malloc(sizeof(CELL));
		strcpy_s( newCell->data ,8, data);
		newCell->next = nullptr;

		while (currentCell->next != nullptr)
		{
			currentCell = currentCell->next;
		}

		currentCell->next = newCell;

	};

	//セル一覧表示
	void Index(CELL* endCell) {
		int no = 1;
		while (endCell->next != nullptr) {
			printf("%d:", no);
			printf("%s,\n", endCell->data);
			endCell = endCell->next;
			
			no++;
		}
		printf("%d:", no);
		printf("%s\n", endCell->data);

		printf("\n");
		printf("要素数:%d\n", no);
	};

	//任意の位置のセルのアドレスを取得
	CELL* GetInsertCellAdress(CELL* cell, int iterator) {
		//セルをイテレータの数だけ進める
		for (int i = 0; i < iterator; i++) {
			if (cell->next) {
				cell = cell->next;
			}
			else {
				break;
			}
		}
		return cell;
	}

	int GetAllCell(CELL* cell) {
		int allnum = 0;
		CELL* insertCell = cell;
		while (insertCell->next != nullptr)
		{
			insertCell = insertCell->next;
			allnum++;
		}

		return allnum;
	}
};

