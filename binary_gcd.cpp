#include <iostream>
using namespace std;
using ul = unsigned long long;

bool even(ul a) { return (~a&1); }
bool odd(ul a) { return (a&1); }

ul binary_gcd(ul a, ul b)
{
        if(a == 0 || b == 0)
                return a|b;
        if(a == b)
                return a;
        if(even(a) && even(b))
                return (binary_gcd(a>>1, b>>1))<<1;
        if(even(a) && odd(b))
                return binary_gcd(a>>1, b);
        if(odd(a) && even(b))
                return binary_gcd(a, b>>1);
        if(a > b)
                return binary_gcd((a-b)>>1, b);
        return binary_gcd(a, (b-a)>>1);
}

int main()
{
        ul a = 2, b = 4;
        cin >> a >> b;
        cout << binary_gcd(a, b) << '\n';
        return 0;
}
