#pragma once
#include<vector>
#include<string>

struct CELL {
	char data[8];
	CELL* prev = nullptr;
	CELL* next = nullptr;
};


class List
{
public:
	//���X�g�̐���
	void Create(CELL* currentCell, const char* data) {
		CELL* newCell;
		newCell = (CELL*)malloc(sizeof(CELL));
		strcpy_s( newCell->data ,8, data);
		newCell->prev = currentCell;
		newCell->next = nullptr;

		//�Ō���ɑ}���ł���悤�ɂ���
		if (currentCell->next) {
			CELL* newCell = currentCell->next;
			newCell->prev = newCell;
		}

		currentCell->next = newCell;

	};

	//�Z���ꗗ�\��
	void Index(CELL* endCell) {
		int no = 0;
		while (endCell->next != nullptr) {
			no++;
			printf("%d:", no);
			printf("%s,\n", endCell->data);
			endCell = endCell->next;
			

		}
		no++;
		printf("%d:", no);
		printf("%s\n", endCell->data);
		printf("\n");
		printf("�v�f��:%d\n", no);
	};

	//�C�ӂ̈ʒu�̃Z���̃A�h���X���擾
	CELL* GetInsertCellAdress(CELL* cell, int iterator) {
		//�Z�����C�e���[�^�̐������i�߂�
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
		int allnum = 1;
		CELL* insertCell = cell;
		while (insertCell->next != nullptr)
		{
			insertCell = insertCell->next;
			allnum++;
		}

		return allnum;
	}

	void DeleteCell(CELL* cell,int iterator) {
		CELL* newcell = cell;

		for (size_t i = 0; i < iterator; i++) {
			newcell = newcell->next;
		}

		if (newcell->next == nullptr) {
			newcell->prev->next = nullptr;
		}
		else {
			newcell->prev->next = newcell->next;
			newcell->next->prev = newcell->prev;
		}
	}
};

