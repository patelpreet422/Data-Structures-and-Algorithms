#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string next_palindrome(string ss)
{
	string s = ss;
	int r = s.size()/2;
	int l = (s.size()%2)? r: r-1;
	
	for(int i=l,j=r; j<s.size();)
		s[j++]=s[i--];
	//s is symmetric about its center
	while(s.size()<=ss.size() && s<=ss)
	{
		int i=l, j=r;
		while(s[i]=='9'&& i>=0)
		{
			// case when we have 9's in middle
			s[i--] = s[j++] = '0';
		}
		if(i<0)
		{
			// i < 0, means all 9's
			s = "1"+s;
			s[s.size()-1] = '1';
		}
		else
		{
			// we made all 9's(if at all) to zero but we didn't add carry of either side so we do it here
			s[i] = s[j] = s[j]+1;
		}
		//cout << s << '\n';
	}
	return s;
}

int main()
{
	string ss = "11";
	cin >> ss;
	cout << next_palindrome(ss) << '\n';
	return 0;
}
