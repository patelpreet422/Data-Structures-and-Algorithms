#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



void subsets(vector<int>& vec, int i, string chosen, int k)
{
	static int c = 0;
	if (k == 0) {
		cout << c << ": " << chosen << '\n';
		++c;
		return;
	}
	if (i == vec.size() || k < 0) return;
	subsets(vec, i + 1, chosen + " " + to_string(vec[i]), k-1);
	subsets(vec, i + 1, chosen, k);
}

int main()
{
	vector<int> vec{1, 2, 3, 4, 5};
	vector<string> ss(vec.size() << 1);
	subsets(vec, 0, "", 2);
	return 0;
}
