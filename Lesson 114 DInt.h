#pragma once
class DInt
{
private:
    int* value;

public:
    DInt(int value): value(new int(value)) { }

    DInt(const DInt& other): value(new int(other.GetValue())){ }

    DInt(DInt&& other) noexcept: value(other.value) {other.value = nullptr;}

    ~DInt();

    int GetValue() const;

    void SetValue(int val);

    DInt& operator+=(const DInt& other);

    DInt& operator-=(const DInt& other);

    DInt& operator*=(const DInt& other);

    DInt& operator/=(const DInt& other);

    DInt& operator%=(const DInt& other);
};

