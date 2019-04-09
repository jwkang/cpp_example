#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "_macro.hpp"

void f2(int i, int j, int k)
{
    using namespace std;
    cout << i << j << k << endl;
}

template<typename ...Args>
void f(Args... args)
{
    f2(args...);
}

int main()
{
    LOG("hihihi");

    f(1,2,3);
    //f(1,2,3,4,5,6,7); // error
}
