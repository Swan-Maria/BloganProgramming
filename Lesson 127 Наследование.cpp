#include <iostream>
/*
	1. ���������� ������������
	������������ � ��� ��������� ���, ����������� ���������� ������ � ������
	�� ��������� � ���� ������ ��������, ������� ���������� ������� ��� 
	����������, � �������� �� � ������� ������������� ������� private � protected.
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
	2. ��� ����� ������������
	3. ����������� ������������
	������������ � ��� ��������� ���, ������� ��������� ��������� ����� ������ 
	�� ������ ��� ������������.
*/

/*
	4. ���������� ������������
	��������� ������������:
	class ���_���������_������ : �����������_������������ ���_�������������_������
	{
		���������� ������
	};

	��������� �����������:
	�������� -> ������������
	����������� -> �������
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
	5. ����������� ������� protected (����������)

	private: ������ ���� �����
	protected: ���� � ��� �������� ������
	public: ���
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
	6. ������������ � ������������
	- ��� ��������� ������� ����������� �� ��������� �� ��������. �� ��������� ����������� �� ��������� ������������� ������.
	- ��� �������� ������� ��������� ������ ������ ������������� ���������� ����������� ������������� ������.
	- ��� ���������� ������������ ����� ��������� ������ ������������� ���������� ����������� ����� ������������� ������.
	- ���� � �������� ������ ���������� ����������� �����, �� ������������ ����������� �� ��������� �� ����� ����������, 
	  ����� ��������� ������������� �������� ������������ �� ��������� �������� �������.
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
	7. ������������ � ����������
	� ������������ �������� ������� ������ ���� �������� ����������� ������������ �������.
	����������� ���������� � �������� ������� �� ��������� � �������������. 
*/

/*
	8. ������������ � ���������
	��������������� ��������� ������������ ������� ����������� ���������.
	���� � �������� ������, ���� �����-�� ������� ������� ������� �� ������������� ������, 
	�� ������������� ���������� ����������� � ������������ �������, � ����� � �������� (���� ��� �� ��������� =). 
	���� � �������� ������ ����� ���������� ����������� �������� ������������, �� ��� ������� ��������.
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
	9. ������������ � ����������� ������
	����������� ������ ������������ ������� ����������� ���������.
	����������� ���� � ������ ������������ �������, ����������� ������������� ������� private,
	�� �������� �������� �������. ��� �������� ����� ��� �� ��� ������� ���� � ������ ��� ������������.
*/

//class A
//{
//private:
//	int value;
//	static int staticValue;
//public:
//	void Method() { std::cout << "Method\n"; }
//	static void StaticMethod() { std::cout << "StaticMethod\n"; }
//};
//
//int A::staticValue = 10;
//
//class B : public A
//{
//public:
//
//
//};

/*
	10. ������������ � �������
	���� ���������� ������������� �� ������� ������, 
	�� ������ ������� ����������� ���������� ����� �� ������� ������!
*/


/*
	11. ������������ ������������
	����������� | A -> private member | A -> protected member | A -> public member
	private A   | private member      | private member        | private member
	protected A | private member	  | protected member      | protected member
	public A    | private member	  | protected member      | public member
*/

/*class A
{
public:
	void MethodA() {}
};

class B : private A
{
public:
	void MethodB()
	{
		MethodA();
	}
};

class C : protected B
{
public:
	void MethodC()
	{
		//MethodA();//error
	}
};*/

/*
	12. ������� �������� �� �������
	� �++ ����� ���������� � ������� ���������� ������ ��� �������:
	1. ����������� ������� �� ���������: � ��������� ��� public, � ������ ��� private.
	2. ����������� ������������ �� ���������: � ��������� ��� public, � ������ ��� private.

*/

/*class MyClass
{
//private:
	void Member();
};

struct MyStruct
{
//public:
	void Member();
};*/

/*
	13.	���������� �������������� ������������	
	����� ����� ������������� �� ���������� �������, ������ ������� ������� � ������������� �� ���������.
	����� �������� ������������� �������������� ������������.
	��������� �������������� ������������ �������� ��� ���������� "����������" ������������:
	��������, ����� ��� ������ ����������� �� ������������� ������, ����� ����������,
	��� � ����� �������� ������, ������� ����������� �� ���� ����, ����� ��������� �������� �� �� ������������� ������.
*/

/*
	14. ����������� ������������
	����������� virtual ������ �������� �������������� ������������ ������������ �������, ��� ��� � ��� 
	����������� ��� ������ ��������� ������ ��� �� ����� ����������� ��������� �������� "����������������" ������.
	����� ������� �����������, ������� ����������� ����������, � ����� �������� ������ ���������� ������ ���� ���. 
*/

class Person
{
private:
	const char* name;
	int age;
public:
	Person(const char* name, int age)
		:name(name), age(age)
	{
	}
	const char* GetName() const { return name; }
};

class Student: virtual public Person
{
private:
	int course;
	double scholarship;
	int subjects;
public:
	Student(const char* name, int age, int course, double scholarship, int subjects)
		: Person(name, age)
		, course(course), scholarship(scholarship), subjects(subjects)
	{	}
	int GetCourse() const{ return course; }
	/*void SayName(const char* name)
	{
		std::cout << "I'm a student. My name is " << name << std::endl;
	}
	~Student()
	{
		std::cout << "Student::~Student()\n";
	}*/
};

class Suit{};

class Waiter : virtual public Person
{
private:
	Suit suit;
	double salary;
	const char* company;
public:
	Waiter(const char* name, int age, double salary, const char* company)
		: Person(name, age)
		,salary(salary), company(company)
	{}
	double Salary() const { return salary; }
	/*void SayName(const char* name)
	{
		std::cout << "I'm a waiter. My name is " << name << std::endl;
	}
	~Waiter()
	{
		std::cout << "Waiter::~Waiter()\n";
	}*/

};

class StudentWaiter :public Student, public Waiter
{
private:
	int daysToDeath;
public:
	StudentWaiter(
		const char* name, int age,
		int daysToDeath, 
		int course, double scholarship, int subjects,
		double salary, const char* company)
		: Student("Student Demian", age, course, scholarship, subjects)
		, Waiter("Waiter Demien", age, salary, company)
		,  Person(name, age)
		, daysToDeath(daysToDeath)
	{ }

	void Pray(const char* pray)
	{
		std::cout << pray << std::endl;
	}
};


int main()
{
	// 4. ���������� ������������
	/*Car car;
	Plane plane;
	//car.Move();
	//plane.Move();
	*/

	// 5. ����������� ������� protected
	/*A object;
	object.value2 = 10;
	//object.value1; // ����������
	//object.Method1; // ����������
	*/

	// 6. ������������ � ������������
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

	// 7. ������������ � ����������
	/*{MathArray myArray(10);}
	{C object;}*/

	// 8. ������������ � ���������
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

	// 9. ������������ � ����������� ������
	/*B object;
	object.StaticMethod();
	B::StaticMethod();*/

	// 10. ������������ � �������
	/*Array<double> arr1(10);
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
	}*/

	// 11. ������������ ������������
	/*B objectB;
	//objectB.MethodA();//error
	
	A objectA;
	objectA.MethodA();*/
	
	// 12. ������� �������� �� �������
	/*MyClass	object1;
	object1.Member();

	MyStruct object2;
	object2.Member();*/

	// 13. ���������� �������������� ������������
	/*{
		StudentWaiter man(23, 4, 25.00, 15, 90.00, "MacDonald's");
		man.Pray("Please, help me!");
		std::cout << "Course = " << man.GetCourse() << std::endl;
		std::cout << "Salary = $" << man.Salary() << std::endl;
		man.Student::SayName("Demien");
		man.Waiter::SayName("Demien");
	}*/
	
	// 14. ����������� ������������
	
	StudentWaiter man("Demien", 24, 23, 4, 25.00, 15, 90.00, "MacDonald's");
	std::cout << man.GetName() << std::endl;
	
	return 0;
}