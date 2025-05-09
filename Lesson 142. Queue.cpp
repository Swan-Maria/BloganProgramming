#include <iostream>
#include <string>
#include <queue>
#include "Lesson 142. Queue.h"
class Person
{
private:
	std::string name;
	int age;
public:
	Person() = default;
	Person(const std::string& name, int age)
		: name(name), age(age)
	{
	}

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
	Queue<double> myQueue;

	for (double value = 1.0; value < 3.0; value+=0.2)
	{
		myQueue.Push(value);
	}

	Queue<double> myQueue2;

	for (double value = 5.0; value < 6.0; value += 0.3)
	{
		myQueue2.Push(value);
	}

	myQueue.Swap(myQueue2);

	std::cout << "Size = "<<myQueue.Size() << std::endl;
	while (!myQueue.IsEmpty())
	{
		std::cout << myQueue.Front() << "    ";
		myQueue.Pop();
	}
	std::cout << std::endl;

	std::cout << "Size = "<<myQueue2.Size() << std::endl;
	while (!myQueue2.IsEmpty())
	{
		std::cout << myQueue2.Front() << "    ";
		myQueue2.Pop();
	}
	std::cout << std::endl;
	return 0;
}
