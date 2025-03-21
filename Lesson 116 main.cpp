#include <iostream>
#include "Lesson_116_Cartesian.h"
#include "Lesson_116_Polar.h"

int main()
{
    Cartesian pointA{ 2, 3 };
    Polar pointB{ 10, 250 };

    std::cout << "A: [X = " << pointA.X() << ", Y = " << pointA.Y() << "]\n";
    std::cout << "B: [Radius = " << pointB.Radius() << ", Angle = " << pointB.Angle() << "]\n\n";

    std::cout << "After A = B:\n";
    pointA = pointB; 
    std::cout << "A: [X = " << pointA.X() << ", Y = " << pointA.Y() << "]\n";

    std::cout << "After B = A:\n";
    pointB = pointA;
    std::cout << "B: [Radius = " << pointB.Radius() << ", Angle = " << pointB.Angle() << "]\n\n";

    return 0;
}

/*
Type operator replacement syntax:
operator Type() const
{
code
}
*/