#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "rule_of_five.hpp"
#include "_macro.hpp"

template<typename T>
void print_all(const T& buffer, size_t size)
{
    for( int i=0; i<size; i++ ) {
        std::cout << buffer[i] << std::endl; 
    }
}

class myClass {
public:
    myClass() { LOG("myClass() called"); }
    myClass(const  myClass& others) { LOG("copy constructor myClass(&) called"); }
    virtual ~myClass() { LOG("~myClass() called"); }

    //myClass(const myClass &&) { LOG("const myClass && is called"); }
    const myClass& operator=(const myClass &a) { LOG("assignment called"); return a;}
    const myClass& operator=(myClass &&a) { LOG("move assignment called"); return a;}
};

int main()
{
	using namespace std;

#if 0
    unique_ptr<int[]> data;
    data.reset(new int[100]);

    for( int i=0; i<100; i++ ) {
        data[i] = i;
    }

    print_all(data, 100);
#endif

    std::unique_ptr<myClass> instance(new myClass());
    std::unique_ptr<myClass> instance2;

#if 0
    //error case
    instance.release();
    // delete instance; // it's required
#endif
    instance2 = std::move(instance);

    if( instance == nullptr ) LOG("myClass is nullptr");
    if( instance.get() == nullptr ) LOG("myClass.get() is nullptr");

    myClass *p = instance2.release();

    myClass p1;
    myClass p2(p1);

    delete p;
}
