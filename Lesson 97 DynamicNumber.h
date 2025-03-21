#pragma once
class DynamicNumber
{
private:
	int* number;
public:
	DynamicNumber(int value)
		:number(new int(value))
	{}

	void SetValue(int value)
	{
		*number = value;
	}

	int GetValue() const
	{
		return *number;
	}

	/*void Delete()
	{
		delete number;
		number = nullptr;
	}*/

	/*
	Syntax of creation destructor:
	~Class_name()
	{
	
	}
	*/

	~DynamicNumber()
	{
		delete number;
		number = nullptr;
	}
};

