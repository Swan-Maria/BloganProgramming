#include <iostream>
#include "Lesson_101_Ork.h"
#include "Lesson_101_Shaman.h"

void ChangeName(Ork& ork, const char* newName)
{
	strcpy_s(ork.name, 20, newName);

}
int main()
{
	Ork myOrk{ "Demien" };
	std::cout << "Ork name: " << myOrk.GetName() << std::endl;
	std::cout << "Ork HP: " << myOrk.GetHP() << std::endl;

	Shaman myShaman{ "Sonya" };
	std::cout << "Shaman name: " << myOrk.GetName() << std::endl;
	std::cout << "Shaman HP: " << myOrk.GetHP() << std::endl;


	myOrk.ReduceHP(23);
	std::cout << "Ork HP: " << myOrk.GetHP() << std::endl;

	myShaman.Heal(myOrk);

	std::cout << "Ork HP: " << myOrk.GetHP() << std::endl;

	ChangeName(myOrk, "Blogan");
	return 0;
}