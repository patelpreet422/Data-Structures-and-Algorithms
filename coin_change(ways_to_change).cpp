#include <iostream>
#include <vector>
using namespace std;

/*
int change(vector<int>& coins, int target, int k)
{
    if(target == 0) return 1;

    int ways = 0;

    for(int i = k; i < coins.size(); ++i)
    {
        if(target - coins[i] >= 0)
            ways += change(coins, target-coins[i], i);
    }

    return ways;
}
*/

int change(vector<int>& coins, int target, int i)
{
    if(i >= coins.size()) return 0;
    if(target == 0) return 1;
    if(target < 0) return 0;
    return change(coins, target-coins[i], i) + change(coins, target, i+1);
}

int main() {
    vector coins{1, 2, 3};
    string chosen = "";
    int ans = change(coins, 4, 0);

    cout << ans << '\n';
    return 0;
}
