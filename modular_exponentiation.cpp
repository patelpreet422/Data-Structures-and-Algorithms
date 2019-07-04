#include <iostream>
#include <vector>
#include <numeric>

// Russian peasant exponentiation (recursive)
// O(log(b)int)
uint64_t mod_exp(uint64_t a, uint64_t b, uint64_t m)
{
    if(b == 0) return 1;
    if(b == 1) return a%m;
    a = a%m;
    return ((mod_exp(a*a%m, b>>1, m)%m) * (b&1? a: 1))%m;
}

// Russian peasant exponentiation (iterative)
// O(log(b))
uint64_t mod_exp_(uint64_t a, uint64_t b, uint64_t m)
{
    if(b == 0) return 1;
    uint64_t r = 1;
    a = a%m;
    while(b > 0)
    {
        if(b&1) r = (r * (a%m)) % m;
        b >>= 1;
        a = a*a%m;
    }
    return r;
}

int main()
{
    uint64_t a = 5, b = 1, m = 6;
    std::cout << mod_exp(a, b, m) << '\n';
    std::cout << mod_exp_(a, b, m) << '\n';
    return 0;
}
