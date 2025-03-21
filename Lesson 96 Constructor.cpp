#include <iostream>
#include "Lesson_96_Window.h"

///Call the default constructor (on the STATIC MEMORY):
Window window5;
Window window6{};

///Call the constructor with parameters (on the STATIC MEMORY):
Window window11(1, 2, 3, 4);
Window window12{ 1,2,3,4 };

int main()
{
	///On the STECK
	Window arr[3];
	Window arr[3] =
	{
		Window(3,4),
		Window(),
		Window(1,2,50,60)
	};

	///Call the default constructor (on the STECK):
	Window window1; 
	Window window1{};

	///Call the constructor with parameters (on the STECK):
	Window window7(1,2,3,4);
	Window window8{1,2,3,4};

	///On the HEAP
	int size = 3;
	Window* arr=new Window[size]
	{
		Window(),
		Window(1,2),
		Window(1,5,6)
	};
	
	///Call the default constructor(on the HEAP):
	Window* window3 = new Window;
	Window* window4 = new Window();

	///Call the constructor with parameters (in the HEAP):
	Window* window9 = new Window(1, 2, 3, 4);
	Window* window10 = new Window{ 1,2,3,4 };

	//Window window( 20,30,5,6,1024, 1028);

	/*Window window1(2, 5, 10, 10);
	Window window2{4, 6, 50 };
	Window window3{500,600 };
	Window window4{700};
	Window window5;
	window1.Show();
	std::cout << std::endl;
	window2.Show();
	std::cout << std::endl;
	window3.Show(); 
	std::cout << std::endl;
	window4.Show();
	std::cout << std::endl;
	window5.Show();*/

	//window.SetX(3);
	//window.SetY(5);
	//window.SetHeight(10);
	//window.SetWidth(5);
	//window.Show();
	return 0;
}
