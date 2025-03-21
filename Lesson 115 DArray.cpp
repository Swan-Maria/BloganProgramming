#include <iostream>
#include "Lesson_115_DArray.h"

DArray& DArray::operator=(const DArray& other)
{
    if (this != &other)
    {
        delete[] arr;
        size = other.size;
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

DArray& DArray::operator=(DArray&& other) noexcept
{
    if (this != &other)
    {
        delete[] arr;
        size = other.size;
        arr = other.arr;
        other.arr = nullptr;
        other.size = 0;
    }
    return *this;
}

int& DArray::operator[](size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("Індекс виходить за межі масиву!");
    }
    return arr[index];
}

int& DArray::operator()(const char* index)
{
    if (arr == nullptr)
    {
        std::cerr << "arr == nullptr in " << __func__ << " method.\n";
        std::exit(1);
    }

    if (std::strcmp(index, "zero") == 0)
    {
        return arr[0];
    }
    else if (std::strcmp(index, "first") == 0)
    {
        return arr[1];
    }
    else if (std::strcmp(index, "second") == 0)
    {
        return arr[2];
    }
    else if (std::strcmp(index, "third") == 0)
    {
        return arr[3];
    }
    else
    {
        std::cerr << "Incorrect index in '" << __func__ << "' method.\n";
        std::exit(1);
    }
}

const int& DArray::operator[](size_t index) const
{
    if (index >= size)
    {
        throw std::out_of_range("Індекс виходить за межі масиву!");
    }
    return arr[index];
}