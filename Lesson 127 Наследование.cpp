#include <iostream>
/*
	1. Вспоминаем инкапсуляцию
	Инкапсуляция – это концепция ООП, позволяющая объединять данные и методы
	их обработки в одну единую сущность, которая называется классом или 
	структурой, и защищать их с помощью модификаторов доступа private и protected.
*/

//class User
//{
//private:
//	int age;
//public:
//	void SetAge(int age)
//	{
//		if (age > 0)
//			this->age;
//	}
//};

/*
	2. Что такое наследование
	3. Определение наследования
	Наследование – это концепция ООП, которая позволяет создавать новые классы 
	на основе уже существующих.
*/

/*
	4. Реализация наследования
	Синтаксис наследования:
	class Имя_Дочернего_Класса : Модификатор_Наследования Имя_Родительского_Класса
	{
		Реализация Класса
	};

	Классовые зависимости:
	Дочерний -> Родительский
	Производный -> Базовый
*/

//struct Point{};
//
//class Person{};
//
//class Vehicle
//{
//private:
//	Point position;
//	double height;
//	double length;
//	double width;
//protected:
//	double weight;
//public:
//	void Move(Point direction);
//	void Rotate(Point direction);
//	void Scale(float factor);
//};
//
//class Car : public Vehicle
//{
//private:
//	int doors;
//	int tankCapacity;
//	char model[30];
//	char mark[30];
//	bool isStarted;
//public:
//	void FillUp(int points)
//	{
//		weight += points;
//	}
//	void Start();
//};
//
//class Plane : public Vehicle
//{
//private:
//	int sets;
//	Point route[2];
//public:
//	void AuthorizePeople(const Person* peopleList);
//	void Fly();
//	void CallDispatcher(Person dispatcher);
//};

/*
	5. Модификатор доступа protected (защищенный)

	private: только этот класс
	protected: этот и его дочерние классы
	public: все
*/

//class A
//{
//private:
//	int value1;
//	void Method1();
//public:
//	int value2;
//	void Method2()
//	{
//		value1 = 10;
//		Method1();
//	}
//};

/*
	6. Наследование и конструкторы
	- Для дочернего классов конструктор по умолчанию не создаётся. Он наследует конструктор по умолчанию родительского класса.
	- При создании объекта дочернего класса всегда первоначально вызывается конструктор родительского класса.
	- При отсутствии конструктора копии дочернего класса автоматически вызывается конструктор копии родительского класса.
	- Если в дочернем классе реализован конструктор копии, то родительский конструктор по умолчанию не будет вызываться, 
	  тогда возникает необходимость создания конструктора по умолчанию дочерним классом.
*/

#include "Lesson 127 Array.h"
#include "Lesson 127 MathArray.h"

class A
{
public:
	A() { std::cout << "A::A()\n"; }
	A(int a) { std::cout << "A::A(int a)\n"; }
	A(int a, int b) { std::cout << "A::A(int a, int b)\n"; }
	A(const A& oth) { std::cout << "A::A(const A& oth)\n"; }
	A(A&& oth) noexcept {std::cout << "A::A(A&& oth)\n";}
};

class B :public A
{
public:
	B():A() { std::cout << "B::B()\n"; }
	B(int a):A(a){ std::cout << "B::B(int a)\n"; }
	B(int a, int b):A(a,b) { std::cout << "B::B(int a, int b)\n"; }
	B(const B& oth):A(oth) { std::cout << "B::B(const B& oth)\n"; }
	B(B&& oth) noexcept :A(std::move(oth)) { std::cout << "B::B(A&& oth)\n"; }

};

class C:public B {};

/*
	7. Наследование и деструктор
*/

int main()
{
	// 4. Реализация наследования
	/*Car car;
	Plane plane;
	//car.Move();
	//plane.Move();
	*/

	// 5. Модификатор доступа protected
	/*A object;
	object.value2 = 10;
	//object.value1; // невозможно
	//object.Method1; // невозможно
	*/

	// 6. Наследование и конструкторы
	/*Array myArray(5);
	for (size_t i = 0; i < myArray.Size(); i++)
		std::cout << myArray[i]<<" ";*/
		
	/*MathArray myArray(10);
	for (size_t i = 0; i < myArray.Size(); i++)
	{
		myArray[i] = i + 1;
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;

	int sum = myArray.Sum();
	std::cout <<"sum = "<< sum << std::endl;

	MathArray myArray2(myArray);
	for (size_t i = 0; i < myArray2.Size(); i++)
	{
		//myArray[i] = i + 1;
		std::cout << myArray2[i] << " ";
	}
	std::cout << std::endl;*/

	/*A object1;
	A object2(1);
	A object3(1, 2);
	B object(5,10);*/

	/*B object;
	B copyObject(std::move(object));*/

	// 7. Наследование и деструктор


	return 0;
}