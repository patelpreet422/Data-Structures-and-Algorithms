#include <iostream>
#include <vector>

using namespace std;

int max_subarray_sum(vector<int> vec)
{
    int s_idx = 0, e_idx = 0;
    int max_s = 0;
    int s = 0;
    for(int i = 0; i < vec.size(); ++i)
    {
        s += vec[i];
        if(s < 0)
        {
            s = 0;
            s_idx = i+1;
        }
        if(max_s < s)
        {
            max_s = s;
            e_idx = i;
        }
    }

    // print range
    for(int i = s_idx; i <= e_idx; ++i) cout << vec[i] << " ";
    cout << '\n';

    return max_s;
}

int main() {
    vector<int> vec{-2, -3, 4, -1, -2, 1, 5, -3};
    cout << max_subarray_sum(vec) << '\n';
    return 0;
}
