#include <iostream>
#include <cstring>
#include "Lesson_94_Student.h"
/*
class Class_Name
{
	Class_Members
};
*/

struct Student2
{
	char name[20];
	int age;
};

//Student GlobalDemien;
//int a;
//const Student demien;

//struct Point
//{
//	int x;
//	int y;
//};

void Initialize(Student& student)
{
	student.EnterName();
	student.EnterAge();
}

void Initialize(Student students[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Student #" << i + 1 << ": \n";
		Initialize(students[i]);
	}
}
void Show(Student students[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Student #" << i + 1 << ": \n";
		students[i].Show();
	}
}

int main()
{
	std::cout << "Enter amount of students: ";
	size_t size;
	std::cin >> size;
	Student* students = new Student[size];
	Initialize(students, size);
	Show(students, size);
	delete[] students;
	

	//std::cout << sizeof(Student) << std::endl;
	////std::cout << sizeof(Point) << std::endl;
	//Student demien;
	//Student olga;
	//std::cout << sizeof(demien);
	//demien.ChangeAge(23); //ChangeAge(demien, 23)
	//demien.Show(); ///Show(demien)
	//olga.Show(); ///Show(olga)

	/*std::cout << "Enter amount of students: ";
	size_t size;
	std::cin >> size;
	Student* students = new Student[size];
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Student #" << i + 1 << ": \n";
		students[i].EnterName();
		students[i].EnterAge();
	}
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Student #" << i + 1 << ": \n";
		students[i].Show();
	}*/

	/*const size_t COUNT = 3;
	Student arr[COUNT];
	for (size_t i = 0; i < COUNT; i++)
	{
		std::cout << "Student #" << i + 1 << ":\n";
		arr[i].EnterName();
		arr[i].EnterAge();
	}
	
	for (size_t i = 0; i < COUNT; i++)
	{
		std::cout << "Student #" << i + 1 << ":\n";
		arr[i].Show();
	}*/

	/*Student demien;
	demien.ChangeAge(24);
	demien.ChangeName("Demien");
	demien.Show();
	Student* pDemien = &demien;
	pDemien->ChangeAge(24);
	pDemien->ChangeName("Demien");
	pDemien->Show();*/

	/*Student* demien = new Student;
	demien->ChangeAge(24);
	demien->ChangeName("Demien");
	demien->Show();
	delete demien;*/

	/*Student demien;
	demien.ChangeAge(24);
	demien.ChangeName("Demien");
	demien.Show();
	Student& refDemien = demien;
	refDemien.ChangeAge(30);
	refDemien.ChangeName("DEMIEN");
	refDemien.Show();*/

	/*new Student;
	const Student demien;
	new const Student;*/

	///Class_Name Object_Name

	/// Encapsulation is a mechanism in the C++ language that 
	/// allows you to combine data and their processing methods 
	/// (functions) into one single entity, which // is called 
	/// a class or structure, and allows you to protect data and methods
	/// from external interference thanks to access modifiers.

	/* //int
	int a;
	const int b = 10;
	int arr[2];
	const int arr2[3] = { 1,2,3 };
	int* p = &a;
	const int* p2 = &a;
	const int* const p4 = &a;
	int& r = a;
	const int& r2 = a;

	Student olga;
	olga.ChangeAge(25);
	olga.ChangeName("Olga");
	olga.Show();*/


	return 0;
}