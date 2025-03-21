#include <iostream>
#include <cstdlib>  // std::rand()
#include <ctime>    // std::time()
#include "Lesson_113_Byte.h"

Byte::Byte()
{
    std::srand(static_cast<unsigned>(std::time(0)));
    for (size_t i = 0; i < SIZE; ++i) {
        bits[i] = std::rand() % 2;
    }
}

void Byte::ShowBits() const
{
    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cout << "[" << bits[i] << "]";
    }
    std::cout << std::endl;
}

Byte Byte::bitwiseAnd(const Byte& other) const
{
    Byte result;
    for (size_t i = 0; i < SIZE; ++i)
    {
        result.setBit(i, this->getBit(i) & other.getBit(i));
    }
    return result;
}

Byte Byte::bitwiseOr(const Byte& other) const
{
    Byte result;
    for (size_t i = 0; i < SIZE; ++i)
    {
        result.setBit(i, this->getBit(i) | other.getBit(i));
    }
    return result;
}

Byte Byte::bitwiseXor(const Byte& other) const
{
    Byte result;
    for (size_t i = 0; i < SIZE; ++i)
    {
        result.setBit(i, this->getBit(i) ^ other.getBit(i));
    }
    return result;
}

Byte Byte::bitwiseNot() const
{
    Byte result;
    for (size_t i = 0; i < SIZE; ++i)
    {
        result.setBit(i, ~this->getBit(i) & 1);
    }
    return result;
}

Byte Byte::leftShift(int offset) const
{
    Byte result;
    for (size_t i = 0; i < SIZE - offset; ++i)
    {
        result.setBit(i, this->getBit(i + offset));
    }
    return result;
}

Byte Byte::rightShift(int offset) const
{
    Byte result;
    for (size_t i = offset; i < SIZE; ++i)
    {
        result.setBit(i, this->getBit(i - offset));
    }
    return result;
}
