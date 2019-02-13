#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "_macro.hpp"
#include <functional>

using namespace std::placeholders;

std::function<void(const char *message)> hello3;
std::function<void()> hello4;
std::function<void(const char *message)> hello5;

int (*temp_function)(int, int);
void test_func(int &each_value)
{
    each_value++;
}

int main2()
{
    temp_function=[](int a, int b) -> int { return a+b; };
    
    std::vector<int> v = {1,2,3,4,5};
    std::for_each(v.begin(), v.end(), 
        [](int &each_value)->void{each_value++;});

    
    std::for_each(v.begin(), v.end(), test_func);

    std::for_each(v.begin(), v.end(), 
        [](int each_value){std::cout << each_value << std::endl;});
    
    return 0;
}

using namespace std;

int main()
{
    cout<< "Illustrating the generic unique algorithm."<< endl;
    const int N = 11;
    int array1[N] = {1, 2, 0, 3, 3, 0, 7, 7, 7, 0, 8};
    vector<int> vector1;
    for (int i=0; i< N; ++i)
        vector1.push_back(array1[i]);
 
    copy(vector1.begin(), vector1.end(), ostream_iterator<int>(cout, " "));
    cout<< endl;

    // vector1에서 연속 중복 원소를 제거한다.
    vector<int>::iterator new_end;
    new_end = unique(vector1.begin(), vector1.end());
    //new_end = unique(vector1.begin(), vector1.end(), [](int &a, int &b){ return a==b; });
 
    // vector1의 사이즈는 변하지 않는다.
    assert (vector1.size() == N);
 
    copy(vector1.begin(), vector1.end(), ostream_iterator<int>(cout, " "));
    cout<< endl;

    // 연이어 붙어 있지 않은 중복 원소들은 [vector1.begin(), new_end)에
    // 그대로 남아 있다. new_end 뒷부분의 원소들은 삭제한다.
    vector1.erase(new_end, vector1.end());
 
    // vector1에 담긴 원소들의 표준 출력 스트림으로 출력
    copy(vector1.begin(), vector1.end(), ostream_iterator<int>(cout, " "));
    cout<< endl;
 
    return 0;
}

