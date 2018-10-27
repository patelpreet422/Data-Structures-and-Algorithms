long getWays(long target, vector<long> coins)
{
    long ways[coins.size()][target+1];
    ways[0][0] = 1;
    // fill first column with 1
    for(int i = 0; i < coins.size(); ++i)
    {
        ways[i][0] = 1;
    }
    
    // fill first row
    for(int j = 1; j <= target; ++j)
    {
        if(j < coins[0])
        {
            ways[0][j] = 0;
        } else {
            if(j % coins[0] == 0)
                ways[0][j] = 1;
            else
                ways[0][j] = 0;
        }
    }
    for(int i = 1; i < coins.size(); ++i)
    {
        for(int j = 1; j <= target; ++j)
        {
            if(j < coins[i])
            {
                ways[i][j] = ways[i-1][j];
            } else {
                ways[i][j] = ways[i-1][j] + ways[i][j - coins[i]];
            }
        }
    }
    /*
    // print
    cout << "    ";
    for(int j = 0; j <= target; ++j)
    {
        cout << j << " ";
    }
    cout << "\n----------------------\n";
    for(int i = 0; i < coins.size(); ++i)
    {
        cout << coins[i] << " | ";
        for(int j = 0; j <= target; ++j)
        {
            cout << ways[i][j] << " ";
        }
        cout << '\n';
    }
    */
    return ways[coins.size()-1][target];
}
