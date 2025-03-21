#pragma once
#include <iostream> 

//template <typename T, size_t size>
//class Array
//{
//private:
//	T arr[size];
//public:
//	Array()
//	{
//		for (size_t i = 0; i < size; i++)
//		{
//			arr[i] = std::rand%100;
//		}
//	}
//
//	void Show() const
//	{
//		for (size_t i = 0; i < size; i++)
//		{
//			std::cout << arr[i] << " ";
//		}
//	}
//};


template <typename T>
class Array
{
private:
	T* arr;
	size_t size;
public:
	Array(size_t size)
		:size(size), arr(new T[size])
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 100;
		}
	}

	Array(const Array& other)
	:size(other.size), arr(new T[other.size])
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	
	Array(Array&& other)
		:size(other.size), arr(other.arr)
	{
		other.size = 0;
		other.arr = nullptr;
	}
	
	~Array()
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
	}
	
	Array operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] arr;
			size = other.size;
			arr = new int[other.size];
			for (size_t i = 0; i < size; i++)
			{
				arr[i] = other.arr[i];
			}
		}
	}
	
	Array operator=(Array&& other)
	{
		if (this != &other)
		{
			delete[] arr;
			size = other.size;
			arr = other.arr;
			other.size = 0;
			other.arr = nullptr;
		}
		return *this;
	}

	size_t Size()const { return size; }

	void Show() const;
};

template<typename T>
inline void Array<T>::Show() const
{
	if (size == 0)
	{
		std::cout << "empty\n";
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
}

template<>
inline void Array<char>::Show() const
{
	if (size == 0)
	{
		std::cout << "empty\n";
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i];
		}
		std::cout << std::endl;
	}
}