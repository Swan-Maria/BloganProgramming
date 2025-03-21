#include <iostream>
#include "Lesson_99_Color.h"

Color::Color(byte red, byte green, byte blue)
	: red(red), green(green), blue(blue)
{
	std::cout << "Color Constructor\n";
}

Color::~Color()
{
	std::cout << "Color Destructor\n";
}

void Color::ShowRGB() const
{
	std::cout << "[R = " << static_cast<int> (red);
	std::cout << " G = " << static_cast<int> (green);
	std::cout << " B = " << static_cast<int> (blue) << "]";
}
