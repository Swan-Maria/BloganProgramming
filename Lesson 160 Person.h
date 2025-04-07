#pragma once
#include <iostream>
#include <string>

class Person {
private:
    int age;
    std::string name;

public:
    Person() : age(0), name("") {
        std::cout << "Default constructor" << std::endl;
    }

    Person(int age, const std::string& name) : age(age), name(name) {
        std::cout << "2param constructor" << std::endl;
    }

    Person(int age, const std::string& name)
        : age(age), name(name)
    {
        std::cout << "2param constructor\n";
    }

    Person(const Person& other)
        : age(other.age), name(other.name)
    {
        std::cout << "Copy constructor\n";
    }

    Person(Person&& other) noexcept
        : age(other.age), name(other.name)
    {
        std::cout << "Move constructor\n";
    }

    ~Person()
    {
        std::cout << "Destructor\n";
    }

    Person& operator=(const Person& other)
    {
        if (this != &other)
        {
            std::cout << "copy operator=\n";
            age = other.age;
            name = other.name;
        }
        return *this;
    }

    Person& operator=(Person&& other) noexcept
    {
        if (this != &other)
        {
            std::cout << "move operator=\n";
            age = std::move(other.age);
            name = std::move(other.name);
        }
        return *this;
    }

    const std::string& Name() const
    {
        return name;
    }

    int Age() const
    {
        return age;
    }
};

bool operator==(const Person& person1, const Person& person2)
{
    return person1.Age() == person2.Age() && person1.Name() == person2.Name();
}

bool operator<(const Person& person1, const Person& person2)
{
    return person1.Name() < person2.Name();
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << "[Name: " << person.Name() << ", Age: " << person.Age() << "]\n";
    return os;
}