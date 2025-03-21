#include <iostream>
using namespace std;

//void Initialize(int arr[], int& size) {}
//void Show(const int(&arr)[3], int size) {}
 
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}

//int* Min(int arr[], int size)
//{
//	int min = arr[0];
//	int minIndex = 0;
//	for (int i = 1; i < size; i++)
//	{
//		if (min > arr[i])
//		{
//			min = arr[i];
//			minIndex = i;
//		}
//	}
//	return arr + minIndex;
//}

int& Min(int arr[], int size)
{
	int min = arr[0];
	int minIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			minIndex = i;
		}
	}
	return arr[minIndex];
}

int main() {
	/// A link is a constant hidden specific pointer that stores the address of the object.

	/// Link creation syntax:
	/// Data_Type& Link_Name = Value; <- reference to l-value
	/// Data_Type& Link_Name = Value; <- reference to r-value
	
	int arr[] = { 1, 2, 3 };
	int size = 3;
	//int* minElement = Min(arr, size);
	int& minElement = Min(arr, size);
	minElement = 50;
	Min(arr, size)= 50;

	/*int*& p = new int{ 5 };
	int arr[] = { 1,2,3 };
	int size = 3;
	Show(arr, size);*/

	/*int a = 10, b = 20;
	Swap(a, b);*/

	/*int arr[] = { 1,2,3 };
	int size = 3;
	Show(arr, size);*/

	/*char a = 'G';
	char* ptr1 = &a;
	char& ref1 = a;
	double b = 5;
	double* ptr2 = &b;
	double& ref2 = b;
	cout << sizeof(a) << endl;
	cout << sizeof(ptr1) << endl;
	cout << sizeof(ref1) << endl;
	cout << sizeof(b) << endl;
	cout << sizeof(ptr2) << endl;
	cout << sizeof(ref1) << endl;*/

	/*int arr[5] = { 1,2,3,4,5 };
	int* p = arr;
	int (&ref)[5] = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
		cout << ref[i] << endl;
	}*/

	/*int a = 10;
	int* p = &a;
	int*& ref = p;
	cout << ref << " = " << p << endl;
	cout << &ref << " = " << &p << endl;*/

	/*int a = 10;
	const int b = 10;
	int& ref1 = a; /// modifiable l-value reference
	const int& ref2 = b; /// const 1-value reference
	int&& ref3 = 200;
	ref3 = 500;
	const int& ref4 = 200;*/

	/*int& ref1 = a;
	const int& ref = a;
	a = 100;
	ref2 = 400;*/

	/*int variable = 10;
	const int CONST = 20;
	int* ptr1 = &variable;
	int& ref1 = variable;
	cout << "&variable = " << &variable << endl;
	cout << "&ptr1 = " << &ptr1 << endl;
	cout << "&ref1 = " << &ref1 << endl;
	const int* ptr2 = &CONST;
	const int& ref2 = CONST;
	variable = 50;
	*ptr1 = 100;
	ref1 = 200;
	cout << CONST << endl;
	cout << *ptr2 << endl;
	cout << ref2 << endl;*/

	return 0;
}