#include <iostream>

int main()
{
	using namespace std;
// LESSON 28. IF
	/*
	Syntax of the if operator:

	if (condition 1)
	{
		instructions ¹1
	}
	else if (condition 2)
	{
		instructions ¹2
	}
	.................................
	else if (condition n)
	{
		instructions ¹n
	}
	else
	{
		other instructions
	}
	*/

	/*cout << "Enter a number: ";
	int number;
	cin >> number;*/
	//cout << "Before if\n";

	/*if (number == 0)
		cout << "You entered ZERO!\n";*/

	/*if (number == 0) {
		cout << "You entered ZERO!\n";
	}*/

	/*if (number) {
		cout << "Yes\n";
	}
	
	if (!number) {
		cout << "No\n";
	}*/

	/*if (number >= 1 && number <= 10) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}*/

	/*if (number == 1)
		cout << "One.\n";
	else if (number == 2)
		cout << "Two.\n";
	else if (number == 3)
		cout << "Three.\n";
	else 
		cout << "Other.\n";*/
	
	//cout << "After if\n";
	
// LESSON 29. TERNARY OPERATOR
	/* Ternary operator syntax:
	
	Condition ? Action1 : Action2
	
	*/

	/*cout << "Enter two numbers: ";
	int number1, number2;
	cin >> number1 >> number2;

	(number1 > number2) ? cout << "Max = " << number1 << endl : cout << "Max = " << number2 << endl;

	cout << (number1 > number2 ? number1 : number2) << endl;

	int max = (number1 > number2 ? number1 : number2);
	cout << max << endl;

	if (number1 > number2)
		cout << "Max = " << number1 << endl;
	else
		cout << "Max = " << number2 << endl;*/

	// x > 0 && y > 0 -> 1
	// x < 0 && y > 0 -> 2
	// x < 0 && y < 0 -> 3
	// x > 0 && y < 0 -> 4
	// x == 0 && y == 0 -> between planes

	/*cout << "Enter x: ";
	int x;
	cin >> x;

	cout << "Enter y: ";
	int y;
	cin >> y;

	cout << ((x > 0 && y > 0) ? 
		"1" : (x < 0 && y > 0) ? 
			"2" : (x < 0 && y < 0) ? 
				"3" : (x > 0 && y < 0) ? 
					"4" : "Between") << endl;

	if (x > 0 && y > 0)
		cout << "1\n";
	else if (x < 0 && y > 0)
		cout << "2\n";
	else if (x < 0 && y < 0)
		cout << "3\n";
	else if (x > 0 && y < 0)
		cout << "4\n";
	else
		cout << "Between\n";*/

// LESSON 30. SWITCH
	/*
	Switch operator syntax:

	switch (name_value)
	{
		case Value #1:
			Instructions #1
			break;
		case Value #2:
			Instructions #2
			break;
		case Value #3:
			Instructions #3
			break;
		case Value #4:
			Instructions #4
			break;
		default:
			Instructions by default
			break;
	}

	*/

	/*int number = 3;

	switch (number)
	{
	case 1:
		cout << "It`s one!\n";
		cout << number << endl;
		break;
	case 2:
		cout << "It`s two!\n";
		cout << number*2 << endl;
		break;
	case 3:
		cout << "It`s three!\n";
		cout << number*3 << endl;
		break;
	default:
		cout << "It`s something different!\n";
		break;
	}

	if (number == 1) {
		cout << "It`s one!\n";
		cout << number << endl; 
	}
	else if (number==2) {
		cout << "It`s two!\n";
		cout << number * 2 << endl;
	}
	else if (number == 3) {
		cout << "It`s three!\n";
		cout << number * 3 << endl;
	}
	else
		cout << "It`s something different!\n";*/

// LESSON 31. THE CONCEPT OF THE CYCLE

// LESSON 32. WHILE()
	/*
	Syntax of the cycle while():

	while (condition 1)
	{
		instructions
	}
	*/
	
	/*int stars = 0;
	while (stars++ < 10)
		cout << '*';

	cout << endl;

	int number1 = 1;
	while (number1 <= 20)
		cout << number1++ << " ";
	
	cout << "\nEnter two bounds: ";
	int min, max;
	cin >> min >> max;
	
	int number2 = min;
	while (number2 <= max)
		cout << number2++ << " ";

	int sum = 0;
	int number3;
	cout << "Enter a number (or 0 to stop): ";
	cin >> number3;
	sum += number3;

	while (number3 != 0)
	{
		cout << "Enter a number (or 0 to stop): ";
		cin >> number3;
		sum += number3;
	}

	//do
	//{
	//	cout << "Enter a number (or 0 to stop): ";
	//	cin >> number3;
	//	sum += number3;
	//} while (number3 != 0);

	cout << "Sum = " << sum << endl;*/

// LESSON 33. DO WHILE()
	/*
	Syntax of the cycle do while():

	do
	{
		instructions
	}while (condition 1)
	*/
	
	/*int stars = 0;

	do
	{
		cout << '*';
		stars++;
	} while (stars < 5);*/

	/*int number;

	do
	{
		cout << "Enter a number (or negative to stop): ";
		cin >> number;

		if(number>=0)
			cout << "square = " << number * number << endl;
	} while (number >= 0);*/

	/*cout << "Enter a number (or negative to stop): ";
	cin >> number;

	while (number >= 0)
	{
		cout << "square = " << number * number << endl;

		cout << "Enter a number (or negative to stop): ";
		cin >> number;
	}*/
	
// LESSON 34. FOR()
	/*
	Syntax of the cycle for():

	for(initialization operator; condition; change operator)
	{
		instructions
	}
	*/
	
	/*int stars = 0;
	while (stars++ < 10)
		cout << '*';

	for (int stars = 0; stars < 10; stars++)
		cout << '*';*/
	
	/*int number = 1;
	while (number <= 10)
	{
		cout << number++ << " ";
		number++;
	}*/

	/*int number;
	for (number = 1; number <= 10; number++)
	{
		cout << number << " ";
	}*/

	/*for (int number = 1; number <= 10; number++)
	{
		cout << number << " ";
	}*/
	
	/*for (;;)
	{
		cout << "*";
	}*/

	/*while (true)
	{
		cout << "*";
	}*/
	
	/*for (char letter = 'a'; letter <= 'z'; letter++)
	{
		cout <<' ' << letter;
	}*/
	
	/*for (int number1 = 1, number2 = 20; number1 <= 10 && number2 <= 40; number1++, number2++)
	{
		cout << number1 << ' ' << number2 << endl;
	}*/

// LESSON 36. BREAK

	/*for(int i=0;i<5;i++)
	{
		cout << "Enter a day number: ";
		int day;
		cin >> day;
		switch (day)
		{
		case 1:
			cout << "It's Monday \n";
			break;
		case 2:
			cout << "It's Tuesday \n";
			break;
		case 3:
			cout << "It's Wednesday \n";
			break;
		case 4:
			cout << "It's Thursday \n";
			break;
		case 5:
			cout << "It's Friday \n";
			break;
		case 6:
			cout << "It's Saturday \n";
			break;
		case 7:
			cout << "It's Sunday \n";
			break;
		default:
			cout << "Incorrect number \n";
			break;
		}
	}*/

	/*int criticalNumber = 5;
	int min, max;
	cout << "Enter min and max: ";
	std::cin >> min >> max;
	
	for (int number = min; number <= max; number++)
	{
		if (number == criticalNumber)
		{
			cout << "Error! We found critical number.\n";
			break;
		}
		std::cout << number << " ";
	}
	std::cout << std::endl;*/

// LESSON 37. CONTINUE
	// while    -> condition
	// do while -> condition
	// for      -> increment block

	/*int sum=0;
	int number;
	do
	{
		cout << "Enter next positive number (or 0 to stop): ";
		cin >> number;
		if (number < 0)
		{
			cout << "You entered negative number.\n";
			continue;
		}
		sum += number;
	} while (number != 0);
	cout << "Sum = " << sum << endl;*/
	
	for(int i =0; i<10;i++)
	{
		//if (i % 2 != 0)
		//	continue;
		//cout << i << " ";
		if (i % 2 == 0)
			cout << i << " ";
	}

	/*int i = 0;
	while (i < 10)
	{
		if (i % 2 != 0)
			continue;
		cout << i << " ";
		i++;
	}*/
	return 0;
}
