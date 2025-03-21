#include <iostream>
//Reload the function call operator
class EvenOddFunctor
{
private:
    int evenSum = 0;
    int oddSum = 0;

public:
    void operator() (int number)
    {
        if (number % 2 == 0)
        {
            evenSum += number;
        }
        else
        {
            oddSum += number;
        }
    }
    int GetEvenSum() const { return evenSum; }
    int GetOddSum() const { return oddSum; }
};

class Greeting
{
private:
    int value = 5;
public:
    /*void Method()
    {
        std::cout << "Hello\n";
    }*/

    /*
    Function call operator overload syntax :
    Return_Value_Type operator () (Parameter_List)
    {Code}
    */
    void operator()() const
    {
        std::cout << "Hello, World!\n";
    }
    ///Functional object / functor
    int operator()(const char* name, int age) const 
    {
        std::cout << "Hello, " << name << "!\n";
        std::cout << "your age is " << age << "!\n";
        std::cout << "value = " << value << "!\n";

        return 450;
    }
};

int main()
{
    /*Greeting myGreeting;
    int value = myGreeting("Demien", 24);
    std::cout << value << std::endl;
    myGreeting();*/

    EvenOddFunctor functor;

    const size_t SIZE = 10;
    int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (size_t i = 0; i < SIZE; i++)
    {
        functor(arr[i]);
    }
    std::cout << "Even numbers: " << functor.GetEvenSum() << "\n";
    std::cout << "Odd numbers: " << functor.GetOddSum() << std::endl;
    return 0;
}

