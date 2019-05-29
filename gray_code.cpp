#include <iostream>
#include <exception>
#include <iomanip>
using namespace std;

void bin_(int k, string & bin_str)
{
	if(k>>1 != 0) bin_(k>>1, bin_str);
	bin_str += '0'+(k%2);
}
	
string bin(int k)
{
	string bin_str;
	bin_(k, bin_str);
	return bin_str;
}
	
int g(int n)
{
	return n ^ (n >> 1);
}

void gray_code(int n)
{
	for(int i = 0; i < (1<<n); ++i)
	{
		cout << setw(n) << setfill('0') << bin(g(i)) << '\n';
	}
}

int main()
{
	gray_code(3);
}
