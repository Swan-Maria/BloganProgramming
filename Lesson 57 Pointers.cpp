#include <iostream>

int* GetMax(int arr[], int size);

void Swap(int* a, int* b);
void Change(int* a);

void Initialize(int arr[], int size, int (*initFunction)());
void Show(const int arr[], int size, void(*showFunction)(int element));

int GetValue1_10();
int GetValue20_30();

void Show1(const int arr[], int size);
void ShowElement(int element);
void ShowElementInBrackets(int element);
void ShowElementInSquareBrackets(int element);
int Func();
void Func1();
void Func2(int a);
void Func3(int a, int b);
void Func4(int a, double b);
int Func5();
double Func6(int a);
char Func7(int a, int b);
long Func8(int a, double b);
void Func9(int arr[], int size);
void Func10(const int a);
void Func11(const int arr[], int size);

int main() {
	using namespace std;
	// Syntax to create pointer:
	// 1. Data_Type *Pointer_Name;
	// 2. Data_Type *Pointer_Name = Address; <- initialization
	
	//Pointer to variable, to constant variable, to pointer, to constant pointer.
	//int a,b;
	//int *p1, *p2;
	/*int a = 5;
	int b = 10;
	int* p;
	int** pp = &p;
	
	p = &a;
	*p = 0;

	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;
	cout << "&p = " << &p << endl;
	cout << "pp = " << pp << endl;

	cout << endl;

	p = &b;
	*p = 100;
	cout << "b = " << b << endl;
	cout << "&b = " << &b<< endl;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;
	cout << "&p = " << &p << endl;
	cout << "pp = " << pp << endl;*/

	/*int a = 1;
	const int b = 2;

	int* p1;
	p1 = &a;
	//p1 = &b; Impossible to do

	const int* p2;
	p2 = &a;
	p2 = &b;

	int** pp1;
	pp1 = &p1;
	//pp1=&p2 Impossible to do

	const int** pp2;
	pp2 = &p1;
	pp2 = &p2;*/

	//Pointer to array
	//const int size = 5;
	//int arr[size] = { 1,2,3,4,5 };

	/*int* p = &arr[0];

	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;
	cout << arr[4] << endl;
	
	cout << &arr[0] << endl;
	cout << &arr[1] << endl;
	cout << &arr[2] << endl;
	cout << &arr[3] << endl;
	cout << &arr[4] << endl;*/

	//int* p = arr;

	/*cout << p << endl; 
	cout << *p << endl;
	cout << arr << endl;
	cout << &arr << endl;
	cout << &arr[0] << endl;*/

	/*for (size_t i = 0; i < size; i++)
	{
		arr[i] = 10 * i + i * 3;
		cout << arr[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = 20* i -10;
		cout << p[i] << " ";
	}*/

	/*cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;
	cout << arr[4] << endl;

	cout << p[0] << endl;
	cout << p[1] << endl;
	cout << p[2] << endl;
	cout << p[3] << endl;
	cout << p[4] << endl;*/

	//const int* p1 = arr;

	//Pointer to function
	//Syntax to creat pointer to function
	// 1. Function_Data_Type (*Pointer_Name) (Type_of_Parameters);
	// 2. Data_Type *Pointer_Name = Address; <- initialization
	
	/*Func();
	cout << Func << endl;
	cout << &Func << endl;*/

	/*void (*p1)()=Func1;
	void (*p2)(int) = Func2;
	void (*p3)(int, int) = Func3;
	void (*p4)(int, double) = Func4;
	int (*p5)() = Func5;
	double (*p6)(int) = Func6;
	char (*p7)(int, int) = Func7;
	long (*p8)(int, double) = Func8;
	void (*p9)(int[], int) = Func9;
	void (*p10)(const int) = Func10;
	void (*p11)(const int[], int) = Func11;

	Func1();
	p1();

	p8(5, 1.2);*/

	/*cout << p1 << " = " << Func1 << endl;
	cout << *p1 << " = " << Func1 << endl;*/

	//Const pointer
	/*int a=10;
	int b = 20;
	const int c = 20;

	int* const p1 = &a;
	const int* p2 = &a;
	const int* const p3 = &a;

	*p1 = 20;
	p2 = &b;*/

	//NULL-pointer
	/*int b=0;
	int* a=nullptr;

	if (a == 0) {
		cout << "It`s null pointer.\n";
		cout << a<<endl;
	}*/

	//VOID-pointer
	/*int a=10;
	double b = 1.2;
	void* p;
	p = &a;
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl;
	cout << "*p = " << *(static_cast<int*>(p)) << endl;
	p = &b;
	cout << "&b = " << &b << endl;
	cout << "p = " << p << endl;
	cout << "*p = " << *(static_cast<double*>(p)) << endl;*/

	//Pointer arithmetic
	/*const int SIZE = 5;
	int arr[SIZE] = { 1, 2, 3, 4, 5 };
	int* ptr = arr;*/

	//accessing elements via indices
	/*for (int i = 0; i < SIZE; i++)	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < SIZE; i++)	{
		cout << ptr[i] << " ";
	}
	cout << endl;*/
	//accessing elements by denaming
	/*for (int i = 0; i < SIZE; i++)	{
		cout << *(arr + i) << " ";
	}
	cout << endl;

	for (int i = 0; i < SIZE; i++)	{
		cout << *(ptr + i) << " ";
	}
	cout << endl;*/
	//accessing elements via indices
	/*for (int i = 0; i < SIZE; i++)	{
		cout << &arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < SIZE; i++)	{
		cout << &ptr[i] << " ";
	}
	cout << endl;*/
	//access to element address
	/*for (int i = 0; i < SIZE; i++)	{
		cout << arr + i << " ";
	}
	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << ptr + i << " ";
	}
	cout << endl;*/

	/*int* p1 = &arr[0];
	int* p2 = &arr[4];

	cout << "p1 + 0 = " << p1 + 0<< endl;
	cout << "p1 + 1 = " << p1 + 1 << endl;
	cout << "p1 + 2 = " << p1 + 2 << endl;
	cout << "p1 + 3 = " << p1 + 3 << endl;
	cout << "p1 + 4 = " << p1 + 4 << endl;
	cout << endl;

	cout << "p2 - 0 = " << p2 - 0 << endl;
	cout << "p2 - 1 = " << p2 - 1 << endl;
	cout << "p2 - 2 = " << p2 - 2 << endl;
	cout << "p2 - 3 = " << p2 - 3 << endl;
	cout << "p2 - 4 = " << p2 - 4 << endl;
	cout << endl;

	cout <<"p2 - p1 = "<<p2-p1 << endl;

	cout << "&p1[0] = " << &p1[0] << endl;
	cout << "&p1[1] = " << &p1[1] << endl;
	cout << "&p1[2] = " << &p1[2] << endl;
	cout << "&p1[3] = " << &p1[3] << endl;
	cout << "&p1[4] = " << &p1[4] << endl;
	cout << endl;
	
	cout << "&arr[0] = " << &arr[0] << endl;
	cout << "&arr[1] = " << &arr[1] << endl;
	cout << "&arr[2] = " << &arr[2] << endl;
	cout << "&arr[3] = " << &arr[3] << endl;
	cout << "&arr[4] = " << &arr[4] << endl;*/

	//Pointers as function parameters
	/*int a=10, b=20;
	cout << "a = " << a << ", b = " << b << endl;
	Swap(&a,&b);
	cout << "a = " << a << ", b = " << b << endl;
	Change(&a);
	cout << a << endl;*/

	/*const int SIZE = 5;
	int arr[SIZE] = { 1, 2, 3, 4, 5 };
	int* ptr = arr;
	Show(arr, SIZE);*/

	const int SIZE=10;
	int arr[SIZE];

	Initialize(arr, SIZE, GetValue20_30);
	Show(arr, SIZE,ShowElement);
	Show(arr, SIZE, ShowElementInBrackets);
	Show(arr, SIZE, ShowElementInSquareBrackets);

	int* maxElement = GetMax(arr, SIZE);
	cout << *maxElement << endl;
	*maxElement = 0;
	cout << *maxElement << endl;
	Show1(arr, SIZE);

	return 0;

}

int* GetMax(int arr[], int size)
{
	int* maxAddress = arr;
	int max = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (max<arr[i]){
			max = arr[i];
			maxAddress = &arr[i];
		}
	}
	return maxAddress;
}

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Change(int* a) {
	*a = 0;
}

void Show(const int arr[], int size, void(*showFunction)(int element))
{
	for (int i = 0; i < size; i++) {
		showFunction(arr[i]);
	}
	std::cout << std::endl;
}

void Initialize(int arr[], int size, int (*initFunction)() )
{
	for (int i = 0; i < size; i++) {
		arr[i] = initFunction();
	}
}

int GetValue1_10() {
	return rand() % 10 + 1;
}
int GetValue20_30() {
	return rand() % (30 - 20) + 20;
}

void Show1(const int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		std::cout <<"(" << arr[i] << ") ";
	}
	std::cout << std::endl;
}

void ShowElement(int element)
{
	std::cout << element << " ";
}

void ShowElementInBrackets(int element)
{
	std::cout <<"(" << element << ") ";
}

void ShowElementInSquareBrackets(int element)
{
	std::cout << "[" << element << "] ";
}

int Func() {
	return 1;
}

void Func1() {
	std::cout << "Hello from Function 1"<<std::endl;
}
void Func2(int a) {

}
void Func3(int a, int b) {

}
void Func4(int a, double b) {

}
int Func5() {
	return 1;
}
double Func6(int a) {
	return 1;
}
char Func7(int a, int b) {
	return 1;
}
long Func8(int a, double b) {
	return 1;
}
void Func9(int arr[], int size) {

}
void Func10(const int a) {

}
void Func11(const int arr[], int size) {

}