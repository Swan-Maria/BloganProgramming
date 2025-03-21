#include <cmath>
#include "Lesson_116_Cartesian.h"
#include "Lesson_116_Polar.h"

Cartesian::operator Polar() const
{
    static const double PI = 3.14159;
    return Cartesian(std::sqrt(x * x + y * y), std::atan2(y, x) * 180.0 / PI);
}