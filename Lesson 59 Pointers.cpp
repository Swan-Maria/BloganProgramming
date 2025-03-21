#include <iostream>
using namespace std;

/*void Func() {
	cout << &"Hello World" << endl;
}
void Show(const char* str);
int CountLength(const char* str);*/

//void Func1();
//void Func2();
//void Func3();

void Show(const int* arr, int size);
void Show(const int (*arr)[5], int rows);
void Show(const char* str);


int main() {

	int arr[3] = { 1,2,3 };
	Show(static_cast<const int*>(nullptr), 3);

	int (*ptr)[4];
	const char* str = "Hello World\0";
	Show(str);

	int doubleArr[3][5] = {
		{1,10,100,1000,10000},
		{2,20,200,2000,20000},
		{3,30,300,3000,30000},
	};
	Show(doubleArr, 3);

	/*int arr[3];
	int* ptr = arr;*/

	/*int arr2[3][5][5] = {0};
	int  (*ptr)[5][5] = arr2;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << ptr[i][j] << " ";
			cout << * (*(ptr+i) +j) << " ";
		}
		cout << endl;
	}*/


	/*void (*ptr1)() = Func1;
	void (*ptr2)() = Func2;
	void (*ptr3)() = Func3;

	// void(*)()
	void (*arr[3])() = { Func1, Func2, Func3 };*/

	/*int a = 10;
	int b = 20;
	int c = 30;
	int* arr[3] = { &a, &b, &c };

	for (int i = 0; i < 3; i++)
	{
		cout << *arr[i] << " ";
	}*/

	/*const char STR[] = "Hello World";
	Show(STR);
	cout << CountLength(STR) << endl;*/

	/*char arr[] = "Hello world";
	const char* ptr = "Hello world";
	cout << &"Hello world" << endl;
	cout << ptr << endl;
	Func();*/

	return 0;
}

void Show(const int* arr, int size) {
	if (arr == nullptr)
		return;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Show(const int (*arr)[5], int rows) {
	if (arr == nullptr)
		return;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void Show(const char* str) {
	if (str == nullptr)
		return;
	while (*str) {
		cout << *str;
		str++;
	}
	cout << endl;
}

/*void Show(const char* str) {
	while (*str != '\0') {
		cout << *str;
		str++;
	}
}
int CountLength(const char* str)
{
	int length = 0;
	while (*str != '\0')
		length++;
	return length;
}*/
