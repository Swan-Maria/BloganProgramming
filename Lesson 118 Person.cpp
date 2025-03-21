#include "Lesson_118_Person.h"
#include <iostream>

Person::Person(const char* firstName, const char* lastName, int age)
{
    this->age = age;
    strncpy_s(this->firstName, firstName, 30 - 1);
    strncpy_s(this->lastName, lastName, 30 - 1);
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << "Person Info: [Name: " << person.firstName;
    os << ", Surname: " << person.lastName;
    os << ", Age: " << person.age << "]";
    return os;
}
