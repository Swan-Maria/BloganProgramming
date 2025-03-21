#include <iostream>
using namespace std;
//void Show(double height, double width, double length, int people, int windows, int doors)
//{
//
//}
//
//bool Compare(double height1, double width1, double length1, int people1, int windows1, int doors1,
//	double height2, double width2, double length2, int people2, int windows2, int doors2)
//{
//
//}

/*
Syntax description stucture
struct Structure_Name
{
	Data#1;
	Data#2;
	Data#3;
	.......
}
*/

//struct Point
//{
//	int x;
//	int y;
//};

//struct MyStruct
//{
//	char a;
//	int b;
//	double c;
//};

//struct Student
//{
//	char name[30]="NoName";
//	int age=0;
//};

//struct DynamicArray
//{
//	int* arr = nullptr;
//	int size = 0;
//};

/// Structure
/// Struction description
struct Point
{
	int x;
	int y;
};
//
//struct Triangle
//{
//	Point a;
//	Point b;
//	Point c;
//};
//
//struct Piramide
//{
//	Triangle mainSide;
//	double height;
//};
//
//void Show(const Piramide& piramide);
//void Set(Piramide& piramide); 
//
//void Show(const Piramide piramide[], int size);
//void Set(Piramide piramide[], int size);

//void Func()
//{
//	struct Point
//	{
//		int x;
//		int y;
//	};
//
//	Point a;
//
//	Point arr[3];
//}
//
//struct
//{
//	int x;
//	int y;
//} point1;
//
//struct Triangle
//{
//	struct
//	{
//		int x;
//		int y;
//	};
//};

int main()
{
	/// A structure is a user - defined data type that combines other data types.
	//cout << sizeof(Point);
	///Syntax to create stucture-variable:
	///Type_of_Structure Variable_Name;

	//Point a = { 10,20 };
	//Point b = { 5, 25 };

	///Variant of initialization:
	/*MyStruct variable{}; ///a='\0', b=0, c=0.0
	MyStruct variable = {}; ///a='\0', b=0, c=0.0

	MyStruct variable{ 'G',10,38.4 }; ///a='G', b=10, c=38.4
	MyStruct variable = { 'G',10,38.4 }; ///a='G', b=10, c=38.4*/

	///Syntax for accessing a structure field:
	///Variable_Name.Field_Name

	/*MyStruct variable{ 'G',10,38.4 };

	variable.a = 'G';
	variable.b = 10;
	variable.c = 38.4;

	cout << "Enter a: ";
	cin >> variable.a;

	cout << "variable.a = " << variable.a << endl;
	cout << "variable.b = " << variable.b << endl;
	cout << "variable.c = " << variable.c << endl;*/

	/*Student student;

	Student maria{ "Maria", 17 };
	cout << maria.name << endl;

	Student copyMaria;

	copyMaria.age = maria.age;

	int i;
	for (i = 0; i < maria.name[i] != '\0'; i++)
		copyMaria.name[i] = maria.name[i];
	copyMaria.name[i] = '\0';

	Student copyMaria(maria);
	Student copyMaria{ maria };
	Student copyMaria={maria};
	Student copyMaria=Student{ maria };

	Student copyMaria2;

	//code

	copyMaria2 = maria;
	copyMaria2 = { maria };
	copyMaria2 = Student {maria};*/

	/*DynamicArray array1;

	array1.size = 5;
	array1.arr = new int[array1.size];

	for (int i = 0; i < array1.size; i++)
	{
		array1.arr[i] = i + 1; 
		cout << array1.arr[i] << " ";
	}

	DynamicArray array2;

	array2.size = array1.size;

	if (array1.arr != nullptr)
	{
		array1.arr = new int[array2.size];
		for (int i = 0; i < array2.size; i++)
			array2.arr[i] = array1.arr[i];
	}
	else
		array2.arr = nullptr;

	delete[] array1.arr;
	delete[] array2.arr;*/

	/*Point point1{ 10,20 };

	Point* ptr = &point1;
	Point& ref = point1;
	cout << sizeof(point1) << endl;
	cout << sizeof(ptr) << endl;

	point1.x = 100;
	point1.y = 200;
	cout << "x = " << point1.x << endl;
	cout << "y = " << point1.y << endl;

	(*ptr).x = 50;
	(*ptr).y = 30;
	cout << "x = " << (*ptr).x << endl;
	cout << "y = " << (*ptr).y << endl;

	ptr->x=100;
	ptr->y = 200;
	cout << "x = " << ptr->x << endl;
	cout << "y = " << ptr->y << endl;

	ref.x = 1000;
	ref.y = 2000;
	cout << "x = " << ref.x << endl;
	cout << "y = " << ref.y << endl;*/

	/*const Point point1;
	const Point* ptr = &point1;
	const Point& ref = point1;*/

	/*const int SIZE=3;

	Point arr[SIZE] =
	{
		Point{10,20},
		Point{30,40},
		Point{50,60}
	};

	for (int i = 0; i < SIZE; i++)
		cout << "Struct #" << i + 1 << ": [" << arr[i].x << "," << arr[i].y << "]\n";

	Point* pointers[SIZE] =
	{
		&arr[0],
		&arr[0],
		&arr[0]

	};

	for (int i = 0; i < SIZE; i++)
		cout << "Struct #" << i + 1 << ": [" << pointers[i]->x << "," << pointers[i]->y << "]\n";*/

	/*//Point point1;
	//Point* point1 = new Point{ 10,20 };
	Point* point1=new Point{};
	point1->x = 10;
	point1->y = 20;
	delete point1;*/

	/*cout << "sizeof (Triangle) = " << sizeof(Triangle) << endl;
	Triangle myTriangle =
	{
		Point{10,20},
		Point{1,40},
		Point{6,50}
	};

	Piramide piramide;
	piramide.mainSide.a.x = 10;*/

	/*point1.x = 10;
	Triangle a;
	a.x = 10;*/

	/*Piramide piramide{};
	Show(piramide);*/

	/// Structure variable
	/// Structure object
	/// Structure instance
	Point point1;

	return 0;
}

//void Show(const Piramide& piramide)
//{
//	cout << "Height = " << piramide.height << endl;
//
//	cout << "Main Side A: [" << piramide.mainSide.a.x << ", " << piramide.mainSide.a.y << "]" << endl;
//	cout << "Main Side B: [" << piramide.mainSide.b.x << ", " << piramide.mainSide.b.y << "]" << endl;
//	cout << "Main Side C: [" << piramide.mainSide.c.x << ", " << piramide.mainSide.c.y << "]" << endl;
//}
