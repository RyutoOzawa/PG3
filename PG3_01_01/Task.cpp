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

	//IDを配列の下から埋めていく
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
		newTask.content = "内容はありません";
	}
	newTask.priority = priority;
	newTask.isComplete = false;
	newTask.manager = manager;
	//タスクのまとまりに入れる
	tasks.push_back(newTask);
	printf("タスクは作成されました ID:%d\n",newId);
}



void Task::Update(int id)
{
	for (int i = 0; i < tasks.size(); i++) {
		printf("行う操作を選択してください\n");
		printf("名前の変更:1\n");
		printf("内容の変更:2\n");
		printf("完了度の変更:3\n");
		printf("優先度の変更:4\n");
		int input = 0;
		scanf_s("%d", &input);
		if (input == Name) {
			printf("新しい名前を入力してください\n");
			char newName[256];
			scanf_s("%s", newName, 256);
			tasks[i].SetName(newName);
			printf("正常に変更されました\n");
		}
		else if (input == Content) {
			printf("新しい内容を入力してください\n");
			char newContent[256];
			scanf_s("%s", newContent, 256);
			tasks[i].SetContent(newContent);
			printf("正常に変更されました\n");
		}
		else if (input == IsComplete) {
			printf("タスクが完了したなら1を、未完了ならそれ以外を押してください");
			int isTaskComp = 0;
			scanf_s("%d", &isTaskComp);
			if (isTaskComp == 1) {
				tasks[i].SetComplete(true);
			}
			else {
				tasks[i].SetComplete(false);
			}
			printf("正常に変更されました\n");
		}
		else if (input == Prioriry) {
			printf("優先度を入力してください。優先度は最大(最も優先)で1、最小で5であり、デフォルトは1に設定されています\n");
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

			printf("正常に変更されました\n");
		}
		else {
			printf("入力エラー:最初からやり直してください\n");
		}

		return;
	}

	printf("タスクが見つかりませんでした\n");
}
