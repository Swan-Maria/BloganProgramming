#pragma once
#include <list>

template<typename T>
class Stack
{
private:
	std::list<T> list;
public:
	void Push(const T& value)
	{
		list.push_back(value);
	}

	void Pop()
	{
		list.pop_back();
	}

	T& Top()
	{
		return list.back();
	}

	bool IsEmpty() const
	{
		return list.empty();
	}

	size_t Size() const
	{
		return list.size();
	}
};