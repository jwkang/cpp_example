#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "_macro.hpp"
#include <functional>

void(*hello)(const char *str) = [](const char *message) { std::cout << message << std::endl; };
void(*hello2)(const char *str);

void greeting(const char *message)
{
    std::cout << message << std::endl;
}

std::function<void(const char *message)> hello3;
std::function<void()> hello4;
std::function<void(const char *message)> hello5;

int main()
{
    hello2 = greeting;
    
    hello("hello");
    hello2("hello2");

    using namespace std::placeholders;
    hello3 = std::bind(
        [](const char *message) { std::cout << message << std::endl; },
        _1);
    
    hello3("hello3");

    hello4 = std::bind(
        hello3, "hello4");

    hello4();

    hello5 = [](const char *message) { std::cout << message << std::endl; };
    hello5("hello5");

    return 0;
}
