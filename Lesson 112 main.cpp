#include <iostream>
#include "Lesson_112_Number.h"

bool operator>(const Number& num1, const Number& num2) { return num1.GetValue() > num2.GetValue(); }
bool operator<(const Number& num1, const Number& num2) { return num1.GetValue() < num2.GetValue(); }
bool operator>=(const Number& num1, const Number& num2) { return num1.GetValue() >= num2.GetValue(); }
bool operator<=(const Number& num1, const Number& num2) { return num1.GetValue() <= num2.GetValue(); }
bool operator==(const Number& num1, const Number& num2) { return num1.GetValue() == num2.GetValue(); }
bool operator!=(const Number& num1, const Number& num2) { return num1.GetValue() != num2.GetValue(); }

bool operator&&(const Number& num1, const Number& num2) { return num1.GetValue() != 0 && num2.GetValue() != 0; }
bool operator||(const Number& num1, const Number& num2) { return num1.GetValue() != 0 || num2.GetValue() != 0; }
bool operator!(const Number& num1) { return num1.GetValue() == 0; }

/// Reload logical operators:
/// Comparison operators: >, <, >=, <=, ==, !=
/// Logical operators: &&, ||, !

int main()
{
    Number num1(10), num2(0), num3(5);

    ///comparison operator
    std::cout << "num1 > num3: " << (num1 > num3) << std::endl;  // 1 (true)
    std::cout << "num1 < num3: " << (num1 < num3) << std::endl;  // 0 (false)
    std::cout << "num1 >= num3: " << (num1 >= num3) << std::endl; // 1 (true)
    std::cout << "num1 <= num3: " << (num1 <= num3) << std::endl; // 0 (false)
    std::cout << "num1 == num3: " << (num1 == num3) << std::endl; // 0 (false)
    std::cout << "num1 != num3: " << (num1 != num3) << std::endl; // 1 (true)

    ///logical operators
    std::cout << "\nLogical operators:" << std::endl;
    std::cout << "num1 && num2: " << (num1 && num2) << std::endl; // 0 (false)
    std::cout << "num1 || num2: " << (num1 || num2) << std::endl; // 1 (true)
    std::cout << "!num2: " << !num2 << std::endl; // 1 (true)
    std::cout << "!num3: " << !num3 << std::endl; // 0 (false)

    return 0;
}