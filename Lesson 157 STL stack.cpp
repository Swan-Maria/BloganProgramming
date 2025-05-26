#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>

int main()
{
	// ������������
	// 1. stack()							- ����������� �� �������������.
	// 2. stack(const Alloc & alloc)		- ����������� �� ������������� � ��������� ���������.
	
	// 3. stack(const std::stack<T>& other)						- ����������� ��ﳿ.
	// 4. stack(const std::deque<T>& other)						- ����������� ��ﳿ deque.
	// 5. stack(const std::stack<T>& other, const Alloc& alloc) - ����������� ��ﳿ � ��������� ���������.
	// 6. stack(const std::deque<T>& other, const Alloc& alloc) - ����������� ��ﳿ deque � ��������� ���������.
	
	// 7. stack(std::stack<T>&& other)						- ����������� ����������.
	// 8. stack(std::deque<T>&& other)						- ����������� ���������� deque.
	// 9. stack(std::stack<T>&& other, const Alloc& alloc)	- ����������� ���������� � ��������� ���������.
	// 10. stack(std::deque<T>&& other, const Alloc& alloc) - ����������� ���������� deque � ��������� ���������.

	// ���������� 
	// ����: ������� std::stack ������ ���� ���� ���� ��������� std::deque, �� ���������� ����� std::stack ������� ����������: ����� std::deque.

	// ������ 
	// 1. bool empty() const ������� true, ���� stack ������, i false, ���� �� ��������. 
	// 2. void push(const T& value) ����� �������� � ����� �����. 
	//	  void push(T && value) ������� �������� � ����� �����.
	// 3. decltype(auto) emplace(Args&&...) ��������� ����� ������� � ���� �����.
	// 4. T& top() 	������� ��������� �� �������(������) ������� �����.
	//    const T& top() const ������� ��������� �� �������(������) ������� �����.
	// 5. void pop() ������� ������� ������� � �����(������� ����������).
	// 6. size t size() const ������� ����� �����.
	// 7. void swap(const std::stack<T>&other) ���� ���� ���� �����.
	// 8. const std::deque<T>& _Get_Container() const �������� ��������� �� �������� ���������.
	// 9. void operator=(const std::stack<T>&other) �������� ���� �����, ������� �������� ������ �����
	//    void operator=(std::stack<T> && other) �������� ���� �����, ���������� �������� ������ �����

	// ������� 
	//  1. bool operator==[const std::stack<T>&si, const std::stack<T>&21 ������� 2 �����(�� ��� �� ��������).
	//	2. bool operator>(const std::stack<T>&51, const std::stack < T>6 s2 - (��������� � �++28).
	//	3. bool operator>=(const std::stack<T>&s1, const std::stack<T>&2)   - (��������� � �++20).
	//	4. bool operator<(const std::stack<T>&s1, const std::stack<T>&s2)   - (��������� � �++20).
	//	5. bool operator<=(const std::stack<T>&s1, const std::stack<T>&s2)  - (��������� � �++28).
	//	6. bool operator!=(const std::stack<T>&s1, const std::stack<T>&s2)  - (��������� � C++28).
	//	7. std::compare_three_way_result_t < Container operator<=>(const std::stack<T>&s1, const std::stack<T>&s2)
	//	8. std::swap(std::stack<T>&s1, std::stack<T>&s2) ���� ���� ���� �����.

	// ������� ������������
	std::stack<int> numbers;
	for (int number =0; number < 5; number++)
	{
		numbers.push(number);
	}
	size_t initialSize = numbers.size();
	for (size_t i = 0; i < initialSize; i++)
	{
		int value = numbers.top();
		numbers.pop();
		std::cout << value << " ";
	}
	std::cout << std::endl;
	if (numbers.empty())
	{
		std::cout << "Stack is empty.\n";
	}

}
