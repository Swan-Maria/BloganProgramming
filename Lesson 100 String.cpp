#include "Lesson_100_String.h"
#include <iostream>
#include <cstring>

String::String()
	: str(nullptr), length(0)
{}

String::String(const String& other)
	:String()
{
	std::cout << "Copy Constructor \n";
	if (other.length != 0)
	{
		this->length = other.length;
		str = new char[length + 1];
		strcpy_s(this->str, length + 1, other.str);
	}
}

String::String(String&& other)
	:str(other.str), length(other.length)
{
	std::cout << "Move Constructor \n";
	//this->str = other.str;
	//this->length = other.length;
	other.str = nullptr;
	other.length = 0;

}

String::String(const char* str)
	:String()
{
	std::cout << "Constructor \n";
	if (str != nullptr && length != 0)
	{
		size_t length = std::strlen(str);
		this->length = length;
		this->str = new char[length + 1];
		strcpy_s(this->str, length + 1, str);
	}
}

String::String(const char arr[], size_t size)
:String()
{
	if (arr != nullptr && size != 0)
	{
		length = size;
		str = new char[length + 1];
		for (size_t i = 0; i < length; i++)
			str[i] = arr[i];
		str[length] = '\0';
	}
}

String::~String()
{
	delete[] str;
	str = nullptr;
	length = 0;
}

void String::SetString(const char* str)
{
	size_t length = std::strlen(str);
	if (str != nullptr && length != 0)
	{
		delete[] this->str;
		this->length = length;
		this->str = new char[length + 1];
		strcpy_s(this->str, length + 1, str);
	}
}

void String::SetString(const String& other)
{
	if (other.length != 0)
	{
		delete[] str;
		this->length = other.length;
		str = new char[length + 1];
		strcpy_s(this->str, length + 1, other.str);
	}
}

void String::SetString(const char arr[], size_t size)
{
	if (str != nullptr && size != 0)
	{
		delete[] str;
		length = size;
		str = new char[length + 1];
		for (size_t i = 0; i < length; i++)
			str[i] = arr[i];
		str[length] = '\0';
	}
}
