#include <iostream>
#include <cstdlib>
#include "Lesson_99_Color.h"
#include "Lesson_99_DynamicIntArray.h"

void Show(const Color& color);
void Show(DynamicIntArray& dynamicArray);
void Initialize(DynamicIntArray& dynamicArray);
DynamicIntArray CreateArray(size_t size);
DynamicIntArray CreateArray(size_t size, int value);

int main()
{
	//std::srand(static_cast<unsigned>(std::time(nullptr)));
	//
	//Color black;
	//Color white{ 255, 255, 255 };

	//Show(black);
	//Show(white);

	DynamicIntArray dynamicArray{ 3 };

	Show(dynamicArray);
	//Initialize(dynamicArray);
	//Show(dynamicArray);

	//DynamicIntArray myArray(dynamicArray);
	//DynamicIntArray myArray{ dynamicArray };
	//DynamicIntArray myArray = dynamicArray;
	
	DynamicIntArray myArray{ CreateArray(6, 10)};

	Show(myArray);


	return 0;
}

void Show(const Color& color)
{
	std::cout << "Color RGB:";
	color.ShowRGB();
	std::cout << std::endl;
}
void Show(DynamicIntArray& dynamicArray)
{
	for (size_t i = 0; i < dynamicArray.GetSize(); i++)
		std::cout << dynamicArray.GetElement(i) << " ";
		std::cout << std::endl;
}
void Initialize(DynamicIntArray& dynamicArray)
{
	for (size_t i = 0; i < dynamicArray.GetSize(); i++)
		dynamicArray.SetElement(i, std::rand() % 100);
}

DynamicIntArray CreateArray(size_t size)
{
	DynamicIntArray dynamicArray{ size };
	return dynamicArray;
}

DynamicIntArray CreateArray(size_t size, int value)
{
	DynamicIntArray dynamicArray{ size };
	for (size_t i = 0; i < size; i++)
		dynamicArray.SetElement(i, value);
	return dynamicArray;
}
