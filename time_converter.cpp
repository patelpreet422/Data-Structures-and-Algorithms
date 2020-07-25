#include <iostream>
#include <string>
using namespace std;

unsigned to_digit(std::string &s, int i, int j) {
  return (s[i] - '0') * 10 + (s[j] - '0');
}

string get_time_str(unsigned hh, unsigned mm, unsigned ss) {
  string time_str, h = "00", m = "00", s = "00";

  if (hh / 10 == 0) {
    h[1] = '0' + hh;
  } else {
    h = to_string(hh);
  }

  if (mm / 10 == 0) {
    m[1] = '0' + mm;
  } else {
    m = to_string(mm);
  }

  if (ss / 10 == 0) {
    s[1] = '0' + ss;
  } else {
    s = to_string(ss);
  }
  time_str = h + ":" + m + ":" + s;
  return time_str;
}

string timeConversion(string s) {
  auto hh = to_digit(s, 0, 1);
  auto mm = to_digit(s, 3, 4);
  auto ss = to_digit(s, 6, 7);
  if (s[8] == 'P') {
    if (hh == 12) {
      hh = 12;
    } else {
      hh += 12;
    }
  } else {
    if (hh == 12) {
      hh = 0;
    }
  }
  return get_time_str(hh, mm, ss);
}

int main() {
  string s;
  getline(cin, s);

  string result = timeConversion(s);

  cout << result << '\n';

  return 0;
}
