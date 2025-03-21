#include <iostream>
#include "Lesson_97_DynamicNumber.h"
#include "Lesson_97_Test.h"
//void Function()
//{
//	Test a;
//}
int main()
{
	Test* ptr = new Test();
	ptr->~Test();

	/*Test* ptr = new Test();
	delete ptr;*/

	//Function();

	/*{
		DynamicNumber number{ 5 };
		std::cout << number.GetValue() << std::endl;
		number.SetValue(10);
		std::cout << number.GetValue() << std::endl;
		number.SetValue(3);
		std::cout << number.GetValue() << std::endl;
		//number.Delete();
		//number.Delete();
	}*/

	return 0;
}
