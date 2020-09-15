#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
#include <climits>
#include <algorithm>
#include <cmath>
#include <vector>
using ll = long long;
using namespace std;

void trim_left(string& s) {
    int i = 0, n = s.size();
    while(i < n and (iscntrl(s[i]) or isblank(s[i]) or isspace(s[i]))) {
        ++i;
    }
    s.erase(0, i);
}

void trim_right(string& s) {
    if(s.empty()) return; 
    int n = s.size(); 
    int i = n-1;
    while(i >= 0 and (iscntrl(s[i]) or isspace(s[i]) or isblank(s[i]))) {
        --i;
    }
    s.erase(i+1);
}

void trim(string& s) {
    trim_left(s);
    trim_right(s);
}

// NOTE: This is just very basic implementation and use it by making proper modification if needed
template <typename Func>
vector<string> split(const string& s, Func predicate) {
    vector<string> tokens;
    string token = "";
    for(auto c: s) {
        if(predicate(c)) {
            trim(token);
            if(!token.empty()) {
                tokens.push_back(token);
                token = "";
            }
        }  else {
            token.push_back(c);
        }
    }
    trim(token);
    if(!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    string table = "\\
        hello, bob, this , my, name,,,,,     kfkkajkfdk markey, \\
        hjfhjaf ,   \t\t \v, jkjk, nj, \\
    ";
    for(auto s: split(table, [](char c) {return c == ',';})) {
        cout << "\"" << s << "\"" << ' ';
    }
    cout << '\n';
    return 0;
}
