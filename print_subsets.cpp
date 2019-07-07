#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void subsets(vector<int>& vec, int i, string chosen)
{
	static int c = 0;
	if (i == vec.size()) {
		cout << c << ": " <<chosen << '\n';
		++c;
		return;
	}
	subsets(vec, i + 1, chosen + " " + to_string(vec[i]));
	subsets(vec, i + 1, chosen);
}

int main()
{
	vector<int> vec{1, 2, 3, 4, 5};
	subsets(vec, 0, "");
	return 0;
}
