#include <iostream>
#include "uniqueptr.h"
#include "complex.h"

int main()
{
    uniqueptr<complex> ptr1 (new complex(10, 5));
   // uniqueptr<complex> ptr2(ptr1); //compilation error
   // uniqueptr<complex> p3 = ptr1; //compilation error
    uniqueptr<complex> p4 (std::move(ptr1));
    if(ptr1.get() == nullptr)
        std::cout << "ptr1 is now nullptr" << std::endl; 
    uniqueptr<complex> p5 = std::move(p4);
    if(p4.get() == nullptr)
        std::cout << "p4 is now nullptr" << std::endl; 

    uniqueptr<int> p6 (new int(10));
    std::cout << "real: " << p5->real() << std::endl;
    std::cout << *p5 << std::endl;

    // //std::cout << p5.get();
    p5.reset(new complex(2, 3));
    std::cout << *p5 << std::endl ;
    return 0;

}