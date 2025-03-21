#pragma once
class DArray
{
private:
    size_t size;
    int* arr;

public:
    DArray(size_t size) : size(size), arr(new int[size] {}) {}

    DArray(const DArray& other) : size(other.size), arr(new int[other.size])
    {
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    /// movement constructor
    DArray(DArray&& other) noexcept : size(other.size), arr(other.arr)
    {
        other.arr = nullptr;
        other.size = 0;
    }

    /// copy assignment operator
    DArray& operator=(const DArray& other);

    /// move assignment operator
    DArray& operator=(DArray&& other) noexcept;

    /// Operator overloading []
    int& operator[](size_t index);

    int& operator()(const char* index);

    const int& operator[](size_t index) const;

    size_t GetSize() const{return size;}

    ~DArray(){delete[] arr;}
};
