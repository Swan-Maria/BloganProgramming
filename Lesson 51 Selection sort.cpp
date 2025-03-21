#include <iostream>
#include <ctime>

template <typename T>
void Initialize(T arr[], int size);
template <typename T>
void Show(const T arr[], int size);
template <typename T>
void SelectionSort(T arr[], int size);

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	const int SIZE1 = 10;
	int arr1[SIZE1];
	const int SIZE2=20;
	double arr2[SIZE2];
	Initialize(arr1, SIZE1);
	Show(arr1, SIZE1);
	Initialize(arr2, SIZE2);
	Show(arr2, SIZE2);
	SelectionSort(arr1, SIZE1);
	SelectionSort(arr2, SIZE2);
	Show(arr1, SIZE1);
	Show(arr2, SIZE2);

	return 0;
}

template <typename T>
void Initialize(T arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

template <typename T>
void Show(const T arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void SelectionSort(T arr[], int size)
{
	for (size_t i = 0; i < size - 1; i++)
		for (size_t j = i + 1; j < size; j++)
			if (arr[j] < arr[i])
				std::swap(arr[j], arr[i]);

}
