#include <cstring>
#include "Lesson_101_Ork.h"
#include "Lesson_101_Shaman.h"

Ork::Ork(const char* name, int hp)
	:name("NoName"), hp(100)
{
	if (name != nullptr && std::strlen(name) < 20)
		strcpy_s(this->name, 20, name);

	if (hp > 0)
		this->hp = hp;
}

void Ork::ReduceHP(int points)
{
	hp -= points;
	if (hp < 0)
		hp = 0;
}

