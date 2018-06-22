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

int waysToChangeHelper(int coin, const vector<int> &coins, int current_it, string &chosen)
{
	
	if(coin == 0)
	{
		cout << chosen << '\n';
		return 1;
	}
	int ways = 0;
	for(int i = current_it; i < coins.size(); ++i)
	{
		int current_coin = coins[i];
		if(coin-current_coin>=0)
		{
			chosen += to_string(current_coin);
			ways += waysToChangeHelper(coin-current_coin, coins, i, chosen);
			int l = len_i(current_coin);
			chosen.erase(chosen.size()-l, l);
		}
	}
	return ways;
}

int waysToChange(int coin, const vector<int> &coins)
{
  string chosen = "";
	return waysToChangeHelper(coin, coins, 0, chosen);
}

int main()
{
	int coin = 5;
	vector<int> coins{1, 2, 3, 4, 5, 6, 7, 8, 9};
    waysToChange(coin, coins);
	return 0;
}
