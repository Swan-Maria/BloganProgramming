#include <iostream>

int main()
{
	// LESSON 10. RAW STRINGS
	/*
	std::cout << R"(C:\Users\User\source\repos\Hello World!)" << std::endl;
	std::cout << R"(Hello
	World)" << std::endl;
    */

	// LESSON 11. TYPE OF DATA
	/* 
	INTEGERS :
	- shot
	- int
	- long
	- long long
	BY THE PRESENCE OF THE SIGN:
	- signed 
	- unsigned
	FLOATING POINT NUMBERS:
	- float
	- double
	- long double
	SYMBOLIC:
	- char
	- wchar_t
	- char16_t
	- char32_t
	LOGICAL:
	- bool {true, false}
	*/

	// Lesson 12. Variables
	// A variable is a named memory area that can be accessed during program execution.
	// Variable declaration syntax:
	// data_type variable_name;
	// Variable initialization syntax (simultaneous declaration and value assignment):
	// data_type variable_name = value;
	// Initialization forms:
	/*
	int number1 = 1; //Copy initialization
    int number2 = { 2 }; //List initialization
    int number3{ 3 }; //Uniform initialization
	int number4(4); //Direct initialization
	*/

	// LESSON 13. CONSTANTS
	// A constant is a named memory area whose value cannot be changed after initialization.
	// Constants must be initialized when declared:
	// const data_type variable_name = value;
	// Constants support all the same forms of initialization as regular variables.
    /*
    const int const1 = 1; //Copy initialization
    const int const2 = { 2 }; //List initialization
    const int const3{ 3 }; //Unified initialization
	const int const4(4); //Direct initialization
	*/

	// LESSON 14. INPUT DATA
	/* EXERCISE 1
	int number1, number2;
	std::cout << "Enter first numver: ";
	std::cin >> number1;

	std::cout << "Enter second numver: ";
	std::cin >> number2;
	
	int sum;
	sum = number1 + number2;
	std::cout <<number1<<" + "<<number2<<" = " << sum << std::endl;

	std::cout << "Sum = "<<sum<<std::endl;
	*/
	
	/* EXERCISE 2
	std::cout << "Enter the side of the squere: ";
	int side;
	std::cin >> side;

	int perimeter = side * 4;
	std::cout << "Perimeter = "<<perimeter<<std::endl;

	int area = side * side;
	std::cout << "Area = " << area << std::endl;
	*/

	 // EXERCISE 3 
	std::cout << "Enter the radius of the circle: ";
	double radius;
	std::cin >> radius;
	const double PI = 3.1415;
	double diameter = radius * 2;
	double area = PI * radius * radius;
	double length = 2 * PI * radius;
	std::cout << "------ Circle information ------\n";
	std::cout << "Radius = " << radius << std::endl; 
		std::cout << "Diameter = "<< diameter << std::endl; 
		std::cout << "Area = " << area << std::endl; 
		std::cout << "Length = " << length << std::endl;

	return 0;
}