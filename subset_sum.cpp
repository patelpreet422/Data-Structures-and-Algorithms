#include <iostream>
#include <vector>
using namespace std;
bool subset_sum_exist(int target, int index, const vector<int> &numbers)
{
    if(target == 0) return true;
    if(index == numbers.size()) return false;
    return subset_sum_exist(target, index+1, numbers) || subset_sum_exist(target-numbers[index], index+1, numbers);
}
bool subset_sum_exist(int target, const vector<int> &numbers)
{
    return subset_sum_exist(target, 0, numbers);
}
int main()
{
    int target = 9;
    vector<int> numbers{3, 34, 4, 12, 5, 2};
    cout << boolalpha << subset_sum_exist(target, numbers) << '\n';
    return 0;
}
