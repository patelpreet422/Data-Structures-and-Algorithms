#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline constexpr int len_i(int i)
{
	int count = 0;
	while(i)
	{
		i = i/10;
		++count;
	}
	return count;
}

void subset_sum_exist(int target, int index, const vector<int> &numbers, string &chosen)
{
	  if(target < 0) return;
    if(target == 0)
    {
    	cout << chosen << '\n';
    }
    for(int i = index; i<numbers.size(); ++i)
    {
    	int e = numbers[i];
    	chosen += to_string(e);
    	subset_sum_exist(target-e, i+1, numbers, chosen);
    	int l = len_i(e);
    	chosen.erase(chosen.size()-l, l);
    }
}
void subset_sum_exist(int target, const vector<int> &numbers)
{
	  string chosen = "";
    subset_sum_exist(target, 0, numbers, chosen);
}
int main()
{
    int target = 10;
    vector<int> numbers{2, 3, 5, 6, 8, 10};
    //vector<int> numbers{1, 2, 3, 4, 5};
    subset_sum_exist(target, numbers);
    return 0;
}
