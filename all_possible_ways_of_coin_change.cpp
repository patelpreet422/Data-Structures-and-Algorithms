#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int change(vector<int>& coins, int target, unordered_map<int, int>& memo)
{
    if(memo.find(target) != memo.end()) return memo[target];

    if(target == 0) return 1;
    int ways = 0;
    for(int i = 0; i < coins.size(); ++i)
    {
        if(target - coins[i] >= 0)
            ways += change(coins, target-coins[i], memo);
    }

    memo[target] = ways;
    return ways;
}


int main() {
    vector coins{1, 2};
    string chosen = "";

    unordered_map<int, int> memo;

    for(int i = 1; i < 10; ++i) {
        int ans = change(coins, i, memo);
        cout << ans << '\n';
    }

    return 0;
}
