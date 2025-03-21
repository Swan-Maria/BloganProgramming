#include <cstring>
#include "Lesson_101_Shaman.h"
#include "Lesson_101_Ork.h"

Shaman::Shaman(const char* name, int hp)
	:name("NoName"), hp(100)
{
	if (name != nullptr && std::strlen(name) < 20)
		strcpy_s(this->name, 20, name);

	if (hp > 0)
		this->hp = hp;
}

void Shaman::Heal(Ork& ork)
{
	ork.hp += 20;
	if (ork.hp>100)
		ork.hp =100;
}

