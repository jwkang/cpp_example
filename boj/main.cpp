#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define TOTAL_DAY 4

static int cnt=0;

class result {
    int day;
    int accLate;
    bool isLate;
public:
    result(int day, int accLate, bool isLate) : day(day), accLate(accLate), isLate(isLate) {}

    friend ostream &operator<<(ostream &os, const result &result) {
        os << "day: " << result.day << " accLate: " << result.accLate << " isLate: " << result.isLate;
        return os;
    }

    bool operator<(const result &rhs) const {
        return day < rhs.day;
    }
};

std::vector<result> v;

void sol(int day, int accLate, bool isLate) {
    if( day > TOTAL_DAY ) return;
    v.emplace_back(day, accLate, isLate);

    if( isLate == 0 ) {
        accLate = 0;
    }

    if( accLate == 3 ) {
        cout << "i'm day: " << day << " accLate: " << accLate << " isLate: " << isLate << endl;
        cnt++;
        return;
    }

    sol(day+1, accLate, false);
    sol(day+1, accLate+1, true);
}

int main() {
    sol(0, 0, false);
    sol(0, 1, true);

    cout << cnt << endl;
    sort(v.begin(), v.end());

    for( const result& r : v) {
        cout << r << endl;
    }

    return 0;
}
