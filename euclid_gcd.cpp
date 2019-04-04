#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int gcd(int a, int b)
{
    int c;
    while(b)
    {
        a = exchange(b, a%b);
    }
    return a;
}
