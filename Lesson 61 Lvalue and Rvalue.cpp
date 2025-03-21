#include <iostream>
//#include <stdio.h>

//int Function()
//{
//	int a = 10;
//	return a;
//}

int main() {

	/// r-value + r-value
	/// l-value -> r-value
	/// r-value -> l-value
	
	/*int var = 10;
	int* bad_addr = &(var + 1);
	int* addr = &var;
	&var = 10;*/

	/*int arr[] = { 1,2 };
	int* p = &arr[0];
	*(p + 1) = 10;
	p[1] = 10;*/

	/// * (dereferencing) takes an r-value and returns a 1-value

	/*int a = 1;
	int b = 2;
	int c = a + b;*/

	/*int arr[3];
	int arr2[4]
	arr=arr2;*/

	/*const int a = 2;
	///changing l-value
	///unchanging l-value
	a = 2;*/

	/// l-value (left value) - is an object that occupies a specific location in memory 
	///                        that can be identified (for example, be an address).
	/// r-value (right value) - is an expreddion that not an object that can identify

	/*int variable = 10;
	variable = variable + 5;
	Function();*/
}