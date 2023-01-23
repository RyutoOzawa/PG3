#include "Enemy.h"
#include<stdio.h>

int Enemy::allEnemyCount = 0;

void Enemy::Approach() {
	printf("“G‚ªÚ‹ßI\n");
}

void Enemy::Attack() {
	printf("“G‚ªUŒ‚I\n");
}

void Enemy::Leave() {
	printf("“G‚ª“¦‘–I\n");
}

void Enemy::Update() {
	//ŠÖ”ŽÀs
	(this->*stateChangeTable[static_cast<size_t>(state)])();
}

void (Enemy::* Enemy::stateChangeTable[])() {
	&Enemy::Approach,
		& Enemy::Attack,
		& Enemy::Leave,
};