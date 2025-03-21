#include <iostream> 
#include <ctime> 
#include "Lesson_121_Array.h" 
#include "Lesson_121_Pair.h" 
#include "Lesson_121_Container8.h"

int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	
	//Syntax of creating object by class template
	//Name_of_Class <Type_Template_Parameters> Object_Name

	/*Array<int> arr1{ 5 };
	arr1.Show();
	
	Array<double> arr2{ 10 };
	arr2.Show();
	
	Array<int> arr3 {20};
	arr3.Show();

	Pair<int, double> myObject {10, 2.3 };
	
	std::cout << "int value = " << myObject.GetObject1() << std::endl;
	std::cout << "double value = " << myObject.GetObject2() << std::endl;*/

	/*const size_t value = 10;
	Array<double, value> object;*/

	/*Array<double, 5> object1;
	object1.Show();
	std::cout << std::endl;
	
	Array<double, 9> object2;
	object1.Show();*/

	/*Array<int>object1{ 10 };
	object1.Show();

	Array<double>object2{ 10 };
	object2.Show();

	Array<char>object3{ 10 };
	object3.Show();*/

	Container8<int>cont1;
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << cont1[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}