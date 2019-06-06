#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int minimum_coin_change(vector<int> coins, int target)
{
    vector<int> min_coins(target+1, target+1);

    min_coins[0] = 0;

    for(int value = 0; value <= target; ++value)
    {
        for(auto coin: coins)
        {
            if(coin <= value)
            {
                min_coins[value] = min(min_coins[value], 1+min_coins[value-coin]);
            }
        }
    }

    return min_coins[target];
}

int main() {
    vector<int> coins {9, 6, 5, 1};
    cout << minimum_coin_change(coins, 11) << '\n';
    return 0;
}
