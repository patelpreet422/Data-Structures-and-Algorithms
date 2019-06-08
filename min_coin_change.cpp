#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int minimum_coin_change(vector<int> coins, int target)
{
    vector<vector<int>> dp(coins.size()+1, vector<int>(target+1, target+1));

    // dp[0][value] = infinity, here target+1 is placeholder for infinity

    for(int coin_idx = 0; coin_idx <= coins.size(); ++coin_idx)
        dp[coin_idx][0] = 0;

    for(int coin_idx = 1; coin_idx <= coins.size(); ++coin_idx)
    {
        for (int value = 0; value <= target; ++value) {
            if(value >= coins[coin_idx-1])
            {
                dp[coin_idx][value] = min(dp[coin_idx-1][value], 1+dp[coin_idx][value-coins[coin_idx-1]]);
            }
        }
    }

    return dp[coins.size()][target];
}

int main() {
    vector<int> coins {9, 6, 5, 1};
    cout << minimum_coin_change(coins, 11) << '\n';
    return 0;
}
