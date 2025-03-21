#include <iostream>
#include "Lesson_114_DInt.h"
#include "Lesson_114_Byte.h"

///Operator overloading syntax:
/*
Return_Value_Type operator Sign (Parameter_List)
{Code}
*/

/// Reloading combined arithmetic operators (functions)
/*
/// The += operator as a function
DInt& operator+=(DInt& destinationNumber, const DInt& sourceNumber)
{
    destinationNumber.SetValue(destinationNumber.GetValue() + sourceNumber.GetValue());
    return destinationNumber;
}

/// The -= operator as a function
DInt& operator-=(DInt& destinationNumber, const DInt& sourceNumber)
{
    destinationNumber.SetValue(destinationNumber.GetValue() - sourceNumber.GetValue());
    return destinationNumber;
}

/// The *= operator as a function
DInt& operator*=(DInt& destinationNumber, const DInt& sourceNumber)
{
    destinationNumber.SetValue(destinationNumber.GetValue() * sourceNumber.GetValue());
    return destinationNumber;
}

/// The /= operator as a function
DInt& operator/=(DInt& destinationNumber, const DInt& sourceNumber)
{
    if (sourceNumber.GetValue() != 0)
    {
        destinationNumber.SetValue(destinationNumber.GetValue() / sourceNumber.GetValue());
    }
    return destinationNumber;
}

/// The %= operator as a function
DInt& operator%=(DInt& destinationNumber, const DInt& sourceNumber)
{
    if (sourceNumber.GetValue() != 0)
    {
        destinationNumber.SetValue(destinationNumber.GetValue() % sourceNumber.GetValue());
    }
    return destinationNumber;
}
*/


/// Operator overloading syntax:
/* 
Return_Value_Type operatorChar(Parameter_List)
{ code } 
*/



/* Byte operator&(const Byte& lhs, const Byte& rhs)
{
    Byte result;
    for (size_t i = 0; i < Byte::SIZE; i++)
    {
        result.bits[i] = lhs.bits[i] & rhs.bits[i];
    }
    return result;
}

Byte operator|(const Byte& lhs, const Byte& rhs)
{
    Byte result;
    for (size_t i = 0; i < Byte::SIZE; i++)
    {
        result.bits[i] = lhs.bits[i] | rhs.bits[i];
    }
    return result;
}

Byte operator^(const Byte& lhs, const Byte& rhs)
{
    Byte result;
    for (size_t i = 0; i < Byte::SIZE; i++)
    {
        result.bits[i] = lhs.bits[i] ^ rhs.bits[i];
    }
    return result;
}

Byte operator<<(const Byte& b, int offset)
{
    Byte result;
    for (size_t i = 0; i < Byte::SIZE; i++)
    {
        if (i + offset < Byte::SIZE)
            result.bits[i] = b.bits[i + offset];
        else
            result.bits[i] = 0;
    }
    return result;
}

Byte operator>>(const Byte& b, int offset)
{
    Byte result;
    for (size_t i = 0; i < Byte::SIZE; i++)
    {
        if (i >= static_cast<size_t>(offset))
            result.bits[i] = b.bits[i - offset];
        else
            result.bits[i] = 0;
    }
    return result;
}

//combined operators by functions:

Byte& operator&=(Byte& destinationByte, const Byte& sourceByte)
{
    destinationByte = destinationByte & sourceByte;
    return destinationByte;
}

Byte& operator|=(Byte& destinationByte, const Byte& sourceByte)
{
    destinationByte = destinationByte | sourceByte;
    return destinationByte;
}

Byte& operator^=(Byte& destinationByte, const Byte& sourceByte)
{
    destinationByte = destinationByte ^ sourceByte;
    return destinationByte;
}

Byte& operator<<=(Byte& destinationByte, int offset)
{
    destinationByte = destinationByte << offset;
    return destinationByte;
}

Byte& operator>>=(Byte& destinationByte, int offset)
{
    destinationByte = destinationByte >> offset;
    return destinationByte;
}
 */

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Class 'DInt':
    std::cout << "Operator +=:\n";
    DInt num1{ 10 }, num2{ 30 };

    std::cout << "num1 = " << num1.GetValue() << std::endl;
    std::cout << "num2 = " << num2.GetValue() << std::endl;

    num1 += num2;
    std::cout << "(num1 += num2) = " << num1.GetValue() << "\n\n";

    std::cout << "Operator -=:\n";
    DInt num3{ 100 }, num4{ 23 };

    std::cout << "num3 = " << num3.GetValue() << std::endl;
    std::cout << "num4 = " << num4.GetValue() << std::endl;

    num3 -= num4;
    std::cout << "(num3 -= num4) = " << num3.GetValue() << "\n\n";

    std::cout << "Operator *=:\n";
    DInt num5{ 3 }, num6{ 5 };

    std::cout << "num5 = " << num5.GetValue() << std::endl;
    std::cout << "num6 = " << num6.GetValue() << std::endl;

    num5 *= num6;
    std::cout << "(num5 *= num6) = " << num5.GetValue() << "\n\n";

    std::cout << "Operator /=:\n";
    DInt num7{ 20 }, num8{ 5 };

    std::cout << "num7 = " << num7.GetValue() << std::endl;
    std::cout << "num8 = " << num8.GetValue() << std::endl;

    num7 /= num8;
    std::cout << "(num7 /= num8) = " << num7.GetValue() << "\n\n";

    std::cout << "Operator %=:\n";
    DInt num9{ 18 }, num10{ 5 };

    std::cout << "num9 = " << num9.GetValue() << std::endl;
    std::cout << "num10 = " << num10.GetValue() << std::endl;

    num9 %= num10;
    std::cout << "(num9 %= num10) = " << num9.GetValue() << "\n\n";
    
    
    // Operator &= demonstration
    std::cout << "\nOperator &=:" << std::endl;
    {
        Byte byte1, byte2;
        std::cout << "Byte #1:" << std::endl;
        byte1.ShowBits();
        std::cout << "Byte #2:" << std::endl;
        byte2.ShowBits();
        byte1 &= byte2;
        std::cout << "Byte #1 &= Byte #2:" << std::endl;
        byte1.ShowBits();
        std::cout << std::endl;
    }

    // Operator |= demonstration 
    std::cout << "\nOperator |=:" << std::endl;
    {
        Byte byte1, byte2;
        std::cout << "Byte #1:" << std::endl;
        byte1.ShowBits();
        std::cout << "Byte #2:" << std::endl;
        byte2.ShowBits();
        byte1 |= byte2;
        std::cout << "Byte #1 |= Byte #2:" << std::endl;
        byte1.ShowBits();
        std::cout << std::endl;
    }

    // Operator ^= demonstration 
    std::cout << "\nOperator ^=:" << std::endl;
    {
        Byte byte1, byte2;
        std::cout << "Byte #1:" << std::endl;
        byte1.ShowBits();
        std::cout << "Byte #2:" << std::endl;
        byte2.ShowBits();
        byte1 ^= byte2;
        std::cout << "Byte #1 ^= Byte #2:" << std::endl;
        byte1.ShowBits();
        std::cout << std::endl;
    }

    // Operator <<= demonstration 
    std::cout << "\nOperator <<=:" << std::endl;
    {
        Byte byte;
        std::cout << "Byte:" << std::endl;
        byte.ShowBits();
        byte <<= 2;
        std::cout << "Byte <<= 2:" << std::endl;
        byte.ShowBits();
        std::cout << std::endl;
    }

    // Operator >>= demonstration 
    std::cout << "\nOperator >>=:" << std::endl;
    {
        Byte byte;
        std::cout << "Byte:" << std::endl;
        byte.ShowBits();
        byte >>= 2;
        std::cout << "Byte >>= 2:" << std::endl;
        byte.ShowBits();
        std::cout << std::endl;
    }

    return 0;
}