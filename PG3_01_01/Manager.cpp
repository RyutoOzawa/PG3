#include "Manager.h"

std::vector<Manager> Manager::managers;

void Manager::Create(std::string name_, std::string memberClass_)
{
	Manager newManager;
	int newId = 0;
	if (managers.empty()) {
		newId = 1;
	}
	else {
		newId = managers.size() + 1;
	}

	newManager.id = newId;
	newManager.name = name_;
	newManager.memberClass = memberClass_;
	managers.push_back(newManager);
}

void Manager::UpdateData(const std::string& oldName, const std::string& newName, const std::string& newMemberClass)
{
	//名前とメンバーを新しいものに更新
	for (int i = 0; i < managers.size(); i++) {
		if (managers[i].name == oldName) {
			managers[i].name = newName;
			managers[i].memberClass = newMemberClass;
			printf("正常に更新されました\n");
			return;
		}
	}
	printf("データベースに%sは見つかりませんでした", oldName.c_str());
}

void Manager::DeleteManager(std::string name)
{
	//削除したい管理者の名前を配列から検索
	for (int i = 0; i < managers.size(); i++) {
		//見つかったら削除
		if (managers[i].name == name) {
			managers.erase(managers.begin() +i);
			printf("担当者「%s」はデータベースから除外されました\n", name.c_str());
			return;
		}
	}
	//for分が終わっちゃったら見つからなかった
	printf("「%s」は担当者データベースに存在しなかったため、削除に失敗しました\n",name.c_str());
}

Manager Manager::Search(int id)
{
	for (int i = 0; i < managers.size(); i++) {
		if (id == managers[i].id) {
			return managers[i];
		}
	}
	
	Manager nullManager;
	nullManager.Create("NAME_NULL", "NAME_CLASS");

	printf("該当IDの担当者はデータベースに存在しませんでした\n");
	return nullManager;
}
