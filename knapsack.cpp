#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int capacity)
{
  vector<vector<int>> dp(capacity+1, vector<int>(value.size()+1, 0));

  for(int i = 1; i <= capacity; ++i)
  {
    for(int j = 1; j <= value.size(); ++j)
    {
      if(i - weight[j-1] >= 0)
      {
        dp[i][j] = max(value[j-1]+dp[i - weight[j-1]][j-1], dp[i][j-1]); 
      } else {
        dp[i][j] = dp[i][j-1];
      }
    }
  }

  return dp[capacity][value.size()];
}

int main()
{
  vector<int> value{3, 4, 5, 6};
  vector<int> weight{2, 3, 4, 5};
  int capacity = 5;
  cout << knapsack(weight, value, capacity) << '\n';
  return 0;
}
