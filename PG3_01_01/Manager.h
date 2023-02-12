#pragma once
#include<string>
#include<vector>

class Manager
{
public:

	static std::vector<Manager> managers;

	std::string name;
	std::string memberClass;
	int id;

public:
	static void Create(std::string name_, std::string memberClass_);

	static void UpdateData(const std::string& oldName, const std::string& newName, const std::string& newMemberClass);

	static void DeleteManager(std::string name);

	static Manager Search(int id);
};

