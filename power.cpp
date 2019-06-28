#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int64_t power(int64_t b, int64_t p)
{
    uint64_t r = 1;
    for(; p; b *= b, p >>= 1)
    {
        if(p & 1) r *= b;
    }
    return r;
}

int main()
{
    cout << power(2, 9) << '\n';
    return 0;
}
