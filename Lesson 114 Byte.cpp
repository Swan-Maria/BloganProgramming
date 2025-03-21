#include <iostream>
#include "Lesson_114_Byte.h"

Byte::Byte()
{
    for (size_t i = 0; i < SIZE; i++)
    {
        bits[i] = std::rand() % 2;
    }
}

void Byte::ShowBits() const
{
    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << "[" << bits[i] << "]";
    }
}

Byte& Byte::operator&=(const Byte& other)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        bits[i] &= other.bits[i];
    }
    return *this;
}

Byte& Byte::operator|=(const Byte& other)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        bits[i] |= other.bits[i];
    }
    return *this;
}

Byte& Byte::operator^=(const Byte& other)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        bits[i] ^= other.bits[i];
    }
    return *this;
}

Byte& Byte::operator<<=(int offset)
{
    if (offset > 0)
    {
        for (size_t i = SIZE - 1; i >= offset; --i)
        {
            bits[i] = bits[i - offset];
        }
        for (size_t i = 0; i < offset; ++i)
        {
            bits[i] = 0;
        }
    }
    return *this;
}

Byte& Byte::operator>>=(int offset)
{
    if (offset > 0)
    {
        for (size_t i = 0; i < SIZE - offset; ++i)
        {
            bits[i] = bits[i + offset];
        }
        for (size_t i = SIZE - offset; i < SIZE; ++i)
        {
            bits[i] = 0;
        }
    }
    return *this;
}

