#ifndef _MACRO_H_
#define _MACRO_H_

#define LOG(...)                                   \
    do {                                            \
        printf("[%s:%d] ", __FUNCTION__, __LINE__);  \
        printf(__VA_ARGS__);                        \
        printf("\n");                               \
    }                                               \
    while(0)

#endif // _MACRO_H_

