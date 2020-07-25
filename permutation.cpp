#include <iostream>
#include <vector>
using namespace std;

vector<bool> pick;

void permute(const string &s, string chosen) {
  if (chosen.size() == s.size()) {
    cout << chosen << '\n';
    return;
  }

  for (int i = 0; i < s.size(); ++i) {
    if (pick[i])
      continue;

    pick[i] = true;

    permute(s, chosen + s[i]);

    pick[i] = false;
  }
}

void permute(const string &s) {
  pick.assign(s.size(), false);
  permute(s, "");
}

int main() {
  string s = "1234";
  permute(s);
  return 0;
}
