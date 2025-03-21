#include "Lesson_102_Tank.h"

int Tank::tanks = 0;

Tank::Tank(int damage, int hp, float moveSpeed, float rotateSpeed)
{
	tanks++;
	if (damage > 0)
		this->damage = damage;
	if (hp > 0)
			this->hp = hp;
	if (moveSpeed > 0)
		this->moveSpeed = moveSpeed;
	if (rotateSpeed > 0)
		this->rotateSpeed = rotateSpeed;
}

Tank::~Tank()
{
	tanks--;
}

void Tank::ReduceHP(int points)
{
	if (points > 0)
	{
		hp -= points;
		if (hp <= 0)
		{
			hp = 0;
			isAlive = false;
		}
	}
}

int Tank::GetAliveTanks()
{
	return tanks;
}
