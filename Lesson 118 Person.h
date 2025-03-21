#pragma once
#include <iostream>
class Person
{
private:
    char firstName[30];
    char lastName[30];
    int age;

public:
    // class constructor Person
    Person(const char* firstName, const char* lastName, int age);

    // getters
    const char* FirstName() const { return firstName; }
    const char* LastName() const { return lastName; }
    int Age() const { return age; }

    // reload operator output
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
};