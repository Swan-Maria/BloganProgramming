#include <iostream>

template<typename T1, typename T2>
void ShowSum(T1 a, T2 b);

//template<typename T>

//void ShowSum(T value)
//{
//	std::cout << value + value << std::endl;
//}

//void Show(T value);

//void Show(const T arr[], int size);

//void Initialize(int arr[], int SIZE);
//void Initialize(double arr[], int SIZE);
//void Initialize(char arr[], int SIZE);

int main()
{
	ShowSum(3, 5.76);

	//ShowSum(4);

	//Show(10);

	//const int SIZE = 5;
	//int arr1[SIZE] = { 1, 2, 3, 4, 5 };
	//double arr2[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	//char arr3[SIZE] = { '1', '2', '3', '4', '5' };
	//long arr4[SIZE] = { 1l, 2l, 3l, 4l, 5l };

	//Initialize(arr1, SIZE);
	//Initialize(arr2, SIZE);
	//Initialize(arr3, SIZE);

	//Show(arr1, SIZE);
	//Show(arr2, SIZE);
	//Show(arr3, SIZE);
	//Show(arr4, SIZE);

	return 0;	 
}

template<typename T1, typename T2>
void ShowSum(T1 a, T2 b)
{
	std::cout << a + b << std::endl;
}

//template<typename T>

//void Show(T value)
//{
//	std::cout << value;
//}

//void Show(const T arr[], int size)
//{
//	for (size_t i = 0; i < size; i++)
//		std::cout << arr[i] << "";
//	std::cout << std::endl;
//}

/*
Syntax for writing a function template:
template <typename T>
Function
*/

//void Initialize(int arr[], int SIZE)
//{
//	for (int i = 0; i < SIZE; i++)
//		arr[i] = rand() % 100;
//}
//
//void Initialize(double arr[], int SIZE)
//{
//	for (int i = 0; i < SIZE; i++)
//		arr[i] = rand() % 100+rand()%100/100.0;
//}
//
//void Initialize(char arr[], int SIZE)
//{
//	for (int i = 0; i < SIZE; i++)
//		arr[i] = rand() % ('Z'+1-'A')+'A';
//}


