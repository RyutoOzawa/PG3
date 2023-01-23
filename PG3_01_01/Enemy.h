#pragma once
class Enemy
{
public:
	Enemy() { allEnemyCount++; }
	~Enemy() { allEnemyCount--; }

public:
	static int allEnemyCount;

	void Kill() { allEnemyCount = 0; }
};

