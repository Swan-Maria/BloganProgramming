#include <iostream>
#pragma once

template<size_t MAX_SIZE>
class Stack
{
	int stack[MAX_SIZE] = {};
	int top = -1;
public:
	bool Push(const int& value)
	{
		if (!IsFull())
		{
			stack[++top] = value;
			return true;
		}
		return false;
	}
	void Pop()
	{
		if (!IsEmpty())
		{
			--top;
		}
	}
	int& Top()
	{
		return stack[top];
	}
	bool IsFull() const
	{
		return top == MAX_SIZE - 1;
	}
	bool IsEmpty() const
	{
		return top == -1;
	}
	size_t MaxSize() const
	{
		return MAX_SIZE;
	}
	size_t Size() const
	{
		return top + 1;
	}
};