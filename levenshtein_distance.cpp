#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

int edit(const string& word1, const string &word2) {
    const int size1 = word1.size(), size2 = word2.size();
    vector<int> dp(size2+1, 0), res(size2+1, 0);
    for(int i = 1; i <= size2; ++i) res[i] = i;
    for(int i = 0; i < size1; ++i) {
        dp[0] = i+1;
        for(int j = 1; j <= size2; ++j) {
            if(word1[i] == word2[j-1]) dp[j] = res[j-1];
            else dp[j] = min(res[j], min(dp[j-1], res[j-1])) + 1;
        }
        swap(dp, res);
    }
    return res[size2];
}

int main()
{
    cout << edit("abc", "abcde") << '\n';
    return 0;
}
