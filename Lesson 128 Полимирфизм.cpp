#include <iostream>

/// [+] 1.  Вспоминаем инкапсуляцию
/// Инкапсуляция – это концепция ООП, позволяющая объединять данные и методы
/// их обработки в одну единую сущность, которая называется классом или
/// структурой, и защищать их с помощью модификаторов доступа private и protected.
/// [+] 2.  Вспоминаем наследование
/// Наследование – это концепция ООП, которая позволяет создавать новые классы 
/// на основе уже существующих.
/// Синтаксис наследования:
/// class Имя_Дочернего_Класса : Модификатор_Наследования Имя_Родительского_Класса
/// {
/// 	Реализация Класса
/// };
/// [+] 3.  Что такое полиморфизм?
/// С латыни переводиться как "разность форм", "много форм"
/// [+] 4.  Определение полиморфизма
/// Полиморфизм - это концепция ООП, которая позволяет получать 
/// различную реализацию кода с одинаковым интерфейсом
/// [+] 5.  Какие есть типы полиморфизма?
/// Полиморфизм делиться на три вида:
/// 1. Параметрический полыморфизм (шаблоны функций)
/// 2. Ad-hoc полиморфизм (перегрузка функций)
/// 3. Полиморфизм подтипов
/// [+] 6.  Что такое параметрический полиморфизм?
//template <typename T>
//void Show(const T arr[], size_t size);
/// [+] 7.  Что такое Ad-hoc полиморфизм?
//void Show(int number);
//void Show(const char* str);
/// [+] 8.  Что такое полиморфизм подтипов?
//struct Position {
//	int x;
//	int y;
//	Position(int x, int y)
//		:x(x), y(y)
//	{
//	}
//};
//
//class Unit
//{
//public:
//	Unit(const Position& position, int hp, const char* name)
//		:position(position), hp(hp > 0 ? hp : 100)
//	{
//		std::cout << "Unit::Unit()\n";
//		size_t size = strlen(name) + 1;
//		this->name = new char[size];
//		strcpy_s(this->name, size, name);
//	}
//
//	virtual ~Unit()
//	{
//		std::cout << "Unit::~Unit()\n";
//		delete[] name;
//		name = nullptr;
//	}
//
//	Position GetPosition() const { return position; }
//
//	int GetHP() const { return hp; }
//
//	virtual void SetPosition(const Position& newPosition) 
//	{
//		std::cout << "Unit::SetPosition()\n";
//		this->position = newPosition;
//	}
//
//	virtual  void Show()
//	{
//		std::cout << "Unit Info:\n";
//		std::cout << "Position: [" << position.x << ", " << position.y << "]\n";
//		std::cout << "HP: " << hp << "\n";
//	}
//private:
//	Position position;
//	int hp; //health points
//	char* name;
//};
//
//class Archer : public Unit
//{
//public:
//	Archer(const Position& position, int hp, const char* name, float bowDamage, int countArrows)
//		:Unit(position, hp, name)
//		, bowDamage(bowDamage > 0 ? bowDamage : 0)
//		, countArrows(countArrows > 0 ? countArrows : 0)
//	{
//		std::cout << "Archer::Archer()\n";
//	}
//
//	virtual ~Archer()
//	{
//		std::cout << "Archer::~Archer()\n";
//	}
//
//	virtual void SetPosition(const Position& newPosition) override
//	{
//		std::cout << "Unit::SetPosition()\n";
//	}
//
//	void Show()
//	{
//		Unit::Show();
//		std::cout << "Archer Info:\n";
//		std::cout << "Bow damage: " << bowDamage << "\n";
//		std::cout << "Arrows: " << countArrows << "\n";
//	}
//
//	float GetBowDamage() const { return bowDamage; }
//
//	int GetArrowsCount() const { return countArrows; }
//
//private:
//	float bowDamage;
//	int countArrows;
//};
//
//class Swordsman :public Unit
//{
//public:
//	Swordsman(const Position& position, int hp, const char* name, float bowDamage, int countArrows)
//		:Unit(position, hp, name)
//		, swordDamage(swordDamage > 0 ? swordDamage : 0)
//		, armorLevel(armorLevel > 0 ? armorLevel : 0)
//	{
//		std::cout << "Swordsman::Swordsman()\n";
//	}
//
//	virtual ~Swordsman()
//	{
//		std::cout << "Swordsman::~Swordsman()\n";
//	}
//
//	void Show()
//	{
//		Unit::Show();
//		std::cout << "Swordsman Info:\n";
//		std::cout << "Sword damage: " << swordDamage << "\n";
//		std::cout << "Armor level: " << armorLevel << "\n";
//	}
//
//	float GetSwordDamage() const { return swordDamage; }
//
//	int GetArmorLevel() const { return armorLevel; }
//
//private:
//	float swordDamage;
//	int armorLevel;
//};
//
//void ShowInfoOnUI(Unit& unit);
/// [+] 9.  Виртуальные методы (функции)
/// Виртуальный метод - это метод, который помечен ключевым словом virtual.
/// Виртуальные методы позволяют создавать иные реализации (переопреденлять) методы в дочерних классах.
//class A
//{
//public:
//	void UsualMethod() { std::cout << "A::UsualMethod\n"; }
//	void UsualMethodA() { std::cout << "A::UsualMethodA\n"; }
//	virtual void Method() { std::cout << "A::Method()\n"; }
//};
//
//class B : public A
//{
//public:
//	void UsualMethod() { std::cout << "B::UsualMethod\n"; }
//	void UsualMethodB() { std::cout << "B::UsualMethodB\n"; }
//	virtual void Method() { std::cout << "B::Method()\n"; }
//};
//
//class C : public B
//{
//public:
//	void UsualMethod() { std::cout << "C::UsualMethod\n"; }
//	void UsualMethodC() { std::cout << "C::UsualMethodC\n"; }
//	virtual void Method() { std::cout << "C::Method()\n"; }
//};
/// [+] 10. Полиморфизм и конструкторы
/// Конструкторы не могут быть виртуальными.
/// [+] 11. Полиморфизм и деструкторы
/// Деструкторы должны быть виртуальными, если у вас есть виртуальные методы в классе.
/// Если деструктор не виртуальный, то при удалении объекта через указатель на базовый класс,
/// вызовется деструктор базового класса, но не вызовется деструктор дочернего класса.
/// Если деструктор виртуальный, то при удалении объекта через указатель на базовый класс,
/// вызовется деструктор дочернего класса, а потом деструктор базового класса.
/// [+] 12. Ключевое слово override
/// override - ключевое слово, которое указывает на то, что метод является переопределенным.
/// [+] 13. Ключевое слово final
/// final - ключевое слово, которое указывает на то, что метод не может быть переопределен или класс не может быть унаследован.
//class Parent /*final*/
//{
//public:
//	virtual void Method() { std::cout << "Parent::Method()\n"; }
//};
//
//class Child : public Parent
//{
//public:
//	virtual void Method() final { std::cout << "Child::Method()\n"; }
//};
//
//class GrandChild : public Child
//{
//public:
//	virtual void Method() override { std::cout << "GrandChild::Method()\n"; }
//};
/// [+] 14. Что такое ранее (статическое) и позднее (динамическое) связывание?
/// Ранее (статическое) связывание - это связывание метода с объектом на этапе компиляции.
/// Позднее (динамическое) связывание - это связывание метода с объектом на этапе выполнения.
//int Sum(int a, int b) { return a + b; }
//int Diff(int a, int b) { return a - b; }
//int Mult(int a, int b) { return a * b; }
//int Div(int a, int b) { return a / b; }
//
//class A
//{
//public:
//	virtual void Method() { std::cout << "A::Method()\n"; }
//};
//
//class B : public A
//{
//public:
//	virtual void Method() override { std::cout << "B::Method()\n"; }
//};
/// [+] 15. Таблица виртуальных функций
/// Таблица виртуальных функций - это таблица, которая хранит адреса виртуальных функций.
/// Если класс содержит хотя бы один виртульный метод, то у него создается таблица виртуальных функций.
/// Компилятор добавляет указатель на таблицу виртуальных функций в начало объекта.
class A
{
public:
	virtual void F1() {}
	virtual void F2() {}
	virtual void F3() {}
	void F4() {}
};

class B : public A
{
public:
	virtual void F1() override{}
	virtual void F2() override{}
	virtual void F5() {}
	void F6() {}
};

int main()
{
	/// 6.  Что такое параметрический полиморфизм?
	//int arr1[] = { 1,2,3 };
	//double arr2[] = { 1.1,2.2,3.3 };
	//char arr3[] = { 'A', 'B','C' };
	//Show(arr1, 3);
	//Show(arr2, 3);
	//Show(arr2, 3);
	/// 7.  Что такое Ad-hoc полиморфизм?
	/*int number = 10;
	char str[] = "Hello World";
	std::cout.operator<<(number)<<std::endl;
	std::cout.operator<<(str) << std::endl;
	Show(number);
	Show(str);*/
	/// 8.  Что такое полиморфизм подтипов?
	//Unit unit(Position(20, 30), 100);
	//Archer archer(Position(25, 40), 80, 30, 20);
	//Swordsman swordsman(Position(25, 40), 200, 35, 4);
	//ShowInfoOnUI(unit);
	//ShowInfoOnUI(archer);
	//ShowInfoOnUI(swordsman);
	/// 9.  Виртуальные методы (функции)
	//A objectA;
	//B objectB;
	//C objectC;
	//A* ptrA = &objectA;
	//ptrA->UsualMethod();
	//ptrA->UsualMethodA();
	//ptrA->Method();
	//std::cout << "-------------------\n";
	//ptrA = &objectB;
	//ptrA->UsualMethod();
	//ptrA->UsualMethodA();
	//ptrA->Method();
	//std::cout << "-------------------\n";
	//ptrA = &objectC;
	//ptrA->UsualMethod();
	//ptrA->UsualMethodA();
	//ptrA->Method();
	//std::cout << "-------------------\n";
	//B* ptrB = &objectB;
	//ptrB->UsualMethodA();
	//ptrB->UsualMethodB();
	//std::cout << "-------------------\n";
	//ptrB = &objectC;
	//ptrB->UsualMethodA();
	//ptrB->UsualMethodB();
	//std::cout << "-------------------\n";
	//C* ptrC = &objectC;
	//ptrC->UsualMethodA();
	//ptrC->UsualMethodB();
	//ptrC->UsualMethodC();
	//std::cout << "-------------------\n";
	//objectB.Method();
	/// 11. Полиморфизм и деструкторы
	/*Unit* unit = new Archer(Position(1, 4), 100, "Archer", 23, 5);
	unit->SetPosition(Position(100, 100));
	delete unit;*/
	/// 14. Что такое ранее (статическое) и позднее (динамическое) связывание?
	//int (*operation)(int, int) = Sum;
	//int number1, number2;
	//std::cout << "Enter two numbers:\n";
	//std::cin >> number1 >> number2;
	//std::cout << "Enter operation: (+, -, *, /): \n";
	//char operationSymbol;
	//std::cin >> operationSymbol;
	//switch (operationSymbol)
	//{
	//case '+':
	//	operation = Sum;
	//	break;
	//case '-':
	//	operation = Diff;
	//	break;
	//case '*':
	//	operation = Mult;
	//	break;
	//case '/':
	//	operation = Div;
	//	break;
	//default:
	//	std::cout << "Invalid operation\n";
	//	return 1;
	//}
	//int result = operation(number1, number2);
	//std::cout << "Result: " << result << std::endl;
	//
	////Ранее (статическое) связывание
	//A objectA;
	//objectA.Method();
	//B objectB;
	//objectB.Method();
	////Позднее (динамическое) связывание
	//A* ptrA = &objectB;
	//ptrA->Method();	//
	/// 15. Таблица виртуальных функций
	std::cout << sizeof(A) << std::endl;
	std::cout << sizeof(B) << std::endl;
	A* ptr = new B;
	ptr->F2();
	ptr->F3();
	ptr = new A;
	ptr->F2();
	delete ptr;

	return 0;
}

//template<typename T>
//void Show(const T arr[], size_t size)
//{
//	for (size_t i = 0; i < size; i++)
//		std::cout << arr[i] << " ";
//	std::cout << std::endl;
//}

//void Show(int number)
//{
//	std::cout << number << std::endl;
//}
//
//void Show(const char* str)
//{
//	size_t size = std::strlen(str);
//	for (size_t i = 0; i < size; i++)
//		std::cout << str[i] << " ";
//	std::cout << std::endl;
//}

//void ShowInfoOnUI(Unit& unit)
//{
//	std::cout << "-------------------------------------\n";
//	unit.Show();
//	std::cout << "-------------------------------------\n";
//}
