#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

typedef void (*Pfunc)(int);

//�R�[���o�b�N�֐�
void Dice(int num) {
	//�����_���Ȓl��Ԃ�
	int randNum;
	randNum = rand() % 6 + 1;
	printf("��������̌���:%d\n", randNum);
	if (randNum % 2 == num % 2) {
		printf("�v���C���[�̏���\n");
	}
	else {
		printf("�v���C���[�̕���");
	}
}

void SetTimeOut(Pfunc p, int second,int num) {
	//�����b�ҋ@
	printf("�ҋ@��...\n");
	Sleep(second * 1000);
	//�R�[���o�b�N�֐��̌Ăяo��
	p(num);
}

int main() {
	
	srand(time(nullptr));
	Pfunc p;
	p = Dice;
	int num = 0;
	printf("����Ǝv���Ȃ��1,�������Ǝv���Ȃ��2�������Ă�������;\n");
	while (true) {
		scanf_s("%d", &num);
		if (num == 1 || num == 2) {
			break;
		}
		else {
			printf("���͒l�G���[:1��2����͂��Ă�������");
		}
	}
	SetTimeOut(p, 3,num);
	return 0;
}