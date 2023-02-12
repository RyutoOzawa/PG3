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

	printf("タスク管理システム\n");

	while (true)
	{

		printf("操作したい番号を選んでください\n");
		printf("担当者の操作:1\n");
		printf("タスクの操作:2\n");
		scanf_s("%d", &selectNumber[STATE_0]);

		//担当者操作が選択された
		if (selectNumber[STATE_0] == IsSelectManager) {
			printf("行う操作を選択してください\n");
			printf("担当者の新規作成:1\n");
			printf("担当者の情報更新:2\n");
			printf("担当者の削除:3\n");
			scanf_s("%d,", &selectNumber[STATE_1]);
			if (selectNumber[STATE_1] == IsSelectCreate) {
				char newName[256], classMember[256];
				printf("新しい担当者の名前を入力してください\n");
				scanf_s("%s", newName, 256);
				string nameStr = newName;
				printf("担当者のクラスを入力してください\n");
				scanf_s("%s", classMember, 256);
				string classStr = classMember;
				Manager::Create(nameStr, classStr);
				printf("クラス:%sの%sが追加されました。ID:%d\n", classStr.c_str(), nameStr.c_str(), Manager::managers[Manager::managers.size() - 1].id);
				DrawLine();
			}
			else if (selectNumber[STATE_1] == IsSelectUpdate) {
				char oldName[256], newName[256], classMember[256];
				printf("更新したい担当者の名前を入力してください\n");
				scanf_s("%s", oldName, 256);
				printf("新しい名前を入力してください\n");
				scanf_s("%s", newName, 256);
				printf("新しいクラスを入力してください\n");
				scanf_s("%s", classMember, 256);
				Manager::UpdateData(oldName, newName, classMember);
				DrawLine();
			}
			else if (selectNumber[STATE_1] == IsSelectDelete) {
				char deleteName[256];
				printf("削除したい担当者の名前を入力してください\n");
				scanf_s("%s", deleteName, 256);
				Manager::DeleteManager(deleteName);
				DrawLine();
			}
			else {
				printf("入力エラーです。最初からやり直してください\n");
				DrawLine();
			}

		}//タスク操作が選択された
		else if (selectNumber[STATE_0] == IsSelectTask) {
			printf("行う操作を選択してください\n");
			printf("タスクの新規作成:1\n");
			printf("既存タスクの編集:2\n");
			scanf_s("%d", &selectNumber[STATE_1]);
			if (selectNumber[STATE_1] == IsSelectCreate) {
				//タスクの新規作成
				printf("タスクを新規作成します\n");
				char taskName[256], taskContent[256];
				printf("新しいタスクの名前を入力してください\n");
				scanf_s("%s", taskName, 256);
				printf("新規タスク「%s」の内容を入力してください\n", taskName);
				scanf_s("%s", taskContent, 256);
				printf("担当者のIDを入力してください\n");
				int id = -1;
				scanf_s("%d", &id);
				Manager newManager = Manager::Search(id);
				Task::Create(taskName, newManager, taskContent);
				
			}
			else if (selectNumber[STATE_1]) {
				//タスクのステータス更新
				printf("情報の更新を行うタスクのIDを入力してください\n");
				int id = -1;
				scanf_s("%d", &id);
				Task::Update(id);
			}
		}
		else {
			printf("入力値エラー:正しい値を入力してください\n");
			DrawLine();
		}

		printf("システム作動中...\n");
	}

	return 0;
}

void DrawLine()
{
	printf("---------------------------------\n");
}
