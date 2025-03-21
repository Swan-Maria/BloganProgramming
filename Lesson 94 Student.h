#pragma once

class Student
{

private:
	/// Fields
	char name[20];
	int age;

public:
	/// Methods
	void Show();
	void ChangeAge(int newAge);
	void ChangeName(const char* newName);
	void EnterName();
	void EnterAge();
};