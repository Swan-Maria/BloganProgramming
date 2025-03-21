#include "Lesson_95_Rectangle.h"

void Rectangle::SetHeight(int newHeight)
{
	if (newHeight > 0)
		height = newHeight;
}

void Rectangle::SetWidth(int newWidth)
{
	if (newWidth > 0)
		height = newWidth;
}

int Rectangle::GetHeight() const
{
	return height;
}

int Rectangle::GetWidth() const
{
	return width;
}
