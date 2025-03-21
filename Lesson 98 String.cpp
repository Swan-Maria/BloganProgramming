#include <cstring>
#include "Lesson_98_String.h"

void String::Copy(const char* str)
{
	size_t length = std::strlen(str);
	this->str = new char[length + 1];
	strcpy_s(this->str, length + 1, str);
}

String::String()
	:str(nullptr)
{ }

String::String(const char* str)
	: str(nullptr)
{
	if (str != nullptr)
		Copy(str);
}

String::~String()
{
	delete[] str;
	str = nullptr;
}
const char* String::GetString() const
{
	
	return str != nullptr ? str : "";
}
size_t String::GetSize() const
{
	return str != nullptr ? std::strlen(str) : 0;
}
void String::SetString(const char* newstrStr)
{
	if (str != nullptr)
	{
		delete[] this->str;
		Copy(str);
	}

}

const String& String::CompareBySize(const String& other)
{
	return other.GetSize() >= GetSize()? other: *this;
	/*if (other.GetSize() >= GetSize())
		return other;
	else
		return *this;*/
}

