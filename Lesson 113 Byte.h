#pragma once
class Byte {
private:
    static const size_t SIZE = 8;  // Byte size (8 bits)
    unsigned bits[SIZE];           // Array for storing bits

public:
    Byte();

    void ShowBits() const;

    unsigned getBit(size_t i) const {return bits[i];}

    void setBit(size_t i, unsigned value) { bits[i] = value;}

    static size_t getSize() {return SIZE;}

    /// Reload bitwise operators (methods):
    ///bitwise operator AND
    Byte bitwiseAnd(const Byte& other) const;

    ///bitwise operator OR
    Byte bitwiseOr(const Byte& other) const;

    ///bitwise operator XOR
    Byte bitwiseXor(const Byte& other) const;

    ///bitwise operator NOT (unary)
    Byte bitwiseNot() const;

    ///left shift operator
    Byte leftShift(int offset) const;

    /// right shift operator
    Byte rightShift(int offset) const;
};