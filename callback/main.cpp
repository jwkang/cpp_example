#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include "_macro.hpp"
#include "MyClass.hpp"

using namespace std;
using namespace std::placeholders;

int main()
{
    MyClass myClass;

    // Wait for 5 seoncds
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        LOG("%d", i);
    }

    return 0;
}
