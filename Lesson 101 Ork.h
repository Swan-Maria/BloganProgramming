#pragma once
#include "Lesson_101_Shaman.h"

class Ork
{
private:
	int hp;
	char name[20];
	/*...*/
public:
	Ork(const char* name, int hp = 100);
	int GetHP() const { return hp; }
	const char* GetName() const { return name; }

	void ReduceHP(int points);
	 
	//friend class Shaman;
	friend void Shaman::Heal(Ork& ork);
	friend void ChangeName(Ork& ork, const char* newName);
};

