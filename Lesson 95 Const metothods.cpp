#include <iostream>
#include "Lesson_95_Rectangle.h"

void Show(const Rectangle& rectangle);

int main()
{
	Rectangle one1;
	Rectangle& ref1 = one1;
	Rectangle* ptr1 = &one1;
	Rectangle arr1[3];

	const Rectangle one1;
	const Rectangle& ref1 = one1;
	const Rectangle* ptr1 = &one1;
	const Rectangle arr1[3];

	one1.GetHeight();
	one1.GetWidth();
	one1.SetHeight(3);
	one1.SetWidth(4);

	ref1.GetHeight();
	ref1.GetWidth();
	ref1.SetHeight(3);
	ref1.SetWidth(4);

	ptr1->GetHeight();
	ptr1->GetWidth();
	ptr1->SetHeight(3);
	ptr1->SetWidth(4);

	for (size_t i= 0; i < 3; i++)
	{
		arr1[i].GetHeight();
		arr1[i].GetWidth();
		arr1[i].SetHeight(3);
		arr1[i].SetWidth(4);
	}


	/*Rectangle one;
	one.SetHeight(20);
	one.SetWidth(30);
	Show(one);*/

	return 0;
}

void Show(const Rectangle& rectangle)
{
	std::cout << "Height = " << rectangle.GetHeight() << std::endl;
	std::cout << "Width = " << rectangle.GetWidth() << std::endl;
}
