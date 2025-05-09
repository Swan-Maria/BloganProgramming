#pragma once
#include <list>
template<typename T>
class Queue
{
private:
	std::list<T> list;
public:
	void Pop()
	{
		list.pop_front();
	}
	
	void Push(const T& value)
	{
		list.push_back(value);
	}
	
	size_t Size() const
	{
		return list.size();
	}
	
	void Swap(Queue& other) noexcept
	{
		list.swap(other.list);
	}
	
	bool IsEmpty() const
	{
		return list.empty();
	}
	
	T& Front()
	{
		return list.front();
	}
	
	const T& Front() const
	{
		return list.front();
	}
	
	T& Back()
	{
		return list.back();
	}
	
	const T& Back() const
	{
		return list.back();
	}
};
