#include <iostream>
#include <unordered_set>
using namespace std;

int waysToChangeHelper(int coin, const unordered_set<int> &coins, unordered_set<int>::const_iterator current_it, string chosen)
{
	if(coin == 0)
	{
		cout << chosen << '\n';
		return 1;
	}
	int ways = 0;
	for(auto it = current_it; it != coins.end();++it)
	{
		int current_coin = *it;
		if(coin-current_coin>=0)
		{
			chosen += to_string(current_coin);
			ways += waysToChangeHelper(coin-current_coin, coins, it, chosen);
			chosen.erase(chosen.size()-1, 1);
		}
	}
	return ways;
}

int waysToChange(int coin, const unordered_set<int> &coins)
{
	return waysToChangeHelper(coin, coins, coins.begin(), "");
}

int main()
{
	int coin = 5;
	unordered_set<int> coins{1, 2, 5};
	cout << waysToChange(coin, coins) << '\n';
	return 0;
}
