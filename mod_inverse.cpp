/*
 *https://comeoncodeon.wordpress.com/2011/10/09/modular-multiplicative-inverse/
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <tuple>

//O(log(m)*log(m))
std::tuple<int64_t, int64_t, int64_t> gcd(int64_t a, int64_t b)
{
    if (a == 0) {
        return {b, 0, 1};
    }
    auto [g, x, y] = gcd(b%a, a);
    return {g, (y-(b/a)*x), x};
}

int64_t mod_inv(int64_t a, int64_t m)
{
    auto r = std::get<1>(gcd(a, m));
    r = (r%m + m)%m;
    return r;
}

//O(log(m))
int64_t mod_inv_(int64_t a, int64_t m)
{
    int m_copy = m;
    int y = 0, x = 1;

    if (m == 1) return 0;

    while (a > 1)
    {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;

        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0) x += m_copy;
    return x;
}

//O(n)
std::vector<int64_t> inverseArray(int64_t n, int64_t m) {
    std::vector<int64_t> modInverse(n + 1, 0);
    modInverse[1] = 1;
    for(int64_t i = 2; i <= n; i++) {
        modInverse[i] = (-(m/i) * modInverse[m % i]) % m + m;
    }
    return modInverse;
}


int main()
{
    int64_t a = 1, m = 15;
    std::cout << mod_inv_(a, m) << '\n';
    std::cout << inverseArray(a, m)[a] << '\n';
    return 0;
}
