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
    f = &fruit::apple;
    x.ff = &fruit::berry;
    (x.*f)();
    (x.*x.ff)();
    return 0;
}
