#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;
using ul = unsigned long;

int horner(vector<int> poly_coeff, int at)
{
    int res = poly_coeff[0];
    for(int i = 1; i < poly_coeff.size(); ++i)
    {
        res = res*at + poly_coeff[i];
    }
    return res;
}


int main() {
    vector<int> poly_coeff {1, 0, 0};
    cout << horner(poly_coeff, 4) << '\n';
    return 0;
}
