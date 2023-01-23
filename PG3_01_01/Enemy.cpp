#include "Enemy.h"
#include<stdio.h>

int Enemy::allEnemyCount = 0;

void Enemy::Approach() {
	printf("�G���ڋ߁I\n");
}

void Enemy::Attack() {
	printf("�G���U���I\n");
}

void Enemy::Leave() {
	printf("�G�������I\n");
}

void Enemy::Update() {
	//�֐����s
	(this->*stateChangeTable[static_cast<size_t>(state)])();
}

void (Enemy::* Enemy::stateChangeTable[])() {
	&Enemy::Approach,
		& Enemy::Attack,
		& Enemy::Leave,
};