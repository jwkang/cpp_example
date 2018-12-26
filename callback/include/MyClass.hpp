#ifndef _MYCLASS_H_
#define _MYCLASS_H_

#include <vector>
#include <memory>
#include <functional>
#include "Test.hpp"

class MyClass
{
  private:
    int private_x;
    std::vector<std::shared_ptr<Test>> mTests;

  public:
    MyClass();
    virtual ~MyClass() = default;

    void Callback(bool, int);
};

#endif
