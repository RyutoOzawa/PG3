#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<functional>

typedef int (*Pfunc)(int);

//�R�[���o�b�N�֐�
int Dice(int num) {
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
	return randNum;

}

void SetTimeOut(Pfunc p, int second,int num) {
	//�����b�ҋ@
	printf("�ҋ@��...\n");
	Sleep(second * 1000);
	//�R�[���o�b�N�֐��̌Ăяo��
	p(num);
}

int main(int argc,const char *argv[]) {
	
	srand(time(nullptr));
	
	
	Pfunc p;
	p = Dice;
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

	std::function<void(Pfunc,int,int)> fx = [](Pfunc p,int second,int num){
		SetTimeOut(p, second,num);
	};
	fx(p, 3,num);


	return 0;
}