#pragma once
class Number
{
private:
    int* value;

public:
    Number(int val) : value(new int(val)) {}
    Number(const Number& other) : value(new int(*other.value)) {}
    Number(Number&& other) noexcept : value(other.value) { other.value = nullptr; }
    ~Number() { delete value; }

    int GetValue() const { return *value; }

    /// Reloading comparison operators
    /* bool operator>(const Number& other) const { return *this->value > *other.value; }
       bool operator<(const Number& other) const { return *this->value < *other.value; }
       bool operator>=(const Number& other) const { return *this->value >= *other.value; }
       bool operator<=(const Number& other) const { return *this->value <= *other.value; }
       bool operator==(const Number& other) const { return *this->value == *other.value; }
       bool operator!=(const Number& other) const { return *this->value != *other.value; }
    */
    /// Reloading logical operators
    /*   bool operator&&(const Number& other) const { return (*value != 0) && (*other.value != 0); }
       bool operator||(const Number& other) const { return (*value != 0) || (*other.value != 0); }
       bool operator!() const { return *value == 0; } 
    */
    /// Output value
    void PrintValue() const { std::cout << *value << std::endl; }
};