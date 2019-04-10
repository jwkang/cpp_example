#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdarg.h>

#include <sstream>

const char* ANDROID_LOG_INFO = "INFO";
const char* MAIN_TAG = "MAIN_TAG";

#define LOGI(...) f(ANDROID_LOG_INFO, MAIN_TAG, ##__VA_ARGS__)

#if 1
template<typename ...Args>
void f(const char *level, const char *tag, const char* fmt, Args... args)
{
    char buf[100];
    sprintf(buf, fmt, args...);

    std::ostringstream ss;
    ss << "[" << level << "]" << "[" << tag << "] " << buf;
    std::string header = ss.str();

    std::cout << header;
}
#else
void f(const char *level, const char *tag, const char* fmt, ...)
{
    printf("[%s][%s]", level, tag);
    va_list args;
    va_start(args, fmt);
    printf(fmt, args);
    va_end(args);
}
#endif

int main()
{
    f(ANDROID_LOG_INFO, MAIN_TAG, "hi %s\n", "jongwon");
    //f(1,2,3,4,5,6,7); // error
}
