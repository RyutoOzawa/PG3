#include<stdio.h>
#include"List.h"


enum ListState {
	MENU,	//0,���j���[
	DISPLAY,//1,�v�f�\��
	INSERT,	//2,�}��
	EDIT,	//3,�ҏW
	DELETE,	//4,�폜
	SORT,	//5,���ёւ�
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
		//���͂��ꂽ�ԍ��ɂ���ĕ\���ύX
		if (inputNum == MENU) {

			printf("[�v�f�̑���]\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");
			printf("3.�v�f�̕ҏW\n");

			//�v�f��1�ȏ�̎��̂ݕ\��
			if (cell) {
				printf("4.�v�f�̍폜\n");
				printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
			}

			printf("\n");
			printf("-----------------------------\n");
			printf("�����I�����Ă�������\n");
			scanf_s("%d", &inputNum);

		}
		else if (inputNum == DISPLAY) {
			int disprayInput = 0;
			printf("[�v�f�̕\��]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.�v�f���w�肵�ėv�f��\��\n");
			printf("9.�v�f����ɖ߂�\n");
			printf("\n");
			printf("�����I�����Ă�������\n");
			scanf_s("%d", &disprayInput);
			while (disprayInput != 1 && disprayInput != 2 && disprayInput != 9) {
				printf("���̓G���[:�������͂��Ă�������\n");
				scanf_s("%d", &disprayInput);
			}
			if (disprayInput == 1) {
				printf("[�v�f�̈ꗗ�\��]\n");
				printf("�v�f�ꗗ:{\n");
				//�v�f�̈ꗗ�\����������
				list.Index(cell);

				printf("\n");
				printf("-------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");
				scanf_s("%d", &inputNum);
				if (inputNum == 1) {
					inputNum = DISPLAY;
				}
				else if (inputNum == 2) {
					inputNum = MENU;
				}

			}
			else if (disprayInput == 2) {
				printf("[���Ԃ��w�肵�ėv�f��\��]\n");
				printf("�\���������v�f�̏��Ԃ��w�肵�Ă�������\n");
				int datanum = 0;
				scanf_s("%d", &datanum);
				//�f�[�^�ԍ��g���ėv�f��\��
				//�v�f�̐��𒲂ׂ�
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
					printf("�w��v�f���͈͊O�ł�");
				}
				printf("\n");
				printf("-------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");
				scanf_s("%d", &inputNum);

			}
			else if (disprayInput == 9) {
				inputNum = MENU;
			}


		}
		else if (inputNum == EDIT) {
			printf("[�v�f�̕ҏW]\n");
			printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
			int editInput = 0;
			int cellCount = 0;
			char insertStr[8]{};
			CELL* insertCell;
			scanf_s("%d" ,&editInput);
			//���͔ԍ��ɃZ�������邩�T��
			insertCell = list.GetInsertCellAdress(cell, editInput-1);
			cellCount = list.GetAllCell(cell);
			//�v�f������ꍇ
			if(cellCount > editInput-1){
				printf("�V�����v�f����͂��Ă�������\n");
				scanf_s("%s", &insertStr, 8);
				//�I�񂾗v�f�̕����������������
				strcpy_s(insertCell->data, 8, insertStr);
				printf("�v�f�͕ҏW����܂���\n\n");

			}
			//�v�f���Ȃ��ꍇ
			else {
				printf("�v�f��������܂���ł���\n");
			}

			//���j���[�ɖ߂�
			inputNum = MENU;
		}
		else if (inputNum == INSERT) {
		int insertNum = 0;
		char insertStr[8]{};
		CELL* insertCell;
		int cellCount = list.GetAllCell(cell);
			printf("[�v�f�̑}��]\n");
			printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�́u-1�v����͂��Ă�������\n");
			scanf_s("%d", &insertNum);
			//���͂��Z���̍ő吔�ȏォ-1�Ȃ�ő吔��
			if (cellCount < insertNum || insertNum == -1) {
				insertNum = cellCount;
			}
			printf("�ǉ�����v�f�̒l����͂��Ă�������\n");
			scanf_s("%s", &insertStr,8);

			//�w��ꏊ�ɃZ�����쐬
			insertCell = list.GetInsertCellAdress(cell, insertNum);
			list.Create(insertCell, insertStr);
	
			//���j���[�ɖ߂�
			printf("�v�f�͒ǉ�����܂���\n");
			inputNum = MENU;
		}
		else if (inputNum == DELETE) {
			printf("[�v�f�̍폜]\n");
			int deleteInput = 0;
			int cellCount = 0;
			CELL* deleteCell;
			printf("�폜�������v�f��I�����Ă�������\n");
			scanf_s("%d", &deleteInput);
			
			//�Z�������邩���ׂ�(�Ȃ������烁�j���[�ɖ߂�)
			deleteCell = list.GetInsertCellAdress(cell, deleteInput-1);
			cellCount = list.GetAllCell(cell);
			if (deleteInput < cellCount) {
				list.DeleteCell(cell, deleteInput-1);

				printf("�v�f�͍폜����܂���\n\n");

			}
			else {
				printf("�v�f��������܂���ł���\n\n");
			}

			inputNum = MENU;

		}
		else if (inputNum == SORT) {
			printf("[�v�f�̕��ёւ�]\n");
			printf("�v�f�̕��ёւ��͖������ł��G�G\n\n");
			inputNum = MENU;

		}
		else {
			printf("���̓G���[\n\n");
			inputNum = 0;
		}
	}


	return 0;
}