#include <iostream>
using namespace std;

bool rabin_karp(string s, string pat)
{
	for(auto i = 0u; i <= s.size() - pat.size(); ++i)
	{
		if(s.substr(i, pat.size()) == pat) return true;
	}
	return false;
}

int main()
{
	string s = "abcdef";
	string pat = "bcd";
	cout << boolalpha << rabin_karp(s, pat) << '\n';
	return 0;
}
