#ifndef _NON_COPYABLE_H_
#define _NON_COPYABLE_H_

class uncopyable {
protected:
    uncopyable() = default;
public:
    ~uncopyable() = default;                // no needs to be virtual
private:
    uncopyable(const uncopyable&) {}        // Prohibit copy constructor
    void operator=(const uncopyable&) {}    // Prohibit copy assignment constructor
}

#endif
