#include <iostream>
#include "Lesson_113_Byte.h"

/// Functions for reloading bitwise operators
///bitwise operator AND
//Byte operator&(const Byte& lhs, const Byte& rhs)
//{
//    Byte result;
//    for (size_t i = 0; i < Byte::getSize(); ++i)
//    {
//        result.setBit(i, lhs.getBit(i) & rhs.getBit(i));
//    }
//    return result;
//}

///bitwise operator OR
//Byte operator|(const Byte& lhs, const Byte& rhs)
//{
//    Byte result;
//    for (size_t i = 0; i < Byte::getSize(); ++i)
//    {
//        result.setBit(i, lhs.getBit(i) | rhs.getBit(i));
//    }
//    return result;
//}

///bitwise operator XOR
//Byte operator^(const Byte& lhs, const Byte& rhs)
//{
//    Byte result;
//    for (size_t i = 0; i < Byte::getSize(); ++i)
//    {
//        result.setBit(i, lhs.getBit(i) ^ rhs.getBit(i));
//    }
//    return result;
//}

///bitwise operator NOT (unary)
//Byte operator~(const Byte& obj)
//{
//    Byte result;
//    for (size_t i = 0; i < Byte::getSize(); ++i)
//    {
//        result.setBit(i, ~obj.getBit(i) & 1); //інвертуємо кожен біт
//    }
//    return result;
//}

///left shift operator
//Byte operator<<(const Byte& obj, int offset)
//{
//    Byte result;
//    for (size_t i = 0; i < Byte::getSize() - offset; ++i)
//    {
//        result.setBit(i, obj.getBit(i + offset));
//    }
//    return result;
//}

/// right shift operator
//Byte operator>>(const Byte& obj, int offset)
//{
//    Byte result;
//    for (size_t i = offset; i < Byte::getSize(); ++i)
//    {
//        result.setBit(i, obj.getBit(i - offset));
//    }
//    return result;
//}

int main()
{
    Byte b1, b2;

    /* std::cout << "Bitwise \"або\" (|):\n";
       std::cout << "Byte #1:\n";
       b1.ShowBits();  //output random bits
       std::cout << "Byte #2:\n";
       b2.ShowBits(); //output random bits
       Byte resultOr = b1 | b2;
       std::cout << "byte1 | byte2: ";
       resultOr.ShowBits();

       std::cout << "\nBitwise \"exclusive or\" (^):\n";
       std::cout << "Byte #1:\n";
       b1.ShowBits();
       std::cout << "Byte #2:\n";
       b2.ShowBits();
       Byte resultXor = b1 ^ b2;
       std::cout << "byte1 ^ byte2: ";
       resultXor.ShowBits();

       std::cout << "\nBitwise inversion (~):\n";
       std::cout << "Byte #1:\n";
       b1.ShowBits();
       Byte resultNot = ~b1;
       std::cout << "~byte1: ";
       resultNot.ShowBits();

       std::cout << "\nBitwise left shift (<<):\n";
       std::cout << "Byte #1:\n";
       b1.ShowBits();
       Byte resultLeftShift = b1 << 2;
       std::cout << "byte1 << 2: ";
       resultLeftShift.ShowBits();

       std::cout << "\nBitwise shift right (>>):\n";
       std::cout << "Byte #1:\n";
       b1.ShowBits();
       Byte resultRightShift = b1 >> 3;
       std::cout << "byte1 >> 3: ";
       resultRightShift.ShowBits();
    */



    std::cout << "Bitwise \"або\" (|):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();  //output random bits
    std::cout << "Byte #2:\n";
    b2.ShowBits();  //output random bits
    Byte resultOr = b1.bitwiseOr(b2);
    std::cout << "byte1 | byte2: ";
    resultOr.ShowBits();

    std::cout << "\nBitwise \"exclusive or\" (^):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();
    std::cout << "Byte #2:\n";
    b2.ShowBits();
    Byte resultXor = b1.bitwiseXor(b2);
    std::cout << "byte1 ^ byte2: ";
    resultXor.ShowBits();

    std::cout << "\nBitwise inversion (~):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();
    Byte resultNot = b1.bitwiseNot();
    std::cout << "~byte1: ";
    resultNot.ShowBits();

    std::cout << "\nBitwise left shift (<<):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();
    Byte resultLeftShift = b1.leftShift(2);
    std::cout << "byte1 << 2: ";
    resultLeftShift.ShowBits();

    std::cout << "\nBitwise shift right (>>):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();
    Byte resultRightShift = b1.rightShift(3);
    std::cout << "byte1 >> 3: ";
    resultRightShift.ShowBits();

    return 0;
}