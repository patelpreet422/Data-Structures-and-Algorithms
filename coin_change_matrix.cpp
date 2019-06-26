#include <iostream>
#include <vector>
using namespace std;

long getWays(vector<long> coins, int target)
{
    vector<vector<long>> ways(coins.size()+1, vector<long>(target+1, 0));

    // fill first column with 1
    for(int i = 0; i <= coins.size(); ++i)
    {
        ways[i][0] = 1;
    }

    for(int i = 1; i <= coins.size(); ++i)
    {
        for(int j = 1; j <= target; ++j)
        {
            if(j-coins[i-1] < 0)
            {
                ways[i][j] = ways[i-1][j];
            } else {
                ways[i][j] = ways[i-1][j] + ways[i][j - coins[i-1]];
            }
        }
    }
    return ways[coins.size()][target];
}

int main() {
    vector<long> coins{1, 2, 5};
    string chosen = "";
    int ans = getWays(coins, 5);

    cout << ans << '\n';
    return 0;
}
