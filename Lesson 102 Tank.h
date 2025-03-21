#pragma once
class Tank
{
private:
	static int tanks;

	int damage = 5;
	int hp = 100;
	float moveSpeed = 30; // km/h
	float rotateSpeed = 3; // degrees/second
	bool isAlive = true;
	/* other fields */
public:
	Tank(int damage = 5, int hp = 100, float moveSpeed = 30, float rotateSpeed = 3 /* other parameters*/);
	~Tank();
	int GetDamage() const { return damage; }
	int GetHP() const { return hp; }
	float GetMoveSpeed() const { return moveSpeed; }
	float GetRotateSpeed() const { return rotateSpeed; }
	bool IsAlive() const { return isAlive; }

	int GetTanks() const { return tanks; }

	void ReduceHP(int points);

	static int GetAliveTanks();
};
