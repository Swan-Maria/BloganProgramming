#include <iostream>
#include <vector>
#include <list>
#include "Lesson 160 Person.h"

void Show(const std::list<int>& container);

void Show(const std::list<Person>& container);

void Constructors();
void Destructor();
void Methods();
void GlobalOperatorsAndFunctions();
void ContainerAliases();
void OwnClassInVector();
void PointersInContainer();

int main()
{
	Constructors();
	//Destructor();
	//Methods();
	//GlobalOperatorsAndFunctions();
	//ContainerAliases();
	//OwnClassInVector();
	//PointersInContainer();

}

void Show(const std::list<int>& container)
{
	if (container.empty())
	{
		std::cout << "Container is empty.\n";
	}
	else
	{
		std::cout << "Elements: ";
		for (int value : container)
		{
			std::cout << value << " ";
		}
		std::cout << "\n";
	}
	std::cout << "Size =" << container.size() << "\n";
}

void Show(const std::list<Person>& container)
{
	if (container.empty())
	{
		std::cout << "Container is empty.\n";
	}
	else
	{
		std::cout << "People: ";
		for (const Person& person : container)
		{
			std::cout << "\t";
			person.ShowInfo();
		}
	}
	std::cout << "Size =" << container.size() << "\n";
}

void Constructors()
{
	std::cout << "----- CONSTRUCTOR -----\n";

	// 1. ����������� �� ���������
	std::list<int> list1;
	Show(list1);
	// 2. ����������� �� ���������, ������� ��������� ���������������� ���������
	std::allocator<int> myAllocator;
	std::list<int> list2(myAllocator);
	Show(list2);

	// 3. �����������, ������� ��������� std::initializer_list
	std::list<int> list3{ 1,2,3,4,5,6,7,8,9,10 };
	Show(list3);

	// 4. ����������� �����
	std::list<int> list4(list3);
	Show(list4);

	// 5. ����������� �����������
	std::list<int> list5(std::move(list4));
	Show(list4);
	Show(list5);

	// 6. �����������, ������� ��������� ���������� ���������
	std::list<int> list6(10);
	Show(list6);

	// 7. �����������, ������� ��������� ���������� ��������� � �� ��������
	std::list<int> list7(3, 100);
	Show(list7);

	// 8. �����������, ������� ��������� ��� ���������
	std::vector<int> vector{ 10,20,30 };
	std::list<int> list8(vector.begin(), vector.begin() + 4);
	Show(list8);
}

void Destructor()
{
	std::cout << "----- DESTRUCTOR -----\n";
	// � ���������� ���� ����������, � ������� ��� ������ ��� ���������� �������� �� ����
	// ������������� �������������/���������. �������� ������������� �������� ����������� ����.
	std::list<Person> list(2);
}

void Methods()
{
	std::cout << "----- METHODS -----\n\n";
	// 1. front ������� ��������� �� ������ �������.
	// 2. back ������� ��������� �� ������� �������.
	{
		std::list<int> list{ 1,2,3,4,5,6,7,8,9,10 };
		list.front() = 100;
		list.back() = 100;
	}
	// 3. get_allocator - ������� ��������, ���� ����'������ �� ����������.
	{
		std::list<int> list;
		std::allocator<int> allocator = list.get_allocator();
	}
	// 4. operator= - �������� ������������ ���� ������� ������ ���������.
	{
		std::list<int> list{ 1,2,3,4,5,6,7,8,9,10 };
		list = {1,2,3,4,5}; //std::initializer_list
		list = std::list<int>(10, 1); // move =
		std::list<int> otherlist{ 200,100,0 };
		list == otherlist; //copy =
	}
	// 5. assign - �������� ������������ ���� ������� ������ ���������.
	//              ������ �� �������� =, ��� �� ����� �����������, �� ���� ��������
	//              ����� ������ ���������.
	{
		std::list<int> list{ 1,2,3,4,5,6,7,8,9,10 };
		list.assign({ 1,2,3,4,5 }); //std::initializer_list
		list.assign(5, 100); // 5 elements with value 100
		std::vector<int> vector{ 500,499,388 };
		list.assign(vector.cbegin(), vector.cend()); //range value
	}
	// 6. begin
	// 7. end
	// 8. cbegin
	// 9. cend
	// 10. rbegin
	// 11. rend
	// 12. crbegin
	// 13. crend
	// 14. empty
	// 15. size - ������� ������� ��������
	// 16. max_size - ������� ������������ ������� ������� ��������
	// 17. clear
	// 18. insert - ������� � ������ ����
	// 19. push_back
	// 20. push_front
	// 21. pop_back
	// 22. pop_front
	// 23. resize
	// 24. swap
	// 25. erase - ������ ���������, �� ������ ��������
	// 26. merge - ��'���� ��� ������������ ������
	// 27. splice - ������� �������� ������� ������ � ������ ������ �� ������� ����
	// 28. remove
	// 29. remove_if
	// 30. reverse
	// 31. unique - ������� ��������-�������, �� ����� � ���, ��������� ���� ������� ��������
	// 32. sort - ����� �������� ������ � �������� O(n*log(n))
}

void GlobalOperatorsAndFunctions()
{
	// 1. operator=
	// ���� � �++20
	// 2. operator!=
	// 3. operator<
	// 4. operator<=
	// 5. operator>
	// 6. operator>=
	// �� ������� �� �������� <=>
	// 7. operator<=>
	// 8. swap
	// �������� � �++20
	// 9. erase
	// 10. erase_if
}

void ContainerAliases()
{
	/*
	ֳ ��������� � � ������� ���������:
	using value_type        = _Ty;
	using allocator_type    = Alloc;
	using pointer           = typename Alty_traits::pointer;
	using const_pointer     = typename Alty_traits::const_pointer;
	using reference         = _Ty&;
	using const_reference   = const _Ty&;
	using size_type         = typename Alty_traits::size_type;
	using difference_type   = typename Alty_traits::difference_type;
	*/
}

void OwnClassInVector()
{
	std::list<Person> people;

	people.push_back(Person());
	people.cbegin()->ShowInfo();

	std::cout << "--------------------\n";

	people.emplace_back(25, "Demian");
	people.back().ShowInfo();

	std::cout << "--------------------\n";

	for (auto iterator = people.cbegin(); iterator != people.cend(); ++iterator)
	{
		iterator->ShowInfo();
	}

	std::cout << "--------------------\n";

	std::list<Person> people;

	people.push_back(Person());
	people.cbegin()->ShowInfo();

	std::cout << "--------------------\n";

	people.emplace_back(25, "Demian");
	people.back().ShowInfo();

	std::cout << "--------------------\n";

	for (auto iterator = people.cbegin(); iterator != people.cend(); ++iterator)
	{
		iterator->ShowInfo();
	}

	std::cout << "--------------------\n";
}

void PointersInContainer()
{
	std::list<Person> people;

	people.push_back(Person());
	people.cbegin()->ShowInfo();

	std::cout << "--------------------\n";

	people.emplace_back(25, "Demian");
	people.back().ShowInfo();

	std::cout << "--------------------\n";

	for (auto iterator = people.cbegin(); iterator != people.cend(); ++iterator)
	{
		iterator->ShowInfo();
	}

	std::cout << "--------------------\n";
}
