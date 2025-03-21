#include <iostream>
class ComplexNumber
{
public:
	ComplexNumber Add(const ComplexNumber& other) const { return *this; }
	ComplexNumber Substract(const ComplexNumber& other) const { return *this; }
	ComplexNumber Multiple(const ComplexNumber& other) const { return *this; }
};

class Container{};

class Number
{
private:
	int a;
public:
	Number (int value):a(value){}
	/// reloaded operator +
	Number operator+(const Number& other) const 
	{ 
		return Number{ this->a + other.a }; 
	}
	Number operator* (const Number& other) const
	{
		return Number{ this->a * other.a };
	}

	//friend Number operator+(const Number& number1, const Number& number2);
	int GetNumber () const { return a; }
};

//Number operator+(const Number& number1, const Number& number2) 
//{
//	return Number{ number1.GetNumber() + number2.GetNumber ()};
//}

int main()
{
	Number n1{ 3 }, n2{ 5 }, n3{ 5 };
	Number result = n1 + n2 * n3;
	Number result_ = n1.operator+(n2);

	/*Number n1{ 3 }, n2{ 5 };
	Number result = n1 + n2;*/

	//int a=-3;
	
	//int arr[3];
	//container.GetElementByIndex(3);
	//container[3];

	//double b = static_cast<double>(a);

	/*PolarCoordinate point 1;
	RectCoordinate point 2;
	point1.ConverteToPolar(point2);
	point2 = point1;*/

	/*MyClass obj;
	obj(3, 4);*/

	//for (size_t i=0, j=5; i<3; i++, j--){}

	/*int a = 3, b = 5;
	Container arr;
	arr += 3, 4, 5, 6;*/

	/// List of operators that CAN be reloaded:
	/// Reloading arithmetic operators +, -, *, /, %, =, ++, --
	/// Reload bitwise operators ^, &, |, ~, <<, >>
	/// Reload boolean operators <, >, <=, >=, ==, !=, !, &&, ||
	/// Reload the combined operators +=, -=, /=, %=, ^=, &=, |=, *=, <<=, >>=
	/// Reload the index operator []
	/// Reloading the typecast operator
	///	Restarting the function call operator ()
	/// Reload the operators associated with the address *, &, ->, ->*
	/// Reloading memory allocation / deletion operators new, new[], delete, delete[]
	/// Restart the comma operator

	/// List of statements that CANNOT be reloaded:
	/// . (access to class members)
	/// .* (access to fields by pointer)
	/// ? : (ternary operator)
	///	sizeof, typeid, XXX_cast
	///:: (scope access)

	/// List of operators that can be reloaded ONLY by class methods:
	/// =, ->, (), [], ->*, operator type, new, new[], delete, delete[]

	//ComplexNumber a, b;
	//// (a + b) * (a - b)
	//(a.Add(b)).Multiple(a.Substract(b));
	//ComplexNumber c = a.Add(b);
	//ComplexNumber d = a.Substract(b);
	//ComplexNumber result = c.Multiple(d);
	//ComplexNumber result = (a + b) * (a - b);



	return 0;
}
