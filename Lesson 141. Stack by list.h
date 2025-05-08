#pragma once
#include "Lesson 140. List.h"

template<typename T>
class Stack :
{
private:
	List<T> list;
public:
	void Push(const T& value)
	{
		list.PushBack(value);
	}

	void Pop()
	{
		list.PopBack();
	}

	T& Top()
	{
		return list.Back();
	}

	bool IsEmpty() const
	{
		return list.isEmpty();
	}

	size_t Size() const
	{
		return list.Size();
	}
};