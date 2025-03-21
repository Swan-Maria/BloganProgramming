#include <iostream>
#include <ctime>

void Initialize(int arr[], int size);
void Show(const int arr[], int size);

template<typename T>
void InsertionSort(T arr[], int SIZE);

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	const int SIZE = 10;
	int arr[SIZE];

	Initialize(arr, SIZE);
	Show(arr, SIZE);

	InsertionSort(arr, SIZE);

	Show(arr, SIZE);

	return 0;
}

void Initialize(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void Show(const int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void InsertionSort(T arr[], int SIZE)
{
	for (int i = 1; i < SIZE; i++)
	{
		int key = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}
