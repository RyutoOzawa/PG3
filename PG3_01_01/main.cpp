#include<stdio.h>
#include"List.h"


enum ListState {
	MENU,	//0,���j���[
	DISPLAY,//1,�v�f�\��
	INSERT,	//2,�}��
	DELETE,	//3,�폜
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
			printf("2.�Ō���ɗv�f�̑}��\n");
			printf("3.�Ō���̗v�f�̍폜\n");

			printf("\n");
			printf("-----------------------------\n");
			printf("�����I�����Ă�������\n");
			scanf_s("%d", &inputNum);

		}
		else if (inputNum == DISPLAY) {

			printf("[�v�f�̈ꗗ�\��]\n");
			printf("�v�f�ꗗ:{\n");
			//�v�f�̈ꗗ�\����������
			list.Index(cell);

			printf("\n");
			printf("-------------------------\n");
			printf("0.������ʂɖ߂�\n");
			scanf_s("%d", &inputNum);
			if (inputNum == 0) {
				inputNum = MENU;
			}
			else {
				printf("���̓G���[\n");
				break;
			}

		}

		else if (inputNum == INSERT) {
			printf("[�v�f�̑}��]\n");
		}
		else if (inputNum == DELETE) {
			printf("[�v�f�̍폜]\n");
		}
		else {
			printf("���̓G���[");
			inputNum = 0;
		}
	}


	return 0;
}