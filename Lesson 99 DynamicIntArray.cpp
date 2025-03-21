#include <iostream>
#include <cstdlib>
#include "Lesson_99_DynamicIntArray.h"

DynamicIntArray::DynamicIntArray(size_t size)
{
	std::cout << "Dynamic Int Array Constructor\n";

	if (size != 0)
		this->size = size;
	arr = new int[size];
	for (size_t i = 0; i < size; i++)
		arr[i] = std::rand() % 100;
}
DynamicIntArray::DynamicIntArray(const DynamicIntArray& other)
	:size(other.size)
{
	std::cout << "Dynamic Int Array Copy Constructor\n";

	if (size != 0)
		this->size = size;
	arr = new int[size];
	for (size_t i = 0; i < size; i++)
		arr[i] = other.arr[i];
}
DynamicIntArray::~DynamicIntArray()
{
	std::cout << "Dynamic Int Array Destructor\n";

	delete[] arr;
	arr = nullptr;
	size = 0;
}
int DynamicIntArray::GetElement(size_t index) const
{
	if (index >= size)
	{
	std::cout << "Incorrect index . \n";
	std::exit(EXIT_FAILURE);
}
return arr[index];
}
void DynamicIntArray::SetElement(size_t index, int value)
{
	if (index >= size)
	{
		std::cout << "Incorrect index. \n";
		std::exit(EXIT_FAILURE);
	}
	arr[index] = value;
}

