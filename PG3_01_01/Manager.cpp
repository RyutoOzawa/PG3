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
	//���O�ƃ����o�[��V�������̂ɍX�V
	for (int i = 0; i < managers.size(); i++) {
		if (managers[i].name == oldName) {
			managers[i].name = newName;
			managers[i].memberClass = newMemberClass;
			printf("����ɍX�V����܂���\n");
			return;
		}
	}
	printf("�f�[�^�x�[�X��%s�͌�����܂���ł���", oldName.c_str());
}

void Manager::DeleteManager(std::string name)
{
	//�폜�������Ǘ��҂̖��O��z�񂩂猟��
	for (int i = 0; i < managers.size(); i++) {
		//����������폜
		if (managers[i].name == name) {
			managers.erase(managers.begin() +i);
			printf("�S���ҁu%s�v�̓f�[�^�x�[�X���珜�O����܂���\n", name.c_str());
			return;
		}
	}
	//for�����I�����������猩����Ȃ�����
	printf("�u%s�v�͒S���҃f�[�^�x�[�X�ɑ��݂��Ȃ��������߁A�폜�Ɏ��s���܂���\n",name.c_str());
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

	printf("�Y��ID�̒S���҂̓f�[�^�x�[�X�ɑ��݂��܂���ł���\n");
	return nullManager;
}
