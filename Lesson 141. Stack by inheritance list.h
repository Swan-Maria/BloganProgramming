#pragma once
#include "Lesson 140. List.h"

template<typename T>
class Stack : private List<T>
{
public:
	void Push(const T& value)
	{
		List<T>::PushBack(value);
	}

	void Pop()
	{
		List<T>::PopBack();
	}

	T& Top()
	{
		return List<T>::Back();
	}

	bool IsEmpty() const
	{
		return  List<T>::isEmpty();
	}

	size_t Size() const
	{
		return  List<T>::Size();
	}
};