#include <iostream>
#include <ctime>

void Initialize(int arr[], int size);
void Show(const int arr[], int size);

template <typename T>
void BubbleSort(T arr[], size_t SIZE);

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	
	const int SIZE = 10;
	int arr[SIZE];

	Initialize(arr, SIZE);
	Show(arr, SIZE);

	BubbleSort(arr, SIZE);
			
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
void BubbleSort(T arr[], size_t SIZE)
{
	for (size_t i = 0; i < SIZE - 1; i++)
		for (size_t j = SIZE - 1; j > i; j--)
			if (arr[j] < arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
}
