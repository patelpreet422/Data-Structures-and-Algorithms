#include <iostream>
#include <vector>
#include <string>
using namespace std;
int ways_to_come_down(int stairs, const vector<int> &steps, string &chosen)
{
    if(stairs < 0) return 0;
    if(stairs == 0)
    {
        cout << chosen << '\n';
        return 1;
    }
    int ways = 0;
    for(const auto &e: steps)
    {
        chosen.push_back(e+'0');
        ways += ways_to_come_down(stairs-e, steps, chosen);
        chosen.pop_back();
    }
    return ways;
}

int ways_to_come_down(int stairs, const vector<int> &steps)
{
    string chosen = "";
    return ways_to_come_down(stairs, steps, chosen);
} 

int main()
{
    int stairs = 5;
    vector<int> steps = {1, 2};
    cout << ways_to_come_down(stairs, steps) << '\n';
    return 0;
}
