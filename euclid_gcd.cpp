#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int gcd(int a, int b)
{
    while(b) a = exchange(b, a%b);
    return a;
}
