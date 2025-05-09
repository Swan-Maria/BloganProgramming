#include <iostream>
//#include "Lesson 141. Stack on stack.h"
//#include "Lesson 141. Stack on heap.h"
//#include "Lesson 141. Stack by list.h"
#include "Lesson 141. Stack by inheritance list.h"

class Person
{
private:
	std::string name;
	int age;
public:
	Person() = default;
	Person(const std::string& name, int age) 
		: name(name), age(age) 
	{}

	std::string Name() const
	{
		return name;
	}

	int Age() const
	{
		return age;
	}
};

int main()
{
	//Stack on stack memory
	/*Stack<10> myStack;
	std::cout << (myStack.IsEmpty() ? "Stack is empty" : "Stack is not empty") << std::endl;
	std::cout << "Max size: " << myStack.MaxSize() << std::endl;

	for (int i = 0; i < myStack.MaxSize()-5; ++i)
	{
		if (myStack.Push(i))
		{
			std::cout << i << " was pushed" << std::endl;
		}
		else
		{
			std::cout << i << " was not pushed" << std::endl;
		}
	}

	std::cout << "Stack size: " << myStack.Size() << std::endl;
	
	while (!myStack.IsEmpty())
	{
		std::cout << myStack.Top() << " ";
		myStack.Pop();
	}*/

	//Stack on heap memory
	/*Stack myStack;
	std::cout << "Size Stack1 = " << myStack.Size() << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		myStack.Push(i);
		std::cout << "Size Stack1 = " << myStack.Size() << std::endl; 
	}

	Stack myStack2(myStack);
	std::cout << "Size Stack2 = " << myStack2.Size() << std::endl;

	Stack myStack3;
	myStack3 = myStack;
	std::cout << "Size Stack3 = " << myStack3.Size() << std::endl;*/
	
	//Stack by list
	Stack<double> myStack;
	for (int i = 0; i < 10; ++i)
	{
		myStack.Push(i);
	}

	while (!myStack.IsEmpty())
	{
		std::cout << myStack.Top() << " ";
		myStack.Pop();
	}

	Stack<Person> myStack2;
	myStack2.Push(Person("John", 25));
	myStack2.Push(Person("Jane", 30));
	myStack2.Push(Person("Alice", 28));
	while (!myStack2.IsEmpty())
	{
		std::cout << myStack2.Top().Name() << " " <<
			myStack2.Top().Age() << std::endl;
		myStack2.Pop();
	}

	return 0;
}