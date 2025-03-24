#include <iostream>
#pragma once

template <typename T>
class Array
{
private:
	T* arr;
	size_t size;
public:
	Array();
	Array(size_t size);
	Array(const Array& oth);
	~Array();

	Array operator=(const Array& oth);
	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	size_t Size() const;
};

template <typename T>
size_t	Array<T>::Size() const { return size; }

template <typename T>
Array<T>::Array()
	:size(0), arr(nullptr)
{}

template <typename T>
Array<T>::Array(size_t size)
	:size(0), arr(nullptr)
{
	if (size > 0)
	{
		this->size = size;
		arr = new T [size] {};
	}
}

template <typename T>
Array<T>::Array(const Array& oth)
	:size(oth.size), arr(nullptr)
{
	if (oth.size > 0)
	{
		this->arr = new T[oth.size];
		for (size_t i = 0; i < size; i++)
			this->arr[i] = oth.arr[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
	arr = nullptr;
}

template <typename T>
Array<T> Array<T>::operator=(const Array& oth)
{
	if (this != &oth)
	{
		delete[] arr;
		arr = nullptr;
		this->size = oth.size;
		if (oth.size > 0)
		{
			this->arr = new T[oth.size];
			for (size_t i = 0; i < size; i++)
				this->arr[i] = oth.arr[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index < size)
		return arr[index];
	std::exit(1);
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index < size)
		return arr[index];
	std::exit(1);
}
