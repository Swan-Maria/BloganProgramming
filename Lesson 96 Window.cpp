#include <iostream>
#include "Lesson_96_Window.h"

//Window::Window(int originX, int originY, int originHeight, int originWidth, 
//	int originMaxHeight, int originMaxWidth)
//	:x(0),y(0),height(5),width(5), maxHeight(originMaxHeight), maxWidth(originMaxWidth)
//{
//	SetX(originX);
//	SetY(originY);
//	SetHeight(originHeight);
//	SetWidth(originWidth);
//
//}

Window::Window(int originX, int originY, int originHeight, int originWidth)
	:x(0), y(0), height(5), width(5)
{
	SetX(originX);
	SetY(originY);
	SetHeight(originHeight);
	SetWidth(originWidth);

}

//Window::Window(int originX, int originY)
//	:Window(originX, originY, 50, 50)
//{ }

//Window::Window(int originX, int originY)
//{
//	SetX(originX);
//	SetY(originY);
//	height = 10;
//	width = 10;
//}

void Window::SetX(int newX)
{
	if (newX > 0 && newX<maxHeight)
		x = newX;
}

void Window::SetY(int newY )
{
	if (newY > 0 && newY < maxWidth)
		x = newY;
}

void Window::SetHeight(int newHeight)
{
	if (newHeight > 0 && newHeight < maxHeight)
		height = newHeight;
}

void Window::SetWidth(int newWidth)
{
	if (newWidth > 0 && newWidth < maxWidth)
		width = newWidth;
}

void Window::Show() const
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t i = 0; i < width; i++)
		{
			std::cout << "#";
		}
		std::cout << std::endl;
	}
}
