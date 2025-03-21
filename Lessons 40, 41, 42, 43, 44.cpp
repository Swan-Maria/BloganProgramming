#include <iostream>
//44
const int SIZE = 5;
int arr[SIZE];
void Initialize();
void Show();

int globalVariable=10;
void Function();
void SecretFunction();

void Function_() {
	static int a;
	a++;
	std::cout << a << std::endl;
}


void Function1() {
	globalVariable = 1;
	std::cout << "Function1: " << globalVariable << std::endl;
}

void Function2() {
	globalVariable = 2;
	std::cout << "Function2: " << globalVariable << std::endl;
}
//43
int Multiple(int a, int b) {
	int prod = a * b;
	return prod;
}

//double ToCube(double number){
//	double cube = number * number * number;
//	return cube;
//}
double ToCube(const double number);

double GetPI() {
	double PI = 3.14159;
	return PI;
}

//void Show(const int number) {
//	std::cout << "It`s " << number << " number.\0";
//}
//
//void Show(const int arr[], int size) {
//	if (size <= 0) {
//		std::cout << "Error\n";
//		return;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << arr[i] << " ";
//	}
//	std::cout << std::endl;
//}
//
//void Initialize(int arr[], int size) {
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = i + i;
//	}
//}

void A(int arr[], int size) {
	arr[0] = 5;
}
void B(int a) {
	a = 3;
}
int main()
{
	/*globalVariable = 3;
	std::cout << "Main: " << globalVariable << std::endl;*/

	using namespace std;
//LESSON 40. ONE-DIMENSIONAL ARRAYS
	// Syntax for creating value:
	// Data_Type Value_Name;
	
	// Syntax for creating array:
	// Data_Type Array_Name [Number_of_Elements);

	// Syntax accessing array elements:
	// Array_Name[Index_of_Element];

	/*
	const int SIZE = 3;
	int arr[SIZE]; //OK
	int size = 3;
	int arr[size]; //BAD
	*/

	/*int arr[3];
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	cout << "arr[0] = " << arr[0] << endl;
	cout << "arr[1] = " << arr[1] << endl;
	cout << "arr[2] = " << arr[2] << endl;*/

	/*const int SIZE = 10;
	int arr[SIZE];
	
	for (int index = 0; index < SIZE; index++)
		arr[index] = index + index;

	for (int index = 0; index < SIZE; index++)
		cout << "arr[" << index << "] = " << arr[index] << endl;*/

// LESSON 41. MULTIDIMENSIONAL ARRAYS
 	/*const int DAYS = 7;
	const int WEEKS = 5;
	double week1[DAYS], week2[DAYS], week3[DAYS], week4[DAYS], week5[DAYS];
	for (int day = 0; day < DAYS; day++)
		cin >> week1[day];
	for (int day = 0; day < DAYS; day++)
		cin >> week2[day];
	for (int day = 0; day < DAYS; day++)
		cin >> week3[day];
	for (int day = 0; day < DAYS; day++)
		cin >> week4[day];
	for (int day = 0; day < DAYS; day++)
		cin >> week5[day]; */

	// A multidimensional array is an array of arrays.
	// The syntax for creating a 2-dimensional array is:
	// Data_Type Array_Name[number_of_subarrays][number_of_elements];
	
	//const int WEEKS = 3, DAYS = 2;
	//int temperatures[WEEKS][DAYS]{{10, 20}, {100, 200}, {1000,2000}};
	
	/*temperatures[0][0] = 2;
	temperatures[0][1] = 4;
	temperatures[1][0] = 78;
	temperatures[1][1] = 3;
	temperatures[2][0] = 5;
	temperatures[2][1] = 65;

	cout << "temperatures[" << 0 << "][" << 0 << "] = " << temperatures[0][0] << endl;
	cout << "temperatures[" << 0 << "][" << 1 << "] = " << temperatures[0][1] << endl;
	cout << "temperatures[" << 1 << "][" << 0 << "] = " << temperatures[1][0] << endl;
	cout << "temperatures[" << 1 << "][" << 1 << "] = " << temperatures[1][1] << endl;
	cout << "temperatures[" << 2 << "][" << 0 << "] = " << temperatures[2][0] << endl;
	cout << "temperatures[" << 2 << "][" << 1 << "] = " << temperatures[2][1] << endl;*/

	/*for(int i =0; i<WEEKS; i++)
	{
		for (int j = 0; j < DAYS; j++)
			temperatures[i][j] = j + i * j + i;
	}*/

	/*for (int i = 0; i < WEEKS; i++)
	{
		for (int j = 0; j < DAYS; j++)
			cout << "temperatures[" << i << "][" << j << "] = " << temperatures[i][j] << endl;
		cout << endl;
	}*/

//LESSON 42. STRING ARRAYS
	/*char greeting1[] = { 'H','e','l','l','o','\0'};
	char greeting2[] = "Hello";
	for (int i = 0; i < 5; i++)
		cout << greeting1[i];
	cout << endl;*/

	/*char word[30];
	char ch;
	cin >> ch;
	for (int i = 0; i < 30 && ch!='\n'; i++)
	{
		word[i] = ch;
		cin >> ch;
	}

	for (int i = 0; i < 30; i++)
		cout << word[i];*/

	/*cout << "Enter world:";
	char word[30];
	cin >> word;
	cout << "Your word: " << word << endl; */

	/*char sentence[50];
	cout << "Enter sentence: ";
	cin.getline(sentence,3);*/

//LESSON 43. FUNCTIONS
	/*
	Syntax function definition:
	Type_of_return_value Function_Name (List_of_Formal_Parameters)
	{
		Code
	}
	*/
	/* 
	Syntax function call:
	Function_Name (List_of_Actual_Parameters);
	*/
	// When creating a function | When calling a function
	// Formal Parameters | Actual Parameters
	// Formal Arguments  | Actual Arguments
	// Parameters        | Arguments  

	/*int number1=2, number2 = 3;
	int product;
	product = Multiple(number1, number2);
	cout << product << endl;*/

	/*double number=2.5;
	double cube = ToCube(number);
	cout << "Number = " << number << endl;
	cout << "Cube = " << cube << endl;*/

	//double radius=3;
	//double area = GetPI() * radius * radius;

	/*Show(3+5);
	cout << endl;
	const int SIZE = 3;
	int arr[SIZE] = { 1,2,3 };
	cout << arr<<endl;
	Show(arr, SIZE);*/
	
	/*const int SIZE1=3;
	const int SIZE2 = 5;
	int arr1[SIZE1];
	int arr2[SIZE2];
	Initialize(arr1, SIZE1);
	Initialize(arr2, SIZE2);
	Show(arr1, SIZE1);
	Show(arr2, SIZE2);*/
	
	/*int arr[3] = { 1,2,3 };
	int a = 10;
	A(arr, 3);
	B(a);
	cout << arr[0] << endl;
	cout << a << endl;*/

	/*double a=3;
	double cube = ToCube(a);*/
	
	// Syntax to creat function prototype:
	// Type_of_return_value Function_Name (List_of_Formal_Parameters);

// LESSON 44. SCOPE, GLOBAL/LOCAL DATA, STATIC/EXTERN.
	/*
	for (int i = 0; i < 3; i++)
	{
		int b;
		b = 5;
	}
	int a=10;
	{
		int a = 3;
		int b=5;
		cout << a << endl;
		cout << b << endl;
	}
	cout << a << endl;*/

	//Initialize();
	//Show();
	//int localVariable;
	//Function();
	////SecretFunction();
	//cout << globalVariable << endl;

	for (int i = 0; i < 3; i++)
	{
		Function_();
	}


	return 0;
}

void Initialize()
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = i;
	}
}

void Show()
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
}

double ToCube(const double number) {
	return number * number * number;
}