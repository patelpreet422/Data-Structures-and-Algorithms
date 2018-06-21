#include <iostream>
#include <algorithm>
#include <string>
const int limit = 200;
std::string factorial(int n)
{
	std::string res(limit, '0');
	res[0] = '1';
	for(int j = 1; j <= n; ++j)
	{
		int carry = 0;
		for(int i = 0; i < limit; ++i)
		{
			int product = (res[i]-'0')*j + carry;
			res[i] = '0'+(product%10);
			carry = product/10;
		}
	}
	
	res.shrink_to_fit();
	std::reverse(res.begin(), res.end());
	res.erase(0, res.find_first_not_of('0'));
	return res;
}
int main()
{
	int n = 100;
	std::cout << factorial(n);
	return 0;
}
