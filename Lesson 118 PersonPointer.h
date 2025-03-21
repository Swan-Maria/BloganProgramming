#pragma once
#include "Lesson_118_Person.h"

class PersonPointer
{
private:
    Person* ptr;

public:
    PersonPointer(Person& person) : ptr(&person) {}

    ~PersonPointer() { } //delete ptr; ptr = nullptr;

    // Methods   
    Person& operator*() const { return *ptr; } //reload * return link
    Person* operator&() const { return ptr; }
    Person* operator->() const { return ptr; }

    // Functions
    //friend Person& operator*(const PersonPointer& pointer) { return *pointer.ptr; }
    //friend Person* operator&(const PersonPointer& pointer) { return pointer.ptr; } //reload &
    //friend Person* operator->(const PersonPointer& pointer) { return *pointer.ptr; } //error because -> must be a method

    /// Type_of_Return_Value operator->* (One_Parameter) const { code }
};

