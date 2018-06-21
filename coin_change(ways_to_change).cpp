#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
			chosen.push_back(current_coin+'0');
			ways += waysToChangeHelper(coin-current_coin, coins, i, chosen);
			chosen.pop_back();
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
	cout << waysToChange(coin, coins) << '\n';
	return 0;
}
