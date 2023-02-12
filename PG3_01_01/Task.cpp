#include "Task.h"

std::vector<Task> Task::tasks;

enum updateIndex {
	Name = 1,
	Content = 2,
	IsComplete = 3,
	Prioriry = 4,
};

void Task::Create(std::string name, Manager manager, std::string content, int priority)
{
	Task newTask;

	//ID��z��̉����疄�߂Ă���
	int newId = 0;
	if (tasks.empty()) {
		newId = 1;
	}
	else {
		newId = tasks.size() + 1;
	}
	newTask.id = newId;

	newTask.name = name;
	if (content != "NULL") {
		newTask.content = "���e�͂���܂���";
	}
	newTask.priority = priority;
	newTask.isComplete = false;
	newTask.manager = manager;
	//�^�X�N�̂܂Ƃ܂�ɓ����
	tasks.push_back(newTask);
	printf("�^�X�N�͍쐬����܂��� ID:%d\n",newId);
}



void Task::Update(int id)
{
	for (int i = 0; i < tasks.size(); i++) {
		printf("�s�������I�����Ă�������\n");
		printf("���O�̕ύX:1\n");
		printf("���e�̕ύX:2\n");
		printf("�����x�̕ύX:3\n");
		printf("�D��x�̕ύX:4\n");
		int input = 0;
		scanf_s("%d", &input);
		if (input == Name) {
			printf("�V�������O����͂��Ă�������\n");
			char newName[256];
			scanf_s("%s", newName, 256);
			tasks[i].SetName(newName);
			printf("����ɕύX����܂���\n");
		}
		else if (input == Content) {
			printf("�V�������e����͂��Ă�������\n");
			char newContent[256];
			scanf_s("%s", newContent, 256);
			tasks[i].SetContent(newContent);
			printf("����ɕύX����܂���\n");
		}
		else if (input == IsComplete) {
			printf("�^�X�N�����������Ȃ�1���A�������Ȃ炻��ȊO�������Ă�������");
			int isTaskComp = 0;
			scanf_s("%d", &isTaskComp);
			if (isTaskComp == 1) {
				tasks[i].SetComplete(true);
			}
			else {
				tasks[i].SetComplete(false);
			}
			printf("����ɕύX����܂���\n");
		}
		else if (input == Prioriry) {
			printf("�D��x����͂��Ă��������B�D��x�͍ő�(�ł��D��)��1�A�ŏ���5�ł���A�f�t�H���g��1�ɐݒ肳��Ă��܂�\n");
			int newPry = 0;
			scanf_s("%d", &newPry);
			if (newPry <= 1) {
				tasks[i].SetPriority(1);
			}
			else if (newPry >= 5) {
				tasks[i].SetPriority(5);
			}
			else {
				tasks[i].SetPriority(newPry);
			}

			printf("����ɕύX����܂���\n");
		}
		else {
			printf("���̓G���[:�ŏ������蒼���Ă�������\n");
		}

		return;
	}

	printf("�^�X�N��������܂���ł���\n");
}
