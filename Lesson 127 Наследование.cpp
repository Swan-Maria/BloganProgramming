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

#include "Lesson 127 Array_.h"
#include "Lesson 127 MathArray_.h"

/*class A
{
public:
	A() { std::cout << "A::A()\n"; }
	A(int a) { std::cout << "A::A(int a)\n"; }
	A(int a, int b) { std::cout << "A::A(int a, int b)\n"; }
	A(const A& oth) { std::cout << "A::A(const A& oth)\n"; }
	A(A&& oth) noexcept {std::cout << "A::A(A&& oth)\n";}
	~A() { std::cout << "A::~A()\n"; }
	void operator=(const A& oth) { std::cout << "A::operator=(const A& oth)\n"; }
	void operator=(A&& oth) { std::cout << "A::operator=(A&& oth)\n"; }
};

class B :public A
{
public:
	B():A() { std::cout << "B::B()\n"; }
	B(int a):A(a){ std::cout << "B::B(int a)\n"; }
	B(int a, int b):A(a,b) { std::cout << "B::B(int a, int b)\n"; }
	B(const B& oth):A(oth) { std::cout << "B::B(const B& oth)\n"; }
	B(B&& oth) noexcept :A(std::move(oth)) { std::cout << "B::B(A&& oth)\n"; }
	~B() { std::cout << "B::~B()\n"; }
	void operator=(const B& oth) { this->A::operator=(oth); std::cout << "B::operator=(const B& oth)\n"; }
	void operator=(B&& oth) { this->A::operator=(std::move(oth)); std::cout << "B::operator=(B&& oth)\n"; }
};

class C:public B 
{
public:
	~C() { std::cout << "C::~C()\n"; }

};*/

/*
	7. Наследование и деструктор
	В деструкторах дочерних классов нельзя явно вызывать деструкторы родительских классов.
	Деструкторы вызываются в обратном порядке по отношению к конструкторам. 
*/

/*
	8. Наследование и операторы
	Перезагруженный операторы родительских классов наследуются дочерними.
	Если в дочернем классе, есть какие-то объекты которые зависят от родительского класса, 
	то первоначально необходимо разобраться с родительским классом, а после с дочерним (речь шла об операторе =). 
	Если в дочернем классе будет реализован собственный оператор присваивания, то это вызовет рекурсию.
*/

/*class Number
{
private:
	int value1;
public:
	Number(int value) :value1(value) {}
	Number operator+(const Number& oth) const { return value1 + oth.value1; }
	bool operator==(const Number& oth) const { return value1 == oth.value1; }
	int GetValue()const { return value1; }
	Number& operator++() 
	{ 
		value1++; 
		return *this; 
	}
	Number operator++(int)
	{
		Number temp(*this);
		value1++; 
		return *this;
	}
};

class DoubleNumber: public Number
{
private:
	int value2;
public:
	DoubleNumber(int value1, int value2):Number(value1), value2(value2) {}
	DoubleNumber operator+(const DoubleNumber& oth) const
	{
		return DoubleNumber(GetValue() + oth.GetValue(), value2 + oth.value2);
	}
	bool operator==(const  DoubleNumber& oth) const
	{
		//return GetValue() == oth.GetValue() && value2 == oth.value2;
		return Number::operator==(oth) && value2 == oth.value2;
	}
	DoubleNumber& operator++()
	{
		Number::operator++();
		value2++;
		return *this;
	}
	DoubleNumber operator++(int)
	{
		DoubleNumber temp(GetValue(), value2);
		Number::operator++(0);
		value2++;
		return *this;
	}
};*/

/*
	9. Наследование и статические методы
	Статические методы родительских классов наследуются дочерними.
	Статические поля и методы родительских классов, объявленных модификатором доступа private,
	не доступны дочерним классам. Они работают точно так же как обычные поля и методы при наследовании.
*/

class A
{
private:
	int value;
	static int staticValue;
public:
	void Method() { std::cout << "Method\n"; }
	static void StaticMethod() { std::cout << "StaticMethod\n"; }
};

int A::staticValue = 10;

class B : public A
{
public:


};

/*
	10. Наследование и шаблоны
	Если необходимо наследоваться от шаблона класса, 
	то нельзя создать специфичный конкретный класс от шаблона класса!
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
	/*{MathArray myArray(10);}
	{C object;}*/

	// 8. Наследование и операторы
	/*MathArray myArray(5);
	for (size_t i = 0; i < myArray.Size(); i++)
	{
		myArray[i] = i + 1;
		std::cout << myArray[i] << " ";
	}
	std::cout<<std::endl;

	MathArray myArray2(myArray);
	for (size_t i = 0; i < myArray2.Size(); i++)
	{
		std::cout << myArray2[i] << " ";
	}
	std::cout << std::endl;

	MathArray myArray3(10);
	myArray3 = myArray2;
	for (size_t i = 0; i < myArray3.Size(); i++)
	{
		std::cout << myArray3[i] << " ";
	}
	std::cout << std::endl;*/

	/*B object1;
	B object2;
	object2 = std::move(object1);*/

	/*DoubleNumber a(4, 5);
	DoubleNumber b(10, 3);
	DoubleNumber result1(a + b);
	bool result2(a == b);
	std::cout << std::boolalpha << result2 << std::endl;*/

	/*DoubleNumber number(10, 20);
	number++;
	std::cout << std::endl;*/

	// 9. Наследование и статические методы
	/*B object;
	object.StaticMethod();
	B::StaticMethod();*/

	// 10. Наследование и шаблоны
	Array<double> arr1(10);
	for (size_t i = 0; i < arr1.Size(); i++)
	{
		arr1[i] = i / 123.0;
		std::cout << arr1[i] << " ";
	} 
	std::cout << std::endl;

	MathArray<double> arr2(10);
	MathArray<double> arr3(arr2);
	MathArray<double> arr4(3);
	arr4 = arr3;
	for (size_t i = 0; i < arr2.Size(); i++)
	{
		arr2[i] = i / 123.0;
		std::cout << arr2[i] << " ";
	}

	return 0;
}