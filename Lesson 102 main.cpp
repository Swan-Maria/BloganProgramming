#include <iostream>
#include "Lesson_102_Tank.h"

class A
{
public:
	static int a;
	static const int b=300; //class inizialization
	static double c; // not ==300.00 - error
	static int& ref;
	static int arr[];
	static const int array[3];
	static int* const p;
	static const int* const ptr;
	static const size_t SIZE = 30;
	char name[SIZE];

};

int globalVariable = 30;
int& A::ref = globalVariable;
int A::arr[3] = { 1,2,3 };
const int A::array[3] = { 1,2,3 };
int* const A::p = nullptr;
const int A::b;

int main()
{
	Tank* tank1 = new Tank();
	Tank* tank2 = new Tank();
	Tank * tank3= new Tank();
	/*tank1->tanks = 3;
	Tank::tanks = 5;*/
	/// Get tanks count
	std::cout << "Count of tanks = " << Tank::GetAliveTanks() << std::endl;
	//std::cout << tank1->GetTanks() << std::endl;
	delete tank1;
	tank1 = nullptr;
	///Get tanks count	
	std::cout << "Count of tanks = " << Tank::GetAliveTanks() << std::endl;
	//std::cout << tank3->GetTanks() << std::endl;
	delete tank3;
	tank3 = nullptr;
	/// Get tanks count
	std::cout << "Count of tanks = " << Tank::GetAliveTanks() << std::endl;
	//std::cout << tank2->GetTanks() << std::endl;
	delete tank2;
	tank2 = nullptr;
	/// Get tanks count
	std::cout << "Count of tanks = " << Tank::GetAliveTanks() << std::endl;

	return 0;
}
