#include <bits/stdc++.h>
/* #include <prettyprint.hpp> */
using namespace std;
using ll = long long;

vector<int> kmp_jump_array(const string& s) {
  /*
   * jmp[i] = length of longest prefix that is also suffix of
   * s[0..i] (0 and i are both inclusive)
   * another way to interpret jmp[i] is to say that it is the index where
   * we must jump inorder to continue searching from there instead of
   * starting all over again
   *
   * Suppose if we are at j in text T and at i in patterm P and if
   * T[j] != P[i] then we must set i = jmp[i-1] and then continue
   * matching P[i] with T[j]
   *
   * Computing jump table is kind of like searching for some prefix of S
   * in S itself but rather than throwing of the information we keep track
   * of what is prefix that we have matched at every points
   */
  int n = s.size();
  vector<int> jmp(n, 0);
  int k = 0;
  for (int i = 1; i < n; ++i) {
    while (k > 0 && s[i] != s[k]) {
      k = jmp[k - 1];
    }
    if (s[i] == s[k]) {
      ++k;
    }
    jmp[i] = k;
  }
  return jmp;
}

bool kmp_search(const string &text, const string &pat) {
  bool found = false;
  vector<int> jmp = kmp_jump_array(pat);

  /*
   * k stores the length of the prefix that is matched till now
   * another way to think about k is that, it is points to the
   * next char in P, that needs to be matched against
   * some char in text T
   */
  int k = 0;
  for (int i = 0; i < text.size(); ++i) {
    while (k > 0 && text[i] != pat[k]) {
      k = jmp[k - 1];
    }
    if (text[i] == pat[k]) {
      ++k;
    }
    if (k == pat.size()) {
      found = true;
      // now we can return or find more occurance of pat
      cout << i - k + 1 << ' ';

      // we go back so as to continue finding more occurance of pat
      k = jmp[k - 1];
    }
  }
  return found;
}

int main() {
  string p = "AABAACAADAABAABA";
  kmp_search(p, "AABA");
  return 0;
}

