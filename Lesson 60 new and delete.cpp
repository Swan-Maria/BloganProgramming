#include <iostream>
#include <time.h>
using namespace std;

//void Func()
//{
//	const int* a = new const int(5);
//	cout << a << endl;
//	cout << *a << endl;
//	//*a = 10;
//	//cout << *a << endl;
//}

//void Func()
//{
//	double** a = new  double*;
//	cout << a << endl;
//	cout << *a << endl;
//}

//int* CreateVariable(int value);

//int EnterSize();
//int* CreateArray(int size);
//void Initialize(int arr[], int size);
//void Show(const int arr[], int size);

//void Show(const int* const * arr, int rows, int columns);

int main() {
	srand(time(NULL));

	long long a = 100000;
	long long * p = new long long[a];

	/*const int SIZE = 1000;
	char buffer[SIZE];
	cin.getline(buffer, SIZE);
	int length = strlen(buffer);
	char* str = new char[ length + 1 ];
	strcpy_s(str, length + 1, buffer);
	cout << str << endl;
	delete[] str;
	str = nullptr;*/

	/*cout << "Enter rows: ";
	int rows;
	cin >> rows;
	cout << "Enter columns: ";
	int columns;
	cin >> columns;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new int[columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	Show(arr, rows, columns);
	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;*/

	/*int size = EnterSize();
	int* arr = CreateArray(size);
	Initialize(arr, size);
	Show(arr, size);
	delete[] arr;
	arr = nullptr;
	delete[] arr;*/

	//cout << "Enter size: ";
	//int size;
	//cin >> size;
	// if (size <= 0)
	//{
	//	// Error
	//	return;
	//}
	//int* arr = new int[size] {1, 2, 3};
	//for (int i = 0; i < size; i++)
	//{
	//	arr[i] = 0;
	//	cout << arr[i] << " ";
	//}
	//cout << endl;

	// // Code
	//int* ptr = CreateVariable(10);
	//// Work with variable
	//delete ptr;
	//ptr = CreateVariable(5);
	//// Work with variable
	//delete ptr;

	/*int* ptr1 = new int{10};
	//To do smth with data at the heap
	delete ptr1;
	ptr1 = nullptr;
	delete ptr1;*/

	/*int* ptr1 = new int{10};
	const int* ptr2 = new const int{ 20 };
	int** ptr3 = new int* { nullptr };
	//To do smth with data at the heap
	delete ptr1;
	delete ptr2;
	delete ptr3;*/

	return 0;
}

//int* CreateVariable(int value)
//{
//	return new int{ value };
//}

//int EnterSize()
//{
//	cout << "Enter size: ";
//	int size;
//	cin >> size;
//	return size;
//}
//
//int* CreateArray(int size)
//{
//	return new int[size];
//}
//
//void Initialize(int arr[], int size)
//{
//	if (arr == nullptr)
//		return;
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = rand() % 100;
//	}
//}
//
//void Show(const int arr[], int size)
//{
//	if (arr == nullptr)
//		return;
//	for (int i = 0; i < size; i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//	cout << endl;
//}

//void Show(const int* const* arr, int rows, int columns)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			cout << arr[i][j] << " ";
//		}
//	}
//	cout << endl;
//}
