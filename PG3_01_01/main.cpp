#include<stdio.h>
#include"Task.h"
#include"Manager.h"
using namespace std;

enum ApplicationState {
	STATE_0,
	STATE_1,
	ApplicationStateCount,
};

enum phase1 {
	IsSelectManager = 1,
	IsSelectTask = 2,
};

enum phase2 {
	IsSelectCreate = 1,
	IsSelectUpdate = 2,
	IsSelectDelete = 3,
};

void DrawLine();

int main() {
	int selectNumber[ApplicationStateCount]{};

	printf("�^�X�N�Ǘ��V�X�e��\n");

	while (true)
	{

		printf("���삵�����ԍ���I��ł�������\n");
		printf("�S���҂̑���:1\n");
		printf("�^�X�N�̑���:2\n");
		scanf_s("%d", &selectNumber[STATE_0]);

		//�S���ґ��삪�I�����ꂽ
		if (selectNumber[STATE_0] == IsSelectManager) {
			printf("�s�������I�����Ă�������\n");
			printf("�S���҂̐V�K�쐬:1\n");
			printf("�S���҂̏��X�V:2\n");
			printf("�S���҂̍폜:3\n");
			scanf_s("%d,", &selectNumber[STATE_1]);
			if (selectNumber[STATE_1] == IsSelectCreate) {
				char newName[256], classMember[256];
				printf("�V�����S���҂̖��O����͂��Ă�������\n");
				scanf_s("%s", newName, 256);
				string nameStr = newName;
				printf("�S���҂̃N���X����͂��Ă�������\n");
				scanf_s("%s", classMember, 256);
				string classStr = classMember;
				Manager::Create(nameStr, classStr);
				printf("�N���X:%s��%s���ǉ�����܂����BID:%d\n", classStr.c_str(), nameStr.c_str(), Manager::managers[Manager::managers.size() - 1].id);
				DrawLine();
			}
			else if (selectNumber[STATE_1] == IsSelectUpdate) {
				char oldName[256], newName[256], classMember[256];
				printf("�X�V�������S���҂̖��O����͂��Ă�������\n");
				scanf_s("%s", oldName, 256);
				printf("�V�������O����͂��Ă�������\n");
				scanf_s("%s", newName, 256);
				printf("�V�����N���X����͂��Ă�������\n");
				scanf_s("%s", classMember, 256);
				Manager::UpdateData(oldName, newName, classMember);
				DrawLine();
			}
			else if (selectNumber[STATE_1] == IsSelectDelete) {
				char deleteName[256];
				printf("�폜�������S���҂̖��O����͂��Ă�������\n");
				scanf_s("%s", deleteName, 256);
				Manager::DeleteManager(deleteName);
				DrawLine();
			}
			else {
				printf("���̓G���[�ł��B�ŏ������蒼���Ă�������\n");
				DrawLine();
			}

		}//�^�X�N���삪�I�����ꂽ
		else if (selectNumber[STATE_0] == IsSelectTask) {
			printf("�s�������I�����Ă�������\n");
			printf("�^�X�N�̐V�K�쐬:1\n");
			printf("�����^�X�N�̕ҏW:2\n");
			scanf_s("%d", &selectNumber[STATE_1]);
			if (selectNumber[STATE_1] == IsSelectCreate) {
				//�^�X�N�̐V�K�쐬
				printf("�^�X�N��V�K�쐬���܂�\n");
				char taskName[256], taskContent[256];
				printf("�V�����^�X�N�̖��O����͂��Ă�������\n");
				scanf_s("%s", taskName, 256);
				printf("�V�K�^�X�N�u%s�v�̓��e����͂��Ă�������\n", taskName);
				scanf_s("%s", taskContent, 256);
				printf("�S���҂�ID����͂��Ă�������\n");
				int id = -1;
				scanf_s("%d", &id);
				Manager newManager = Manager::Search(id);
				Task::Create(taskName, newManager, taskContent);
				
			}
			else if (selectNumber[STATE_1]) {
				//�^�X�N�̃X�e�[�^�X�X�V
				printf("���̍X�V���s���^�X�N��ID����͂��Ă�������\n");
				int id = -1;
				scanf_s("%d", &id);
				Task::Update(id);
			}
		}
		else {
			printf("���͒l�G���[:�������l����͂��Ă�������\n");
			DrawLine();
		}

		printf("�V�X�e���쓮��...\n");
	}

	return 0;
}

void DrawLine()
{
	printf("---------------------------------\n");
}
