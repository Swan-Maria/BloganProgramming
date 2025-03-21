#include <cmath>
#include "Lesson_116_Cartesian.h"
#include "Lesson_116_Polar.h"

Polar::operator Cartesian() const
{
    static const double PI = 3.14159;
    return Cartesian(radius * std::cos(angle * PI / 180.0), radius * std::sin(angle * PI / 180.0));
}
