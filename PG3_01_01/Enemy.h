#pragma once

enum StateIndex {
	approach,
	attack,
	leave,
};

class Enemy
{
public:
	Enemy() { allEnemyCount++; }
	~Enemy() { allEnemyCount--; }

public:
	static int allEnemyCount;

	int state = approach;

	void Kill() { allEnemyCount = 0; }

	void Approach();
	void Attack();
	void Leave();

	void Update();

private:
	static void(Enemy::* stateChangeTable[])();
};