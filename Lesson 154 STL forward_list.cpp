// Які є контейнери?
// Схема роботи контейнера forward_list
// Конструктори
// Деструктор
// Методи
// Глобальні перезавантаження операторів і функції
// Типи - члени контейнера
// Оцінка операцій по О - нотації

// forward_list - однозв'язний список

#include <iostream>
#include <forward_list>
#include <list>
#include <vector>
#include "Lesson 160 Person.h"

void Show(const std::forward_list<int>& container)
{
	if (container.empty())
	{
		std::cout << "Container is empty" << std::endl;
		return;
	}
	else
	{
		std::cout << "Elements: ";
		for (int value : container)
		{
			std::cout << value<<" ";
		}
		std::cout << std::endl;
	}
}

void Show(const std::forward_list<Person>& container)
{
	if (container.empty())
	{
		std::cout << "Container is empty" << std::endl;
		return;
	}
	else
	{
		std::cout << "Elements: ";
		for (const Person& person : container)
		{
			std::cout <<"\t(Name: "<< person.Name() <<
				", age: "<<person.Age() << ")\n";
		}
		std::cout << std::endl;
	}
}

int main()
{
	///Constructors
	std::cout << "--- Constructors ---\n";
	{
		std::forward_list<int> container1; // default constructor
		Show(container1);

		std::forward_list<int> container2 = { 1,10,30 };
		Show(container2);

		std::vector<int> vec = { 1,2,3,4,5 };
		std::forward_list<int> container3(vec.cbegin(), vec.cend());
		Show(container3);

		std::forward_list<int> container4(container3);
		Show(container4);

		std::forward_list<int> container5(std::move(container2));
		Show(container5);

		std::forward_list<int> container6(6);
		Show(container6);

		std::forward_list<int> container7(5, 25);
		Show(container7);
	}
	std::cout << "\n\n";


	///Destructor
	std::cout << "--- Destructor ---\n";
	{
		std::forward_list<Person> container(2);
	}
	std::cout << "\n\n";

	///Methods
	std::cout << "--- Methods ---\n";
	{
		std::forward_list<int> list;
		std::forward_list<int> otherList{ 0,1,0,1 };
		std::list<int> otherContainer { 1000,999,888 };
		/// 1. operator=
		list = { 100,101,102,103 };
		Show(list);
		list = std::forward_list<int>(10,-1);
		Show(list);
		list = otherList;
		Show(list);

		///	2. assign
		list.assign(5, 100);
		Show(list);
		list.assign({ -1, -2, -3 });
		Show(list);
		list.assign(otherContainer.begin(), otherContainer.end());
		Show(list);

		/// 3. get_allocator
		auto alloc = list.get_allocator();

		/// 4. front
		std::cout << "Front: " << list.front() << std::endl;
		list.front() = 1000;
		std::cout << "Front: " << list.front() << std::endl;

		/// 5. begin
		/// 6. cbegin
		/// 7. end
		/// 8. cend
		Show(list);
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			*it += 1000;
		}
		for (auto it = list.cbegin(); it != list.cend(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		/// 9. clear
		list.clear();
		Show(list);
		/// 10. push_front
		/// 11. pop_front
		list.push_front(10);
		list.push_front(20);
		list.push_front(30);
		Show(list);
		list.pop_front();
		list.pop_front();
		Show(list);
		/// 12. sort
		list = { 5,4,3,2,1 };
		list.sort();
		Show(list);
		list.sort([](int value1, int value2)
			{
				return value1 > value2;
			});
		Show(list);
		/// 13. unique
		list = { 1,1,2,2,3,3,4,4,5,5 };
		Show(list);
		list.unique();
		Show(list); 
		/// 14. reverse
		list = { 1,10,100 };
		Show(list);
		list.reverse();
		Show(list);
		/// 15. swap
		list = { 1,2,3 };
		std::forward_list<int> list2{ 10,20,30,40};
		Show(list);
		Show(list2);
		list.swap(list2);
		Show(list);
		Show(list2);
		/// 16. resize
		list.resize(1);
		Show(list);
		list.resize(10);
		Show(list);
		/// 17. remove
		/// 18. remove_if
		list = { 1,2,3,4,5,6,7,8,9 };
		Show(list);
		list.remove(2);
		Show(list);
		list.remove_if([](int value)
			{
				return value >=5;
			});
		Show(list);
		/// 19. merge
		list = { 1,10,100 };
		list2 = { 0,2,5,20,40,200 };
		list.merge(list);
		Show(list);
		Show(list2);
		/// 20. emplace_front
		{
			std::forward_list<Person> people;
			people.emplace_front(25, "Demian");
			people.emplace_front(26, "Olga");
			people.emplace_front(22, "Helena");
			//people.push_front(Person(25, "Demian"));
			//people.push_front(Person(26, "Olga"));
			//people.push_front(Person(22, "Helena"));
			Show(people);
		}
		/// 21. empty
		list = { 1,2,3 };
		std::cout << (list.empty() ? "List is empty\n" : "List is not empty\n");
		list.clear();
		std::cout << (list.empty() ? "List is empty\n" : "List is not empty\n");
		/// 22. max_size
		std::cout << "Max size = " << list.max_size() << std::endl;
		/// 23. before_begin
		/// 24. cbefore_begin
		/// 25. insert_after
		/// 26. emplase_after
		/// 27. arase_after
		/// 28. splice_after
		{
			// використання insert_after:
			list = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			Show(list);
			auto iter1 = std::find(list.cbegin(), list.cend(), 5);
			list.insert_after(iter1, 100);
			Show(list);

			// використання emplace_after:
			std::forward_list<Person> people
			{
				Person(10, "George"),
				Person(25, "Demian"),
				Person(20, "Viktoria"),
			};
			Show(people);
			auto iter2 = std::find(people.cbegin(), people.cend(), Person(25, "Demian"));
			people.emplace_after(iter2, 30, "David");
			Show(people);

			// використання before_begin/cbefore_begin:
			list.insert_after(list.before_begin(), { 200, 200, 200 });
			Show(list);

			// використання erase_after:
			list.erase_after(iter1);
			Show(list);

			// використання splice_after:
			list2 = { 1000, 1001, 1002 };
			list.splice_after(iter1, list2);
			Show(list);
			Show(list2);

		}
	}
	std::cout << "\n\n";

	///Global reloading operators and functions
	std::cout << "--- Global operators and functions ---\n";
	{
		// 1. operator== - порівнює вміст контейнерів.
//                  true - якщо контейнери мають однаковий розмір і всі
//                         їх елементи рівні між собою.
		std::forward_list<int> list1 = { 1, 2, 3 };
		std::forward_list<int> list2 = { 1, 2, 3 };
		std::forward_list<int> list3 = { 1, 2, 3, 4 };
		std::forward_list<int> list4 = { 1, 2, 5 };

		if (list1 == list2)
		{
			std::cout << "list1 == list2\n";
		}
		if (list1 == list3) // ні, бо розміри різні
		{
			std::cout << "list1 == list3\n";
		}
		if (list1 == list4) // ні, бо значення різні
		{
			std::cout << "list1 == list4\n";
		}

		// Оператори 2-6 убрані в стандарті C++20. Ви можете самі
		// догадатися, як вони працюють, якщо знаєте, як працює оператор==.
		// 2. operator!=
		// 3. operator<
		// 4. operator<=
		// 5. operator>
		// 6. operator>=

		// В стандарті C++20 замість операторів 1-6 появився оператор <=>.
		// Він продуктивніший. Оскільки я не показував його роботу окремо від контейнеру
		// то й тут його показувати не буду. Це діло за вами.
		// 7. operator<=>
		// 8. std::swap - міняє місцями вміст двох контейнерів. Це спеціалізація шаблону
		//                функції std::swap, яка викликає всередині метод forward_list::swap().

		// Ці функції добавлені в C++20, тому їх оглядати не будемо. Вони видаляють елементи контейнера так,
		// як це робить метод erase.
		//  9.  std::erase
		// 10. std::erase_if
	}
	std::cout << "\n\n";

	// Типы-члены контейнера:
	std::cout << "--- Member types ---\n";
	{
		std::forward_list<int>::value_type value = 10;        // int value = 10;
		std::forward_list<int>::const_reference reference = value; // const int& reference = value;
		std::forward_list<int>::pointer pointer = &value;     // int* pointer = &value;
	}
	std::cout << "\n\n";

	return 0;
}