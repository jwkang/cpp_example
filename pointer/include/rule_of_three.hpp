#ifndef _RULEOFTHREE_
#define _RULEOFTHREE_

class rule_of_three
{
    char* cstring; // raw pointer used as a handle to a dynamically-allocated memory block
    rule_of_three(const char* s, std::size_t n) // to avoid counting twice
    : cstring(new char[n]) // allocate
    {
        std::memcpy(cstring, s, n); // populate
    }
 public:
    rule_of_three(const char* s = "")
    : rule_of_three(s, std::strlen(s) + 1)
    {}
    ~rule_of_three()
    {
        delete[] cstring;  // deallocate
    }
    rule_of_three(const rule_of_three& other) // copy constructor
    : rule_of_three(other.cstring)
    {}
    rule_of_three& operator=(rule_of_three other) // copy assignment
    {
        std::swap(cstring, other.cstring);
        return *this;
    }
};

#endif
