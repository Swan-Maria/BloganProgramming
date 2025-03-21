#pragma once
#include <iostream>
class Number
{
private:
    int* value;
public:
    Number(int val) : value(new int(val)) {}
    Number(const Number& other) : value(new int(*other.value)) {}
    Number(Number&& other) noexcept : value(other.value) { other.value = nullptr; }
    ~Number() { delete value; }

    int GetValue() const { return value ? *value : 0; }

    // Unary operators (by methods)
    Number operator+() const { return Number(GetValue()); }
    Number operator-() const { return Number(-GetValue()); }
    Number& operator++() { if (value) ++(*value); return *this; }
    Number operator++(int) { Number temp(*this); if (value) ++(*value); return temp; }
    Number& operator--() { if (value) --(*value); return *this; }
    Number operator--(int) { Number temp(*this); if (value) --(*value); return temp; }

    // Binary operators (by methods)
    Number operator+(const Number& other) const { return Number(GetValue() + other.GetValue()); }
    Number operator-(const Number& other) const { return Number(GetValue() - other.GetValue()); }
    Number operator*(const Number& other) const { return Number(GetValue() * other.GetValue()); }
    Number operator/(const Number& other) const { return other.GetValue() != 0 ? Number(GetValue() / other.GetValue()) : Number(0); }
    Number operator%(const Number& other) const { return other.GetValue() != 0 ? Number(GetValue() % other.GetValue()) : Number(0); }

    Number& operator=(const Number& other) //appropriation
    {
        if (this != &other) { *value = *other.value; }
        return *this;
    }
    Number& operator=(Number&& other) noexcept //moving
    {
        if (this != &other) { delete value; value = other.value; other.value = nullptr; }
        return *this;
    }
    Number& operator=(int number) { if (value) *value = number; return *this; } //appropriation int value
    // re
    friend std::ostream& operator<<(std::ostream& os, const Number& num)
    {
        os << num.GetValue();
        return os;
    }
    // By function
    /* friend Number operator+(const Number& number) { return Number(number.GetValue()); }
    friend Number operator-(const Number& number) { return Number(-number.GetValue()); }
    friend Number& operator++(Number& number) { if(number.value) ++(*number.value); return number; }
    friend Number operator++(Number& number, int) { Number temp(number); if(number.value) ++(*number.value); return temp; }
    friend Number& operator--(Number& number) { if(number.value) --(*number.value); return number; }
    friend Number operator--(Number& number, int) { Number temp(number); if(number.value) --(*number.value); return temp; }

    friend Number operator+(const Number& number1, const Number& number2) { return Number(number1.GetValue() + number2.GetValue()); }
    friend Number operator-(const Number& number1, const Number& number2) { return Number(number1.GetValue() - number2.GetValue()); }
    friend Number operator*(const Number& number1, const Number& number2) { return Number(number1.GetValue() * number2.GetValue()); }
    friend Number operator/(const Number& number1, const Number& number2) { return number2.GetValue() != 0 ? Number(number1.GetValue() / number2.GetValue()) : Number(0); }
    friend Number operator%(const Number& number1, const Number& number2) { return number2.GetValue() != 0 ? Number(number1.GetValue() % number2.GetValue()) : Number(0); }
    */
};

