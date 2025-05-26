#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>

int main()
{
	// Конструктори
	// 1. stack()							- конструктор за замовчуванням.
	// 2. stack(const Alloc & alloc)		- конструктор за замовчуванням з указанням алокатора.
	
	// 3. stack(const std::stack<T>& other)						- конструктор копії.
	// 4. stack(const std::deque<T>& other)						- конструктор копії deque.
	// 5. stack(const std::stack<T>& other, const Alloc& alloc) - конструктор копії з указанням алокатора.
	// 6. stack(const std::deque<T>& other, const Alloc& alloc) - конструктор копії deque з указанням алокатора.
	
	// 7. stack(std::stack<T>&& other)						- конструктор переміщення.
	// 8. stack(std::deque<T>&& other)						- конструктор переміщення deque.
	// 9. stack(std::stack<T>&& other, const Alloc& alloc)	- конструктор переміщення з указанням алокатора.
	// 10. stack(std::deque<T>&& other, const Alloc& alloc) - конструктор переміщення deque з указанням алокатора.

	// Деструктор 
	// Опис: оскільки std::stack містить лише одне поле контейнер std::deque, то деструктор класу std::stack викликає деструктор: класу std::deque.

	// Методи 
	// 1. bool empty() const повертає true, якщо stack пустий, i false, якщо має елементи. 
	// 2. void push(const T& value) копіює значення в кінець стеку. 
	//	  void push(T && value) переміщає значения в кінець стеку.
	// 3. decltype(auto) emplace(Args&&...) конструює новий елемент в кінці стеку.
	// 4. T& top() 	повертає посилання на останній(верхній) елемент стеку.
	//    const T& top() const повертає посилання на останній(верхній) елемент стеку.
	// 5. void pop() видаляє останній елемент зі стеку(викликає деструктор).
	// 6. size t size() const повертає розмір стеку.
	// 7. void swap(const std::stack<T>&other) міняє вміст двох стеків.
	// 8. const std::deque<T>& _Get_Container() const повератає посилання на внутрішній контейнер.
	// 9. void operator=(const std::stack<T>&other) переписує вміст стеку, копіюючи значення нового стеку
	//    void operator=(std::stack<T> && other) переписує вміст стеку, переміщаючи значення нового стеку

	// Функції 
	//  1. bool operator==[const std::stack<T>&si, const std::stack<T>&21 порівнює 2 стеки(чи рівні їх елементи).
	//	2. bool operator>(const std::stack<T>&51, const std::stack < T>6 s2 - (видалений в С++28).
	//	3. bool operator>=(const std::stack<T>&s1, const std::stack<T>&2)   - (видалений в С++20).
	//	4. bool operator<(const std::stack<T>&s1, const std::stack<T>&s2)   - (видалений в С++20).
	//	5. bool operator<=(const std::stack<T>&s1, const std::stack<T>&s2)  - (видалений в С++28).
	//	6. bool operator!=(const std::stack<T>&s1, const std::stack<T>&s2)  - (видалений в C++28).
	//	7. std::compare_three_way_result_t < Container operator<=>(const std::stack<T>&s1, const std::stack<T>&s2)
	//	8. std::swap(std::stack<T>&s1, std::stack<T>&s2) міняє вміст двох стеків.

	// Приклад використання
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
