#include <iostream>

int main()
{
	using namespace std;
	// LESSON 23. HIERARCHY OF DATA TYPES
	// long double
	// double
	// float
	// unsigned long long
	// long long
	// unsigned int
	// int
	// char, bool, wchar_t, char16_t, char32_t, short, unsigned short (automatic casting -> int)
	
	/*int a = 2;
	char b = 'A';
	float c = 1.1F;
	double d = 2.2;
	cout << a + b + c + d<<endl; //double
	cout << UINT32_MAX; */

	// LESSON 24. DATA TYPE CASTING
	// Explicit cast
	// Implicit cast

	// 1. (C)   -> (Type)Value
	// 2. (C++) -> Type(Value)
	// 3. (C++) -> static_cast<Type>(Value)

	//int side1 = 3, side2 = 4;
	//double division = (double) side1 / side2;
	//double division = double(side1) / side2;
	//double division = static_cast<double>(side1) / side2;
	//cout << division << endl;

	// LESSON 25. SIZEOF
	// sizeof(Type_of_data)
	// sizeof(Expression/Value)
	// sizeof Expression/Value

	/*
	cout << "--- Characters ---\n";
	cout << "char: "<< sizeof(char) << endl;
	cout << "wchar_t: "<< sizeof(wchar_t) << endl;
	cout << "char16_t: " << sizeof(char16_t) << endl;
	cout << "char32_t: "<< sizeof(char32_t) << endl; 
	cout << endl;
	cout << "--- Integers ---\n";
	cout << "short: "<< sizeof(short) << endl;
	cout << "unsigned short: "<< sizeof(unsigned short) << endl;
	cout << "int: "<<sizeof(int) << endl;
	cout << "unsigned int: "<< sizeof(unsigned) << endl;
	cout << "long: "<< sizeof(long) << endl;
	cout << "unsigned long: "<< sizeof(unsigned long) << endl;
	cout << "long long: "<< sizeof(long long) << endl;
	cout << "unsigned long long: "<<sizeof(unsigned long long) << endl;
	cout << endl;
	cout << "--- Floats ----\n";
	cout << "float: "<< sizeof(float) << endl;
	cout << "double: "<<sizeof(double) << endl;
	cout << "long double: " << sizeof(long double) << endl;
	*/

	// LESSON 26. COMPARISON OPERATORS
	// >, <, >=, <=, ==, !=

	//bool expression = (true>false);
	//cout << expression;

	/*std::cout << "Enter a number: ";
	int number;
	std::cin >> number;
	bool expression = (2 < number < 5);
	std::cout << expression*/

	// LESSON 27. LOGICAL OPERATORS
	
	// LOGICAL "AND" -> &&
	// condition1 && condition2
	// 1. true  && true  -> true
	// 2. true  && false -> false
	// 3. false && true  -> false
	// 4. false && false -> false

	// LOGICAL "OR"  -> ||
	// condition1 || condition2
	// 1. true  || true  -> true
	// 2. true  || false -> true
	// 3. false || true  -> true
	// 4. false || false -> false
	
	// LOGICAL "NOT" -> !
	// !condition
	// 1. !true  = false
	// 2. !false = true

	bool expression = (!strcmp("hello", "hello"));

	cout << expression;

	return 0;
}