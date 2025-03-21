#include <iostream>
#include "Lesson_94_Student.h"

void Student::Show()
{
	std::cout << "\tName: " << name << std::endl;
	std::cout << "\tAge: " << age << std::endl;
}

void Student::ChangeAge(int newAge)
{
	if (newAge > 0)
		age = newAge;
	else
		std::cout << "New age is incorrect.\n";
}

void Student::ChangeName(const char* newName)
{
	if (newName != nullptr && std::strlen(newName) < 20)
		strcpy_s(name, 20, newName);
	else
		std::cout << "New name is incorrect.\n";
}

void Student::EnterName()
{
	char temp[255];
	std::cout << "Enter name: ";
	std::cin >> name;
	ChangeName(temp);
}

void Student::EnterAge()
{
	int temp;
	std::cout << "Enter age: ";
	std::cin >> temp;
	ChangeAge(temp);
}