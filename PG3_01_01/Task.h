#pragma once
#include"Manager.h"
#include<vector>

class Task
{
	

public:

	//タスクをまとめる配列
	static std::vector<Task> tasks;

	int id;
	Manager manager;
	std::string name;
	std::string content;
	bool isComplete;
	int priority;
public:
	static void Create(std::string name, Manager manager, std::string content = "NULL", int priority = 1);
	static void Update(int id);

	void SetManager(Manager newManager) { manager = newManager; }
	void SetName(std::string newName) { name = newName; }
	void SetContent(std::string newContent) { content = newContent; }
	void SetComplete(bool newState) { isComplete = newState; }
	void SetPriority(int newPriority) { priority = newPriority; }

};

