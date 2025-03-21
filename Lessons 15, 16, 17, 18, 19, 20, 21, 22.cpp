#include <iostream>

int main() 
{
	using namespace std;
	// LESSON 15.LITERALS and LESSON 16. COMENTS
	/*
	short a = 10;
	int b = 10;
	long c = 11L;
	long long d = 10LL;

	unsigned short a2 = 10;
	unsigned int b2 = 10U;
	unsigned long c2 = 10UL;
	unsigned long long d2 = 10ULL;

	float a3 = 1.5F;
	double b3 = 1.5;
	long double c3 = 1.5L;

	char a4 = 'g';
	wchar_t b4 = L'g';
	char16_t c4 = u'g';
	char32_t d4 = U'g';

	bool a5 = false;

	cout << "Hello" << endl;
	*/

	//LESSONS 17. OPERATORS AND 18. ARITHMETIC OPERATORS
	// = + - * / %
	
	/*
	int a, b;
	cout << "Enter two numbers: ";
	cin >> a >> b;
	cout << "a = " << a << "b = " << b<<endl;
	cout << "+a = " << +a << "+b = " << +b << endl;
	cout << "-a = " << -a << "-b = " << -b << endl;
	cout << "a % b = "<< a%b << endl;
	*/

	/*
	cout << "Enter seconds: ";
	int userSeconds;
	cin >> userSeconds;

	const int SEC_IN_MIN = 60;

	//200 s = 3 m 20 s

	int seconds = userSeconds % SEC_IN_MIN;
	int minutes = userSeconds / SEC_IN_MIN;

	cout << "It`s " << minutes << " minutes and " << seconds << " seconds\n";
	*/

	// LESSON 19. OPERATOR PRIORITY
	/*
	() [] . ->
	! *(YH) -(YH) ~ ++ --
	% * /
	+ -
	<< >>
	< > <= >=
	!= ==
	&
	^
	|
	&&
	||
	?:
	= += -= *= /= %= &= |= ^= >>= <<=
	*/

	// LESSON 20. ASSOCIATION OF OPERATORS
	/*
	int number = 4 * 2 / 2;
	int a, b, c, d;
	a = b = c = d = 10;
	cout << (a = 3);
	*/
	// use () to increase the priority of operations

	//LESSON 21. COMBINED ARITHMETIC OPERATORS
	
	/*cout << "Enter a number: ";
	int number;
	cin >> number;
	cout << "Number = " << number << endl;
	number += 10;
	cout << "Number = " << number << endl;
	number -= 10;
	cout << "Number = " << number << endl;
	number *= 2;
	cout << "Number = " << number << endl;
	number /= 4;
	cout << "Number = " << number << endl;
	number %= 2;
	cout << "Number = " << number << endl;
	*/

	//LESSON 22. INCREMENT AND DECREMENT
	int a = 1; 
	int b = a++; // b=1 a=2
	int c= ++a; //c=3 a=3
	int d = a--; // d=3 a=2
	int e = --a; //e=1 a=1

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	return 0;
}