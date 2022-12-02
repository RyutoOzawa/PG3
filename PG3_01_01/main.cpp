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
	list.Create(cell, "abcde");
	list.Create(cell, "aaaaa");
	list.Create(cell, "bbbbb");
	list.Create(cell, "ccccc");
	

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
				if (datanum < allCellCount) {
					CELL* displayCell = cell;
					for (int i = 0; i < allCellCount; i++) {
						displayCell = displayCell->next;
					}
					printf("%d : %s\n", allCellCount, displayCell->data);
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
			scanf_s("%d\n" ,&editInput);

			//�v�f������ꍇ
			if(true){}
			//�v�f���Ȃ��ꍇ
			else {}

			//���j���[�ɖ߂�
			inputNum = 0;
		}
		else if (inputNum == INSERT) {
			printf("[�v�f�̑}��]\n");
		}
		else if (inputNum == DELETE) {
			printf("[�v�f�̍폜]\n");
		}
		else if (inputNum == SORT) {
			printf("[�v�f�̕��ёւ�]\n");
		}
		else {
			printf("���̓G���[");
			inputNum = 0;
		}
	}


	return 0;
}