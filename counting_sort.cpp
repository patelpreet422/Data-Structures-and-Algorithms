#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

void counting_sort(vector<int>& vec)
{
    auto largest = *max_element(vec.begin(), vec.end());
    vector<int> temp(largest+1, 0);
    for(auto e: vec) ++temp[e];
    vec.assign(vec.size(), 0);

    for(size_t k = 0, i = 0; k < temp.size(); ++k) {
        while(temp[k]) {
            vec[i++] = k;
            --temp[k];
        }
    }
}

int main()
{
    vector<int> vec{1, 45, 78, 1, 1, 1, 1, 2, 0, 0, 45};
    counting_sort(vec);
    for(auto e: vec) cout << e << " ";
    return 0;
}
