#pragma once
#include <list>

template<typename T>
class Stack : private std::list<T>
{
public:
	void Push(const T& value)
	{
		std::list<T>::push_back(value);
	}

	void Pop()
	{
		std::list<T>::pop_back();
	}

	T& Top()
	{
		return std::list<T>::back();
	}

	bool IsEmpty() const
	{
		return  std::list<T>::empty();
	}

	size_t Size() const
	{
		return  std::list<T>::size();
	}
};