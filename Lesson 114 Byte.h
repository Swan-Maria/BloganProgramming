#pragma once
class Byte
{
private:
    static const size_t SIZE = 8;
    unsigned bits[SIZE];

public:
    Byte();

    void ShowBits() const;

    /// Overload operator &= 
    Byte& operator&=(const Byte& other);

    /// Overload operator |= 
    Byte& operator|=(const Byte& other);

    /// Overload operator ^=
    Byte& operator^=(const Byte& other);

    /// Overload operator <<=
    Byte& operator<<=(int offset);

    /// Overload operator >>=
    Byte& operator>>=(int offset);

    /// Allowing access to private data for external operators
    /*
    friend Byte operator&(const Byte& left, const Byte& right);
    friend Byte operator|(const Byte& left, const Byte& right);
    friend Byte operator^(const Byte& left, const Byte& right);
    friend Byte operator<<(const Byte& b, int offset);
    friend Byte operator>>(const Byte& b, int offset);
    */
};