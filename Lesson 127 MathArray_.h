#include <iostream>
#include "Lesson 127 Array_.h"
#pragma once

template <typename U>
class MathArray : public Array<U>
{
private:
	U* asshole;
public:
	MathArray(size_t size);
	MathArray(const MathArray& oth);
	~MathArray();
	MathArray operator=(const MathArray& oth);
    U& operator[](size_t index);
    const U& operator[](size_t index) const;
	U Sum() const;
	U Product() const;
	U Max() const;
	U Min() const;
	U Average() const;
};

template <typename U>
MathArray<U>::MathArray(size_t size)
    :Array<U>(size), asshole(new U())
{}

template <typename U>
MathArray<U>::MathArray(const MathArray& oth)
    :Array<U>(oth), asshole(new U(*oth.asshole))
{}

template <typename U>
MathArray<U>::~MathArray()
{
    delete asshole;
    asshole = nullptr;
}

template <typename U>
MathArray<U> MathArray<U>::operator=(const MathArray& oth)
{
    if (this != &oth)
    {
        //Через объект вызывается оператор =, который находиться в родительском классе.
        this->Array<U>::operator=(oth);
        //Явный вызов деструкторов не рекомендуется
        delete asshole;
        asshole = nullptr;
        asshole = new U(*oth.asshole);
    }
    return *this;
}

template <typename U>
U& MathArray<U>::operator[](size_t index)
{
    return Array<U>::operator[](index); //Если использовать (*this)[i] будет рекурсия!
}

template <typename U>
const U& MathArray<U>::operator[](size_t index) const
{
    return Array<U>::operator[](index); //Если использовать (*this)[i] будет рекурсия!
}

template <typename U>
U MathArray<U>::Sum() const
{
    if (this->Size() == 0)
        return 0;
    U sum = 0;
    for (size_t i = 0; i < this->Size(); i++)
        sum += Array<U>::operator[](i); //(*this)[i]
    return sum;
}

template <typename U>
U MathArray<U>::Product() const
{
    if (this->Size() == 0)
        return 0;
    U product = 0;
    for (size_t i = 0; i < this->Size(); i++)
        product *= (*this)[i];
    return product;
}

template <typename U>
U MathArray<U>::Max() const
{
    U max = (*this)[0];
    for (size_t i = 1; i < this->Size(); i++)
        if (max < (*this)[i])
            max = (*this)[i];
    return max;
}

template <typename U>
U MathArray<U>::Min() const
{
    U min = (*this)[0];
    for (size_t i = 1; i < this->Size(); i++)
        if (min < (*this)[i])
            min = (*this)[i];
    return min;
}

template <typename U>
U MathArray<U>::Average() const
{
    if (this->Size() == 0)
        return 0;
    U sum = Sum();
    return sum / this->Size();
}
