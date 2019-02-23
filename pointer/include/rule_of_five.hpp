#ifndef _RULEOFFIVE_
#define _RULEOFFIVE_

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <utility>

class rule_of_five
{
    char* cstring; // raw pointer used as a handle to a dynamically-allocated memory block
    rule_of_five(const char* s, std::size_t n) // to avoid counting twice
    : cstring(new char[n]) // allocate
    {
        std::memcpy(cstring, s, n); // populate
    }
 public:
    rule_of_five(const char* s = "")
    : rule_of_five(s, std::strlen(s) + 1)
    {}
    ~rule_of_five()
    {
        delete[] cstring;  // deallocate
    }
    rule_of_five(const rule_of_five& other) // copy constructor
    : rule_of_five(other.cstring)
    {}
    rule_of_five(rule_of_five&& other) noexcept // move constructor
    : cstring(std::__exchange(other.cstring, nullptr))
    {}
    rule_of_five& operator=(const rule_of_five& other) // copy assignment
    {
         return *this = rule_of_five(other);
    }
    rule_of_five& operator=(rule_of_five&& other) noexcept // move assignment
    {
        std::swap(cstring, other.cstring);
        return *this;
    }
// alternatively, replace both assignment operators with 
//  rule_of_five& operator=(rule_of_five other) noexcept
//  {
//      std::swap(cstring, other.cstring);
//      return *this;
//  }
};

#endif
