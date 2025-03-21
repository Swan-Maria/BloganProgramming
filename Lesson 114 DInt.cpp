#include "Lesson_114_DInt.h"

DInt::~DInt()
{
    delete value;
    value = nullptr;
}

int DInt::GetValue() const
{
    return value != nullptr ? *value : 0;
}

void DInt::SetValue(int val)
{
    *value = val;
}

DInt& DInt::operator+=(const DInt& other)
{
    *value += other.GetValue();
    return *this;
}

DInt& DInt::operator-=(const DInt& other)
{
    *value -= other.GetValue();
    return *this;
}

DInt& DInt::operator*=(const DInt& other)
{
    *value *= other.GetValue();
    return *this;
}

DInt& DInt::operator/=(const DInt& other)
{
    if (other.GetValue() != 0)
    {
        *value /= other.GetValue();
    }
    return *this;
}

DInt& DInt::operator%=(const DInt& other)
{
    if (other.GetValue() != 0)
    {
        *value %= other.GetValue();
    }
    return *this;
}