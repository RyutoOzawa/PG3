#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

typedef void (*Pfunc)();

//�R�[���o�b�N�֐�
void Callback() {
	//�����_���Ȓl��Ԃ�
	printf("����:%d\n",rand());
}

void SetTimeOut(Pfunc p, int second) {
	//�����b�ҋ@
	printf("�ҋ@��...\n");
	Sleep(second * 1000);
	//�R�[���o�b�N�֐��̌Ăяo��
	p();
}

int main() {
	
	srand(time(nullptr));
	
	
	Pfunc p;
	p = Callback;
	printf("�l����͂��ĉ�����\n");
	int num = 0;
	scanf_s("%d", &num);

	SetTimeOut(p, 3);

	//���ʂ������̏ꍇ
	if (num %2 ==0) {
		printf("���͂��ꂽ�l�͋����ł�\n");
	}
	else {
		printf("���͂��ꂽ�l�͊�ł�\n");
	}


	return 0;
}