#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<functional>

typedef void (*Pfunc)(int);

//�R�[���o�b�N�֐�
void Dice(int num) {
	//�����_���Ȓl��Ԃ�
	int randNum = rand();
	randNum  %= 6 + 1;
	printf("��������̌���:%d\n",randNum);
	
	if (num % 2 == randNum % 2) {
		printf("�v���C���[�̏����ł�");
	}
	else {
		printf("�v���C���[�̕����ł�");
	}


}

//void SetTimeOut(Pfunc p, int second,int num) {
//	//�����b�ҋ@
//	printf("�ҋ@��...\n");
//	Sleep(second * 1000);
//	//�R�[���o�b�N�֐��̌Ăяo��
//	p(num);
//}

int main(int argc,const char *argv[]) {
	
	srand(time(nullptr));
	
	
	Pfunc diceFuncP;
	diceFuncP = Dice;
	int num = 0;
	printf("����Ǝv���Ȃ��1,�������Ǝv���Ȃ��2�������Ă�������\n");
	while (true) {
		scanf_s("%d", &num);
		//���͒l��2��1�Ȃ烋�[�v�I���
		if (num == 2 || num == 1) {
			break;
		}
		else {
			//�ݒ�l�ȊO�Ȃ�G���[���b�Z�[�W
			printf("���͒l�G���[:1��2����͂��Ă�������\n");
		}
	}

	//�^�C���A�E�g�֐�
	std::function<void(Pfunc ,int)> SetTimeOut= [=](Pfunc func, int second) {
		//�ҋ@��Ɏ��s
		printf("�ҋ@��...\n");
		Sleep(second);
		func(num);
	};
	SetTimeOut(diceFuncP, 3000);


	return 0;
}