#include <iostream>
#include "Lesson_115_DArray.h"
//Reload the indexer

int main()
{
    DArray arr(5);

    for (size_t i = 0; i < arr.GetSize(); i++)
    {
        arr[i] = static_cast<int>(i) * 10;
    }

    for (size_t i = 0; i < arr.GetSize(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    //change array element via indexer
    arr[1] = 11671;
    arr[4] = 11;
    arr("first");

    for (size_t i = 0; i < arr.GetSize(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << arr("first") << std::endl;

    return 0;
}