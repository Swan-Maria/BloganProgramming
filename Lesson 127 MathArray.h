#pragma once
#include "Lesson 127 Array.h"

class MathArray:public Array
{
private:
	int* asshole;
public:
	MathArray(size_t size);
	/*MathArray(const MathArray& oth)
		:Array(oth)
	{
		this->asshole = oth.asshole;
	}
	~MathArray()
	{
		delete asshole;
	}*/
	int Sum() const;
	int Product() const;
	int Max() const;
	int Min() const;
	double Average() const;
};

