#include <iostream>
#pragma once

class Stack
{
	int* stack=nullptr;
	int top = -1;
public:
	Stack() = default;
	Stack(const Stack& other)
	{
		if (other.stack == nullptr)
		{
			stack = nullptr;
			top = -1;
		}
		else
		{
			stack = new int[other.top + 1];
			for (int i = 0; i <= other.top; ++i)
			{
				stack[i] = other.stack[i];
			}
			top = other.top;
		}
	}
	
	~Stack()
	{
		delete[] stack;
		stack = nullptr;
	}
	
	Stack& operator=(const Stack& other)
	{
		if (this != &other)
		{
			delete[] stack;
			if (other.stack == nullptr)
			{
				stack = nullptr;
				top = -1;
			}
			else
			{
				stack = new int[other.top + 1];
				for (int i = 0; i <= other.top; ++i)
				{
					stack[i] = other.stack[i];
				}
				top = other.top;
			}
		}
		return *this;
	}
	void Push(const int& value)
	{
		if (IsEmpty())
		{
			stack = new int[1];
			stack[++top] = value;
			return;
		}
		else
		{
			int* newStack = new int[top + 2];
			for (int i = 0; i <= top; ++i)
			{
				newStack[i] = stack[i];
			}
			delete[] stack;
			stack = newStack;
			stack[++top] = value;
		}
	}
	
	void Pop()
	{
		if (!IsEmpty())
		{
			if (Size() == 1)
			{
				delete[] stack;
				stack = nullptr;
				top = -1;
			}
			else
			{
				int* newStack = new int[top];
				for (int i = 0; i < top; ++i)
				{
					newStack[i] = stack[i];
				}
				delete[] stack;
				stack = newStack;
				--top;
			}
		}
	}
	
	int& Top()
	{
		return stack[top];
	}
	
	bool IsEmpty() const
	{
		return top == -1;
	}
	
	size_t Size() const
	{
		return top + 1;
	}
};