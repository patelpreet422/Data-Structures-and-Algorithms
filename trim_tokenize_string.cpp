#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
#include <climits>
#include <algorithm>
#include <cmath>
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

int main() {
    string s = "hello | this | is | columns";
    stringstream ss(s);
    while(getline(ss, s, '|')) {
        trim_left(s);
        trim_right(s);
        cout << "\"" << s << "\"\n";
    }
    return 0;
}
