#include <iostream>
#include "Lesson 127 Array.h"

Array::Array()
	:size(0), arr(nullptr)
{
	std::cout << "Array::Array()\n";
}

Array::Array(size_t size)
	:size(0), arr(nullptr)
{
	std::cout << "Array::Array(size_t size)\n";
	if (size > 0)
	{
		this->size = size;
		arr = new int [size] {};
	}
}

Array::Array(const Array& oth)
	:size(oth.size), arr(nullptr)
{
	if (oth.size > 0)
	{
		this->arr = new int[oth.size];
		for (size_t i = 0; i < size; i++)
			this->arr[i] = oth.arr[i];
	}
}

Array::~Array()
{
	delete[] arr;
	arr = nullptr;
}

Array Array::operator=(const Array& oth)
{
	if (this != &oth)
	{
		this->~Array();
		this->size = oth.size;
		if (oth.size > 0)
		{
			this->arr = new int[oth.size];
			for (size_t i = 0; i < size; i++)
				this->arr[i] = oth.arr[i];
		}
	}
	return *this;
}

int& Array::operator[](size_t index)
{
	if (index < size)
		return arr[index];
	std::exit(1);
}

const int& Array::operator[](size_t index) const
{
	if (index < size)
		return arr[index];
	std::exit(1);
}
