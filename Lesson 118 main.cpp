// *, &, ->, ->*
#include <iostream>
#include "Lesson_118_Person.h"
#include "Lesson_118_PersonPointer.h"

int main()
{
    Person demien("Demien", "Blogan", 24);

    std::cout << demien << std::endl; 

    PersonPointer ptr{ demien };

    std::cout << &demien << std::endl;
    std::cout << &ptr << std::endl; 
    std::cout << (*ptr) << std::endl;


    std::cout << (*ptr).Age() << std::endl;
    std::cout << ptr->Age() << std::endl;

    /* 
    pointer p in class ptr
    ptr->p* 
    */

    return 0;
}