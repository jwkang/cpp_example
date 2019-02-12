#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "_macro.hpp"
#include "main.hpp"

int main()
{
    fruit x;
    void (fruit::*f)(void);
    void (fruit::*hello)(void);

    // error: assigning to 'void (*)()' from incompatible type 'void (fruit::*)()'
    // void (*hello2)(void);
    // so, it can be corrected like
    // void (*fruit::*hello2)(void)

    hello = &fruit::apple;
    f = &fruit::apple;

#if 1
    x.ff = &fruit::berry;
#else
    // it will error 
    x.ff = []() { std::cout << "hello" << std::endl; };
#endif
    (x.*f)();
    (x.*x.ff)();
    (x.*hello)();
    return 0;
}
