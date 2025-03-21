#include <iostream>
#include "Lesson_111_Number.h"

int main()
{
    Number num1(1000), num2(22), num7(5000), num6(8);

    std::cout << "num1 = " << num1.GetValue() << std::endl;
    std::cout << "num2 = " << num2.GetValue() << std::endl;

    /// Unary operators
    std::cout << "\nUnary operator +:\n";
    Number num3 = +num1;
    std::cout << "num3 = " << num3.GetValue() << std::endl;

    std::cout << "\nUnary operator -:\n";
    Number num4 = -num1;
    std::cout << "num4 = " << num4.GetValue() << std::endl;

    std::cout << "\nPrefix increment:\n";
    ++num1;
    std::cout << "num1 after increment = " << num1.GetValue() << std::endl;

    std::cout << "\nPostfix increment:\n";
    num1++;
    std::cout << "num1 after postfix increment = " << num1.GetValue() << std::endl;

    std::cout << "\nPrefix decrement:\n";
    --num1;
    std::cout << "num1 after decrement = " << num1.GetValue() << std::endl;

    std::cout << "\nPostfix decrement:\n";
    num1--;
    std::cout << "num1 after postfix decrement = " << num1.GetValue() << std::endl;

    /// Appropriation
    std::cout << "\nБінарний оператор = (переміщення):\n";
    Number num5 = num1;
    num1 = num2;
    std::cout << "num1 = " << num1.GetValue() << std::endl;
    std::cout << "num5 = " << num5.GetValue() << std::endl;

    std::cout << "\nБінарний оператор = (integer value):\n";
    num7 = num6 = 5000;
    std::cout << "num7 = " << num7.GetValue() << std::endl;
    std::cout << "num6 = " << num6.GetValue() << std::endl;

    /// Binary operators
    std::cout << "\nThe binary operator +, -, *, /, %:\n";
    std::cout << "num1 = " << num1.GetValue() << std::endl;
    std::cout << "num2 = " << num2.GetValue() << std::endl;

    std::cout << "num1 + num2 = " << num1 + num2 << std::endl;
    std::cout << "num1 - num2 = " << num1 - num2 << std::endl;
    std::cout << "num1 * num2 = " << num1 * num2 << std::endl;
    std::cout << "num1 / num2 = " << num1 / num2 << std::endl;
    std::cout << "num1 % num2 = " << num1 % num2 << std::endl;

    return 0;
}