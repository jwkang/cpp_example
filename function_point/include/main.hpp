#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>

using namespace std;

class fruit
{
  public:
    void (fruit::*ff)(void);
    void apple()
    {
      cout << "apple" << endl;
    }
    void berry()
    {
      cout << "berry" << endl;
    }
};

#endif
