#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_subarray_sum(vector<int>& A)
{
    bool all_negative = true;
    
    for(auto e: A) {
        all_negative &= (e < 0);
    }
    
    if(all_negative) {
        return *max_element(begin(A), end(A));
    }
    
    int s = 0;
    int rs = 0;
    int n = A.size();
    for(int i = 0; i < n; ++i) {
        rs += A[i];
        if(rs < 0) {
            rs = 0;
        }
        s = max(s, rs);
    }
    return s;
}

int main() {
    vector<int> vec{-2, -3, 4, -1, -2, 1, 5, -3};
    cout << max_subarray_sum(vec) << '\n';
    return 0;
}
