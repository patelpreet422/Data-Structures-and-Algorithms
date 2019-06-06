#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int coin_row_problem(const vector<int>& coins)
{
    vector<int> value(coins.size(), numeric_limits<int>::min());
    value[0] = coins[0];
    cout << "Coins: ";
    if(coins[0] > coins[1])
    {
        value[1] = coins[0];
        cout << coins[0] << " ";
    } else {
        value[1] = coins[1];
        cout << coins[1] << " ";
    }

    for(int i = 2; i < coins.size(); ++i)
    {
        if(value[i-2] + coins[i] > value[i-1])
        {
            value[i] = value[i-2] + coins[i];
            cout << coins[i] << " ";
        }
    }
    cout << "\nValue: " << value[coins.size()-1] << '\n';

    return value[coins.size()-1];
}

int main() {
    vector<int> coins {5, -1, -2, 10, 6, 3};
    coin_row_problem(coins);
    return 0;
}
