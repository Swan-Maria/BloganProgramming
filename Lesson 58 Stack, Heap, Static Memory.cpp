#include <iostream>

int global1;
int* global2;
const int global3 = 5;
int global4[3];


int Function2() {
	int a=4;
	return a;
}

int Function1(int a, int b) {
	int c=1;
	char arr[3] = "Hi";
	char* p=arr;
	return c;
}

void Heap() {
	/* code */
	/* code */
	/* code */
	/* code */
	// create variable in heap
	/* code */
	/* code */
	/* code */
	/* code */
	/* code */
	/* code */
	/* code */
	/* code */
	/* code */
	/* code */
	// delete variable in heap
	/* code */
	/* code */
	/* code */
	/* code */
}
int main() {

	int variable = 10;
	int arr[3] = { 1, 2, 3 };

	if (true) {
		int b = 1;
	}

	Function1(arr[0], variable);

	variable = Function2();

	// 1. Stack
	// 2. Static memory
	// 3. Dynamic memory / Heap

}