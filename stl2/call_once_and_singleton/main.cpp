#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "_macro.hpp"

#include <cstdio>
#include <mutex>
#include <memory>

using namespace std;

class myClass {
    public:
        static myClass *getInstance() {
            call_once(myClass::mOnceFlag, []() {
                    printf("myClass Instance is created...\n");
                    mInstance.reset(new myClass);
                    });

            return mInstance.get();
        }

        void log() {
            printf("hello\n");
        }

        ~myClass() { LOG("%s called", __FUNCTION__); }


    private:
        static unique_ptr<myClass> mInstance;
        static once_flag mOnceFlag;

        myClass() = default;
        myClass(const myClass &) = delete;
        myClass &operator=(const myClass &) = delete;
};

unique_ptr<myClass> myClass::mInstance;
once_flag myClass::mOnceFlag;

int main()
{
    LOG("hihihi");

    myClass::getInstance()->log();
    myClass::getInstance()->log();
}
