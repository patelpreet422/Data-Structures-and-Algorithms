#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <bitset>

using namespace std;

vector<unsigned long> sieve(unsigned long k)
{
    // initially all are primes, except 0 and 1
    vector<bool> prime_candidates(k+1, true);
    vector<unsigned long> primes;
    for(unsigned long i = 2; i*i <= k; ++i){
        if(prime_candidates[i]){
            for(unsigned long j = i*i; j <= k; j += i)
                prime_candidates[j] = false;
        }
    }

    for(auto i = 2; i <= k; ++i){
        if(prime_candidates[i]) primes.push_back(i);
    }
    return primes;
}

int main()
{
    auto primes = sieve(1000);
    for(auto e: primes) cout << e << " ";
    return 0;
}
