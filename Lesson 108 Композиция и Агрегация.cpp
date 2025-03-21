/*В ООП существует три способа организации взаимодействия между классами. 

Наследование — это когда класс-наследник имеет все поля и методы родительского 
класса, и, как правило, добавляет какой-то новый функционал или/и поля. 
Наследование описывается словом «является». Легковой автомобиль является автомобилем. 
Вполне естественно, если он будет его наследником.

Ассоциация – это когда один класс включает в себя другой класс в качестве одного из полей.
Ассоциация описывается словом «имеет». Автомобиль имеет двигатель. 
Вполне естественно, что он не будет являться наследником двигателя.

Выделяют два частных случая ассоциации: композицию и агрегацию.
Агрегация и композиция - это название отношений между классами.

Композиция – это когда двигатель не существует отдельно от автомобиля. 
Он создается при создании автомобиля и полностью управляется автомобилем.
В типичном примере, экземпляр двигателя будет создаваться в конструкторе автомобиля.

Агрегация – это когда экземпляр двигателя создается где-то в другом месте кода, 
и передается в конструктор автомобиля в качестве параметра.

*/

#include <iostream>

// 1. Объекты клаcсов в классах

//class A
//{
//private: 
//	int a;
//	int b;
//public:
//	/*A() :a(0), b(0)
//	{
//		std::cout << "A::Constructor\n";
//	}*/
//
//	A(int a, int b) :a(a), b(b)
//	{
//		std::cout << "A::Constructor(int a, int b)\n";
//	}
//};
//
//class B
//{
//private:
//	char c;
//	char d;
//	A object;
//public:
//	B() : c('c'), d('d'), object(0,0)
//	{
//		std::cout << "B::Constructor\n";
//	}
//
//	B(int a, int b) : c('c'), d('d'), object(a, b)
//	{
//		std::cout << "B::Constructor(int a, int b)\n";
//	}
//
//	B(int a, int b, char c, char d) : c(c), d(d), object(a, b)
//	{
//		std::cout << "B::Constructor(int a, int b, char c, char d)\n";
//	}
//};

class A
{
private:
	int* ptr;
public:
	A(int value) :ptr(new int(value))
	{
		std::cout << "A::Constructor(int value)\n";
	}
	~A()
	{
		delete ptr;
		ptr = nullptr;
		std::cout << "A::Destructor\n";
	}
};

class B
{
private:
	A object;
	double* ptr;
public:
	B(int value) :object(value), ptr(new double(value/10.0))
	{
		std::cout << "B::Constructor(int value)\n";
	}

	~B()
	{
		delete ptr;
		ptr = nullptr;
		std::cout << "B::Destructor\n";
	}
};

// 2. Композиция (агрегирование по значению)

class Person{};
class Window{};
class Roof{};
class House
{
private:
	//размеры
	Window* windows;
	Person* people;
	Roof roof;
public:
	House(int windowCount, int peopleCount)
		:windows(new Window[windowCount]), people(new Person[peopleCount])
	{

	}
};

// 3. Агрегация (агрегирование по ссылке)

class Snake
{
public:
	Snake()
	{
		std::cout << "Snake::Constructor\n";
	}

	~Snake()
	{
		std::cout << "Snake::Destructor\n";
	}

	void Method(){}
};

class Field
{
private:
	const Snake& snake;
public:
	Field(const Snake& snake)
		:snake(snake)
	{
		std::cout << "Field::Constructor\n";
	}

	~Field()
	{
		std::cout << "Field::Destructor\n";
	}
};


//int main()
//{
//
//	// 1. Объекты классов в классах
//
//	/*B object1;
//	B object2{ 3,5};
//	B object3{ 3,5, '!', 'G' };*/
//
//	{B object{ 10 };}
//
//	// 2. Композиция
//
//	House house{ 12,3 };
//
//	// 3. Агрегация
//
//	{
//		Snake snake;
//
//		/*....код....*/
//
//		Field* field = new Field(snake);
//
//		/*....код....*/
//
//		delete field;
//
//		snake.Method();
//	}
//
//	return 0;
//}