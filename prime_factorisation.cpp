#include <iostream>
using namespace std;
void prime_factorisation(unsigned long k)
{
    while(k%2==0)
    {
        cout << 2 << ' ';
        k = k/2;
    }
    int i = 3;
    while(k!=1)
    {
        while(k%i==0)
        {
            cout << i << ' ';
            k = k/i;
        }
        i += 2;
    }
}
int main()
{
    prime_factorisation(225);
    cout << '\n';
    return 0;
}
